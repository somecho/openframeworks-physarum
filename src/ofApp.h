#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
		void keyPressed(int key);

		ofShader shader;
		ofFbo trailmap;
		ofPixels pixBuffer;
		ofTexture texBuffer; 
		bool showGui = true;

		static const int numParticles = 50000;
		particle p[numParticles];

		ofxPanel gui;
		ofxFloatSlider depositAmt;
		ofxFloatSlider maxSpeed;
		ofxFloatSlider senseDist;
		ofxFloatSlider decayRate;
		ofxIntSlider numDirs;

		


		
};
