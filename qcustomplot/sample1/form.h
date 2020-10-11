#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QFrame>
#include <QtWidgets/QTextBrowser>

//struct Rect
//{
//  int x, y, w, h;
//  Rect(int x, int y, int w, int h)
//  {
//    this->x = x; this->y = y; this->w = w; this->h = h;
//  }
//  Rect(const QRect& r)
//  {
//    this->x = r.x(); this->y = r.y(); this->w = r.width(); this->h = r.height();
//  }
//  Rect operator*(double factor)
//  {
//    Rect ret = Rect(this->x*factor, this->y*factor, this->w*factor, this->h*factor);
//    return ret;
//  }

//  QRect operator()()
//  {
//    QRect ret = QRect(this->x, this->y, this->w, this->h);
//    return ret;
//  }

//};



class form
{
public:
    QTextBrowser *textBrowsers[4];
//    QRect baseSize[4] = {QRect(20, 40, 71, 31),
//                         QRect(110, 40, 71, 31),
//                         QRect(20, 90, 71, 31),
//                         QRect(110, 90, 71, 31)};

    form(QFrame *f)
    {

      textBrowsers[0] = new QTextBrowser(f);
      textBrowsers[1] = new QTextBrowser(f);
      textBrowsers[2] = new QTextBrowser(f);
      textBrowsers[3] = new QTextBrowser(f);



      textBrowsers[0]->setGeometry(QRect(20, 40, 71, 31));
      textBrowsers[1]->setGeometry(QRect(110, 40, 71, 31));
      textBrowsers[2]->setGeometry(QRect(20, 90, 71, 31));
      textBrowsers[3]->setGeometry(QRect(110, 90, 71, 31));

      textBrowsers[0]->setText("Madam");
      textBrowsers[1]->setText("Akshitha");
      textBrowsers[2]->setText("Rowdy");
      textBrowsers[3]->setText("Baby");

    }

//    void update_size(double factor)
//    {
//      for(int ii=0; ii<4; ii++)
//      {
//          Rect nRect = Rect(baseSize[ii]);
//          nRect = nRect*factor;
//        textBrowsers[ii]->setGeometry(nRect());
//      }
//    }

};



#endif // FORM_H
