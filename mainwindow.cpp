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


#include <QLabel>
void MainWindow::TemaYukle(){
    QFileSystemModel *dirModel = new QFileSystemModel(this);
    dirModel->setRootPath("/root/talimatname/genel/");

    ui->listView->setModel(dirModel);
    ui->listView->setRootIndex(dirModel->setRootPath("/root/talimatname/genel/"));
    ui->comboBox->setModel(dirModel);
    ui->comboBox->setRootModelIndex(dirModel->setRootPath("/root/talimatname/genel/"));
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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commandLinkButton_clicked()
{

   sayac=10;
   ui->progressBar->setValue(sayac);
   QString uygulama = ui->comboBox->currentText();
       ui->progressBar->setValue(sayac);
       sayac=50;
       QProcess::execute("sudo -i mps kur "+uygulama);
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
    ui->listView->clearSelection();
    QString kategori = ui->comboBox_2->currentText();
  QFileSystemModel *dirModel = new QFileSystemModel(this);
  dirModel->setRootPath("/root/talimatname/"+ kategori +"/");
  ui->listView->setModel(dirModel);
  ui->listView->setRootIndex(dirModel->setRootPath("/root/talimatname/"+ kategori +"/"));
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    QString kategori = ui->comboBox_2->currentText();
   QString uygulama = ui->listView->model()->data(index).toString();
   ui->comboBox->setCurrentText(uygulama);
          ui->label_5->setPixmap(QPixmap("/root/arayuz/"+uygulama+".png") );

   QProcess bilgi;
   bilgi.start("sed 7q /root/talimatname/"+kategori+"/"+uygulama+"/talimat");
   bilgi.waitForFinished();
   QString output(bilgi.readAllStandardOutput());
   ui->textEdit->setText(output);

}

void MainWindow::on_commandLinkButton_3_clicked()
{
    sayac=10;
    ui->progressBar->setValue(sayac);
         sayac=20;
          QString uygulama = ui->comboBox->currentText();
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

           QString uygulama = ui->comboBox->currentText();
          sayac=50;
          ui->progressBar->setValue(sayac);

           QProcess::execute("mps sil "+uygulama);

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
