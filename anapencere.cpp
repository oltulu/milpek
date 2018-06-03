#include "anapencere.h"
#include "ui_anapencere.h"
#include <QtDebug>
#include <QProcess>
#include <QMessageBox>
#include <string>
#include <QDateTime>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QSysInfo>
#include <QRegExp>
#include <QTextStream>
#include <QDebug>
#include <QLabel>
#include <QByteArray>

void AnaPencere::addSignalsSlots(){
    connect(terminal, SIGNAL(readyReadStandardOutput()), this, SLOT( processOutput() ) );
    connect(terminal, SIGNAL(readyReadStandardError() ), this, SLOT( processOutput() ) );
}
    int sayac=0;
void AnaPencere::processOutput(){
    terminalOutput = terminal->readAllStandardOutput();
    terminalOutputErr = terminal->readAllStandardError();

    // To Show info about installing
    QString preparedText = terminalOutput.left(70);
    preparedText.replace("\n","");
    ui->ciktimetni->setText(preparedText);
    //qDebug() << terminalOutput;
    //qDebug() << terminalOutputErr;

    const QString terminalOutputConst = terminalOutput;

}

AnaPencere::AnaPencere(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnaPencere)
{
    ui->setupUi(this);
    ui->label_5->setPixmap(QPixmap("/root/arayuz/milpek.png") );
    ui->listWidget->reset();
    QString kategori = ui->Kategoriler->currentText();
    QProcess process;
    process.start("mps paketler");
    process.waitForFinished(-1); // will wait forever until finished
    ui->listWidget->clear();
    ui->listWidget->addItems(QString(process.readAll()).split('\n'));
}

AnaPencere::~AnaPencere()
{
    delete ui;
}
void AnaPencere::on_kurbutonu_clicked()
{
    if (ui->listWidget->currentItem())

{
        QString kategori = ui->Kategoriler->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

    sayac=10;
     ui->progressBar->setValue(sayac);

     ui->progressBar->setValue(sayac);
     sayac=50;

QProcess liste;
liste.start("mps kur "+uygulama+" --normal");
liste.waitForFinished();
QString output(liste.readAllStandardOutput());
ui->ciktimetni->setText(output);
sayac=100;
ui->progressBar->setValue(sayac);

QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla kuruldu.");

ui->listWidget->reset();
           }
               else
           {
   QMessageBox::information(this, "MilPeK",uygulama +" uygulaması zaten kurulu.");
   QString preparedText = terminalOutput.left(70);
   preparedText.replace("\n","");
   ui->ciktimetni->setText(preparedText);
   ui->listWidget->reset();
           }

   }
else
   {
   QMessageBox::information(this, "MilPeK"," Lütfen kurmak için bir uygulama seçiniz");
   }
}

