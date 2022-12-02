#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("visual_prog_lab7"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter qp(this);
    drawCube(&qp);
}

void MainWindow::drawCube(QPainter *qp)
{
    QPainter painter(this);

      painter.setBrush(QBrush("lime green"));
      painter.drawRect(st_x, st_y, en_x, en_y);
      painter.isActive();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    this->starting_point = event->pos();
    if (starting_point.x() >= st_x && starting_point.x() <= st_x + en_x && starting_point.y() >= st_y && starting_point.y() <= st_y + en_y)
    {
        this->active = true;

    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (this->active == true)
    {
    this->cursor_point += event->pos() - starting_point;
    st_x = cursor_point.x();
    st_y = cursor_point.y();
    starting_point = event->pos();
    repaint();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    this->active =false;
}

