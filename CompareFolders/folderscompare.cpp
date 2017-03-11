#include "folderscompare.h"
#include "ui_folderscompare.h"
#include "laiter/compare_files.h"

FoldersCompare::FoldersCompare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoldersCompare)
{
    ui->setupUi(this);
    this->setWindowTitle("Compare Folders");

    // folder 1
    file_model1_ = new QFileSystemModel(this);
    file_model1_->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    // folder 2
    file_model2_ = new QFileSystemModel(this);
    file_model2_->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    // duplicates
    string_list_model1_ = new QStringListModel(this);
    string_list_model2_ = new QStringListModel(this);
}

FoldersCompare::~FoldersCompare()
{
    delete ui;
}

void FoldersCompare::on_pushButton_clicked()
{
    // select folder1
    QString path = QFileDialog::getExistingDirectory(this, "Select folder");
    ui->listView->setModel(file_model1_);
    ui->listView->setRootIndex(file_model1_->setRootPath(path));
}

void FoldersCompare::on_pushButton_2_clicked()
{
    // select folder2
    QString path = QFileDialog::getExistingDirectory(this, "Select folder");
    ui->listView_2->setModel(file_model2_);
    ui->listView_2->setRootIndex(file_model2_->setRootPath(path));
}

void FoldersCompare::on_pushButton_3_clicked()
{
    // compare
    QDirIterator it1(file_model1_->rootPath(), QDir::Files); // Find files in firs folder
    QStringList dir1_files_path;
    while (it1.hasNext())
    {
        dir1_files_path << it1.next();
    }

    QDirIterator it2(file_model2_->rootPath(), QDir::Files); // Find files in second folder
    QStringList dir2_files_path;
    while (it2.hasNext())
    {
        dir2_files_path << it2.next();
    }

    QStringList duplicates_folder_1;
    QStringList duplicates_folder_2;
    for (auto &dir1_file : dir1_files_path)                  // Find all pair of equal files
    {                                                        // in 2 folders
        for (auto &dir2_file : dir2_files_path)
        {
            if(laiter::CompareFiles(dir1_file.toStdString(), dir2_file.toStdString()))
            {
                duplicates_folder_1 << dir1_file;
                duplicates_folder_2 << dir2_file;
            }
        }
    }
    string_list_model1_->setStringList(duplicates_folder_1);  // fill matches
    ui->listView_3->setModel(string_list_model1_);
    string_list_model2_->setStringList(duplicates_folder_2);
    ui->listView_4->setModel(string_list_model2_);
}
