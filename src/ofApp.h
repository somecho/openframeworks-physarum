#pragma once

#include "ofMain.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);

		ofShader shader;
		ofFbo trailmap;
		ofPixels pixBuffer;
		ofTexture texBuffer; 

		static const int numParticles = 15000;
		particle p[numParticles];

		


		
};
