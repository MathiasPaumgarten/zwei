#include "BoundingBox.h"

zwei::BoundingBox& zwei::BoundingBox::operator+=( const BoundingBox& other ) {

    if ( other.getX() < position.x ) {

        position.x = other.getX();
        size.x = std::max( position.x + other.getX() - position.x, position.x + size.x - position.x );

    } else if ( other.getX() >= position.x ) {

        if ( other.getX() + other.getSize().x > position.x + size.x ) {
            size.x = other.getX() + other.getSize().x - position.x;
        }

    }

    if ( other.getY() < position.y ) {

        position.y = other.getY();
        size.y = std::max( position.y + other.getY() - position.y, position.y + size.y - position.y );

    } else if ( other.getY() >= position.y ) {

        if ( other.getY() + other.getSize().y > position.y + size.y ) {
            size.y = other.getY() + other.getSize().y - position.y;
        }

    }

    return *this;
}

zwei::BoundingBox zwei::BoundingBox::makeFromPoints( cinder::vec2 a, cinder::vec2 b ) {

    cinder::vec2 min = glm::min( a, b );
    cinder::vec2 max = glm::max( a, b );

    cinder::vec2 size = glm::abs( max - min );

    return zwei::BoundingBox( min, size );

}

void zwei::BoundingBox::offset( cinder::vec2 transform ) {
    position += transform;
}

bool zwei::BoundingBox::contains( const cinder::vec2& point ) const {

    auto withinLowerBound = glm::greaterThanEqual( point, position );
    auto withinUpperBound = glm::lessThanEqual( point, position + size );

    return glm::all( withinLowerBound ) && glm::all( withinUpperBound );
}