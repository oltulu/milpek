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

    void on_label_5_linkActivated(const QString &link);

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

