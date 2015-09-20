#ifndef __Zwei__View__
#define __Zwei__View__

#include <stdio.h>
#include <list>

#include "cinder/gl/gl.h"

#include "Context.h"
#include "MouseEvent.h"

namespace zwei {

    class Container;

    class View {

      public:
        View() : context( _context ), rotation( 0.0f ) {
            View::start( this );
        }

        ~View() {
            View::stop( this );
        }

        cinder::vec2 position;
        float rotation;

        virtual float getWidth();
        virtual float getHeight();

        virtual BoundingBox getBoundingBox() const;

        virtual void draw();

        virtual void handleMouseEvent( zwei::MouseEvent event );

        zwei::Container* getParent();
        void setParent( zwei::Container* parent );

        static void tick();

      protected:
        virtual void update();
        Context& context;
        void adjustEvent( zwei::MouseEvent& event );

      private:
        static void start( View* view );
        static void stop( View* view );
        static std::list<View*> views;

        Context _context;
        zwei::Container* _parent = nullptr;
    };
}

#endif /* defined(__Zwei__View__) */
