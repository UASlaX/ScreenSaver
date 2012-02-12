#ifndef GLSCENE_HPP
#define GLSCENE_HPP

#include <QGLWidget>
#include "headers/gldata.hpp"

class GLScene
    :   public QGLWidget
{
    Q_OBJECT

public:

    GLScene( QWidget * _parent = 0 );


protected:

    /*virtual*/ void initializeGL();

    /*virtual*/ void resizeGL( int _width, int _height );

    /*virtual*/ void paintGL();

    /*virtual*/ void timerEvent(QTimerEvent * _event);


protected:

    typedef
        std::vector< GlFigure::Ptr >
        FiguresCollection;

    const std::size_t m_maxFigures;

    FiguresCollection m_figures;

};

#endif // GLSCENE_HPP
