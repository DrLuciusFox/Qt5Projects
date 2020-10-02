#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  bx = new QGridLayout(ui->dataFrame);
  t2 = new QGridLayout(ui->tab_2);

//  bx->addWidget(ui->textBrowser, 0, 0, 1, 1);
//  bx->addWidget(ui->textBrowser_2, 0, 1, 1, 1);
//  bx->addWidget(ui->textBrowser_3, 1, 0, 1, 1);
//  bx->addWidget(ui->textBrowser_4, 1, 1, 1, 1);

  t2->addWidget(ui->plot2, 0, 1, 1, 2);
  t2->addWidget(ui->dataFrame, 0, 3, 1, 1);

  ui->textBrowser->setText("Madam");
  ui->textBrowser_2->setText("Akshitha");
  ui->textBrowser_3->setText("Rowdy");
  ui->textBrowser_4->setText("Baby");

  ui->plot1_1->setSelectionRectMode(QCP::srmZoom);
  ui->plot2->setSelectionRectMode(QCP::srmZoom);
  setupSimpleDemo(ui->plot1_1);
  setupSimpleDemo(ui->plot1_2);
  setupSimpleDemo(ui->plot2);

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setupSimpleDemo(QCustomPlot *customPlot)
{
  // add two new graphs and set their look:
  customPlot->addGraph();
  customPlot->graph(0)->setPen(QPen(Qt::blue));
  // line color blue for first graph
  customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
  // first graph will be filled with translucent blue
  customPlot->addGraph();
  customPlot->graph(1)->setPen(QPen(Qt::red));
  // line color red for second graph

  // generate some points of data (y0 for first, y1 for second graph):
  QVector<double> x(250), y0(250), y1(250);
  for (int i=0; i<250; ++i)
    {
      x[i] = i;
      y0[i] = exp(-i/150.0)*cos(i/10.0);
      // exponentially decaying cosine
      y1[i] = exp(-i/150.0);
      // exponential envelope
    }

  customPlot->xAxis2->setVisible(true);
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setVisible(true);
  customPlot->yAxis2->setTickLabels(false);
  customPlot->graph(0)->setData(x, y0);
  customPlot->graph(1)->setData(x, y1);
  customPlot->graph(0)->rescaleAxes();
  customPlot->graph(1)->rescaleAxes(true);

}




































/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*
void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    QString result = "";
    qDebug() << result;
}

#if QT_CONFIG(wheelevent)
void MainWindow::wheelEvent (QWheelEvent *e)
{
//    QString result;
//    if (e->delta() > 0) {

//        if (e->orientation() == Qt::Vertical) {
//            result = "Mouse Wheel Event: UP";
//        } else {
//            result = "Mouse Wheel Event: LEFT";
//        }
//    } else if (e->delta() < 0) {
//        if (e->orientation() == Qt::Vertical) {
//            result = "Mouse Wheel Event: DOWN";
//        } else {
//            result = "Mouse Wheel Event: RIGHT";
//        }
//    }
//    qDebug() << result;
}
#endif
*/

//int MainWindow::buttonByNumber(const Qt::MouseButton button)
//{
//    if (button == Qt::NoButton)      return 0;
//    if (button == Qt::LeftButton)    return 1;
//    if (button == Qt::RightButton)   return 2;
//    if (button == Qt::MiddleButton)  return 3;

///* Please note that Qt Button #4 corresponds to button #8 on all
// * platforms which EMULATE wheel events by creating button events
// * (Button #4 = Scroll Up; Button #5 = Scroll Down; Button #6 = Scroll
// * Left; and Button #7 = Scroll Right.) This includes X11, with both
// * Xlib and XCB.  So, the "raw button" for "Qt::BackButton" is
// * usually described as "Button #8".

// * If your platform supports "smooth scrolling", then, for the cases of
// * Qt::BackButton and higher, this program will show "raw button" with a
// * value which is too large. Subtract 4 to get the correct button ID for
// * your platform.
// */

//    if (button == Qt::BackButton)    return 8;
//    if (button == Qt::ForwardButton) return 9;
//    if (button == Qt::TaskButton)    return 10;
//    if (button == Qt::ExtraButton4)  return 11;
//    if (button == Qt::ExtraButton5)  return 12;
//    if (button == Qt::ExtraButton6)  return 13;
//    if (button == Qt::ExtraButton7)  return 14;
//    if (button == Qt::ExtraButton8)  return 15;
//    if (button == Qt::ExtraButton9)  return 16;
//    if (button == Qt::ExtraButton10) return 17;
//    if (button == Qt::ExtraButton11) return 18;
//    if (button == Qt::ExtraButton12) return 19;
//    if (button == Qt::ExtraButton13) return 20;
//    if (button == Qt::ExtraButton14) return 21;
//    if (button == Qt::ExtraButton15) return 22;
//    if (button == Qt::ExtraButton16) return 23;
//    if (button == Qt::ExtraButton17) return 24;
//    if (button == Qt::ExtraButton18) return 25;
//    if (button == Qt::ExtraButton19) return 26;
//    if (button == Qt::ExtraButton20) return 27;
//    if (button == Qt::ExtraButton21) return 28;
//    if (button == Qt::ExtraButton22) return 29;
//    if (button == Qt::ExtraButton23) return 30;
//    if (button == Qt::ExtraButton24) return 31;
//    qDebug("QMouseShortcutEntry::addShortcut contained Invalid Qt::MouseButton value");
//    return 0;
//}

