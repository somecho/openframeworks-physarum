#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	trailmap.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);
	pixBuffer.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_GRAYSCALE);
	texBuffer.allocate(pixBuffer);

	shader.load("shader");



}

//--------------------------------------------------------------
void ofApp::update(){	

	for(int i = 0; i < numParticles; i++){
		p[i].sense(pixBuffer);
		p[i].move();
		p[i].deposit(pixBuffer);
	}

	texBuffer.loadData(pixBuffer);


	trailmap.begin();
	shader.begin();
	shader.setUniformTexture("tex",texBuffer,0);
	texBuffer.draw(0,0);
	shader.end();
	trailmap.end();

	trailmap.readToPixels(pixBuffer);
}

//--------------------------------------------------------------
void ofApp::draw(){

	trailmap.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofColor c = ofColor(255);
	pixBuffer.setColor(x,y,c);
}