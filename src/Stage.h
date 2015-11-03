#ifndef __Zwei__Stage__
#define __Zwei__Stage__

#include <stdio.h>

#include "cinder/app/App.h"
#include "cinder/Color.h"
#include "cinder/gl/Context.h"

#include "Container.h"
#include "MouseEvent.h"

namespace zwei {

    class Stage : public Container {

      private:
        Stage() : backgroundColor( cinder::Color( 255, 255, 255 ) ) {}
        Stage( Stage const& ) = delete;
        void operator=( Stage const& ) = delete;

      public:

        static Stage& getStage() {
            static Stage instance;

            return instance;
        }

        bool findMouseEventTarget( zwei::MouseEvent::Type type, cinder::app::MouseEvent event );

        cinder::Color backgroundColor;

        void draw( float opacity = 1.f ) const override;
    };

}

#endif /* defined(__Zwei__Stage__) */
