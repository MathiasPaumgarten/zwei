#include "Container.h"

using ViewPtr = zwei::View*;

ViewPtr zwei::Container::removeView( ViewPtr view ) {
    children.remove( view );
    view->setParent( nullptr );

    return view;
}

void zwei::Container::addView( ViewPtr view ) {

    // TODO: Make Exception classes.
    if ( view->getParent() != nullptr ) throw "View has different parent";

    view->setParent( this );

    children.push_back( view );
}

void zwei::Container::draw() {
    cinder::gl::pushMatrices();
    cinder::gl::translate( position );
    cinder::gl::rotate( rotation );

    context.apply();

    for ( auto iterator = children.begin(); iterator != children.end(); ++iterator ) {
        (*iterator)->draw();
    }

    cinder::gl::popMatrices();
}

zwei::BoundingBox zwei::Container::getBoundingBox() const {
    zwei::BoundingBox boundingBox;

    for( auto it = children.begin(); it != children.end(); it++ ) {

        BoundingBox b = ( *it )->getBoundingBox();
        b.offset( ( *it )->position );

        boundingBox += b;
    }

    return boundingBox;
}

void zwei::Container::handleMouseEvent( zwei::MouseEvent event ) {

    adjustEvent( event );

    cinder::vec2 point = event.getPostion();

    for( auto it = children.begin(); it != children.end(); it++ ) {

        BoundingBox childBoundingBox = ( *it )->getBoundingBox();
		
		( *it )->handleMouseEvent( event );

        /*cinder::mat3 transform{ 1 };

        transform = glm::translate( transform, ( *it )->position * -1.f );
        transform = glm::rotate( transform, ( *it )->rotation * -1.f );

        cinder::vec3 projectedPoint = cinder::vec3( point, 1 );
        cinder::vec2 usePoint( transform * projectedPoint );

        if ( childBoundingBox.contains( usePoint ) ) {
			( *it )->handleMouseEvent( event );
        }*/
    }
}

std::list<ViewPtr> zwei::Container::removeAllViews() {
    std::list<ViewPtr> cache = children;
    children.clear();

    return cache;
}

void zwei::Container::destroyAllViews() {

    for( auto it = children.begin(); it != children.end(); it++ ) {
        delete *it;
    }

    children.clear();
}