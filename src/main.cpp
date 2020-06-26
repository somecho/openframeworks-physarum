#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings setting;
	setting.resizable = false;
	setting.setSize(1024,720);
	setting.setGLVersion(2,1);
	ofCreateWindow(setting);

	ofRunApp(new ofApp());

}