//QString MainWindow::enumNameFromValue(const Qt::MouseButton button)
//{
//    if (button == Qt::NoButton)      return "NoButton";
//    if (button == Qt::LeftButton)    return "LeftButton";
//    if (button == Qt::RightButton)   return "RightButton";
//    if (button == Qt::MiddleButton)  return "MiddleButton";
//    if (button == Qt::BackButton)    return "BackButton";
//    if (button == Qt::ForwardButton) return "ForwardButton";
//    if (button == Qt::TaskButton)    return "TaskButton";
//    if (button == Qt::ExtraButton4)  return "ExtraButton4";
//    if (button == Qt::ExtraButton5)  return "ExtraButton5";
//    if (button == Qt::ExtraButton6)  return "ExtraButton6";
//    if (button == Qt::ExtraButton7)  return "ExtraButton7";
//    if (button == Qt::ExtraButton8)  return "ExtraButton8";
//    if (button == Qt::ExtraButton9)  return "ExtraButton9";
//    if (button == Qt::ExtraButton10) return "ExtraButton10";
//    if (button == Qt::ExtraButton11) return "ExtraButton11";
//    if (button == Qt::ExtraButton12) return "ExtraButton12";
//    if (button == Qt::ExtraButton13) return "ExtraButton13";
//    if (button == Qt::ExtraButton14) return "ExtraButton14";
//    if (button == Qt::ExtraButton15) return "ExtraButton15";
//    if (button == Qt::ExtraButton16) return "ExtraButton16";
//    if (button == Qt::ExtraButton17) return "ExtraButton17";
//    if (button == Qt::ExtraButton18) return "ExtraButton18";
//    if (button == Qt::ExtraButton19) return "ExtraButton19";
//    if (button == Qt::ExtraButton20) return "ExtraButton20";
//    if (button == Qt::ExtraButton21) return "ExtraButton21";
//    if (button == Qt::ExtraButton22) return "ExtraButton22";
//    if (button == Qt::ExtraButton23) return "ExtraButton23";
//    if (button == Qt::ExtraButton24) return "ExtraButton24";
//    qDebug("QMouseShortcutEntry::addShortcut contained Invalid Qt::MouseButton value");
//    return "NoButton";
//}

//QString MainWindow::enumNamesFromMouseButtons(const Qt::MouseButtons buttons)
//{
//    QString returnText = "";
//    if (buttons == Qt::NoButton)      return "NoButton";
//    if (buttons & Qt::LeftButton)    returnText += "LeftButton ";
//    if (buttons & Qt::RightButton)   returnText +=  "RightButton ";
//    if (buttons & Qt::MiddleButton)  returnText +=  "MiddleButton ";
//    if (buttons & Qt::BackButton)    returnText +=  "BackButton ";
//    if (buttons & Qt::ForwardButton) returnText +=  "ForwardButton ";
//    if (buttons & Qt::TaskButton)    returnText +=  "TaskButton ";
//    if (buttons & Qt::ExtraButton4)  returnText +=  "ExtraButton4 ";
//    if (buttons & Qt::ExtraButton5)  returnText +=  "ExtraButton5 ";
//    if (buttons & Qt::ExtraButton6)  returnText +=  "ExtraButton6 ";
//    if (buttons & Qt::ExtraButton7)  returnText +=  "ExtraButton7 ";
//    if (buttons & Qt::ExtraButton8)  returnText +=  "ExtraButton8 ";
//    if (buttons & Qt::ExtraButton9)  returnText +=  "ExtraButton9 ";
//    if (buttons & Qt::ExtraButton10) returnText +=  "ExtraButton10 ";
//    if (buttons & Qt::ExtraButton11) returnText +=  "ExtraButton11 ";
//    if (buttons & Qt::ExtraButton12) returnText +=  "ExtraButton12 ";
//    if (buttons & Qt::ExtraButton13) returnText +=  "ExtraButton13 ";
//    if (buttons & Qt::ExtraButton14) returnText +=  "ExtraButton14 ";
//    if (buttons & Qt::ExtraButton15) returnText +=  "ExtraButton15 ";
//    if (buttons & Qt::ExtraButton16) returnText +=  "ExtraButton16 ";
//    if (buttons & Qt::ExtraButton17) returnText +=  "ExtraButton17 ";
//    if (buttons & Qt::ExtraButton18) returnText +=  "ExtraButton18 ";
//    if (buttons & Qt::ExtraButton19) returnText +=  "ExtraButton19 ";
//    if (buttons & Qt::ExtraButton20) returnText +=  "ExtraButton20 ";
//    if (buttons & Qt::ExtraButton21) returnText +=  "ExtraButton21 ";
//    if (buttons & Qt::ExtraButton22) returnText +=  "ExtraButton22 ";
//    if (buttons & Qt::ExtraButton23) returnText +=  "ExtraButton23 ";
//    if (buttons & Qt::ExtraButton24) returnText +=  "ExtraButton24 ";
//    return returnText;
//}


