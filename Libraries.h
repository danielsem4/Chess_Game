#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>


// Operators
_COORD operator+(_COORD ia, _COORD ib);
bool operator==(_COORD ia, _COORD ib);
_COORD operator*(_COORD ia, int ib);
// Board 
COORD ConvLoc(COORD iloc, double);
COORD ReConvLoc(COORD iloc, double);
bool validLoc(COORD);
void GetDesktopResolution(double&, double&, double&, double&);
