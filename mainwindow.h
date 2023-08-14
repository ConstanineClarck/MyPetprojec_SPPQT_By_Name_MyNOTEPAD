#ifndef MAINWINDOW_H   // Защита включения, проверяет истина ли макроопределение MAINWINDOW_H гаранирует наам, что класс  MainWIndow уже был определён один раз, что бы нам не определить его второй раз
#define MAINWINDOW_H

#include <QMainWindow> // Объявление класса для MainWindow наследуется от QMainWindow, может расширять функциальность QMainWindow
                       // MinWindow может переопределять виртуальные методы QMainWindow, объекты MainWindow могут служить указателями на QMainWindow!!!

namespace Ui           // Объявляем пространство имён пользовательского интерфейса которое хранит класс MainWindow, сгенерированый с помощью uic из файла mainwindow.ui, оно позволяет получиь доступ к элементам пользовательского интерфейса в коде и предотвращает конфликты имён с пользовательским классом управления, если он будет называться так же
{
  class MainWindow;    // 
}
 class MainWindow : public QMainWindow   // Объявление класса MainWIndow, который мы наследуем от QMainWindow, по средством него можно переопределиь виртуальные методы, сигналы и т.д
{
     Q_OBJECT
public:
     MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

 private slots:

    void onNew();

    void onOpen();

    void onSave();

private:
    Ui::MainWindow *ui;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;


    QtexEdit *textEdit;

 };

#endif // MAINWINDOW_H
