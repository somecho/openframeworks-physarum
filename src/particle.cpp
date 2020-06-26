#include "particle.h"


particle::particle(){
	pos.set(ofRandomWidth(),ofRandomHeight());

	heading = floor(ofRandom(numDirs));
	depositAmt = 170;
	maxSpeed = 7.8;
	senseDist = 9.2;
}

void particle::deposit(ofPixels &trailMap){
	float intensity = trailMap.getColor(pos.x,pos.y).r;
	intensity += depositAmt; 
	intensity = ofClamp(intensity,0,255);
	ofColor c = ofColor(intensity,255);
	trailMap.setColor(pos.x,pos.y,c);
}

void particle::sense(ofPixels &trailMap){
	float nextIntensity = 0;
	float maxIntensity = 0;
	float maxHeading = 0;
	for(int i = -1; i<2; i++){
		float look = heading + i;
		float angle = look* (360./ numDirs);
		//ofVec2f offset = ofVec2f(0,1).getRotated(angle);
		ofVec2f offset = ofVec2f(cos(angle),sin(angle));
		offset.scale(senseDist);

		int currentX, currentY;
		currentX = pos.x + offset.x;
		currentY = pos.y + offset.y;

		if(currentX > ofGetWidth()){
			currentX = 0;
		} else if (currentX < 0){
			currentX = ofGetWidth();
		}

		if(currentY > ofGetHeight()){
			currentY = 0;
		} else if (currentY < 0){
			currentY = ofGetHeight();
		}

		nextIntensity = trailMap.getColor(currentX,currentY).r;
	

		if(maxIntensity < nextIntensity){
			maxIntensity = nextIntensity;
			dir.x = offset.x;
			dir.y = offset.y;
			dir.scale(maxSpeed);
			maxHeading = i;
		}
	}

	heading += maxHeading;

}

void particle::move(){
	pos += dir;
	//wrap();
	reset();
}

void particle::wrap(){
	if(pos.x > ofGetWidth())
		pos.x = 0;

	if(pos.x < 0)
		pos.x = ofGetWidth();

	if(pos.y > ofGetHeight())
		pos.y = 0;

	if(pos.y < 0)
		pos.y = ofGetHeight();
}

void particle::reset(){
	if(pos.x > ofGetWidth() || pos.x < 0) pos.x = ofRandomWidth();

	if(pos.y > ofGetWidth() || pos.y < 0) pos.y = ofRandomHeight();
}

void particle::setMaxSpeed(float n){
	maxSpeed = n;
}
void particle::setSenseDist(float n){
	senseDist = n;
}
void particle::setDepositAmt(float n){
	depositAmt = n;
}

void particle::setNumDirs(int n){
	numDirs = n;
}