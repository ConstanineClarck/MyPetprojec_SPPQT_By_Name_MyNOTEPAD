#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)   // Конструктор класса MainWindow, который получает на вход параметр виджет родительского класса QmainWindow, все виджиты в иерархии Qt принимать в своём конструкторе параметр родительского виджита
    : QMainWindow(parent)                 
    , ui(new Ui::MainWindow)              // Создаём новый класс пользовательского интерфейса MainWindow в пространстве имён Ui, созданный инструментом uic от Qt

{
    ui->setupUi(this);                    // Этот указатель пользовательского интерфейса предоставляет доступ ко всем элементам интерфейса, cвязывает форму пользовательского интерфейса с фактическим экземпляром MainWindow


    textEdit = new QTextEit;              // 
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

    textEdit->clear();                // При вызове, метод clear() удаляет весь текст, делает документ пустым и вызывает заголовок окна

    setWindowTitle("Untitled");       // Изменяет заголовок в верху главного окна на значение, которое ещё не было задано и стоит по умолчанию в системе, типа "Без названия" 
}                                     // Слот onNew() вызывается при действии "Новый документ", что бы очистить документ, сбросить заголовок и настроить новый файл

void MainWIndow::onOpen()
{
    QString filePath = QFileDialog::getOpenFileName(this); // Показывает диалог открытия файла для выбора файла
    
    QFile file(filePath);                                  // Создаём объект типа файл
    if(file.open(QFile::ReadOnly))                         //
    {
        QByteArray text = file.readAll();                  // ЧИтаем сожержимое в массив байтов?
        textEdit->setText(text);                           // Установить содержимое для редактирования текста?
        setWindowTitle(filePath);                          // Помещаем заголовок окна в имя файла
    }
    else
    {
        QMessageBox::warning(this, "ОШИБКА! Не удалось открыть файл!");   // Выводит сообщение об ошибке, файл был открыт с ошибкой
}
void MainWindo::onSave()                                   // Слот для обработки сохранения текущего файла
{
    QString text = textEdit->toPlainText();                // Получить содержимое редактирования текста???
    
    QFile file(fileName);                                  // Открываем файл для записи
    if(file.open(QFile::WriteOnly))                        
    {
        file.write(text.toUtf8());
        setWindowTitle(fileName);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");     // Выводит сообщение об ошибке, что файл не был сохранён
    }

}



