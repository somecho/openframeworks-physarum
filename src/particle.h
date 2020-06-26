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
	int numDirs = 32;

	particle();
	void deposit(ofPixels &trailMap);
	void sense(ofPixels &trailMap);
	void move();
	void wrap();
	void reset();

	void setMaxSpeed(float n);
	void setDepositAmt(float n);
	void setSenseDist(float n);
	void setNumDirs(int n);


};