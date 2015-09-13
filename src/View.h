//
//  View.h
//  Zwei
//
//  Created by roboshoes on 8/18/15.
//
//

#ifndef __Zwei__View__
#define __Zwei__View__

#include <stdio.h>
#include <list>
#include "Context.h"

namespace zwei {

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

        virtual void draw();
        static void tick();

    protected:
        virtual void update();
        Context& context;

    private:
        void static start( View* view );
        void static stop( View* view );
        static std::list<View*> views;

        Context _context;
    };

    using ViewRef = View*;
}

#endif /* defined(__Zwei__View__) */
