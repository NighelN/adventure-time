#ifndef TextHandler
#define TextHandler

#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

void handleOutput(string message, bool newLine);
void slowText(string message, int speed);

#endif