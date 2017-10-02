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
    QString kategori = ui->Kategoriler->currentText();
    QDir kaynak("/root/talimatname/genel");
    kaynak.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    listem = kaynak.entryList();
    ui->listWidget->addItems(listem);
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
QProcess::execute("mps kur "+uygulama);
sayac=100;
ui->progressBar->setValue(sayac);
QString preparedText = terminalOutput.left(70);
preparedText.replace("\n","");
ui->ciktimetni->setText(preparedText);
qDebug() << terminalOutput;
qDebug() << terminalOutputErr;
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
        QString kategori = ui->Kategoriler->currentText();
        QString uygulama = ui->listWidget->currentItem()->text();
           QFile kurulumu("/var/lib/pkg/DB/"+uygulama+"/kurulan");

           if(!kurulumu.exists()) {

    sayac=10;
     ui->progressBar->setValue(sayac);

     ui->progressBar->setValue(sayac);
     sayac=50;
QProcess::execute("mps -tb "+uygulama);
sayac=100;
   ui->ciktimetni->setText(terminalOutputErr);
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
        if (ui->Kategoriler->currentText() == "yerel")

    {
            QStringList yenilistem;
             ui->listWidget->reset();
            QString kategori = ui->Kategoriler->currentText();
            QDir yeniliste("/root/talimatlar/");
            ui->listWidget->clear();
            yeniliste.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
            yenilistem = yeniliste.entryList();
        ui->listWidget->addItems(yenilistem);
        }
     else
        {
    QStringList yenilistem;
     ui->listWidget->reset();
    QString kategori = ui->Kategoriler->currentText();
    QDir yeniliste("/root/talimatname/"+kategori);
    ui->listWidget->clear();
    yeniliste.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    yenilistem = yeniliste.entryList();
ui->listWidget->addItems(yenilistem);
}
}

void AnaPencere::on_UygulamaAra_textChanged(const QString &arg1)
{
    ui->listWidget->reset();
    QStringList yenilistem1;
   QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    QString kategori = ui->Kategoriler->currentText();
    QDir yeniliste1("/root/talimatname/"+kategori);
    ui->listWidget->clear();
    yeniliste1.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    yenilistem1 = yeniliste1.entryList();
ui->listWidget->addItems(yenilistem1.filter(regExp));
}

void AnaPencere::on_listWidget_currentTextChanged(const QString &currentText)
{
    QString kategori = ui->Kategoriler->currentText();
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
    QProcess::execute("mps -GG");
    QProcess::execute("mps -G");
    sayac=100;
    ui->progressBar->setValue(sayac);
    ui->ciktimetni->setText(terminalOutputErr);
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
    QProcess::execute("lxqt-sudo mps kur "+fileName);

    QString preparedText = terminalOutput.left(70);
    preparedText.replace("\n","");
    ui->ciktimetni->setText(preparedText);
    QMessageBox::information(this, "MilPeK","Bilgisayardan program kurma işlemi tamamlanmıştır.");
}

void AnaPencere::on_actionMiLPeK_Hakk_nda_triggered()
{
   QMessageBox::information(this, "MilPeK"," Milis Linux için Cihan Alkan tarafından hazırlanmıştır.");
}