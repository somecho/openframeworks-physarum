#pragma once

#include "ofMain.h"


class particle{
public:
	ofVec2f pos;
	ofVec2f dir;

	float heading;
	float maxSpeed;
	float depositAmt;
	float senseDist;

	particle();
	void deposit(ofPixels &trailMap);
	void sense(ofPixels &trailMap);
	void move();
	void wrap();


};