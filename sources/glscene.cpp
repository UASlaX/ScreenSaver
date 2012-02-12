
#include "headers/glscene.hpp"
#include <QtGui/QMessageBox>


GLScene::GLScene( QWidget * _parent )
    :   QGLWidget( QGLFormat(QGL::SampleBuffers|QGL::AlphaChannel|QGL::DirectRendering), _parent )
    ,   m_maxFigures( 100 )
    //,   m_figures( m_maxFigures )
{
} // GLScene::GLScene


void
GLScene::initializeGL()
{
    makeCurrent();
    startTimer( 500 );

    glShadeModel(GL_SMOOTH);				// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);		// Black Background
    glClearDepth(1.0f);					// Depth Buffer Setup

    glEnable(GL_DEPTH_TEST);                            // Enables Depth Testing

    //glEnable ( GL_LIGHT1 );
    //glEnable ( GL_LIGHTING );

    glDepthFunc(GL_LEQUAL);				// The Type Of Depth Testing To Do

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

} // GLScene::initializeGL


void
GLScene::resizeGL( int _width, int _height )
{
    if (_height==0)							// Prevent A Divide By Zero By
        _height=1;							// Making Height Equal One

    glViewport(0,0,_width,_height);					// Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);					// Select The Projection Matrix
    glLoadIdentity();							// Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(GLfloat)_width/(GLfloat)_height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
    glLoadIdentity();

} // GLScene::resizeGL


void
GLScene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//     glLoadIdentity();
//     glTranslatef(-1.5f,0.0f,-6.0f);
//
//     glBegin(GL_TRIANGLES);
//                  glVertex3f( 0.0f, 1.0f, 0.0f);  // Вверх
//                  glVertex3f(-1.0f,-1.0f, 0.0f);  // Слева снизу
//                  glVertex3f( 1.0f,-1.0f, 0.0f);  // Справа снизу
//     glEnd();

    glLoadIdentity();

    glTranslatef(-1.5f,0.0f,-6.0f);
    //glTranslatef(-1.5f,0.0f,-6.0f);

    FiguresCollection::const_iterator
        it( m_figures.begin() )
    ,   itEnd( m_figures.end() );

    for( ; it != itEnd ; ++it )
    {
        GlFigure::Ptr figure( *it );

        glTranslatef(
            figure->m_position.m_x
        ,   figure->m_position.m_y
        ,   figure->m_position.m_z );

        glColor3f(
            figure->m_color.m_red
        ,   figure->m_color.m_green
        ,   figure->m_color.m_blue );

        glBegin(GL_QUADS);
            glVertex3f(-1.0f, 1.0f, 0.0f);
            glVertex3f( 1.0f, 1.0f, 0.0f);
            glVertex3f( 1.0f,-1.0f, 0.0f);
            glVertex3f(-1.0f,-1.0f, 0.0f);
        glEnd();
    }

} // GLScene::paintGL


void
GLScene::timerEvent( QTimerEvent * /*_event*/)
{
    if( m_figures.size() >= m_maxFigures )
        m_figures.clear();

    GlFigure::Ptr newFigure( new GlFigure() );

    newFigure->m_position.m_x = rand() % 100;
    newFigure->m_position.m_y = rand() % 100;
    newFigure->m_position.m_z = rand() % 100;

    newFigure->m_color.m_red    = rand() % 6;
    newFigure->m_color.m_green  = rand() % 6;
    newFigure->m_color.m_blue   = rand() % 6;

    m_figures.push_back( newFigure );

    updateGL();

} // GLScene::timeOutSlot
