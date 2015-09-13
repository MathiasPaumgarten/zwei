//
//  Stage.h
//  Zwei
//
//  Created by roboshoes on 8/28/15.
//
//

#ifndef __Zwei__Stage__
#define __Zwei__Stage__

#include <stdio.h>
#include "Container.h"

namespace zwei {

    class Stage : public Container {

      private:
        Stage() : backgroundColor( cinder::Color( 255, 255, 255 ) ) {}
        Stage( Stage const& ) = delete;
        void operator=( Stage const& ) = delete;

      public:
        int getWidth();
        int getHeight();

        static Stage& getStage() {
            static Stage instance;

            return instance;
        }

        cinder::Color backgroundColor;

        void tick();
    };

}

#endif /* defined(__Zwei__Stage__) */
