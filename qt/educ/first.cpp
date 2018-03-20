#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget wgt;
    wgt.setWindowTitle(tr("Hello world"));
    wgt.show();
    return app.exec();
}