#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

class GravelerSoftLockPick {
public:
	GravelerSoftLockPick();
	~GravelerSoftLockPick();
	void update(int ones);
	int getRolls() const;
	int getOnes() const;

private:
	int rolls;
	int maxOnes;
};

GravelerSoftLockPick::GravelerSoftLockPick() {  //constructor
	rolls = 0;
	maxOnes = 0;
}

GravelerSoftLockPick::~GravelerSoftLockPick(){}  //destructor

void GravelerSoftLockPick::update(int ones) {  //updates counts
	if (ones > maxOnes) {  //updates if # of ones is bigger
		maxOnes = ones;
	}

	rolls++;
}

int GravelerSoftLockPick::getRolls() const {
	return rolls;
}

int GravelerSoftLockPick::getOnes() const {
	return maxOnes;
}