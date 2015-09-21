#include <math.h>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Bar.h"
#include "Stage.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ZweiApp : public App {
  public:
    void setup() override;
    void update() override;

    virtual void start() {};
    void draw() override;

    void mouseDown( MouseEvent event ) override;
    void mouseUp( MouseEvent event ) override;
    void mouseMove( MouseEvent event ) override;

    zwei::Stage& stage = zwei::Stage::getStage();
};

void ZweiApp::setup() {
    start();
}

void ZweiApp::update() {
    zwei::View::tick();
}

void ZweiApp::draw() {
    stage.draw();
}

void ZweiApp::mouseDown( MouseEvent event ) {
    stage.findMouseEventTarget( zwei::MouseEvent::Type::DOWN, event );
}

void ZweiApp::mouseUp( MouseEvent event ) {
    stage.findMouseEventTarget( zwei::MouseEvent::Type::UP, event );
}

void ZweiApp::mouseMove( MouseEvent event ) {
    stage.findMouseEventTarget( zwei::MouseEvent::Type::MOVE, event );
}


class MyApp : public ZweiApp {

    Bar* bar;

  public:
    void start() override {

        bar = new Bar();

        bar->position += vec2( 200, 50 );
        bar->rotation += M_PI / 4;

        stage.addView( bar );
    }
};

CINDER_APP( MyApp, RendererGl )