#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QProcess>
#include <QModelIndex>
#include <QSysInfo>
#include <QRegExp>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>


#include <QLabel>
void MainWindow::TemaYukle(){

    ui->label_3->setText("Hazır");
    ui->label_5->setPixmap(QPixmap("/root/arayuz/milpek.png") );
}

    int sayac=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    TemaYukle();
    QString kategori = ui->comboBox_2->currentText();
    QDir kaynak("/root/talimatname/genel");
    kaynak.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    listem = kaynak.entryList();
    ui->listWidget->addItems(listem);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commandLinkButton_clicked()
{
   sayac=10;
   ui->progressBar->setValue(sayac);
    QString kategori = ui->comboBox_2->currentText();
    QString uygulama = ui->listWidget->currentItem()->text();
       ui->progressBar->setValue(sayac);
       sayac=50;
       QProcess::execute("sudo -i mps kur "+uygulama);
       ui->label_3->setText(QApplication::translate("MainWindow", "Console output", 0));
    sayac=100;
    ui->progressBar->setValue(sayac);
         QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla kuruldu.");
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    QMessageBox::information(this, "MilPeK","Cihan Alkan tarafından Milis Linux için hazırlanmıştır.");
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    QStringList yenilistem;
     ui->listWidget->clearSelection();
    QString kategori = ui->comboBox_2->currentText();
    QDir yeniliste("/root/talimatname/"+kategori);
    ui->listWidget->clear();
    yeniliste.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    yenilistem = yeniliste.entryList();
    ui->listWidget->addItems(yenilistem);
}


void MainWindow::on_commandLinkButton_3_clicked()
{
    sayac=10;
    ui->progressBar->setValue(sayac);
         sayac=20;
        QString uygulama = ui->listWidget->currentItem()->text();
           ui->progressBar->setValue(sayac);
            sayac=50;

           QProcess::execute("mps odkp "+uygulama);

          sayac=100;
           ui->progressBar->setValue(sayac);
          QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla derlendi ve kuruldu.");
}

void MainWindow::on_commandLinkButton_5_clicked()
{
          sayac=10;
           ui->progressBar->setValue(sayac);

        QString uygulama = ui->listWidget->currentItem()->text();
          sayac=50;
          ui->progressBar->setValue(sayac);

           QProcess::execute("mps -sz "+uygulama);

          sayac=100;
          ui->progressBar->setValue(sayac);
          QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla silindi.");
}



void MainWindow::on_commandLinkButton_4_clicked()
{
        ui->progressBar->setValue(sayac);
        sayac=50;
        QProcess::execute("mps guncelle");

        sayac=100;
        ui->progressBar->setValue(sayac);
        QMessageBox::information(this, "MilPeK"," Uygulama veritabanı başarıyla güncellendi.");
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
     ui->listWidget->clearSelection();
    QStringList yenilistem1;
   QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    QString kategori = ui->comboBox_2->currentText();
    QDir yeniliste1("/root/talimatname/"+kategori);
    ui->listWidget->clear();
    yeniliste1.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    yenilistem1 = yeniliste1.entryList();
    ui->listWidget->addItems(yenilistem1.filter(regExp));

}

void MainWindow::on_listWidget_currentTextChanged(const QString &currentText)
{
    QString kategori = ui->comboBox_2->currentText();
 QString uygulama = ui->listWidget->currentItem()->text();
          ui->label_5->setPixmap(QPixmap("/root/arayuz/"+uygulama+".png") );

   QProcess bilgi;
   bilgi.start("sed 7q /root/talimatname/"+kategori+"/"+uygulama+"/talimat");
   bilgi.waitForFinished();
   QString output(bilgi.readAllStandardOutput());
   ui->textEdit->setText(output);
}


