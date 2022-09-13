#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QActionGroup>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QActionGroup *g = new QActionGroup(this);

    g->addAction(ui->actionRead_Only);
    g->addAction(ui->actionRead_Write);

    g->setExclusive(true);


    connect(ui->actionAbout_DarkTheme, &QAction::triggered, this, &MainWindow::aboutDarkTheme);
    connect(ui->theme_combobox, &QComboBox::currentTextChanged, this, &MainWindow::changeTheme);
    connect(ui->actionAboutQt, &QAction::triggered, this, QApplication::aboutQt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTheme(QString str)
{
    if(str == "Select Theme Here")
    {
        setStyleSheet("");
        return;
    }

    QString file_name = QString(":/%1.qss").arg(str.replace(" ",""));
    QFile file(file_name);
    file.open(QFile::ReadOnly);

    if(file.isOpen()){
        style()->unpolish(this);
        setStyleSheet(QString::fromLatin1(file.readAll()));
        style()->polish(this);
        file.close();
    }

}


void MainWindow::aboutDarkTheme()
{
    QMessageBox::information(this,
                             "About DarkTheme Example",
                             "This is a demo application to show theme appearances.",
                             QMessageBox::Button::Close);
}

