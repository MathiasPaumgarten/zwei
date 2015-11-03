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

void zwei::Container::draw( const zwei::RenderData renderData ) {
    cinder::gl::pushMatrices();
    cinder::gl::translate( position );
    cinder::gl::rotate( rotation );

	float opacity = renderData.getOpacity() * getOpacity();

    context.apply( opacity );

    renderData.update( getOpacity(), getScale() );

    for ( auto iterator = children.begin(); iterator != children.end(); ++iterator ) {
        ( *iterator )->draw( renderData );
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

    boundingBox += context.getBoundingBox();

    return boundingBox;
}

bool zwei::Container::findMouseEventTarget( zwei::MouseEvent event ) {

    adjustEvent( event );

    for( auto it = children.begin(); it != children.end(); it++ ) {

        if ( ( *it )->getMouseEnabled() && ( *it )->findMouseEventTarget( event ) ) return true;

    }

    if ( context.getBoundingBox().contains( event.getPostion() ) ) {
        callEvent( event );
        return true;
    }

    return false;
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