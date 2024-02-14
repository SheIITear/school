#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QApplication>

#include "mainwin.h"

#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwin w;
    w.show();
    return a.exec();
}

mainwin::mainwin(QWidget* parent)
    : QMainWindow(parent), count(0) {
    QPushButton *button = new QPushButton("Count", this);
    QPushButton *button2 = new QPushButton("Reset", this);

    lineEdit = new QLineEdit(this);
    lineEdit->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->addWidget(button2);
    layout->addWidget(lineEdit);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(button, &QPushButton::clicked, this, &mainwin::handleCount);
    connect(button2, &QPushButton::clicked, this, &mainwin::handleReset);

    lineEdit->setText(QString::number(count));    
}

mainwin::~mainwin() {}

void mainwin::handleCount() {
    count++;
    lineEdit->setText(QString::number(count));
}

void mainwin::handleReset() {
    count = 0;
    lineEdit->setText(QString::number(count));
}
