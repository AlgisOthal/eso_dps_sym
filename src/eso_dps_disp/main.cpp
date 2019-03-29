#include <iostream>

#include <QApplication>

#include <form_dpssym.h>

int main(int argc, char* argv[] )
{
    QApplication app( argc, argv );

    FormDpsSym fds;
    fds.show();

    return app.exec();
}
