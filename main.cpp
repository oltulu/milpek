#include "anapencere.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnaPencere w;
    w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w.size(),
            a.desktop()->availableGeometry()
        )
    );
    w.move(w.pos().x(), w.pos().y() - 50);
    w.show();

    return a.exec();
}

