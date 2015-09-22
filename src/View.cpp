#include "View.h"

float zwei::View::getWidth() const {
    auto boundingBox = context.getBoundingBox();

    if ( boundingBox.getX() > 0 ) {
        return boundingBox.getX() + boundingBox.getWidth();
    } else if ( boundingBox.getX() + boundingBox.getWidth() < 0.0f ) {
        return std::abs( boundingBox.getX() );
    }

    return boundingBox.getWidth();
}

float zwei::View::getHeight() const {
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

bool zwei::View::findMouseEventTarget( zwei::MouseEvent event ) {
    adjustEvent( event );

    if ( ! getBoundingBox().contains( event.getPostion() ) ) return false;

    callEvent( event );

    return true;
}

void zwei::View::callEvent( zwei::MouseEvent& event ) {
    event.setTarget( this );

    switch ( event.getType() ) {
        case zwei::MouseEvent::DOWN:
            mouseDownSignal( event );
            break;
        case zwei::MouseEvent::UP:
            mouseUpSignal( event );
            break;
        case zwei::MouseEvent::MOVE:
            mouseMoveSignal( event );
            break;
    }

    if ( event.getBubbling() && _parent != nullptr ) {
        ( (zwei::View*) _parent )->callEvent( event );
    }
}

zwei::Container* zwei::View::getParent() const {
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

void zwei::View::adjustEvent( zwei::MouseEvent &event ) const {
    cinder::mat3 transform{ 1 };

    transform = glm::rotate( transform, rotation * -1.f );
    transform = glm::translate( transform, position * -1.f );

    event.transform( transform );
}

std::list<zwei::View*> zwei::View::views;

void zwei::View::start( zwei::View* view ) {
    zwei::View::views.push_back( view );
}

void zwei::View::stop( zwei::View* view ) {
    zwei::View::views.remove( view );
}

