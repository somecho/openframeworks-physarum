#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings setting;
	setting.resizable = false;
	setting.setSize(1024,720);
	ofCreateWindow(setting);

	ofRunApp(new ofApp());

}
