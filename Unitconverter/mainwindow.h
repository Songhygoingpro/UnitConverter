#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void performConversion();
    void updateUnitBoxes(const QString &conversionType);

private:
    QComboBox *conversionTypeBox;
    QComboBox *fromUnitBox;
    QComboBox *toUnitBox;
    QLineEdit *inputEdit;
    QPushButton *convertButton;
    QLineEdit *resultEdit;
};

#endif // MAINWINDOW_H
