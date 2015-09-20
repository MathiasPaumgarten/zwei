#ifndef __Zwei__Container__
#define __Zwei__Container__

#include <stdio.h>
#include <list>
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

		// Todo: implement those
		float getWidth() const override { return zwei::View::getWidth(); }
		float getHeight() const override { return zwei::View::getHeight(); }

        BoundingBox getBoundingBox() const override;

        void handleMouseEvent( zwei::MouseEvent ) override;

      private:
        std::list<ViewPtr> children;
    };
}

#endif /* defined(__Zwei__Container__) */
