#ifndef FOLDERSCOMPARE_H
#define FOLDERSCOMPARE_H

#include <QDialog>
#include <QtCore>
#include <QtWidgets>

namespace Ui {
class FoldersCompare;
}

class FoldersCompare : public QDialog
{
    Q_OBJECT

public:
    explicit FoldersCompare(QWidget *parent = 0);
    ~FoldersCompare();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FoldersCompare *ui;

    QFileSystemModel *file_model1_;         // Folder 1
    QFileSystemModel *file_model2_;         // Folder 2
    QStringListModel *string_list_model1_;  // Matches 1
    QStringListModel *string_list_model2_;  // Matches 2
};

#endif // FOLDERSCOMPARE_H
