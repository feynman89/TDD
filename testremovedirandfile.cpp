#include "testremovedirandfile.h"

TestRemoveDirAndFile::TestRemoveDirAndFile(QObject *parent) : QObject(parent)
{

}

void TestRemoveDirAndFile::testCreate()
{
    RemoveDirAndFile removeDirAndFile;
}

void TestRemoveDirAndFile::testRemoveFile()
{
    RemoveDirAndFile removeDirAndFile;
    QCOMPARE(removeDirAndFile.removeFile("E:\tdd\test.txt"), true);
}
