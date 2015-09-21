#include "MouseEvent.h"

void zwei::MouseEvent::stopPropagation() {
    isBubbling = false;
}

void zwei::MouseEvent::stopImmediatePropagation() {
    isActive = false;
    isBubbling = false;
}