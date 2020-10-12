#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QFrame>
#include <QtWidgets/QTextBrowser>
#include "dynamicfontsizelabel.h"

struct Rect
{
  int x, y, w, h;
  Rect(int x, int y, int w, int h)
  {
    this->x = x; this->y = y; this->w = w; this->h = h;
  }
  Rect(const QRect& r)
  {
    this->x = r.x(); this->y = r.y(); this->w = r.width(); this->h = r.height();
  }
  Rect operator*(double factor)
  {
    Rect ret = Rect(this->x*factor, this->y*factor, this->w*factor, this->h*factor);
    return ret;
  }

  QRect operator()()
  {
    QRect ret = QRect(this->x, this->y, this->w, this->h);
    return ret;
  }

};



class form
{
public:
    DynamicFontSizeLabel *labels[4];
    DynamicFontSizeTextBrowser *texts[4];

    form(QFrame *f)
    {

      labels[0] = new DynamicFontSizeLabel(f);
      labels[1] = new DynamicFontSizeLabel(f);
      labels[2] = new DynamicFontSizeLabel(f);
      labels[3] = new DynamicFontSizeLabel(f);

      labels[0]->setGeometry(QRect(20, 40, 71, 31));
      labels[1]->setGeometry(QRect(110, 40, 71, 31));
      labels[2]->setGeometry(QRect(20, 90, 71, 31));
      labels[3]->setGeometry(QRect(110, 90, 71, 31));

      labels[0]->setText("Madam");
      labels[1]->setText("Akshitha");
      labels[2]->setText("Rowdy");
      labels[3]->setText("Baby");

      texts[0] = new DynamicFontSizeTextBrowser(f);
      texts[1] = new DynamicFontSizeTextBrowser(f);
      texts[2] = new DynamicFontSizeTextBrowser(f);
      texts[3] = new DynamicFontSizeTextBrowser(f);

      texts[0]->setGeometry(QRect(20, 140, 75, 35));
      texts[1]->setGeometry(QRect(110, 140, 75, 35));
      texts[2]->setGeometry(QRect(20, 190, 75, 35));
      texts[3]->setGeometry(QRect(110, 190, 75, 35));

      texts[0]->setText("Madam");
      texts[1]->setText("Akshitha");
      texts[2]->setText("Rowdy");
      texts[3]->setText("Baby");

    }

    void update_size(double f)
    {
      Rect nRect1 = Rect(QRect(20, 40, 71, 31));
      Rect nRect2 = Rect(QRect(110, 40, 71, 31));
      Rect nRect3 = Rect(QRect(20, 90, 71, 31));
      Rect nRect4 = Rect(QRect(110, 90, 71, 31));

      Rect mRect1 = Rect(QRect(20, 140, 75, 35));
      Rect mRect2 = Rect(QRect(110, 140, 75, 35));
      Rect mRect3 = Rect(QRect(20, 190, 75, 35));
      Rect mRect4 = Rect(QRect(110, 190, 75, 35));

      nRect1 = nRect1*f;      mRect1 = mRect1*f;
      nRect2 = nRect2*f;      mRect2 = mRect2*f;
      nRect3 = nRect3*f;      mRect3 = mRect3*f;
      nRect4 = nRect4*f;      mRect4 = mRect4*f;

      labels[0]->setGeometry(nRect1());
      labels[1]->setGeometry(nRect2());
      labels[2]->setGeometry(nRect3());
      labels[3]->setGeometry(nRect4());

      texts[0]->setGeometry(mRect1());
      texts[1]->setGeometry(mRect2());
      texts[2]->setGeometry(mRect3());
      texts[3]->setGeometry(mRect4());
    }

};



#endif // FORM_H
