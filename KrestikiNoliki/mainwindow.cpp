#include "mainwindow.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QDebug>
#include <QMessageBox>
#include <QSize>

MainWindow::MainWindow()
{
    resize(200, 200);
    setWindowTitle("X - O");
    createWidgets();
}

void MainWindow::createWidgets() {
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    actualPlayer = new QLabel("player1");

    buttonClear = new QPushButton("Clear");

    actualPlayer->setBuddy(buttonClear);

    panel = new QHBoxLayout;
    panel->addWidget(actualPlayer);
    panel->addWidget(buttonClear);

    //actualPlayer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //buttonClear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    mainLayout->addLayout(panel);

    field = new QGridLayout;

    button1 = new QPushButton("");
    button2 = new QPushButton("");
    button3 = new QPushButton("");
    button4 = new QPushButton("");
    button5 = new QPushButton("");
    button6 = new QPushButton("");
    button7 = new QPushButton("");
    button8 = new QPushButton("");
    button9 = new QPushButton("");

    field->addWidget(button1, 0, 0);
    field->addWidget(button2, 0, 1);
    field->addWidget(button3, 0, 2);
    field->addWidget(button4, 1, 0);
    field->addWidget(button5, 1, 1);
    field->addWidget(button6, 1, 2);
    field->addWidget(button7, 2, 0);
    field->addWidget(button8, 2, 1);
    field->addWidget(button9, 2, 2);

    mainLayout->addLayout(field);

    button1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QSize size(60, 60);

    button1->setFixedSize(size);
    button2->setFixedSize(size);
    button3->setFixedSize(size);
    button4->setFixedSize(size);
    button5->setFixedSize(size);
    button6->setFixedSize(size);
    button7->setFixedSize(size);
    button8->setFixedSize(size);
    button9->setFixedSize(size);

    signalMapField = new QSignalMapper(this);
    connect(button1, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button2, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button3, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button4, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button5, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button6, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button7, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button8, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);
    connect(button9, SIGNAL(clicked()), signalMapField, SLOT(map()), Qt::UniqueConnection);

    signalMapField->setMapping(button1, 1);
    signalMapField->setMapping(button2, 2);
    signalMapField->setMapping(button3, 3);
    signalMapField->setMapping(button4, 4);
    signalMapField->setMapping(button5, 5);
    signalMapField->setMapping(button6, 6);
    signalMapField->setMapping(button7, 7);
    signalMapField->setMapping(button8, 8);
    signalMapField->setMapping(button9, 9);

    connect(signalMapField, SIGNAL(mapped(int)), this, SLOT(slotPushButton(int))/*, Qt::UniqueConnection*/);

    connect(buttonClear, SIGNAL(clicked()), this, SLOT(slotClearField()), Qt::UniqueConnection);
}

void MainWindow::checkWin() {
    QPushButton* a1;
    QPushButton* a2;
    QPushButton* a3;
    for (int i = 1; i < 4; ++i){
        a1 = (QPushButton*) signalMapField->mapping(i);
        a2 = (QPushButton*) signalMapField->mapping(i + 3);
        a3 = (QPushButton*) signalMapField->mapping(i + 6);
        if (a1->text() == "X" && a2->text() == "X" && a3->text() == "X")
            winUser(actualPlayer->text());
    }
    for (int i = 1; i < 10; i += 3){
        a1 = (QPushButton*) signalMapField->mapping(i);
        a2 = (QPushButton*) signalMapField->mapping(i + 1);
        a3 = (QPushButton*) signalMapField->mapping(i + 2);
        if (a1->text() == "X" && a2->text() == "X" && a3->text() == "X")
            winUser(actualPlayer->text());
    }
    for (int i = 1; i < 4; ++i){
        a1 = (QPushButton*) signalMapField->mapping(i);
        a2 = (QPushButton*) signalMapField->mapping(i + 3);
        a3 = (QPushButton*) signalMapField->mapping(i + 6);
        if (a1->text() == "O" && a2->text() == "O" && a3->text() == "O")
            winUser(actualPlayer->text());
    }
    for (int i = 1; i < 10; i += 3){
        a1 = (QPushButton*) signalMapField->mapping(i);
        a2 = (QPushButton*) signalMapField->mapping(i + 1);
        a3 = (QPushButton*) signalMapField->mapping(i + 2);
        if (a1->text() == "O" && a2->text() == "O" && a3->text() == "O")
            winUser(actualPlayer->text());
    }
    a1 = (QPushButton*) signalMapField->mapping(1);
    a2 = (QPushButton*) signalMapField->mapping(5);
    a3 = (QPushButton*) signalMapField->mapping(9);
    if (a1->text() == "X" && a2->text() == "X" && a3->text() == "X")
        winUser(actualPlayer->text());
    if (a1->text() == "X" && a2->text() == "X" && a3->text() == "X")
        winUser(actualPlayer->text());
    a1 = (QPushButton*) signalMapField->mapping(3);
    a2 = (QPushButton*) signalMapField->mapping(5);
    a3 = (QPushButton*) signalMapField->mapping(7);
    if (a1->text() == "X" && a2->text() == "X" && a3->text() == "X")
        winUser(actualPlayer->text());
    if (a1->text() == "O" && a2->text() == "O" && a3->text() == "O")
        winUser(actualPlayer->text());
}

void MainWindow::winUser(QString name) {
    QMessageBox::information(this, name + " win!", name + " - Win!", QMessageBox::Ok);
    slotClearField();
    playerWin = 1;
}

void MainWindow::noWin() {
    for (int i = 1; i < 10; i++) {
        QPushButton* p = (QPushButton*) signalMapField->mapping(i);
        if (p->text() == "X" || p->text() == "O") {

        } else {
            return;
        }
    }
    QMessageBox::information(this, "Ничья", "Ничья", QMessageBox::Ok);
    slotClearField();
}

void MainWindow::slotClearField() {
    actualPlayer->setText("player1");
    button1->setText("");
    button2->setText("");
    button3->setText("");
    button4->setText("");
    button5->setText("");
    button6->setText("");
    button7->setText("");
    button8->setText("");
    button9->setText("");
    playerWin = 0;
    //QMessageBox::information(this, "NO", "p->text()", QMessageBox::Ok);
}

void MainWindow::slotPushButton(int pre) {
    QPushButton* p = (QPushButton*) signalMapField->mapping(pre);
    //QMessageBox::information(this, "NO", /*QString::number(pre)*/p>text(), QMessageBox::Ok);

    if (p->text() != "X" && p->text() != "O") {
        if (actualPlayer->text() == "player1") {
            p->setText("X");
            checkWin();
            if (playerWin == 1) {
                slotClearField();
            } else {
                actualPlayer->setText("player2");
            }
        } else if (actualPlayer->text() == "player2") {
            p->setText("O");
            checkWin();
            if (playerWin == 1) {
                slotClearField();
            } else {
                actualPlayer->setText("player1");
            }
        }
    } else {
        //QMessageBox::information(this, "NO", p->text(), QMessageBox::Ok);
        //qDebug >> "ячейка не пуста" ;
        //winUser(actualPlayer->text());
    }
    noWin();
}
