#include "mainwindow.h"
#include "Philosopher.cpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    appendTextToLabel("Anachronism");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendTextToLabel(const QString& text)
{
    QString temp = ui->label->text();
    temp.append(text);
    ui->label->setText(temp);
}

void MainWindow::on_pushButton_clicked()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < N; i++)
    {
        threads.push_back(std::thread(philosopher, i));
    }

    for (int i = 0; i < N; i++)
    {
        threads.at(i).join();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}

