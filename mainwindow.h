#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Объявление класса для MainWindow наследуется от QMainWindow, может расширять функциальность QMainWindow
                       // MinWindow может переопределять виртуальные методы QMainWindow, объекты MainWindow могут служить указателями на QMainWindow!!!

namespace Ui           
{
  class MainWindow;
}
 class MainWindow : public QMainWindow
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
