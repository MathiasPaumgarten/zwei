#ifndef __Zwei__Bar__
#define __Zwei__Bar__

#include <stdio.h>
#include "Container.h"
#include "Foo.h"

class Bar : public zwei::Container {
  public:
    Bar() : zwei::Container() {

        int position = 0;

        for ( int i = 0; i < 5; i++ ) {
            Foo* line = new Foo( i );
            line->position.y = position;

            position += line->getHeight() + 2;

            addView( line );
        }
    }

    void onMouseDown( zwei::MouseEvent& event ) override {
        std::cout << event.getTarget() << std::endl;
    }

    ~Bar() {
        destroyAllViews();
    }
};

#endif /* defined(__Zwei__Bar__) */
