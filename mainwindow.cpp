#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextEdit *textEdit = new QTextEdit(this);

    setCentralWidget(textEdit);

}


MainWindow::~MainWindow()
{
    delete ui;
}

