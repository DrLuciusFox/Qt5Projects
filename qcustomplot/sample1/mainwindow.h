#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QCustomPlot *plot_1;
  QGridLayout *glay_1;

private:
  Ui::MainWindow *ui;

protected:
    void setupSimpleDemo(QCustomPlot *customPlot);
};
#endif // MAINWINDOW_H




