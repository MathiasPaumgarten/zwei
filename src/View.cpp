//
//  View.cpp
//  Zwei
//
//  Created by roboshoes on 8/18/15.
//
//

#include "View.h"

std::list<zwei::View*> zwei::View::views;

void zwei::View::draw() {
    cinder::gl::pushMatrices();
    cinder::gl::translate( position );
    cinder::gl::rotate( rotation );

    context.apply();

    cinder::gl::popMatrices();
}

void zwei::View::update() {}

void zwei::View::start( zwei::View* view ) {
    zwei::View::views.push_back( view );
}

void zwei::View::stop( zwei::View* view ) {
    zwei::View::views.remove( view );
}

void zwei::View::tick() {
    for ( auto iterator = views.begin(); iterator != views.end(); ++iterator ) {
        (*iterator)->update();
    }
}
