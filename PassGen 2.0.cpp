#include <iostream>
#include <ctime>
using namespace std;

int passwordSize;

string vowelsLowercase[5] = { "a", "e", "i", "o", "u" };
string vowelsUppercase[5] = { "A", "E", "I", "O", "U", };

string consonantsLowercase[19] = { "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "x", "z" };
string consonantsUppercase[19] = { "B", "C", "D", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "V","X", "Z" };

string easySpecials[5] = { "!", "@", "#", "?", "&" };
string allSpecials[32] = { "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", "-", "=", "[", "]", "{", "}", "\\", "|", "`", "~", "/", "?", ".", ",", "'", "\"", ";", ":", ">", "<" };

string numbers[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

void easyToRememberPasswordsGenerator() {
	srand(time(0)); //true random number generation

	string password = "";

	int passwordLengthFilled = 0;

	while (passwordLengthFilled != passwordSize - 2) //checking if we already have the length of the numbers we want
	{
		password += consonantsLowercase[rand() % 19];
		passwordLengthFilled++;

		if (passwordLengthFilled != passwordSize - 2) //checking here as well because if the password length is filled in the previous line, the password += vowelsLoercase... will be executed as well and we don't want that.
		{
			password += vowelsLowercase[rand() % 5];
			passwordLengthFilled++;
		}

	}

	password += easySpecials[rand() % 5];
	password += numbers[rand() % 10];

	for (int i = 0; i < passwordSize; i++) {
		cout << "-"; //just for the effect
	}

	cout << endl << password << endl;

	for (int i = 0; i < passwordSize; i++) {
		cout << "-"; //just for the effect
	}
	cout << endl << endl;
}

void randomPasswordGenerator() {
	srand(time(0)); //true random number generation
	string password = "";

	int passwordLengthFilled = 0;
	while (passwordLengthFilled != passwordSize) {

		int chooseRandomCharacter = rand() % 4 + 1; //1 -4 | choosing if the next character printed to the password is going to be vowel, consonant, special or number.

		if (chooseRandomCharacter == 1) {
			bool randomPicker_VowelUpper = rand() % 2; //choosing randomly between vowelsUppercase and vowelsLowercase
			if (randomPicker_VowelUpper) {
				password += vowelsUppercase[rand() % 5]; // in this case uppercase

			}
			else {
				password += vowelsLowercase[rand() % 5]; //in this case lowercase
			}
			passwordLengthFilled++;

		}
		else if (chooseRandomCharacter == 2) {
			bool randomPicker_consonantsUpper = rand() % 2;
			if (randomPicker_consonantsUpper) {
				password += consonantsUppercase[rand() % 19];

			}
			else {
				password += consonantsLowercase[rand() % 19];
			}
			passwordLengthFilled++;

		}
		else if (chooseRandomCharacter == 3) {
			password += allSpecials[rand() % 32];
			passwordLengthFilled++;
		}
		else if (chooseRandomCharacter == 4) {
			password += numbers[rand() % 10];
			passwordLengthFilled++;
		}
	}

	for (int i = 0; i < passwordSize; i++) {
		cout << "-"; //just for the effect
	}

	cout << endl << password << endl;

	for (int i = 0; i < passwordSize; i++) {
		cout << "-"; //just for the effect
	}
	cout << endl << endl;
}

int main() {
	srand(time(0)); //true random number generation

	cout << "Welcome to PassGen 2.0!" << endl << endl;

	bool canContinue = true;

	while (true) {
		cout << "(1) Generate easy-to-remember password (weak)" << endl << "(2) Generate actually random password (strong)" << endl << "(3) Exit" << endl << endl;

		int typeOfPasswordChoice = 0;
		cin >> typeOfPasswordChoice;

		if (typeOfPasswordChoice == 3) {
			return 0;
		}

		if (typeOfPasswordChoice >= 1 && typeOfPasswordChoice <= 2) { //if choice is valid, do this, else restart program...

			cout << "Select password size: ";
			cin >> passwordSize;
			cout << endl;

			if (typeOfPasswordChoice == 1) {

				easyToRememberPasswordsGenerator();

			}
			else if (typeOfPasswordChoice == 2) {

				randomPasswordGenerator();

			}
		}
	}
}
