/********************************************************************************
** Form generated from reading UI file 'anapencere.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANAPENCERE_H
#define UI_ANAPENCERE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnaPencere
{
public:
    QAction *action_cikis;
    QAction *actionVeritaban_G_ncelle;
    QAction *actionKurulu_Paketler;
    QAction *actionBilgisayardan_Program_Kur;
    QAction *actionMiLPeK_Hakk_nda;
    QAction *actionSe_ili_Paketi_ndir;
    QAction *actionSe_ili_Paketi_ndir_Kur;
    QAction *actionSe_ili_Paketi_Yeniden_Kur;
    QAction *actionSe_ili_Paketi_Gerekleyiyle_Kald_r;
    QAction *actionSe_ili_Paketin_Eksi_ini_Bul;
    QAction *actionSe_ili_Paketin_K_rd_Paketler;
    QAction *actionSistem_K_r_k_Kontrol;
    QAction *actionPaket_Gruplar;
    QAction *actionTopluluk_Talimatlar_n_ndir;
    QWidget *centralWidget;
    QProgressBar *progressBar;
    QCommandLinkButton *DerleKurButon;
    QLabel *label_2;
    QComboBox *Kategoriler;
    QListWidget *listWidget;
    QCommandLinkButton *SilButonu;
    QCommandLinkButton *kurbutonu;
    QLineEdit *UygulamaAra;
    QCommandLinkButton *commandLinkButton_7;
    QLabel *label_5;
    QCommandLinkButton *TersGereklerButonu;
    QTextEdit *ciktimetni;
    QCommandLinkButton *PaketicerigiButonu;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuDosya;
    QMenu *menu_lemler;
    QMenu *menuHakk_nda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnaPencere)
    {
        if (AnaPencere->objectName().isEmpty())
            AnaPencere->setObjectName(QStringLiteral("AnaPencere"));
        AnaPencere->resize(730, 527);
        AnaPencere->setMinimumSize(QSize(730, 527));
        AnaPencere->setMaximumSize(QSize(730, 527));
        action_cikis = new QAction(AnaPencere);
        action_cikis->setObjectName(QStringLiteral("action_cikis"));
        actionVeritaban_G_ncelle = new QAction(AnaPencere);
        actionVeritaban_G_ncelle->setObjectName(QStringLiteral("actionVeritaban_G_ncelle"));
        actionKurulu_Paketler = new QAction(AnaPencere);
        actionKurulu_Paketler->setObjectName(QStringLiteral("actionKurulu_Paketler"));
        actionBilgisayardan_Program_Kur = new QAction(AnaPencere);
        actionBilgisayardan_Program_Kur->setObjectName(QStringLiteral("actionBilgisayardan_Program_Kur"));
        actionMiLPeK_Hakk_nda = new QAction(AnaPencere);
        actionMiLPeK_Hakk_nda->setObjectName(QStringLiteral("actionMiLPeK_Hakk_nda"));
        actionSe_ili_Paketi_ndir = new QAction(AnaPencere);
        actionSe_ili_Paketi_ndir->setObjectName(QStringLiteral("actionSe_ili_Paketi_ndir"));
        actionSe_ili_Paketi_ndir_Kur = new QAction(AnaPencere);
        actionSe_ili_Paketi_ndir_Kur->setObjectName(QStringLiteral("actionSe_ili_Paketi_ndir_Kur"));
        actionSe_ili_Paketi_Yeniden_Kur = new QAction(AnaPencere);
        actionSe_ili_Paketi_Yeniden_Kur->setObjectName(QStringLiteral("actionSe_ili_Paketi_Yeniden_Kur"));
        actionSe_ili_Paketi_Gerekleyiyle_Kald_r = new QAction(AnaPencere);
        actionSe_ili_Paketi_Gerekleyiyle_Kald_r->setObjectName(QStringLiteral("actionSe_ili_Paketi_Gerekleyiyle_Kald_r"));
        actionSe_ili_Paketin_Eksi_ini_Bul = new QAction(AnaPencere);
        actionSe_ili_Paketin_Eksi_ini_Bul->setObjectName(QStringLiteral("actionSe_ili_Paketin_Eksi_ini_Bul"));
        actionSe_ili_Paketin_K_rd_Paketler = new QAction(AnaPencere);
        actionSe_ili_Paketin_K_rd_Paketler->setObjectName(QStringLiteral("actionSe_ili_Paketin_K_rd_Paketler"));
        actionSistem_K_r_k_Kontrol = new QAction(AnaPencere);
        actionSistem_K_r_k_Kontrol->setObjectName(QStringLiteral("actionSistem_K_r_k_Kontrol"));
        actionPaket_Gruplar = new QAction(AnaPencere);
        actionPaket_Gruplar->setObjectName(QStringLiteral("actionPaket_Gruplar"));
        actionTopluluk_Talimatlar_n_ndir = new QAction(AnaPencere);
        actionTopluluk_Talimatlar_n_ndir->setObjectName(QStringLiteral("actionTopluluk_Talimatlar_n_ndir"));
        centralWidget = new QWidget(AnaPencere);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 410, 681, 23));
        progressBar->setFocusPolicy(Qt::ClickFocus);
        progressBar->setContextMenuPolicy(Qt::ActionsContextMenu);
        progressBar->setValue(0);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        DerleKurButon = new QCommandLinkButton(centralWidget);
        DerleKurButon->setObjectName(QStringLiteral("DerleKurButon"));
        DerleKurButon->setGeometry(QRect(90, 440, 121, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 0, 421, 20));
        Kategoriler = new QComboBox(centralWidget);
        Kategoriler->setObjectName(QStringLiteral("Kategoriler"));
        Kategoriler->setGeometry(QRect(10, 20, 211, 23));
        Kategoriler->setMinimumContentsLength(0);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(5, 101, 221, 301));
        SilButonu = new QCommandLinkButton(centralWidget);
        SilButonu->setObjectName(QStringLiteral("SilButonu"));
        SilButonu->setGeometry(QRect(220, 440, 71, 31));
        kurbutonu = new QCommandLinkButton(centralWidget);
        kurbutonu->setObjectName(QStringLiteral("kurbutonu"));
        kurbutonu->setGeometry(QRect(10, 440, 71, 31));
        UygulamaAra = new QLineEdit(centralWidget);
        UygulamaAra->setObjectName(QStringLiteral("UygulamaAra"));
        UygulamaAra->setGeometry(QRect(10, 50, 211, 23));
        UygulamaAra->setAlignment(Qt::AlignCenter);
        commandLinkButton_7 = new QCommandLinkButton(centralWidget);
        commandLinkButton_7->setObjectName(QStringLiteral("commandLinkButton_7"));
        commandLinkButton_7->setGeometry(QRect(440, 440, 111, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 20, 461, 251));
        label_5->setAutoFillBackground(true);
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        TersGereklerButonu = new QCommandLinkButton(centralWidget);
        TersGereklerButonu->setObjectName(QStringLiteral("TersGereklerButonu"));
        TersGereklerButonu->setGeometry(QRect(560, 440, 131, 31));
        ciktimetni = new QTextEdit(centralWidget);
        ciktimetni->setObjectName(QStringLiteral("ciktimetni"));
        ciktimetni->setEnabled(true);
        ciktimetni->setGeometry(QRect(230, 280, 461, 121));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(8);
        ciktimetni->setFont(font);
        ciktimetni->setAutoFillBackground(false);
        ciktimetni->setReadOnly(true);
        ciktimetni->setTextInteractionFlags(Qt::NoTextInteraction);
        PaketicerigiButonu = new QCommandLinkButton(centralWidget);
        PaketicerigiButonu->setObjectName(QStringLiteral("PaketicerigiButonu"));
        PaketicerigiButonu->setGeometry(QRect(300, 440, 121, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, -11, 211, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 211, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 220, 61, 51));
        AnaPencere->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AnaPencere);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 730, 24));
        menuDosya = new QMenu(menuBar);
        menuDosya->setObjectName(QStringLiteral("menuDosya"));
        menu_lemler = new QMenu(menuBar);
        menu_lemler->setObjectName(QStringLiteral("menu_lemler"));
        menuHakk_nda = new QMenu(menuBar);
        menuHakk_nda->setObjectName(QStringLiteral("menuHakk_nda"));
        AnaPencere->setMenuBar(menuBar);
        statusBar = new QStatusBar(AnaPencere);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AnaPencere->setStatusBar(statusBar);

        menuBar->addAction(menuDosya->menuAction());
        menuBar->addAction(menu_lemler->menuAction());
        menuBar->addAction(menuHakk_nda->menuAction());
        menuDosya->addAction(action_cikis);
        menu_lemler->addAction(actionVeritaban_G_ncelle);
        menu_lemler->addAction(actionKurulu_Paketler);
        menu_lemler->addAction(actionBilgisayardan_Program_Kur);
        menu_lemler->addAction(actionSe_ili_Paketi_ndir);
        menu_lemler->addAction(actionSe_ili_Paketi_ndir_Kur);
        menu_lemler->addAction(actionSe_ili_Paketi_Yeniden_Kur);
        menu_lemler->addAction(actionSe_ili_Paketi_Gerekleyiyle_Kald_r);
        menu_lemler->addAction(actionSe_ili_Paketin_Eksi_ini_Bul);
        menu_lemler->addAction(actionSe_ili_Paketin_K_rd_Paketler);
        menu_lemler->addAction(actionSistem_K_r_k_Kontrol);
        menu_lemler->addAction(actionPaket_Gruplar);
        menu_lemler->addAction(actionTopluluk_Talimatlar_n_ndir);
        menuHakk_nda->addAction(actionMiLPeK_Hakk_nda);

        retranslateUi(AnaPencere);

        Kategoriler->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AnaPencere);
    } // setupUi

    void retranslateUi(QMainWindow *AnaPencere)
    {
        AnaPencere->setWindowTitle(QApplication::translate("AnaPencere", "MiLPek - Milis Program Ekle Kald\304\261r 0.3", Q_NULLPTR));
        action_cikis->setText(QApplication::translate("AnaPencere", "\303\207\304\261k\304\261\305\237", Q_NULLPTR));
        actionVeritaban_G_ncelle->setText(QApplication::translate("AnaPencere", "Veritaban\304\261 G\303\274ncelle", Q_NULLPTR));
        actionKurulu_Paketler->setText(QApplication::translate("AnaPencere", "Kurulu Paketler", Q_NULLPTR));
        actionBilgisayardan_Program_Kur->setText(QApplication::translate("AnaPencere", "Bilgisayardan Program Kur", Q_NULLPTR));
        actionMiLPeK_Hakk_nda->setText(QApplication::translate("AnaPencere", "MiLPeK Hakk\304\261nda", Q_NULLPTR));
        actionSe_ili_Paketi_ndir->setText(QApplication::translate("AnaPencere", "Se\303\247ili Paketi \304\260ndir", Q_NULLPTR));
        actionSe_ili_Paketi_ndir_Kur->setText(QApplication::translate("AnaPencere", "Se\303\247ili Paketi \304\260ndir ve Kur", Q_NULLPTR));
        actionSe_ili_Paketi_Yeniden_Kur->setText(QApplication::translate("AnaPencere", "Se\303\247ili Paketi Yeniden Kur", Q_NULLPTR));
        actionSe_ili_Paketi_Gerekleyiyle_Kald_r->setText(QApplication::translate("AnaPencere", "Se\303\247ili Paketi Gerekleriyle Kald\304\261r", Q_NULLPTR));
        actionSe_ili_Paketin_Eksi_ini_Bul->setText(QApplication::translate("AnaPencere", "Se\303\247ili Paketin Eksi\304\237ini Bul", Q_NULLPTR));
        actionSe_ili_Paketin_K_rd_Paketler->setText(QApplication::translate("AnaPencere", "Se\303\247ili Paketin K\304\261rd\304\261\304\237\304\261 Paketler", Q_NULLPTR));
        actionSistem_K_r_k_Kontrol->setText(QApplication::translate("AnaPencere", "Sistem K\304\261r\304\261k Kontrol\303\274", Q_NULLPTR));
        actionPaket_Gruplar->setText(QApplication::translate("AnaPencere", "Paket Sunucu Bilgisi", Q_NULLPTR));
        actionTopluluk_Talimatlar_n_ndir->setText(QApplication::translate("AnaPencere", "Topluluk Talimatlar\304\261n\304\261 \304\260ndir", Q_NULLPTR));
        DerleKurButon->setText(QApplication::translate("AnaPencere", "Derle >> Kur", Q_NULLPTR));
        label_2->setText(QApplication::translate("AnaPencere", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#204a87;\">Uygulama Aray\303\274z\303\274</span></p></body></html>", Q_NULLPTR));
        Kategoriler->clear();
        Kategoriler->insertItems(0, QStringList()
         << QApplication::translate("AnaPencere", "genel", Q_NULLPTR)
         << QApplication::translate("AnaPencere", "yerel", Q_NULLPTR)
         << QApplication::translate("AnaPencere", "onsistem", Q_NULLPTR)
         << QApplication::translate("AnaPencere", "temel", Q_NULLPTR)
         << QString()
        );
        Kategoriler->setCurrentText(QApplication::translate("AnaPencere", "genel", Q_NULLPTR));
        SilButonu->setText(QApplication::translate("AnaPencere", "Sil", Q_NULLPTR));
        kurbutonu->setText(QApplication::translate("AnaPencere", "Kur", Q_NULLPTR));
        UygulamaAra->setText(QApplication::translate("AnaPencere", "Uygulama Ara", Q_NULLPTR));
        commandLinkButton_7->setText(QApplication::translate("AnaPencere", "Gerekler", Q_NULLPTR));
        label_5->setText(QString());
        TersGereklerButonu->setText(QApplication::translate("AnaPencere", "Ters Gerekler", Q_NULLPTR));
        ciktimetni->setHtml(QApplication::translate("AnaPencere", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#204a87;\">Uygulama kategorisi se\303\247tikten sonra, Mevcut uygulamalardan i\305\237lem yapmak istedi\304\237iniz program\304\261 se\303\247erek butonlar yard\304\261m\304\261yla i\305\237leminizi ger\303\247ekle\305\237tirebilirsiniz...</span></p></body></html>", Q_NULLPTR));
        PaketicerigiButonu->setText(QApplication::translate("AnaPencere", "Paket \304\260\303\247eri\304\237i", Q_NULLPTR));
        label_4->setText(QApplication::translate("AnaPencere", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#204a87; vertical-align:sub;\">Uygulama Kategorisi Se\303\247iniz</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("AnaPencere", "<html><head/><body><p align=\"center\">Mevcut Uygulamalar</p></body></html>", Q_NULLPTR));
        label_3->setText(QString());
        menuDosya->setTitle(QApplication::translate("AnaPencere", "Dosya", Q_NULLPTR));
        menu_lemler->setTitle(QApplication::translate("AnaPencere", "Paket \304\260\305\237lemleri", Q_NULLPTR));
        menuHakk_nda->setTitle(QApplication::translate("AnaPencere", "Hakk\304\261nda", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AnaPencere: public Ui_AnaPencere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANAPENCERE_H
