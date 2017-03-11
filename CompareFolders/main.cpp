#include "folderscompare.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FoldersCompare w;
    w.show();

    return a.exec();
}
