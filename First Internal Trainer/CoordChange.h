#pragma once
#include "pch.h"

struct Coordinates 
{
	float X;
	float Y;
	float Z;
};

void SetCoordinates(Coordinates Values);

float ReturnXvalue();
float ReturnYvalue();
float ReturnZvalue();