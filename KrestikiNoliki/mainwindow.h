#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;
class QGridLayout;
class QSignalMapper;
class QPushButton;
class QString;
class QHBoxLayout;
class QVBoxLayout;
class QSize;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private:
    void createWidgets();
    void checkWin();
    void winUser(QString name);
    void noWin();

    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *buttonClear;

    QLabel *actualPlayer;

    QSignalMapper *signalMapField;

    QGridLayout *field;
    QVBoxLayout *mainLayout;
    QHBoxLayout *panel;

    QString player1, player2; // скажем, что player1 - X / player2 - O
    int playerWin;

private slots:
    void slotClearField();
    void slotPushButton(int widget);
};

#endif // MAINWINDOW_H
