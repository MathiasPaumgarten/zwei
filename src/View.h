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
        View() : context( _context ), rotation( 0.0f ), position( 0 ) {
            View::start( this );
        }

        ~View() {
            View::stop( this );
        }

        cinder::vec2 position;
        float rotation;

        virtual float getWidth() const;
        virtual float getHeight() const;

        virtual BoundingBox getBoundingBox() const;

        virtual void draw();

        virtual bool findMouseEventTarget( zwei::MouseEvent event );

        zwei::Container* getParent() const;
        void setParent( zwei::Container* parent );

        virtual void callEvent( zwei::MouseEvent& event ); 

        static void tick();

      protected:

        virtual void onMouseDown( zwei::MouseEvent& event ) {}
        virtual void onMouseUp( zwei::MouseEvent& event ) {}
        virtual void onMouseMove( zwei::MouseEvent& event ) {}

        virtual void update();
        void adjustEvent( zwei::MouseEvent& event ) const;

        Context& context;

      private:
        static void start( View* view );
        static void stop( View* view );
        static std::list<View*> views;

        Context _context;
        zwei::Container* _parent = nullptr;
    };
}

#endif /* defined(__Zwei__View__) */
