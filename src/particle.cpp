#include "particle.h"


particle::particle(){
	pos.set(ofRandomWidth(),ofRandomHeight());
	dir.set(ofRandom(-1,1),ofRandom(-1,1));

	heading = floor(ofRandom(16));
	depositAmt = 170;
	maxSpeed = 5.5;
	senseDist = 6.2;
}

void particle::deposit(ofPixels &trailMap){
	float intensity = trailMap.getColor(pos.x,pos.y).r;
	ofColor c = ofColor(intensity + depositAmt);
	trailMap.setColor(pos.x,pos.y,c);
}

void particle::sense(ofPixels &trailMap){
	float nextIntensity = 0;
	float maxIntensity = 0;
	float maxHeading = 0;
	for(int i = -1; i<2; i++){
		float look = heading + i;
		float angle = look*22.5;
		ofVec2f offset = ofVec2f(1,0).getRotated(angle);
		offset.scale(senseDist);

		int currentX, currentY;
		currentX = pos.x + offset.y;
		currentY = pos.x + offset.y;

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
	wrap();
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