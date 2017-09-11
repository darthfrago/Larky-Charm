#ifndef LUCKYCHARMGUI_H
#define LUCKYCHARMGUI_H

#include <QMainWindow>
#include "ui_LarkyCharm.h"

class LarkyCharmGui: public QMainWindow, public Ui::LarkyCharm
{
    Q_OBJECT
public:
    LarkyCharmGui();
public slots:
    generateNumbers();
    generateLetters();
    clearNumbers();
    clearLetters();
private:
    QList<int>* lottoNumbers;
    QList<char>* yeboLetters;
};

#endif // LUCKYGUI_H
