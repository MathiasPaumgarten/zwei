//
//  Stage.cpp
//  Zwei
//
//  Created by roboshoes on 8/28/15.
//
//

#include "Stage.h"

void zwei::Stage::tick() {
    cinder::gl::clear( backgroundColor );

    Container::draw();
}