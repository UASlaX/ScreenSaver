#ifndef GLDATA_HPP
#define GLDATA_HPP

#include <GL/gl.h>
#include <vector>
#include <boost/shared_ptr.hpp>

struct GlColor
{
    GLfloat m_red;

    GLfloat m_green;

    GLfloat m_blue;
    
    GlColor()
        :   m_red( 0.0 )
        ,   m_green( 0.0 )
        ,   m_blue( 0.0 )
    {
    }


    GlColor(
            GLfloat const _red
        ,   GLfloat const _green
        ,   GLfloat const _blue
    )
        :   m_red( _red )
        ,   m_green( _green )
        ,   m_blue( _blue )
    {
    }

};


/*-------------------------------------------------------------*/


struct GlCord
{
    GLfloat m_x, m_y, m_z;
};


/*-------------------------------------------------------------*/


struct GlFigure
{
    typedef
        boost::shared_ptr< GlFigure >
        Ptr;

    GlColor m_color;

    std::vector< GlCord > m_cords;

    GlCord m_position;
};


/*-------------------------------------------------------------*/


#endif // GLDATA_HPP
