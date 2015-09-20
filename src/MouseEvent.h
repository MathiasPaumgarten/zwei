#ifndef __Zwei__MouseEvent__
#define __Zwei__MouseEvent__

#include <stdio.h>
#include "cinder/app/MouseEvent.h"

namespace zwei {

    class MouseEvent {
      public:
        MouseEvent( cinder::app::MouseEvent* e ) :
            originalEvent( e ),
            position( cinder::vec3( e->getX(), e->getY(), 1 ) )
            {}

        const cinder::app::MouseEvent* getOriginalEvent() const { return originalEvent; }
        float getX() const { return position.x; }
        float getY() const { return position.y; }
        cinder::vec2 getPostion() const { return cinder::vec2( position ); }

        void transform( const cinder::mat3& matrix ) {
            position = matrix * position;
        }

        friend std::ostream& operator<<( std::ostream& stream, MouseEvent const & object ) {
            return stream << "x: " << object.position.x << " y: " << object.position.y;
        }

      private:
        const cinder::app::MouseEvent* originalEvent;

        cinder::vec3 position;
    };
}

#endif /* defined(__Zwei__MouseEvent__) */
