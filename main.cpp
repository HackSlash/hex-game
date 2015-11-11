
#include <ctime>
#include <iostream>
#include <thread>
#include "game.h"
#include "player.h"

using namespace std;

/// Checks if the computer has a multi-core CPU.
bool benchmark() {
	unsigned int n = thread::hardware_concurrency();
	if (n <= 1)	{
		cout << "Single Core CPU Detected..." << endl;
		return false;
	} else {
		cout << "n Core CPU Detected..." << endl;
		return true
	}
}

/// Checks if the user wants the program to run multi-core.
bool multithreadChecker(int argc, const char *argv[]) {
	if (!benchmark) return false;
	if (argc == 2 && (argv[1] == "True" || argv[1] == "true")) 
		return true;
	if (argc == 2 && (argv[1] == "False" || argv[1] == "false")) 
		return false; 
	cerr << "Error: invalid system arguments" << endl;
	return false;
}


int main(int argc, const char *argv[]) {
	srand(time(0));// Randomizes the Randomizer.

	cout << "==-- Hex-game Simulator V0.5 [nogui] --=="// Label
	Game newGame(multithreadChecker);// Start the actuall game.

	return 0;
}