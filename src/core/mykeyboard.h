#include "display.h"
#include "globals.h"


String keyboard(String mytext, int maxSize = 76, String msg = "Type your message:");

bool checkNextPress();

bool checkPrevPress();

bool checkSelPress();

bool checkEscPress();


#ifdef CYD

bool updateTouch();

bool checkTouchedRegion(int xMin, int xMax);

void printTouchToSerial();

#endif
