#ifndef __Zwei__Stage__
#define __Zwei__Stage__

#include <stdio.h>
#include "Container.h"
#include "MouseEvent.h"

namespace zwei {

    class Stage : public Container {

      private:
        Stage() : backgroundColor( cinder::Color( 255, 255, 255 ) ) {}
        Stage( Stage const& ) = delete;
        void operator=( Stage const& ) = delete;
        cinder::app::App* app;

      public:

        static Stage& getStage() {
            static Stage instance;

            return instance;
        }

        void handleMouseEvent( cinder::app::MouseEvent event );

        void setApp( cinder::app::App* a ) {
            app = a;
        }

        const cinder::app::App* getApp() const {
            return app;
        }

        cinder::Color backgroundColor;

        void draw() override;
    };

}

#endif /* defined(__Zwei__Stage__) */
