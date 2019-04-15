#include "removedirandfile.h"

RemoveDirAndFile::RemoveDirAndFile(QObject *parent) : QObject(parent)
{

}

bool RemoveDirAndFile::removeFile(QString link)
{
    if(QFile::remove(link))
        return true;
    else
        return false;
}

bool RemoveDirAndFile::removeDir(QString link, QString symbols, int n_countReapet)
{
    //Получаем список каталогов
    QStringList lstDirs = getAllFoldersInDir(link);

    //Получаем список файлов
    QStringList lstFiles = getAllFilesInDir(link);

    //Удаляем файлы
    foreach (QString entry, lstFiles)
    {
        QString entryAbsPath = link + "/" + entry;
        inputSumbolsInFile(entryAbsPath, symbols, n_countReapet);
        QFile::setPermissions(entryAbsPath, QFile::ReadOwner | QFile::WriteOwner);
        removeFile(entryAbsPath);
    }

    //Для папок делаем рекурсивный вызов
    foreach (QString entry, lstDirs)
    {
        QString entryAbsPath = link + "/" + entry;
        removeDir(entryAbsPath, symbols, n_countReapet);
    }

    if (QDir().rmdir(link))
        return  true;
    else
        return false;
}

QStringList RemoveDirAndFile::getAllFilesInDir(QString link)
{
    return QDir(link).entryList(QDir::Files);
}

QStringList RemoveDirAndFile::getAllFoldersInDir(QString link)
{
    return QDir(link).entryList(QDir::Dirs | QDir::AllDirs | QDir::NoDotAndDotDot);
}

bool RemoveDirAndFile::checkFile(QString link)
{
    if(QFile::exists(link))
        return true;
    else
        return false;
}

bool RemoveDirAndFile::checkDir(QString link)
{
    if(QDir().exists(link))
        return true;
    else
        return false;
}

QString RemoveDirAndFile::inputSumbolsInFile(QString link, QString symbols, int n_countReapet)
{
    QFile file(link);
    file.open(QIODevice::WriteOnly);
    QTextStream writeStream(&file);
    for (int i=0; i<n_countReapet; ++i)
        writeStream << symbols;
    file.close();
    file.open(QIODevice::ReadOnly);
    QString result = file.readAll();
    file.close();
    return result;
}
