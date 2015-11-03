#ifndef ____RenderData__
#define ____RenderData__

#include <stdio.h>
#include "cinder/gl/gl.h"

namespace zwei {

    class RenderData {

      public:
        RenderData() {}

        float getOpacity() const { return opacity; }

        float getScaleX() const { return scale.x; }
        float getScaleY() const { return scale.y; }
        cinder::vec2 getScale() const { return scale; }

        void update( float o, cinder::vec2 s ) {
            opacity *= o;
            scale *= s;
        }

      private:
        float opacity = 1.0f;
        cinder::vec2 scale;

    };

}

#endif /* defined(____RenderData__) */
