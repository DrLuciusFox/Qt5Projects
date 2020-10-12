#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "qcustomplot.h"
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QGridLayout *bx;
  QGridLayout *t2;
  QGridLayout *t3;
  form *t3f1;
  form *t3f2;
  form *t3f3;

  QRect r0, c0;
  double AR;
  bool frameInit = true;
private:
  Ui::MainWindow *ui;

public slots:
  void random();

protected:
    void setupSimpleDemo(QCustomPlot *customPlot);
    void resizeEvent(QResizeEvent*) override;

};
#endif // MAINWINDOW_H




