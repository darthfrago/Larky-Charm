#ifndef LARKYCHARMGUI_H
#define LARKYCHARMGUI_H

#include <QMainWindow>
//#include "ui_larkycharmgui.h"

namespace Ui {
    class LarkyCharmGui;
}

class LarkyCharmGui : public QMainWindow
{
    Q_OBJECT
public:
    explicit LarkyCharmGui(QWidget* parent = 0);
    ~LarkyCharmGui();
private slots:
    void generateNumbers();
    void generateLetters();
    void clearNumbers();
    void clearLetters();
private:
    Ui::LarkyCharmGui *ui;
    QList<int>* lottoNumbers;
    QList<char>* yeboLetters;
    //QStringList* yeboLetters;
};

#endif // LARKYCHARMGUI_H
