#ifndef __Zwei__Context__
#define __Zwei__Context__

#include <stdio.h>
#include "BoundingBox.h"

namespace zwei {

    class Command {

      public:
        enum CommandType {
            DRAW_LINE,
            DRAW_RECT,
            DRAW_CIRCLE,
            SET_COLOR
        };

        Command( CommandType t, std::vector<float> args ) : type( t ), arguments( args ) {}

        const CommandType getName() const { return type; }
        const std::vector<float>& getArguments() const {
            return arguments;
        }

      private:
        const CommandType type;
        const std::vector<float> arguments;
    };

    class Context {

      public:
        Context() {};

        Context& setColor( cinder::Color color );
        Context& drawLine( cinder::vec2 start, cinder::vec2 end );
        Context& drawRect( cinder::vec2 position, cinder::vec2 size );
        Context& drawCircle( cinder::vec2 center, float radius );

        const zwei::BoundingBox& getBoundingBox() { return boundingBox; };

        void apply() const;

      private:

        std::vector<Command> commands;

        zwei::BoundingBox boundingBox;
    };

}

#endif /* defined(__Zwei__Context__) */
