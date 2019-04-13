#include <QCoreApplication>
#include "testremovedirandfile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new TestRemoveDirAndFile, argc, argv);
    return a.exec();
}
