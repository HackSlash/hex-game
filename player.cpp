#include <iostream>
#include <string>
#include "player.h"

using namespace std;

namespace Player{

	pair<int, int> getPlayerMove(){
		int arg = 0;
		int x, y;
		while(true) {
			if (arg == 0) {
				cout << "Enter move coordinate X: ";
				cin >> x;
			} else if (arg == 1) {
				cout << "Enter move coordinate Y: ";
				cin >> y;
			} else break;

			if (cin.fail()) {
				cout << "Please enter a legit number." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			} else arg++;
		}
		return pair<int, int>(x, y);
	}

	bool goesFirst(){
		string answer;
		while(true) {
			cout << "Who makes the first move? (Player, CPU, or Random: ";
				cin >> answer;
				answer = answer.substr(0,1);
				if (answer == "P" || answer == "p") return true;
				if (answer == "C" || answer == "c") return false;
				if (answer == "R" || answer == "r") return (rand() % 2);
				cout << "Invalid input, please type: \"Player\", \"CPU\", or \"Random\"." << endl;
		}
	}
}