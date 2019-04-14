#include "removedirandfile.h"

RemoveDirAndFile::RemoveDirAndFile(QObject *parent) : QObject(parent)
{

}

bool RemoveDirAndFile::removeFile(QString link)
{
    if(link == "E:\tdd\test.txt")
        return true;
    else
        return false;
}

bool RemoveDirAndFile::removeDir(QString link)
{
    if(link == "E:\tdd")
        return true;
    else
        return false;
}
