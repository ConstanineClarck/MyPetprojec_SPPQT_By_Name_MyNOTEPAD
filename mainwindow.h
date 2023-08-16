#ifndef MAINWINDOW_H   // Защита включения, проверяет истина ли макроопределение MAINWINDOW_H гаранирует наам, что класс  MainWIndow уже был определён один раз, что бы нам не определить его второй раз
#define MAINWINDOW_H

#include <QMainWindow> // Объявление класса для MainWindow наследуется от QMainWindow, может расширять функциальность QMainWindow
                       // MinWindow может переопределять виртуальные методы QMainWindow, объекты MainWindow могут служить указателями на QMainWindow!!!

namespace Ui           // Объявляем пространство имён пользовательского интерфейса которое хранит класс MainWindow, сгенерированый с помощью uic из файла mainwindow.ui, оно позволяет получиь доступ к элементам пользовательского интерфейса в коде и предотвращает конфликты имён с пользовательским классом управления, если он будет называться так же
{
  class MainWindow;    // Создаёт дочерний класс от QMainWindow, из формы ui, для дальнейшего использования, и окружает его пространством имён, с целью чтоб созданный класс, в случае чего не конфликтовал с нашими пользовательскими классвми которые мы можем, назвать так же, по случайности 
}
 class MainWindow : public QMainWindow   // Объявление класса MainWIndow, который мы наследуем от QMainWindow, по средством него можно переопределиь виртуальные методы, сигналы и т.д
{
     Q_OBJECT                            // Служебный макрос Qt, который, просто, должен быть включен в классы, включает поддержку метообъектов (moc) для класса в который доавлен, позволяет классу использовать функции Qt, moc генерирует для реализации функций согласно их заголовкам, которые он анализирует
public:
     MainWindow(QWidget * parent = nullptr); // Объявление конструктора и диструктора для создания и уничтожения класса MainWindow
    ~MainWindow();

 private slots:

    void onNew();       // Обрабатывает создание нового документа, которое мы вызываем из меню на панели инструментов блокнота

    void onOpen();      // Открытие существующего документа, при реализации использует QFile что бы открыть существующий файл который мы выбираем

    void onSave();      // Сохранение текущего документа, при реализации получаем текст из QTextEdit, открываем файл для записи по средством QFile! 
                        // Так же может запрашивать имя файл, если это новый несохранённый файл
private:
    Ui::MainWindow *ui; //

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;


    QtexEdit *textEdit;

 };

#endif // MAINWINDOW_H
