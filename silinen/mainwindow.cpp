// Rastgele
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ctime>                         //Need this so random will work
#include <cstdlib>

#include <QFile>
#include <QTextStream>
//#include <QInputDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QCloseEvent>

//#include <QCheckBox>

//#include <QDebug>
//#include <QMap>
//#include <QMultiMap>
//#include <QList>
//#include <QColorGroup>
//#include <QPalette>


MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent),
            ui(new Ui::MainWindow)
{
            ui->setupUi(this);

//            about = new MyForm();

            zaman = new QTimer(this);
            connect(zaman, SIGNAL(timeout()), this, SLOT(timer()));
            zamanci = -1;

            srand(time(0));

            kalan_eleman_sayisi = 0;

            ui->label_soru->setText("...");
            ui->label->setText("...");
            ui->label_soru_no->setText("...");

            ui->secButton->setDisabled(true);
            ui->S_S_Button->setDisabled(true);

            ui->S_S_Button->hide();
            ui->label->hide();
            ui->label_soru_no->hide();
}

MainWindow::~MainWindow()
{
            delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(QString index)
{

            if (index.startsWith("B"))
            {
                        ui->secButton->setDisabled(true);
                        ui->S_S_Button->setDisabled(true);
                        ui->actionListe->setEnabled(false);
            }
            else
            {
                        ui->secButton->setDisabled(false);
                        ui->S_S_Button->setDisabled(false);
                        ui->actionListe->setEnabled(true);
            }

            soru_listesi.clear();
//            liste2.clear();

            kalan_eleman_sayisi = 0;

            ui->label_soru->setText("...");
            ui->label->setText("...");
            ui->label_soru_no->setText("...");


            parca_numarasi = index;
            //    QFile file1(":/DATA/Siniflar/"+parca_numarasi+".txt");
            QFile file1(":/DATA/Veri/"+parca_numarasi+".txt");
            if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                        ui->label_sinif->setText(tr("Baþlamak için bölüm seçmelisiniz!"));
                        return;
            }

            QTextStream in1(&file1);

            while (!in1.atEnd())
            {
                        QString line1 = in1.readLine().trimmed().toUpper().replace("\t","  ");
                        soru_listesi.append(line1);
            }

            eleman_sayisi = soru_listesi.size();
            kalan_eleman_sayisi = soru_listesi.size();

            ui->label_sinif->setText(parca_numarasi +
                                     tr(" için ")
                                     +QString::number(eleman_sayisi)
                                     +tr(" soru var. "));
}

void MainWindow::timer()
{
            if (soru_listesi.isEmpty())
            {
                        timer2();
                        zaman->stop();
            }
            else
            {
                        zamanci += 1;
                        QString kim ;

                        if(zamanci > soru_listesi.size()-1)
                        {
                                    zaman->stop();
                                    zamanci = -1 ;
                                    timer2();
                        }
                        else
                        {
                                    kim = soru_listesi.at(zamanci);
                                    ui->label_soru->setText(kim);
                        }
            }
}

void MainWindow::on_secButton_clicked()
{
            //    zaman->start(111);
            timer2();
}

void MainWindow::timer2()
{
            if (soru_listesi.isEmpty())
            {
                        ui->label_soru->setText(tr("Liste bitti!"));
            }
            else
            {
                        /* soru_listesinin boyutuna göre rastgele sayýmýzý seçip
            ona göre öðrenci adýný alýp
            ona göre label_isim e yazdýrýp
            sonra da onu listeden siliyoruz
        */

                        rastgele_sayi = (rand() % (soru_listesi.size())) ;
                        soru = soru_listesi.at(rastgele_sayi);

                        ui->label_soru->setText(soru);
                        soru_listesi.removeAt(rastgele_sayi);

                        if (kalan_eleman_sayisi > 0)
                        {
                                    kalan_eleman_sayisi -= 1;
                        }
            }
            ui->statusBar->showMessage(tr("Listede ")
                                       +QString::number(kalan_eleman_sayisi)+
                                       //                               tr(" öðrenci ve ")
                                       //                               +QString::number(kalan_soru_sayisi)+
                                       tr(" soru kalmýþtýr. "));
}


void MainWindow::on_actionFont_triggered()
{
            bool ok;
            QFont font = QFontDialog::getFont(
                                                &ok,  this);
            if (ok) {
                        ui->label->setFont(font);
                        ui->label_soru->setFont(font);
                        ui->label_soru_no->setFont(font);
                        ui->label_sinif->setFont(font);
            }
}

void MainWindow::on_actionYaz_Rengi_triggered()
{
            QColor renk = QColorDialog::getColor();
            MainWindow::setStyleSheet("QLabel {color: "+renk.name()+";}");
}

void MainWindow::on_actionQtHakknda_triggered()
{
            QMessageBox::aboutQt(this,"Qt");
}

void MainWindow::on_actionLisans_triggered()
{
            QMessageBox::about(this, tr("Lisans"),
                               tr("<td align='left'>Lisans: GPLv3 <br/> "
                                  "<br/>Ýngilizce konuþma sorularý için hazýrlanmýþ basit bir program<br/> "
                                  "Sürüm: 1.0<br/>"
                                  "<br/>akrep55tr@gmail.com"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
            int son = QMessageBox::warning(this,tr("Emin misin?"),
                                           tr("Programý kapatmak üzeresiniz!"),
                                           tr("Kapat"),tr("Ýptal"));

            if (son == 0) {
                        event->accept();
            }
            else {
                        event->ignore();
            }
}
