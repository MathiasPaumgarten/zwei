//
//  Style.h
//  Zwei
//
//  Created by roboshoes on 8/27/15.
//
//

#ifndef __Zwei__Style__
#define __Zwei__Style__

#include <stdio.h>

namespace zwei {

    class Style {
      public:
        Style( cinder::Color c ) : color( c ) {}
        Style();

      private:
        cinder::Color color;
    };
}

#endif /* defined(__Zwei__Style__) */
