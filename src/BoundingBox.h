#ifndef __Zwei__BoundingBox__
#define __Zwei__BoundingBox__

#include <stdio.h>

namespace zwei {
    class BoundingBox {
      public:
        BoundingBox() {}

        BoundingBox( float _x, float _y, float _width, float _height ) :
            position( _x, _y ),
            size( _width, _height ) {}

        BoundingBox( cinder::vec2 p, cinder::vec2 s ) :
            position( p ),
            size( s ) {}

        BoundingBox& operator+=( const BoundingBox& rhs);

        float getWidth() const              { return size.x; }
        float getHeight() const             { return size.y; }

        float getX() const                  { return position.x; }
        float getY() const                  { return position.y; }

        cinder::vec2 getPosition() const    { return position; }
        cinder::vec2 getSize() const        { return size; }

        static BoundingBox makeFromPoints( cinder::vec2 a, cinder::vec2 b );

        void offset( cinder::vec2 transform );

        bool contains( const cinder::vec2& point ) const;

        friend std::ostream& operator<<( std::ostream& stream, BoundingBox const & object ) {
            return stream << "x: " << object.position.x << " y: " << object.position.y << " width: " << object.size.x << " height: " << object.size.y;
        }

      private:
        cinder::vec2 position;
        cinder::vec2 size;
    };
}

#endif /* defined(__Zwei__BoundingBox__) */
