#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)   // Конструктор класса MainWindow, который получает на вход параметр виджет родительского класса QmainWindow, все виджиты в иерархии Qt принимать в своём конструкторе параметр родительского виджита
    : QMainWindow(parent)                 
    , ui(new Ui::MainWindow)              // Создаём новый класс пользовательского интерфейса MainWindow в пространстве имён Ui, созданный инструментом uic от Qt

{
    ui->setupUi(this);                    // Этот указатель пользовательского интерфейса предоставляет доступ ко всем элементам интерфейса, cвязывает форму пользовательского интерфейса с фактическим экземпляром MainWindow


    textEdit = new QTextEit;              // Динамически размещает объект типа QTextEdit в стеке, что позволяет ему иметь время жизни, не привязанное к конструктору, textEdit действует как дискриптор для доступа к экземпляру QTextEdit, это позволяет окнам управлять дочерним объектом
    setCentralWidget(textEdit);           // По умолчанию центральный виджет представляе из себя пустой QWidget, метод setCentralWidget(textEdit) - принимает указатель textEdit типа QTextEdit, который наследуется от QWidget, то есть вызов данной функции заменяет центральный пустой по умолчанию виджет на QTextEdit, что бы форма редактировани текста заняла большу часть окна по центру 

    QMenuBar *menuBar = new QMenuBar(this);   // Динамически выделяет объъект виджиьа QMenuBar и назначает его указателю *menuBar, мы передаём указатель this в MainWindow в качестве родителя, сам menuBar как дочерний элемент MainWindow указывает на созданное меню  

    QMenu *fileMenu = menuBar->addMenu("FIle");   // Создаём новый объект QMenu и добавляем его в панель меню с заголовком Fail, посредством addMenu("FIle"), возвращаемый указатель типа QMenu передаём в failMenu 

    newAction = new QAction("New", this);         // QAction - это класс Qt для действий, которые можно добавлять к виджетам, таким образом мы создаём новое действие с текстом "New", указатель this делвет MainWIndow родителем этого действия, о етсь свзяывает время жизни объекта типа QAction c окном! Вкладка Текст->"Новый" появится в меню инструментов  
    fileMenu->addAction(newAction);               // Помещаем возможность создать "Новый документ" и нажать на него в меню, за счёт добавления указателя типа QAction в меню через метод занося его значение в переменную указатель типа fileMenu
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
    if(file.open(QFile::WriteOnly))                        // Проверяет на то открыт ли документ только на запись, через вызов дочернего WriteOnly метода из родительского QFile
    {
        file.write(text.toUtf8());                         // Объект text это QSTring, содержащая текст для записи, а метод toUtf8() преобразует текст QString в массив байтов типа QByteArray закодированный в utf-8 для юникод символов, write() записываетпреобразованный массив байтов utf-8 в файл
        setWindowTitle(fileName);                          // Устанавливает название для главного окна которое мы указываем для сохранения
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");     // Выводит сообщение об ошибке, что файл не был сохранён
    }

}