void AnaPencere::on_SilButonu_clicked()
{
        if (ui->listWidget->currentItem())


    {
            QString kategori = ui->Kategoriler->currentText();
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

              QProcess liste;
              liste.start("mps -sz "+uygulama+" --normal");
              liste.waitForFinished();
              QString output(liste.readAllStandardOutput());
              ui->ciktimetni->setText(output);
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

void AnaPencere::on_DerleKurButon_clicked()
{
    if (ui->listWidget->currentItem())

{
        QString kategori = ui->Kategoriler->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

    sayac=10;
    ui->progressBar->setValue(sayac);
         sayac=20;
        QString uygulama = ui->listWidget->currentItem()->text();
           ui->progressBar->setValue(sayac);
            sayac=50;

            QProcess liste;
            liste.start("mps odkp "+uygulama+" --normal");
            liste.waitForFinished();
            QString output(liste.readAllStandardOutput());
            ui->ciktimetni->setText(output);
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

void AnaPencere::on_PaketicerigiButonu_clicked()
{
    if (ui->listWidget->currentItem())

{
        QString kategori = ui->Kategoriler->currentText();
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
          ui->ciktimetni->setText(output);
 }
}
          else
    {
          QMessageBox::information(this, "MilPeK"," Lütfen içeriğini görmek istediğiniz uygulamayı seçiniz");
   }
}

void AnaPencere::on_TersGereklerButonu_clicked()
{
    if (ui->listWidget->currentItem())

{
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

    sayac=10;
     ui->progressBar->setValue(sayac);

     ui->progressBar->setValue(sayac);
     sayac=50;
     QProcess liste;
     liste.start("mps -tb "+uygulama+" --normal");
     liste.waitForFinished();
     QString output(liste.readAllStandardOutput());
     ui->ciktimetni->setText(output);
     sayac=100;
     ui->progressBar->setValue(sayac);
ui->progressBar->setValue(sayac);
ui->listWidget->reset();
           }
               else
           {
   QMessageBox::information(this, "MilPeK",uygulama +" uygulaması zaten kurulu.");
   ui->listWidget->reset();

   sayac=10;
   ui->progressBar->setValue(sayac);
   sayac=100;
   ui->progressBar->setValue(sayac);
   ui->listWidget->reset();
           }
   }
else
   {
   QMessageBox::information(this, "MilPeK"," Lütfen paketi kullanan uygulamaları öğrenmek istediğiniz paketi seçiniz");
}
}

void AnaPencere::on_Kategoriler_currentTextChanged(const QString &arg1)
    {
        if (ui->Kategoriler->currentText() == "Tümü")

    {
            ui->listWidget->reset();
            QProcess process;
            process.start("mps paketler");
            process.waitForFinished(-1); // will wait forever until finished
            ui->listWidget->clear();
            ui->listWidget->addItems(QString(process.readAll()).split('\n'));
        }

        else if (ui->Kategoriler->currentText() == "Yerel")

    {
            ui->listWidget->reset();
            QStringList yenilistem1;
            QDir yeniliste1("/root/talimatlar/");
            ui->listWidget->clear();
            yeniliste1.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
            yenilistem1 = yeniliste1.entryList();
        ui->listWidget->addItems(yenilistem1);
        }
        else
      {
            ui->listWidget->reset();
            QString kategori = ui->Kategoriler->currentText();
            QProcess process;
            process.start("mps paketler "+kategori);
            process.waitForFinished(-1); // will wait forever until finished
            ui->listWidget->clear();
            ui->listWidget->addItems(QString(process.readAll()).split(' '));
        }

}

void AnaPencere::on_UygulamaAra_textChanged(const QString &arg1)
{
    if (ui->Kategoriler->currentText() == "yerel")

{
        ui->listWidget->reset();
        QStringList yenilistem1;
       QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
        QDir yeniliste1("/root/talimatlar/");
        ui->listWidget->clear();
        yeniliste1.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
        yenilistem1 = yeniliste1.entryList();
    ui->listWidget->addItems(yenilistem1.filter(regExp));
    }
   else if (ui->Kategoriler->currentText() == "genel")

{
        ui->listWidget->reset();
        QStringList yenilistem1;
       QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
        QDir yeniliste1("/usr/share/milpek/paketler/");
        ui->listWidget->clear();
        yeniliste1.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
        yenilistem1 = yeniliste1.entryList();
    ui->listWidget->addItems(yenilistem1.filter(regExp));
    }
 else
    {
        ui->listWidget->reset();
        QString kategori = ui->Kategoriler->currentText();
        QProcess process;
        process.start("mps paketler "+kategori);
        process.waitForFinished(-1); // will wait forever until finished
        ui->listWidget->clear();
        ui->listWidget->addItems(QString(process.readAll()).split(' '));

    ui->listWidget->clear();
//    process.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
 //   process = process.entryList();
//ui->listWidget->addItems(process.filter(regExp));
}
    }

void AnaPencere::on_listWidget_currentTextChanged(const QString &currentText)
{
    QString kategori = ui->Kategoriler->currentText();
 QString uygulama = ui->listWidget->currentItem()->text();



  QFile resimvarmi("/root/arayuz/"+uygulama+".png");

  if(!resimvarmi.exists()) {

      ui->label_5->setPixmap(QPixmap("/root/arayuz/resimyok.png") );
      ui->label_3->setPixmap(QPixmap("/root/arayuz/milpek2.png") );
  }
      else
  {
     ui->label_5->setPixmap(QPixmap("/root/arayuz/"+uygulama+".png") );
     ui->label_3->setPixmap(QPixmap("/root/arayuz/simgeler/"+uygulama+"_"+uygulama+".png") );
  }

   QProcess bilgi;
   bilgi.start("mps tbilgi "+uygulama+" --normal");
   bilgi.waitForFinished();
   QString output(bilgi.readAllStandardOutput());
ui->ciktimetni->setText(output);

}
void AnaPencere::on_action_cikis_triggered()
{
     close();
}

void AnaPencere::on_actionVeritaban_G_ncelle_triggered()
{
    ui->progressBar->setValue(sayac);
    sayac=50;
    QProcess::execute("mps -G");

    QProcess liste;
    liste.start("mps -GG --normal");
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
    sayac=100;
    ui->progressBar->setValue(sayac);
    QProcess::execute("/usr/share/milpek/dizinyap");
QMessageBox::information(this, "MilPeK","Veritabanı güncelleme işlemi tamamlanmıştır.");
}

void AnaPencere::on_actionKurulu_Paketler_triggered()
{
    sayac=10;
    ui->progressBar->setValue(sayac);
    sayac=100;
    ui->progressBar->setValue(sayac);
    ui->listWidget->reset();
    QProcess liste;
    liste.start("mps -kl | sed 300q");
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
}

void AnaPencere::on_actionBilgisayardan_Program_Kur_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Kurmak istediğiniz paketi seçin"),"~/",tr("milis (*.mps.lz)"));
    QProcess::execute("sudo mps kur "+fileName);

    QString preparedText = terminalOutput.left(70);
    preparedText.replace("\n","");
    ui->ciktimetni->setText(preparedText);
    QMessageBox::information(this, "MilPeK","Bilgisayardan program kurma işlemi tamamlanmıştır.");
}

void AnaPencere::on_actionMiLPeK_Hakk_nda_triggered()
{
   QMessageBox::information(this, "MilPeK"," Milis Linux için Cihan Alkan tarafından hazırlanmıştır.");
}

void AnaPencere::on_actionSe_ili_Paketi_ndir_triggered()
{
    if (ui->listWidget->currentItem())

{
        QString kategori = ui->Kategoriler->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

    sayac=10;
    ui->progressBar->setValue(sayac);
         sayac=20;
        QString uygulama = ui->listWidget->currentItem()->text();
           ui->progressBar->setValue(sayac);
            sayac=50;

           QProcess::execute("mps -i "+uygulama);

          sayac=100;
           ui->progressBar->setValue(sayac);
          QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla indirildi ama kurulmadı");
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
       QMessageBox::information(this, "MilPeK"," Lütfen indirmek istediğiniz uygulamayı seçiniz");
}
}


void AnaPencere::on_actionSe_ili_Paketi_ndir_Kur_triggered()
{
    if (ui->listWidget->currentItem())

{
        QString kategori = ui->Kategoriler->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

    sayac=10;
    ui->progressBar->setValue(sayac);
         sayac=20;
        QString uygulama = ui->listWidget->currentItem()->text();
           ui->progressBar->setValue(sayac);
            sayac=50;

           QProcess::execute("mps -ik "+uygulama);

          sayac=100;
           ui->progressBar->setValue(sayac);
          QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla indirildi ve kuruldu");
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
       QMessageBox::information(this, "MilPeK"," Lütfen indirip kurmak istediğiniz uygulamayı seçiniz");
}
}

void AnaPencere::on_actionSe_ili_Paketi_Yeniden_Kur_triggered()
{
        if (ui->listWidget->currentItem())


    {
            QString kategori = ui->Kategoriler->currentText();
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

               QProcess::execute("mps yekur "+uygulama);

              sayac=100;
              ui->progressBar->setValue(sayac);
              QMessageBox::information(this, "MilPeK",uygulama +" uygulaması başarıyla yeniden kuruldu.");
              ui->listWidget->reset();
     }
    }
              else
              {
                     QMessageBox::information(this, "MilPeK"," Lütfen yeniden kurmak istediğiniz uygulamayı seçiniz");
               }
}

