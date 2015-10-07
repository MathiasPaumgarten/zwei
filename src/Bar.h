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
			line->setOpacity( i == 2 ? 0.5 : 1.0 );

            position += line->getHeight() + 2;

            addView( line );
        }
    }

    ~Bar() {
        destroyAllViews();
    }
};

#endif /* defined(__Zwei__Bar__) */
