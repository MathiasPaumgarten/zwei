//
//  Foo.h
//  Zwei
//
//  Created by roboshoes on 8/28/15.
//
//

#ifndef __Zwei__Foo__
#define __Zwei__Foo__

#include <stdio.h>
#include "View.h"

class Foo : public zwei::View {
  public:

    Foo( int i ) : index( i ), zwei::View() {
        context.setColor( cinder::Color( 0, 0, 0 ) );
        context.drawRect( cinder::vec2( 0 ), cinder::vec2( 100, 20 ) );
    }

    void handleMouseEvent( zwei::MouseEvent event ) {
        std::cout << index << " -> " << event << std::endl;
    }

  private:
    int index;
};

#endif /* defined(__Zwei__Foo__) */
