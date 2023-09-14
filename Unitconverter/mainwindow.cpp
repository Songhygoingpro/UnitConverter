#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    centralWidget->setLayout(mainLayout);


    conversionTypeBox = new QComboBox;
    fromUnitBox = new QComboBox;
    toUnitBox = new QComboBox;
    inputEdit = new QLineEdit;
    convertButton = new QPushButton("Convert");
    resultEdit = new QLineEdit;
    resultEdit->setReadOnly(true);


    conversionTypeBox->addItem("Mass");
    conversionTypeBox->addItem("Length");
    conversionTypeBox->addItem("Temperature");


    connect(convertButton, &QPushButton::clicked, this, &MainWindow::performConversion);
connect(conversionTypeBox, &QComboBox::currentTextChanged, this, &MainWindow::updateUnitBoxes);

    mainLayout->addWidget(conversionTypeBox);
    mainLayout->addWidget(fromUnitBox);
    mainLayout->addWidget(toUnitBox);
    mainLayout->addWidget(inputEdit);
    mainLayout->addWidget(convertButton);
    mainLayout->addWidget(resultEdit);

    setCentralWidget(centralWidget);

}

MainWindow::~MainWindow() {}

void MainWindow::updateUnitBoxes(const QString &conversionType)
{
    if (conversionType == "Mass") {
        fromUnitBox->clear();
        fromUnitBox->addItems({"Kilograms", "Pounds"});
        toUnitBox->clear();
        toUnitBox->addItems({"Kilograms", "Pounds"});
    } else if (conversionType == "Length") {
        fromUnitBox->clear();
        fromUnitBox->addItems({"Meters", "Feet"});
        toUnitBox->clear();
        toUnitBox->addItems({"Meters", "Feet"});
    }
    else if(conversionType == "Temperature"){
        fromUnitBox->clear();
        fromUnitBox->addItems({"Celsius", "Fahrenheit"});
        toUnitBox->clear();
        toUnitBox->addItems({"Celsius", "Fahrenheit"});
    }
}
void MainWindow::performConversion()
{




    QString conversionType = conversionTypeBox->currentText();
    QString fromUnit = fromUnitBox->currentText();
    QString toUnit = toUnitBox->currentText();
    double inputValue = inputEdit->text().toDouble();
    double resultValue;

    if (conversionType == "Mass") {
        if (fromUnit == "Kilograms" && toUnit == "Pounds") {
            resultValue = inputValue * 2.20462;
        } else if (fromUnit == "Pounds" && toUnit == "Kilograms") {
            resultValue = inputValue / 2.20462;
        } else {
            resultValue = inputValue;
        }
    } else if (conversionType == "Length") {
        if (fromUnit == "Meters" && toUnit == "Feet") {
            resultValue = inputValue * 3.28084;
        } else if (fromUnit == "Feet" && toUnit == "Meters") {
            resultValue = inputValue / 3.28084;
        } else {
            resultValue = inputValue;
        }}
        else if (conversionType == "Temperature") {
            if (fromUnit == "Celsius" && toUnit == "Fahrenheit") {
                resultValue = (inputValue * 9/5) + 32;
            } else if (fromUnit == "Fahrenheit" && toUnit == "Celsius") {
                resultValue = (inputValue - 32) * 5/9;
            } else {
                resultValue = inputValue;
            }
        }



    resultEdit->setText(QString::number(resultValue));


    QFile file("Conversions.txt");
    if (file.open(QFile::Append | QFile::Text)) {
        QTextStream out(&file);
        out << conversionType << ": " << inputValue << " " << fromUnit << " = "
            << resultValue << " " << toUnit << "\n";
        file.close();
    }

}
