#ifndef __Zwei__MouseEvent__
#define __Zwei__MouseEvent__

#include <stdio.h>

#include "cinder/app/MouseEvent.h"
#include "cinder/Matrix.h"

namespace zwei {

    class View;

    class MouseEvent {
      public:

        enum Type {
            DOWN,
            UP,
            MOVE
        };

        inline static const char* toString( Type v ) {
            switch ( v ) {
                case DOWN:   return "DOWN";
                case UP:   return "UP";
                case MOVE: return "MOVE";
            }
        }

        MouseEvent( cinder::app::MouseEvent* e, Type t, bool bubbles = true ) :
            originalEvent( e ),
            position( cinder::vec3( e->getPos(), 1 ) ),
            isActive( true ),
            isBubbling( bubbles ),
            type( t ),
            target( nullptr ),
            currentTarget( nullptr )
            {}

        const cinder::app::MouseEvent* getOriginalEvent() const { return originalEvent; }
        float getX() const { return position.x; }
        float getY() const { return position.y; }
        cinder::vec2 getPostion() const { return cinder::vec2( position ); }

        void transform( const cinder::mat3& matrix ) {
            position = matrix * position;
        }

        friend std::ostream& operator<<( std::ostream& stream, MouseEvent const & object ) {
            return stream << toString( object.type ) << " x: " << object.position.x << " y: " << object.position.y;
        }

        void stopPropagation();
        void stopImmediatePropagation();

        void setTarget( zwei::View* t ) { if ( target == nullptr ) target = t; }
        const zwei::View* getTarget() { return target; }

        void setCurrentTarget( zwei::View* t ) { currentTarget = t; }
        const zwei::View* getCurrentTarget() { return currentTarget; };

        Type getType() const { return type; }

        bool getBubbling() const { return isBubbling; }
        bool getActive() const { return isActive; }

      private:
        const cinder::app::MouseEvent* originalEvent;

        zwei::View* target;
        zwei::View* currentTarget;

        cinder::vec3 position;

        bool isActive;
        bool isBubbling;


        Type type;
    };
}

#endif /* defined(__Zwei__MouseEvent__) */
