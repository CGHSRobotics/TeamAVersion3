#pragma once

#include "vex.h"
#include "util.h"
#include "userMovement.cpp"

float filterAxis(float input);
void checkAxis();

void intakeForwardAsync();
void intakeReverseAsync();

void launchDisksAsync();

void triggerEndgameAsync();

void rollerForwardAsync();
void rollerReverseAsync();

void conveyorForwardAsync();
void conveyorReverseAsync();