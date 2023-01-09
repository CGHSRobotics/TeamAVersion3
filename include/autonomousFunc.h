#pragma once

#include "util.h"
#include "autonomousFunc.cpp"

void autoDriveDistance(float distance, float velocity, string distanceType);
void autoDriveTime(float time, float velocity);
void autoTurnXDegrees(float angle);

void autoSpinRollerTime(float time);