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
    QCOMPARE(removeDirAndFile.removeFile("E:/tdd/test.txt"), true);
}

void TestRemoveDirAndFile::testRemoveDir()
{
    RemoveDirAndFile removeDirAndFile;
    QCOMPARE(removeDirAndFile.removeDir("E:/tdd"), true);
}

void TestRemoveDirAndFile::testGetAllFilesInDir()
{
    RemoveDirAndFile removeDirAndFile;
    QCOMPARE(removeDirAndFile.getAllFilesInDir("E:/tdd"), QStringList({"test.txt", "test1.txt"}));
}
