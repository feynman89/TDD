#include <QCoreApplication>
#include "testremovedirandfile.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new TestRemoveDirAndFile, argc, argv);

    RemoveDirAndFile removeDirAndFile;

    do{

        QString fileOrDir;
        std::cout << "Input type for delete (file or folder): ";
        std::string tempStr;
        std::cin >> tempStr;
        fileOrDir = QString::fromStdString(tempStr);

        if(fileOrDir == "file" || fileOrDir == "File")
        {
            std::cout << "Input link to file: ";
            std::cin >> tempStr;

            QString fileLink = QString::fromStdString(tempStr);
            if(removeDirAndFile.checkFile(fileLink))
            {
                removeDirAndFile.removeFile(fileLink);
                std::cout << "File " << fileLink.toStdString() << " was remove!" << std::endl;
            }
            else
            {
                std::cout << "Oh no! File not found! Create? ";
                std::cin >> tempStr;

                QString answer = QString::fromStdString(tempStr);
                if(answer == "yes" || answer == "y")
                {
                    std::cout << "Input symbols for new file: ";
                    std::cin >> tempStr;

                    QString symbols = QString::fromStdString(tempStr);
                    int n_countReapet;

                    std:: cout << "And count reapet: ";
                    std::cin >> n_countReapet;
                    for(int i=0; i< n_countReapet; ++i)
                        removeDirAndFile.inputSumbolsInFile(fileLink, symbols);
                }
                else
                    continue;
            }
        }
        else if(fileOrDir == "folder" || fileOrDir == "Folder")
        {
            std::cout << "Input link to folder: ";
            std::cin >> tempStr;

            QString folderLink = QString::fromStdString(tempStr);

            if(removeDirAndFile.checkDir(folderLink))
            {
                removeDirAndFile.removeDir(folderLink);
                std::cout << "Folder " << folderLink.toStdString() << " was remove!" << std::endl;
            }
            else
            {
                std::cout << "Oh no! File not found!";
                continue;
            }
        }
        else
        {
            break;
        }

    }while(true);

    return a.exec();
}
