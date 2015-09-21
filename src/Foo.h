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

  protected:
    void onMouseDown( zwei::MouseEvent& event ) override {
        std::cout << event.getTarget() << std::endl;
    }

  private:
    int index;
};

#endif /* defined(__Zwei__Foo__) */
