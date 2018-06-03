#ifndef ANAPENCERE_H
#define ANAPENCERE_H

#include <QMainWindow>
#include <QProcess>
#include <QListWidget>

namespace Ui {
class AnaPencere;
class InstallThread;
}

class AnaPencere : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnaPencere(QWidget *parent = 0);
    ~AnaPencere();

private slots:
    void processOutput();
    void on_kurbutonu_clicked();

    void on_SilButonu_clicked();

    void on_DerleKurButon_clicked();

    void on_PaketicerigiButonu_clicked();

    void on_TersGereklerButonu_clicked();

    void on_Kategoriler_currentTextChanged(const QString &arg1);

    void on_UygulamaAra_textChanged(const QString &arg1);

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_action_cikis_triggered();

    void on_actionVeritaban_G_ncelle_triggered();

    void on_actionKurulu_Paketler_triggered();

    void on_actionBilgisayardan_Program_Kur_triggered();

    void on_actionMiLPeK_Hakk_nda_triggered();

    void on_actionSe_ili_Paketi_ndir_triggered();

    void on_actionSe_ili_Paketi_ndir_Kur_triggered();

    void on_actionSe_ili_Paketi_Yeniden_Kur_triggered();

    void on_actionSe_ili_Paketi_Gerekleyiyle_Kald_r_triggered();

    void on_actionSe_ili_Paketin_Eksi_ini_Bul_triggered();

    void on_actionSe_ili_Paketin_K_rd_Paketler_triggered();

    void on_actionSistem_K_r_k_Kontrol_triggered();

    void on_actionPaket_Gruplar_triggered();

    void on_actionTopluluk_Talimatlar_n_ndir_triggered();

    void on_commandLinkButton_7_clicked();

    void on_actionToplam_Paket_Say_s_triggered();

private:
    Ui::AnaPencere *ui;
    void addSignalsSlots();
    QStringList listem;
    QMap< QString, QStringList > AppList;
    QProcess *terminal;
    QByteArray terminalOutput;
    QByteArray terminalOutputErr;

};

#endif // ANAPENCERE_H

