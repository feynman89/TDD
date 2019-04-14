#ifndef TESTREMOVEDIRANDFILE_H
#define TESTREMOVEDIRANDFILE_H

#include <QObject>
#include <QTest>
#include <QFile>
#include <QDir>
#include "removedirandfile.h"

class TestRemoveDirAndFile : public QObject
{
    Q_OBJECT
public:
    explicit TestRemoveDirAndFile(QObject *parent = nullptr);

signals:

private slots:
    void testCreate();
    void testRemoveFile();
    void testRemoveDir();
    void testGetAllFilesInDir();
    void testGetAllFoldersInDir();
    void testCheckFile();
    void testCheckDir();
    void testInputSumbolsInFile();
    void testCreateFile();
};

#endif // TESTREMOVEDIRANDFILE_H
