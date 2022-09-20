#include "pch.h"
#include "TextHandler.h"

void handleOutput(string message, bool newLine)
{
	cout << message + (newLine ? "\n\n" : "");
}

void slowText(string message, int speed)
{
	//Loops though all characters from the message
	for (int index = 0; index < message.length(); index++) {
		//Outputs the char from the index
		cout << message[index];
		//Tells the thread to sleep for 'speed' ms;
		Sleep(speed);
		//If its the last last character end the line
		if (index == message.length() - 1)
			cout << endl;
	}
}
