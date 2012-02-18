#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QCloseEvent>
#include <QEvent>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
            Q_OBJECT

public:
            explicit MainWindow(QWidget *parent = 0);
            ~MainWindow();

private:
            Ui::MainWindow *ui;
            QTimer *zaman;

            QString parca_numarasi;
            QString soru;
            QStringList soru_listesi;
            int eleman_sayisi;
            int rastgele_sayi;
            int kalan_eleman_sayisi;
            int zamanci;
protected:
            bool eventFilter(QObject *watched, QEvent *e);

private slots:
            void closeEvent(QCloseEvent *event);
            void on_comboBox_currentIndexChanged(QString index);
            void on_secButton_clicked();
            void timer();
            void timer2();
            void on_actionFont_triggered();
            void on_actionYaz_Rengi_triggered();
            void on_actionQtHakknda_triggered();
            void on_actionLisans_triggered();
};

#endif // MAINWINDOW_H
