#include "Context.h"

using ContextRef = zwei::Context&;
using Command = zwei::Command;
using vectorf = std::vector<float>;

void zwei::Context::apply() const {
    cinder::gl::color( cinder::Color( 0, 0, 0 ) );

    for ( auto it = commands.begin(); it != commands.end(); ++it ) {
        const std::vector<float>& argsRef = it->getArguments();

        switch ( it->getName() ) {
            case Command::DRAW_LINE:
                cinder::gl::drawLine( cinder::vec2( argsRef[ 0 ], argsRef[ 1 ] ), cinder::vec2( argsRef[ 2 ], argsRef[ 3 ] ) );
                break;
            case Command::DRAW_RECT:
                cinder::gl::drawSolidRect( cinder::Rectf( argsRef[ 0 ], argsRef[ 1 ], argsRef[ 2 ], argsRef[ 3 ] ) );
                break;
            case Command::DRAW_CIRCLE:
                cinder::gl::drawSolidCircle(cinder::vec2( argsRef[ 0 ], argsRef[ 1 ] ), argsRef[ 2 ] );
                break;
        }
    }
}

ContextRef zwei::Context::drawLine( cinder::vec2 start, cinder::vec2 end ) {

    commands.push_back( Command( Command::DRAW_LINE, vectorf{ start.x, start.y, end.x, end.y } ) );

    return *this;
}

ContextRef zwei::Context::drawRect( cinder::vec2 position, cinder::vec2 size ) {

    commands.push_back( Command( Command::DRAW_RECT, vectorf{ position.x, position.y, size.x, size.y } ) );

    return *this;
}

ContextRef zwei::Context::drawCircle( cinder::vec2 circle, float radius ) {

    commands.push_back( Command( Command::DRAW_CIRCLE, vectorf{ circle.x, circle.y, radius } ) );

    return *this;
}