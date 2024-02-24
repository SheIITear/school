#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>

class QLineEdit;

class mainwin : public QMainWindow {
    Q_OBJECT

public:
    mainwin(QWidget* parent = nullptr);
    ~mainwin();

private slots:
    void handleCount();
    void handleOperation();

private:
    QLineEdit *lineEdit;
    int count;
};

#endif
