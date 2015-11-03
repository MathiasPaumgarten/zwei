#ifndef __Zwei__View__
#define __Zwei__View__

#include <stdio.h>
#include <list>
#include <boost/signals2.hpp>

#include "cinder/gl/gl.h"

#include "Context.h"
#include "MouseEvent.h"
#include "RenderData.h"

namespace zwei {

    class Container;

    class View {

      public:
        View() :
            context( _context ),
            rotation( 0.f ),
            position( 0 ),
            scale( 1.0f ),
            opacity( 1.f ),
            mouseEnabled( true )
            {

            View::start( this );

            mouseDownSignal.connect( std::bind( &View::onMouseDown, this, std::placeholders::_1 ) );
            mouseUpSignal.connect( std::bind( &View::onMouseUp, this, std::placeholders::_1 ) );
            mouseMoveSignal.connect( std::bind( &View::onMouseMove, this, std::placeholders::_1 ) );
        }

        ~View() {
            View::stop( this );

            mouseDownSignal.disconnect_all_slots();
            mouseUpSignal.disconnect_all_slots();
            mouseMoveSignal.disconnect_all_slots();
        }

        cinder::vec2 position;
        float rotation;

        virtual float getWidth() const;
        virtual float getHeight() const;

        void setMouseEnabled( bool value ) { mouseEnabled = value; }
        bool getMouseEnabled() const { return mouseEnabled; }

        float getOpacity() const { return opacity; }
        void setOpacity( float value ) { opacity = value; }

        cinder::vec2 getScale() const { return scale; }

        virtual BoundingBox getBoundingBox() const;

        virtual void draw( const zwei::RenderData renderData );

        virtual bool findMouseEventTarget( zwei::MouseEvent event );

        zwei::Container* getParent() const;
        void setParent( zwei::Container* parent );

        virtual void callEvent( zwei::MouseEvent& event ); 

        static void tick();

        boost::signals2::signal<void (zwei::MouseEvent&)> mouseDownSignal;
        boost::signals2::signal<void (zwei::MouseEvent&)> mouseUpSignal;
        boost::signals2::signal<void (zwei::MouseEvent&)> mouseMoveSignal;

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

        bool mouseEnabled;

        float opacity;
        cinder::vec2 scale;
    };
}

#endif /* defined(__Zwei__View__) */
