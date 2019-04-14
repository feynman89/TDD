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
    //todo реализовать метод removeDir до конца позднее
    if(link == "E:\tdd")
        return true;
    else
        return false;
}
