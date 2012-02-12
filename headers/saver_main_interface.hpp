#ifndef SAVER_MAIN_INTERFACE_HPP
#define SAVER_MAIN_INTERFACE_HPP

#include <kscreensaver.h>

class SetupDialog;
class ScreenSaver;

class SaverMainInterface
    :   public KScreenSaverInterface
{

public:

        SaverMainInterface();


public:

        /*virtual*/ KAboutData* aboutData();


        // function to create screen saver object
        /*virtual*/ KScreenSaver* create( WId _id );


        // function to create setup dialog for screen saver
        /*virtual*/ QDialog* setup();


protected:

    SetupDialog * m_setupDialog;

    KAboutData * m_aboutData;

    ScreenSaver * m_scrrenSaver;

};

#endif // SAVER_MAIN_INTERFACE_HPP
