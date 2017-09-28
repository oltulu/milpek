#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFileSystemModel>
#include <QListWidget>
#include <QByteArray>

namespace Ui {
class MainWindow;
class InstallThread;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_4_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_listWidget_currentTextChanged(const QString &currentText);

    void processOutput();

    void on_commandLinkButton_6_clicked();

    void on_commandLinkButton_9_clicked();

    void on_commandLinkButton_8_clicked();

    void on_commandLinkButton_11_clicked();

    void on_commandLinkButton_10_clicked();

    void on_commandLinkButton_7_clicked();

private:
    Ui::MainWindow *ui;
    void TemaYukle();
    void addSignalsSlots();
    QStringList listem;
    QProcess *terminal;
    QByteArray terminalOutput;
    QByteArray terminalOutputErr;


};

#endif // MAINWINDOW_H