void AnaPencere::on_actionSe_ili_Paketi_Gerekleyiyle_Kald_r_triggered()
{
        if (ui->listWidget->currentItem())


    {
            QString kategori = ui->Kategoriler->currentText();
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

               QProcess::execute("mps -Sz "+uygulama);

              sayac=100;
              ui->progressBar->setValue(sayac);
              QMessageBox::information(this, "MilPeK",uygulama +" uygulaması gerekleriyle birlikte başarıyla kaldırıldı.");
              ui->listWidget->reset();
     }
    }
              else
              {
                     QMessageBox::information(this, "MilPeK"," Lütfen gerekleriyle birlikte kaldırmak istediğiniz uygulamayı seçiniz");
               }
}

void AnaPencere::on_actionSe_ili_Paketin_Eksi_ini_Bul_triggered()
{
        if (ui->listWidget->currentItem())
    {
    QString uygulama = ui->listWidget->currentItem()->text();
    QProcess liste;
    liste.start("mps -kpp "+uygulama+" --normal");
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
        }
    else
    {
           QMessageBox::information(this, "MilPeK"," Lütfen eksiğini bulmak istediğiniz uygulamayı seçiniz");
     }
}

void AnaPencere::on_actionSe_ili_Paketin_K_rd_Paketler_triggered()
{
        if (ui->listWidget->currentItem())
    {
    QString uygulama = ui->listWidget->currentItem()->text();
    QProcess liste;
    liste.start("mps kirma "+uygulama+" --normal");
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
        }
    else
    {
           QMessageBox::information(this, "MilPeK"," Lütfen sistemde kırdığı paketleri görmek istediğiniz uygulamayı seçiniz");
     }
}

void AnaPencere::on_actionSistem_K_r_k_Kontrol_triggered()
{
    QProcess liste;
    liste.start("mps -kks --normal");
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
}

void AnaPencere::on_actionPaket_Gruplar_triggered()
{
    QProcess liste;
    liste.start("mps sunucular");
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
}

void AnaPencere::on_actionTopluluk_Talimatlar_n_ndir_triggered()
{
    QProcess liste;
    liste.start("sudo git_indir https://github.com/milislinux-topluluk/Ek-Talimatlar /root/talimatlar");
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
}

void AnaPencere::on_commandLinkButton_7_clicked()
{
        if (ui->listWidget->currentItem())
    {
    QString uygulama = ui->listWidget->currentItem()->text();
    QProcess liste;
    liste.start("mps -bb "+uygulama);
    liste.waitForFinished();
    QString output(liste.readAllStandardOutput());
    ui->ciktimetni->setText(output);
        }
    else
    {
           QMessageBox::information(this, "MilPeK"," Lütfen gereklerini görmek istediğiniz uygulamayı seçiniz");
     }
}
