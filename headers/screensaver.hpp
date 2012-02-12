#ifndef SCREENSAVER_HPP
#define SCREENSAVER_HPP

#include <kscreensaver.h>
#include <boost/scoped_ptr.hpp>

class GLScene;

class ScreenSaver
    :   public KScreenSaver
{
public:

    ScreenSaver( WId _drawable );

    virtual ~ScreenSaver();


protected:

    boost::scoped_ptr< GLScene > m_glScene;

};

#endif // SCREENSAVER_HPP
