#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QApplication>


#include "mainwin.h"

#pragma comment(lib, "user32.lib")

int number1 = 0;
int number2 = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwin w;
    w.show();
    return a.exec();
}

mainwin::mainwin(QWidget* parent)
    : QMainWindow(parent), count(0) {

    QPushButton *addition = new QPushButton("+", this);
    QPushButton *minus = new QPushButton("-", this);
    QPushButton *division = new QPushButton("/", this);
    QPushButton *multiply = new QPushButton("*", this);

    lineEdit = new QLineEdit(this);
    lineEdit->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(addition);
    layout->addWidget(minus);
    layout->addWidget(division);
    layout->addWidget(multiply);
    layout->addWidget(lineEdit);

    for (int i = 0; i < 10; i++) {
        QPushButton *testButton = new QPushButton(QString::number(i), this);
        layout->addWidget(testButton);
        connect(testButton, &QPushButton::clicked, this, &mainwin::handleCount);
    }

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(addition, &QPushButton::clicked, this, &mainwin::handleOperation);
    connect(minus, &QPushButton::clicked, this, &mainwin::handleOperation);
    connect(division, &QPushButton::clicked, this, &mainwin::handleOperation);
    connect(multiply, &QPushButton::clicked, this, &mainwin::handleOperation);

    lineEdit->setText(QString::number(count));    
}

mainwin::~mainwin() {}

void mainwin::handleCount() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();

    int *number;

     if (count == 0) {
        number = &number1;
        lineEdit->setText(buttonText);
        count++;
     } else {
        number = &number2;
        lineEdit->setText(buttonText);
        count = 0;
     }

    int chosen = buttonText.toInt();
    *number = chosen;
}

void mainwin::handleOperation() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString operation = buttonSender->text();

    float result;
    
    if (operation == "*")
            result = number1 * number2;
    else if (operation == "+")
            result = number1 + number2;
    else if (operation == "-")
            result = number1 - number2;
    else if (operation == "/")
            result = (float)number1 / number2;
    
    lineEdit->setText(QString::number(result));
}
