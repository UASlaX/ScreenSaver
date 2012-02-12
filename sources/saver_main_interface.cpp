
#include "headers/saver_main_interface.hpp"
#include "headers/setup_dialog.hpp"
#include "headers/screensaver.hpp"

#include "headers/resources.hpp"

#include <kaboutdata.h>


SaverMainInterface::SaverMainInterface()
    :   m_setupDialog( NULL )
    ,   m_aboutData( NULL )
    ,   m_scrrenSaver( NULL )
{
} // SaverMainInterface::SaverMainInterface


KAboutData*
SaverMainInterface::aboutData()
{
    if( m_aboutData )
        return m_aboutData;

    m_aboutData =
        new KAboutData(
                Resources::ApplicationInternalName
            ,   0
            ,   ki18n(Resources::ApplicationName)
            ,   "0.1"
            ,   ki18n(Resources::ApplicationDescription)
            ,   KAboutData::License_GPL
            ,   ki18n(Resources::ApplicationCopyright)
            ,   KLocalizedString()
            ,   Resources::ApplicationWeb
            ,   Resources::AuthorEmail );

    m_aboutData->addAuthor(
            ki18n(Resources::Author)
        ,   ki18n("")
        ,   Resources::AuthorEmail
    );

    return m_aboutData;

}  // SaverMainInterface::aboutData


KScreenSaver*
SaverMainInterface::create( WId _id )
{
    if( m_scrrenSaver )
        return m_scrrenSaver;

    return m_scrrenSaver = new ScreenSaver( _id ), m_scrrenSaver;

} // SaverMainInterface::create


QDialog*
SaverMainInterface::setup()
{
    if( m_setupDialog )
        return m_setupDialog;

    return m_setupDialog = new SetupDialog(), m_setupDialog;

} // SaverMainInterface::setup
