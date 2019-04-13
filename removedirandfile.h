#ifndef REMOVEDIRANDFILE_H
#define REMOVEDIRANDFILE_H

#include <QObject>

class RemoveDirAndFile : public QObject
{
    Q_OBJECT
public:
    explicit RemoveDirAndFile(QObject *parent = nullptr);

signals:

public slots:
    bool removeFile(QString link);
};

#endif // REMOVEDIRANDFILE_H
