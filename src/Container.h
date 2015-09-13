//
//  Container.h
//  Zwei
//
//  Created by roboshoes on 8/18/15.
//
//

#ifndef __Zwei__Container__
#define __Zwei__Container__

#include <stdio.h>
#include "View.h"

namespace zwei {

    class Container : public View {

    public:

        ViewRef removeView( ViewRef view );
        void addView( ViewRef view );
        void draw();

    private:
        std::list<ViewRef> children;
    };


    using ContainerRef = Container*;
}

#endif /* defined(__Zwei__Container__) */
