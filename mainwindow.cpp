#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);


    textEdit = new QTextEit;
    setCentralWidget(textEdit);

    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *fileMenu = menuBar->addMenu("FIle");

    newAction = new QAction("New", this);
    fileMenu->addAction(newAction);
    connect(newAction, &QAction::triggered, this, &MainWindow::onNew);

    QToolBar *toolBar = addToolBar("Toolbar");
    toolBar->addAction(newAction);

    setWindowTitle("Uninstal");

}

void MaiWindow::onNew()               // Слот обработки создания нового документа в текстовом редакторе, он запускается если пользователь выбирает новое действие в меню! 
                                      // При вызове onNew()  сначала очищается содержимое QTextEdit, отображающего текст документа, очищая любой существующий документ
{

    textEdit->clear();                // При вызове, метод clear() удаляет весь текст, делает документ пустым и вызывает заголовок окна, вызывая 

    setWindowTitle("Untitled");
}

void MainWIndow::onOpen()
{    }
void MainWindo::onSave()
{    }



