#include "Stage.h"
#include "cinder/gl/Context.h"

void zwei::Stage::draw() {
    cinder::gl::clear( backgroundColor );
    zwei::Container::draw();
}

void zwei::Stage::handleMouseEvent( cinder::app::MouseEvent event ) {
    zwei::Container::handleMouseEvent( zwei::MouseEvent( &event ) );
}