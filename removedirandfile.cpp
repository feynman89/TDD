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

bool RemoveDirAndFile::removeDir(QString link)
{
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
