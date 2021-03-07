#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	trailmap.allocate(ofGetWidth(),ofGetHeight(),GL_RGB);
	pixBuffer.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_GRAYSCALE);
	texBuffer.allocate(ofGetWidth(),ofGetHeight(),GL_RGB);

	shader.load("shader");

	gui.setup();
	gui.add(numDirs.setup("Number of Directions", 26, 1, 64));
	gui.add(depositAmt.setup("Deposit Amount",170,0,255));
	gui.add(maxSpeed.setup("Max Speed",7.8,0,10));
	gui.add(decayRate.setup("Decay Rate",0.6,0.,1.));
	gui.add(senseDist.setup("Sense Distance",9.,0.,200.));

}

//--------------------------------------------------------------
void ofApp::update(){	
;

	for(int i = 0; i < numParticles; i++){
		p[i].setMaxSpeed(maxSpeed);
		p[i].setNumDirs(numDirs);
		p[i].setSenseDist(senseDist);
		p[i].setDepositAmt(depositAmt);
		p[i].sense(pixBuffer);
		p[i].move();
		p[i].deposit(pixBuffer);
	}

	texBuffer.loadData(pixBuffer);


	trailmap.begin();
	shader.begin();
	shader.setUniformTexture("tex",texBuffer,0);
	shader.setUniform1f("dR", decayRate);
	texBuffer.draw(0,0);
	shader.end();
	trailmap.end();

	trailmap.readToPixels(pixBuffer);
}

//--------------------------------------------------------------
void ofApp::draw(){

	trailmap.draw(0,0);

	ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
	if(showGui) gui.draw();


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofColor c = ofColor(255);
	pixBuffer.setColor(x,y,c);

	//ofSaveScreen("screenshot" + ofToString(ofGetFrameNum()) + ".png");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'g') showGui = !showGui;
}
