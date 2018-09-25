#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOtw_rz_triggered();

    void on_actionNowy_triggered();

    void on_actionZapisz_jako_triggered();

    void on_actionDrukuj_triggered();

    void on_actionWyjd_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWklej_triggered();

    void on_actionWytnij_triggered();

    void on_actionCofnij_triggered();

    void on_actionPon_w_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};

#endif // MAINWINDOW_H
