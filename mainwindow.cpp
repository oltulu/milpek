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
#include <QtDebug>
#include <QRegExp>
#include <string>
#include <QLabel>
#include <QDateTime>

void MainWindow::addSignalsSlots(){
    connect(terminal, SIGNAL(readyReadStandardOutput()), this, SLOT( processOutput() ) );
    connect(terminal, SIGNAL(readyReadStandardError() ), this, SLOT( processOutput() ) );
}
    int sayac=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->label_5->setPixmap(QPixmap("/root/arayuz/milpek.png") );
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
    if (ui->listWidget->currentItem())


{
        QString kategori = ui->comboBox_2->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

    sayac=10;
     ui->progressBar->setValue(sayac);

     ui->progressBar->setValue(sayac);
     sayac=50;
QProcess::execute("mps kur "+uygulama);
sayac=100;
ui->progressBar->setValue(sayac);
QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla kuruldu.");
ui->listWidget->reset();
           }
               else
           {
   QMessageBox::information(this, "MilPeK",uygulama +" uygulaması zaten kurulu.");
   ui->listWidget->reset();
           }

}

else

   {
   QMessageBox::information(this, "MilPeK"," Lütfen kurmak için bir uygulama seçiniz");
    }

}


void MainWindow::on_commandLinkButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Kurmak istediğiniz paketi seçin"),"~/",tr("milis peketi (*.mps.lz)"));
    QProcess::execute("lxqt-sudo mps kur "+fileName);
    QMessageBox::information(this, "MilPeK","Kurulum işlemi tamamlanmıştır.");
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{

    QStringList yenilistem;
     ui->listWidget->reset();
    QString kategori = ui->comboBox_2->currentText();
    QDir yeniliste("/root/talimatname/"+kategori);
    ui->listWidget->clear();
    yeniliste.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    yenilistem = yeniliste.entryList();
    ui->listWidget->addItems(yenilistem);
}


void MainWindow::processOutput(){
    terminalOutput = terminal->readAllStandardOutput();
    terminalOutputErr = terminal->readAllStandardError();

    // To Show Percentage of the Download
    QString errOutput = (QString)terminalOutputErr;
    if(errOutput.contains(QRegExp("[0-9]%"))){
        errOutput.replace('.',"");
        errOutput.replace("\n","");
    }

    // To Show info about installing
    QString preparedText = terminalOutput.left(70);
    preparedText.replace("\n","");
    ui->textEdit->setText(preparedText);
    //qDebug() << terminalOutput;
    //qDebug() << terminalOutputErr;

    const QString terminalOutputConst = terminalOutput;

    // If all commands finished.
    if(terminalOutputConst.indexOf("--- |TAMAMLANDI| ---") > -1){
        terminal->close();
    }
    // Check Download Folder
    if(terminalOutputConst.indexOf("--CHECKDOWNLOADFOLDER--") > -1){
        QMessageBox::information(this, "Bilgi", "İndirme tamamlandı.\n\nİndirilen dosyalara şu adresten erişebilirsiniz:\n/sources/");
    }
    // Extracted to /opt
    if(terminalOutputConst.indexOf("--EXTRACTEDTOOPT--") > -1){
        QMessageBox::information(this, "Bilgi", "Dosyalar /sources/ klasörüne açılıyor.\n\nOradan erişebilirsiniz.");
    }

}

void MainWindow::on_commandLinkButton_3_clicked()
{
    if (ui->listWidget->currentItem())


{
        QString kategori = ui->comboBox_2->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

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
          ui->listWidget->reset();
           }
               else
           {
   QMessageBox::information(this, "MilPeK",uygulama +" uygulaması zaten kurulu.");
   ui->listWidget->reset();
           }

}

else
        {
       QMessageBox::information(this, "MilPeK"," Lütfen derleyip kurmak istediğiniz uygulamayı seçiniz");
         }
}

void MainWindow::on_commandLinkButton_5_clicked()
{
    if (ui->listWidget->currentItem())


{
        QString kategori = ui->comboBox_2->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {
    QMessageBox::information(this, "MilPeK",uygulama +" uygulaması zaten kurulu değil.");
           }
               else
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
          ui->listWidget->reset();
 }
}
          else
          {
                 QMessageBox::information(this, "MilPeK"," Lütfen silmek istediğiniz uygulamayı seçiniz");
           }
}



void MainWindow::on_commandLinkButton_4_clicked()
{
        ui->progressBar->setValue(sayac);
        sayac=50;
        QProcess::execute("mps guncelle");
        QProcess::execute("ln -s /root/talimatlar /root/talimatname/yerel");
        sayac=100;
        ui->progressBar->setValue(sayac);
        QMessageBox::information(this, "MilPeK"," Uygulama veritabanı başarıyla güncellendi.");
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->listWidget->reset();
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



  QFile resimvarmi("/root/arayuz/"+uygulama+".png");

  if(!resimvarmi.exists()) {

      ui->label_5->setPixmap(QPixmap("/root/arayuz/resimyok.png") );
  }
      else
  {
     ui->label_5->setPixmap(QPixmap("/root/arayuz/"+uygulama+".png") );
  }
   QProcess bilgi;
   bilgi.start("sed 7q /root/talimatname/"+kategori+"/"+uygulama+"/talimat");
   bilgi.waitForFinished();
   QString output(bilgi.readAllStandardOutput());
   ui->textEdit->setText(output);
}


void MainWindow::on_commandLinkButton_6_clicked()
{
    if (ui->listWidget->currentItem())


{
        QString kategori = ui->comboBox_2->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {
    QMessageBox::information(this, "MilPeK",uygulama +" uygulaması kurulu değil.");
           }
               else
           {
          sayac=10;
           ui->progressBar->setValue(sayac);

        QString uygulama = ui->listWidget->currentItem()->text();
          sayac=50;
          ui->progressBar->setValue(sayac);

          sayac=100;
          ui->progressBar->setValue(sayac);
          ui->listWidget->reset();
          QProcess liste;
          liste.start("sed 200q /var/lib/pkg/DB/"+uygulama+"/kurulan");
          liste.waitForFinished();
          QString output(liste.readAllStandardOutput());
          ui->textEdit->setText(output);
 }
}
          else
          {
                 QMessageBox::information(this, "MilPeK"," Lütfen silmek istediğiniz uygulamayı seçiniz");
           }
}
