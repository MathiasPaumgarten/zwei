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

    class Container : public zwei::View {

        using ViewPtr = zwei::View*;

      public:

        void addView( ViewPtr view );
        ViewPtr removeView( ViewPtr view );
        std::list<ViewPtr> removeAllViews();
        void destroyAllViews();

        void draw() override;

        BoundingBox getBoundingBox() const override;

        void handleMouseEvent( zwei::MouseEvent ) override;

      private:
        std::list<ViewPtr> children;
    };
}

#endif /* defined(__Zwei__Container__) */
