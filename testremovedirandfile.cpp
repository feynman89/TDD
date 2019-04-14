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
    QDir().mkdir("E:/tdd");

    QFile file("E:/tdd/test.txt");
    file.open(QIODevice::WriteOnly);
    file.close();

    RemoveDirAndFile removeDirAndFile;
    QCOMPARE(removeDirAndFile.removeFile("E:/tdd/test.txt"), true);
}

void TestRemoveDirAndFile::testRemoveDir()
{
    RemoveDirAndFile removeDirAndFile;
    QCOMPARE(removeDirAndFile.removeDir("E:/tdd"), true);

    QDir().mkdir("E:/tdd");
}

void TestRemoveDirAndFile::testGetAllFilesInDir()
{
    QFile file("E:/tdd/test.txt");
    file.open(QIODevice::WriteOnly);
    file.close();

    QFile file1("E:/tdd/test1.txt");
    file1.open(QIODevice::WriteOnly);
    file1.close();

    RemoveDirAndFile removeDirAndFile;
    QCOMPARE(removeDirAndFile.getAllFilesInDir("E:/tdd"), QStringList({"test.txt", "test1.txt"}));

    removeDirAndFile.removeFile("E:/tdd/test1.txt");
}

void TestRemoveDirAndFile::testGetAllFoldersInDir()
{
    QDir().mkdir("E:/tdd/test");
    QDir().mkdir("E:/tdd/test1");

    RemoveDirAndFile removeDirAndFile;
    QCOMPARE(removeDirAndFile.getAllFoldersInDir("E:/tdd"), QStringList({"test", "test1"}));
}
