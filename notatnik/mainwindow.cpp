#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNowy_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOtw_rz_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Otworz plik");
    QFile file(filename);
    currentFile = filename;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {

        QMessageBox::warning(this, "Ostrzezenie", "Nie mozna otwozyc pliku: " + file.errorString());
        return;
    }

    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui -> textEdit -> setText(text);
    file.close();


}

void MainWindow::on_actionZapisz_jako_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Zapisz jako...");
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {

        QMessageBox::warning(this, "Ostrzezenie", "Nie mozna zapisac pliku: " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui -> textEdit -> toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionDrukuj_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Nazwa drukarki");
    QPrintDialog pDialog(&printer, this);
    if (pDialog.exec()== QDialog::Rejected) {
        QMessageBox::warning(this, "Ostrzezenie", "Nie ma dostepu do drukarki");
        return;
    }

    ui -> textEdit -> print(&printer);
}

void MainWindow::on_actionWyjd_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionKopiuj_triggered()
{
    ui -> textEdit -> copy();
}

void MainWindow::on_actionWklej_triggered()
{
    ui -> textEdit -> paste();
}

void MainWindow::on_actionWytnij_triggered()
{
    ui -> textEdit -> cut();
}

void MainWindow::on_actionCofnij_triggered()
{
    ui -> textEdit -> undo();
}

void MainWindow::on_actionPon_w_triggered()
{
    ui -> textEdit -> redo();
}
