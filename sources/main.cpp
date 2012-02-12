
#include <QtCore/QCoreApplication>

#include <kscreensaver.h>
#include <kdialog.h>

#include "headers/saver_main_interface.hpp"


int
main( int _argc, char *_argv[] )
{
    SaverMainInterface mainInterface;

    return kScreenSaverMain( _argc, _argv, mainInterface );
}
