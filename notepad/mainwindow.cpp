#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_close_file_triggered()
{
    QApplication::exit();
}


void MainWindow::on_action_4_triggered()
{
    QMessageBox::information(this, "Информация", "Блокното был создан 10/02/2024", QMessageBox::Ok);
}


void MainWindow::on_color_triggered()
{
   QColor color = QColorDialog::getColor(Qt::black, this);
    ui->notepad->setTextColor(color);
}


void MainWindow::on_shrift_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times New Roman", 14), this);
    if(&ok)
        ui->notepad->setFont(font);
}


void MainWindow::on_open_triggered()
{
   QString file = QFileDialog::getOpenFileName(this, "Открыть файл", "C://");
   QFile open(file);
   if(!open.open(QIODevice::ReadOnly | QFile::Text)){ // !open.open(QIODevice::ReadOnly | QFile::Text) для считывания информации взятой из файла
       QMessageBox::critical(this, "ERROR", "Не удалось открыть файл");
        return;
   }

   QTextStream out(&open);
   QString text = ui->notepad->toPlainText();
   text.append(out.readAll()); //append позволяет добавить к тексту доп. строку
   open.close();

   ui->notepad->setText(text);
}

void MainWindow::on_Create_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Сохранить файл?", "Ds хотите сохранить файл?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
        on_open_triggered();

    ui->notepad->setText("");
}


void MainWindow::on_save_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Сохранить файл", "C://");
    QFile open(file);
    if(!open.open(QIODevice::WriteOnly | QFile::Text)){ // !open.open(QIODevice::ReadOnly | QFile::Text) для считывания информации взятой из файла
        QMessageBox::critical(this, "ERROR", "Не удалось сохранить файл");
        return;
    }

    QTextStream out(&open);
    QString text = ui->notepad->toPlainText();
    out << text;
    open.close();

    ui->notepad->setText(text);
}

