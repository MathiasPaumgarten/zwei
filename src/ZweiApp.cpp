#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Foo.h"
#include "Bar.h"
#include "Stage.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ZweiApp : public App {
  public:
	void setup() override;
    void update() override;
	void draw() override;

    Foo* view;
    Bar* viewB;
    zwei::Container* container;
};

void ZweiApp::setup() {
    zwei::Stage& stage = zwei::Stage::getStage();

    view = new Foo();
    viewB = new Bar();

    view->position += 50;
    viewB->position += 100;

    stage.addView( view );
    stage.addView( viewB );
}

void ZweiApp::update() {
    
    zwei::View::tick();
}

void ZweiApp::draw() {
    zwei::Stage::getStage().tick();
}

CINDER_APP( ZweiApp, RendererGl )
