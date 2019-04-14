#ifndef REMOVEDIRANDFILE_H
#define REMOVEDIRANDFILE_H

#include <QObject>
#include <QFile>
#include <QDir>

class RemoveDirAndFile : public QObject
{
    Q_OBJECT
public:
    explicit RemoveDirAndFile(QObject *parent = nullptr);

signals:

public slots:
    bool removeFile(QString link);
    bool removeDir(QString link);
    QStringList getAllFilesInDir(QString link);
};

#endif // REMOVEDIRANDFILE_H
