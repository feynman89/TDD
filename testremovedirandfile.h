#ifndef TESTREMOVEDIRANDFILE_H
#define TESTREMOVEDIRANDFILE_H

#include <QObject>
#include <QTest>

class TestRemoveDirAndFile : public QObject
{
    Q_OBJECT
public:
    explicit TestRemoveDirAndFile(QObject *parent = nullptr);

signals:

private slots:
    void testCreate();
};

#endif // TESTREMOVEDIRANDFILE_H
