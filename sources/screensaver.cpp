
#include "headers/screensaver.hpp"

#include "headers/glscene.hpp"


ScreenSaver::ScreenSaver( WId _drawable )
    :   KScreenSaver( _drawable )
    ,   m_glScene( new GLScene( this ) )
{
    QPalette backgroundPalette = palette();
    backgroundPalette.setColor( backgroundRole(), Qt::black );
    setPalette( backgroundPalette );

    embed( m_glScene.get() );

    m_glScene->show();

} // ScreenSaver::ScreenSaver


ScreenSaver::~ScreenSaver()
{
} // ScreenSaver::~ScreenSaver
