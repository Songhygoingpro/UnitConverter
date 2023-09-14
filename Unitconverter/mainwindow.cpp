#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    centralWidget->setLayout(mainLayout);

    QLabel *conversionTypeLabel = new QLabel("Conversion Type:");
    QLabel *fromUnitLabel = new QLabel("From Unit:");
    QLabel *toUnitLabel = new QLabel("To Unit:");
    QLabel *inputLabel = new QLabel("Input Value:");
    QLabel *resultLabel = new QLabel("Result:");

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
    conversionTypeBox->addItem("Time");
    conversionTypeBox->addItem("Currency");

    connect(convertButton, &QPushButton::clicked, this, &MainWindow::performConversion);
    connect(conversionTypeBox, &QComboBox::currentTextChanged, this, &MainWindow::updateUnitBoxes);

    mainLayout->addWidget(conversionTypeLabel);
    mainLayout->addWidget(conversionTypeBox);
    mainLayout->addWidget(fromUnitLabel);
    mainLayout->addWidget(fromUnitBox);
    mainLayout->addWidget(toUnitLabel);
    mainLayout->addWidget(toUnitBox);
    mainLayout->addWidget(inputLabel);
    mainLayout->addWidget(inputEdit);
    mainLayout->addWidget(convertButton);
    mainLayout->addWidget(resultLabel);
    mainLayout->addWidget(resultEdit);

    setCentralWidget(centralWidget);
}


MainWindow::~MainWindow() {}

void MainWindow::updateUnitBoxes(const QString &conversionType)
{
    if (conversionType == "Mass") {
        fromUnitBox->clear();
        fromUnitBox->addItems({"Kilograms", "Pounds", "Grams"});
        toUnitBox->clear();
        toUnitBox->addItems({"Kilograms", "Pounds", "Grams"});
    } else if (conversionType == "Length") {
        fromUnitBox->clear();
        fromUnitBox->addItems({"Meters", "Foot", "Miles", "Kilometers", "Centimeters"});
        toUnitBox->clear();
        toUnitBox->addItems({"Meters", "Foot", "Miles", "Kilometers", "Centimeters"});
    }
    else if(conversionType == "Temperature"){
        fromUnitBox->clear();
        fromUnitBox->addItems({"Celsius", "Fahrenheit"});
        toUnitBox->clear();
        toUnitBox->addItems({"Celsius", "Fahrenheit"});
    }
    else if (conversionType == "Time") {
        fromUnitBox->clear();
        fromUnitBox->addItems({"Second", "Minute", "Hour"});
        toUnitBox->clear();
        toUnitBox->addItems({"Second", "Minute", "Hour"});
    } else if (conversionType == "Currency") {
        fromUnitBox->clear();
        fromUnitBox->addItems({"Dollar", "Riel", "EURO"});
        toUnitBox->clear();
        toUnitBox->addItems({"Dollar", "Riel", "EURO"});
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
        if (fromUnit == "Meters" && toUnit == "Foot") {
            resultValue = inputValue * 3.28084;
        } else if (fromUnit == "Foot" && toUnit == "Meters") {
            resultValue = inputValue / 3.28084;
        } else if (fromUnit == "Meters" && toUnit == "Miles") {
            resultValue = inputValue * 0.000621371;
        } else if (fromUnit == "Miles" && toUnit == "Meters") {
            resultValue = inputValue / 0.000621371;
        } else if (fromUnit == "Kilometers" && toUnit == "Miles") {
            resultValue = inputValue * 0.621371;
        } else if (fromUnit == "Miles" && toUnit == "Kilometers") {
            resultValue = inputValue / 0.621371;
        } else if (fromUnit == "Centimeters" && toUnit == "Meters") {
            resultValue = inputValue / 100.0;
        } else if (fromUnit == "Meters" && toUnit == "Centimeters") {
            resultValue = inputValue * 100.0;
        } else if (fromUnit == "Foot" && toUnit == "Miles") {
            resultValue = inputValue * 0.000189394;
        } else if (fromUnit == "Miles" && toUnit == "Foot") {
            resultValue = inputValue / 0.000189394;
        } else if (fromUnit == "Kilometers" && toUnit == "Meters") {
            resultValue = inputValue * 1000.0;
        } else if (fromUnit == "Meters" && toUnit == "Kilometers") {
            resultValue = inputValue / 1000.0;
        } else if (fromUnit == "Centimeters" && toUnit == "Foot") {
            resultValue = inputValue / 30.48;
        } else if (fromUnit == "Foot" && toUnit == "Centimeters") {
            resultValue = inputValue * 30.48;
        } else if (fromUnit == "Centimeters" && toUnit == "Miles") {
            resultValue = inputValue * 0.0000062137;
        } else if (fromUnit == "Miles" && toUnit == "Centimeters") {
            resultValue = inputValue / 0.0000062137;
        } else if (fromUnit == "Foot" && toUnit == "Kilometers") {
            resultValue = inputValue * 0.0003048;
        } else if (fromUnit == "Kilometers" && toUnit == "Foot") {
            resultValue = inputValue / 0.0003048;
        } else {
            resultValue = inputValue;
        }
    }

    else if (conversionType == "Temperature") {
        if (fromUnit == "Celsius" && toUnit == "Fahrenheit") {
            resultValue = (inputValue * 9/5) + 32;
        } else if (fromUnit == "Fahrenheit" && toUnit == "Celsius") {
            resultValue = (inputValue - 32) * 5/9;
        } else {
            resultValue = inputValue;
        }}
    else if (conversionType == "Time") {
        if (fromUnit == "Second" && toUnit == "Minute") {
            resultValue = inputValue / 60;
        } else if (fromUnit == "Minute" && toUnit == "Second") {
            resultValue = inputValue * 60;
        } else if (fromUnit == "Hour" && toUnit == "Minute") {
            resultValue = inputValue * 60;
        } else if (fromUnit == "Minute" && toUnit == "Hour") {
            resultValue = inputValue / 60;
        } else if (fromUnit == "Hour" && toUnit == "Second") {
            resultValue = inputValue * 3600;
        } else if (fromUnit == "Second" && toUnit == "Hour") {
            resultValue = inputValue / 3600;
        } else {
            resultValue = inputValue;
        }
    }
            else if (conversionType == "Currency") {
                if (fromUnit == "Dollar" && toUnit == "Riel") {
                    // Assuming 1 Dollar = 4000 Riel
                    resultValue = inputValue * 4100;
                } else if (fromUnit == "Riel" && toUnit == "Dollar") {
                    // Assuming 1 Riel = 0.00025 Dollar
                    resultValue = inputValue * 0.00025;
                } else if (fromUnit == "Dollar" && toUnit == "EURO") {
                    // Assuming 1 Dollar = 0.85 EURO
                    resultValue = inputValue * 0.85;
                } else if (fromUnit == "EURO" && toUnit == "Dollar") {
                    // Assuming 1 EURO = 1.18 Dollar
                    resultValue = inputValue * 1.18;
                } else if (fromUnit == "Riel" && toUnit == "EURO") {
                    // Assuming 1 Riel = 0.00021 EURO
                    resultValue = inputValue * 0.00021;
                } else if (fromUnit == "EURO" && toUnit == "Riel") {
                    // Assuming 1 EURO = 4761.90 Riel
                    resultValue = inputValue * 4761.90;
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
