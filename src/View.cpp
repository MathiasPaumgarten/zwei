#include "View.h"


float zwei::View::getWidth() {
    auto boundingBox = context.getBoundingBox();

    if ( boundingBox.getX() > 0 ) {
        return boundingBox.getX() + boundingBox.getWidth();
    } else if ( boundingBox.getX() + boundingBox.getWidth() < 0.0f ) {
        return std::abs( boundingBox.getX() );
    }

    return boundingBox.getWidth();
}

float zwei::View::getHeight() {
    auto boundingBox = context.getBoundingBox();

    if ( boundingBox.getY() > 0 ) {
        return boundingBox.getY() + boundingBox.getHeight();
    } else if ( boundingBox.getY() + boundingBox.getHeight() < 0.0f ) {
        return std::abs( boundingBox.getY() );
    }

    return boundingBox.getHeight();
}

zwei::BoundingBox zwei::View::getBoundingBox() const {
    zwei::BoundingBox boundingBox = context.getBoundingBox();

    return boundingBox;
}

void zwei::View::draw() {
    cinder::gl::pushMatrices();
    cinder::gl::translate( position );
    cinder::gl::rotate( rotation );

    context.apply();

    cinder::gl::popMatrices();
}

void zwei::View::handleMouseEvent( zwei::MouseEvent event ) {
    adjustEvent( event );
}

zwei::Container* zwei::View::getParent() {
    return _parent;
}

void zwei::View::setParent( zwei::Container* parent ) {
    _parent = parent;
}

void zwei::View::tick() {
    for ( auto it = views.begin(); it != views.end(); ++it ) {
        ( *it )->update();
    }
}

void zwei::View::update() {}

void zwei::View::adjustEvent( zwei::MouseEvent &event ) {
    cinder::mat3 transform = glm::translate( cinder::mat3{ 1 }, position * -1.f );
    event.transform( transform );
}

std::list<zwei::View*> zwei::View::views;

void zwei::View::start( zwei::View* view ) {
    zwei::View::views.push_back( view );
}

void zwei::View::stop( zwei::View* view ) {
    zwei::View::views.remove( view );
}

