#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QWheelEvent>

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

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", scale));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    scale += event->angleDelta().y();
    repaint();
}
