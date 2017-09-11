#include <QtGui>
#include <QTime>
#include "LarkyCharmGui.h"
#include "ui_larkycharmgui.h"

LarkyCharmGui::LarkyCharmGui(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LarkyCharmGui)
{
    //setupUi(this);
    ui->setupUi(this);
    connect(ui->lottoGoButton, SIGNAL(clicked()), this, SLOT(generateNumbers()));
    connect(ui->lottoClearButton, SIGNAL(clicked()), this, SLOT(clearNumbers()));
    connect(ui->yeboGoButton, SIGNAL(clicked()), this, SLOT(generateLetters()));
    connect(ui->yeboClearButton, SIGNAL(clicked()), this, SLOT(clearLetters()));
}

LarkyCharmGui::~LarkyCharmGui()
{
    delete ui;
}

void LarkyCharmGui::generateNumbers()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int luckyNo = 0;
    lottoNumbers = new QList<int>;

    for(int i = 0; i < 6; i++)
    {
        bool done = false;
        while (!done)
        {

            luckyNo = qrand()%(49);
            if(lottoNumbers->isEmpty() && luckyNo != 0)
            {
                done = true;
            }
            else
            {
                if(lottoNumbers->contains(luckyNo))
                    done = false;
                else if (luckyNo != 0)
                    done = true;
            }
        }
        lottoNumbers->append(luckyNo);
    }
    ui->lcd1->display(lottoNumbers->at(0));
    ui->lcd2->display(lottoNumbers->at(1));
    ui->lcd3->display(lottoNumbers->at(2));
    ui->lcd4->display(lottoNumbers->at(3));
    ui->lcd5->display(lottoNumbers->at(4));
    ui->lcd6->display(lottoNumbers->at(5));
}

void LarkyCharmGui::clearNumbers()
{
    ui->lcd1->display(0);
    ui->lcd2->display(0);
    ui->lcd3->display(0);
    ui->lcd4->display(0);
    ui->lcd5->display(0);
    ui->lcd6->display(0);
}

void LarkyCharmGui::generateLetters()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int luckyNo = 0;
    //yeboLetters = new QStringList();
    yeboLetters = new QList<char>;

    yeboLetters->clear();
    for(int i = 0; i < 9; i++)
    {
        luckyNo = qrand()%(26);
        luckyNo = luckyNo + 65;
        char letter = luckyNo;
        yeboLetters->append(letter);
    }

    //QString myLetters = yeboLetters->join("-");
    QString myLetters;
    for(int j = 0; j < 9; j++)
    {
        myLetters = myLetters + yeboLetters->at(j) + "  ";
    }
    //ui->yeboEdit.setText(myLetters);
    ui->yeboEdit->setText(myLetters);
}

void LarkyCharmGui::clearLetters()
{
    ui->yeboEdit->clear();
}




