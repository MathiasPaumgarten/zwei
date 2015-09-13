//
//  Container.cpp
//  Zwei
//
//  Created by roboshoes on 8/18/15.
//
//

#include "Container.h"

zwei::ViewRef zwei::Container::removeView( zwei::ViewRef view ) {
    children.remove( view );

    return view;
}

void zwei::Container::addView( zwei::ViewRef view) {
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