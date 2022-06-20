/*The program includes a file named demo.txt
in the working directory for testing purposes.
Other .txt files may be used if desired.
Output files are saved to the working directory.*/

//Date Created: 20 Jun 2022
//Author: Kyle Noel

#define WINDOWS

#include <iostream>
#include <string>
#include <cctype>
#include "FProc.h"
#include "Decrypt.h"
#include "Encrypt.h"
#include "Plain.h"

using namespace std;

//Global vars
const char HEADER[65] = "-------------------  SIMPLE ENCRYPT/DECRYPT  -------------------";
const char FOOTER[65] = "-------------------   PROGRAM   TERMINATED   -------------------";
//Prototypes
void menuSystem();
void clearConsole();

int main()
{
	char rerun;

	//Run with option to rerun
	do {
		menuSystem();

		cout << endl << "Would you like to run the program again? Y/N:  ";
		cin >> rerun;
		rerun = toupper(rerun);
	} while (rerun == 'Y');
	cout << endl << FOOTER << endl;

	return 0;
}

void menuSystem()
{
	string inName,
		outName;
	char contents;
	int key = 0,
		choice;
	bool flag = false;

	clearConsole();
	cout << HEADER << endl;
	cout << "Demo file name: demo.txt" << endl << endl;

	//User file name input
	cout << "Enter the name of the file to be processed:  ";
	cin >> inName;
	cout << "Enter the name of the output file (ex: anything.txt):  ";
	cin >> outName;
	cout << endl;

	//Menu
	cout << "What would you like to do with this file?" << endl;
	cout << "1. Encrypt" << endl;
	cout << "2. Decrypt" << endl;
	cout << "3. Output as is" << endl;
	cout << ">> ";
	cin >> choice;

	do {
		switch (choice) {
		case 1:
		{
			//Gathering encryption key input
			cout << "Enter an encrpytion key to encrypt the file:  ";
			cin >> key;
			cout << "You have entered the following encryption key:  " << key << endl;
			cout << "Remember this key for decrypting \'" << outName << "\' in the future." << endl;
			cout << endl;
			//Creating Encrypt object
			Encrypt scramble(inName, outName, key);
			//Processing
			scramble.process();
			flag = false;
			break;
		}
		case 2:
		{
			//Gathering encryption key input
			cout << "Enter the key used to encrypt this file:  ";
			cin >> key;
			cout << "You have entered the following encryption key:  " << key << endl;
			cout << endl;
			//Creating Decrypt object
			Decrypt unscramble(inName, outName, key);
			//Processing
			unscramble.process();
			flag = false;
			break;
		}
		case 3:
		{
			//Creating Plain object
			Plain asIs(inName, outName);
			//Processing
			asIs.process();
			flag = false;
			break;
		}
		default:
		{
			cout << "Invalid input. Try again." << endl;
			cout << ">> ";
			cin >> choice;
			flag = true;
		}
		}
	} while (flag == true);

	//Display output contents to console
	cout << "Would you like to view the contents of the output file? Y/N:  ";
	cin >> contents;
	cout << endl;
	contents = toupper(contents);
	if (contents == 'Y')
	{
		fstream output(outName);
		if (output.is_open())
			cout << output.rdbuf() << endl;
		cout << endl << "End of file contents..." << endl << "SESSION TERMINATED" << endl;
	}
	else
		cout << endl << "SESSION TERMINATED" << endl;
}

void clearConsole()
{
#ifdef WINDOWS
	system("cls");
#endif
#ifdef LINUX
	system("clear")
#endif
}