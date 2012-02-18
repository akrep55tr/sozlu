#include "ui_form.h"
#include "form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MyForm::MyForm(QWidget* parent):QWidget(parent)
{
    ui.setupUi(this);

    MyForm::setStyleSheet("QWidget {color: blue ;}");

}

QSize MyForm::sizeHint() const
{
    QSize size = ui.tableWidget->size();
    size += QSize(1, 1);
    return size;
}

void MyForm::on_buttonBox_accepted()
{ /*QFile file("file.xxx");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
   */
    // Write a header with a "magic number" and a version
//    out << (quint32)0xA0B0C0D0;
//    out << (qint32)123;

//    out.setVersion(QDataStream::Qt_4_0);

//    // Write the data
//    out << lots_of_interesting_data;



//    QFile file(qApp->applicationDirPath()
//               +"/DATA/Veri/"+p_n+".ymn");
//         if (!file.open(QIODevice::WriteOnly))
//             return;

//         QDataStream out(&file);
////         QTextStream out(&file);
//         QStringList hucre_listesi;
//         QString hucre;

//         // Write a header with a "magic number" and a version
//         out << (quint32)0xA0B0C0D0;
//         out << (qint32)123;
////         out.setVersion(QDataStream::Qt_4_7);

//         for(int i =0;i < e_s ; i++){
//             for(int j = 0;j<3;j++){
//                 if(ui.tableWidget->item(i,j)){
//                     hucre = ui.tableWidget->item(i,j)->text();
//                     hucre_listesi.append(hucre);
//                 }
//                 else
//                    return;
//             }
//             if(hucre_listesi.isEmpty()){
//                 return;
//             }
//             QString str = hucre_listesi.join("\t");
//             out << str<< "\n";
//             hucre_listesi.clear();
//         }
//         file.close();
}
