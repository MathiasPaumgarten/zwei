#include "Stage.h"

void zwei::Stage::draw() {
    cinder::gl::clear( backgroundColor );
    zwei::Container::draw();
}

bool zwei::Stage::findMouseEventTarget( zwei::MouseEvent::Type type, cinder::app::MouseEvent event ) {
    return zwei::Container::findMouseEventTarget( zwei::MouseEvent( &event, type ) );
}