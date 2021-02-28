#include <iostream>
#include <jni.h>
#include <fstream>		// RW to file
#include <vector>		// Add vectors
#include <string>		// Validate strings
#include "Animal.h"		// Temp pointers
#include "Bat.h"		// For creating instance
#include "Crocodile.h"	// For creating instance
#include "Goose.h"		// For creating instance
#include "Pelican.h"	// For creating instance
#include "SeaLion.h"	// For creating instance
#include "Whale.h"		// For creating instance
using namespace std;

vector<Animal*> g_list;	// Global vector for loading/saving data and add/delete functions

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal() {
	int tracker = -1;				// Animal class variable
	int eggs = -1;					// Oviparous class variable
	int nurse = -1;					// Mammal class variable
	unsigned int i;					// Loop index
	string name = "";				// Animal class variable
	string type = "";				// Determine if mammal or oviparous
	string subType = "";			// Determine what type of instance to create
	string saveCancel = "";			// Save or cancel entry
	//Animal* tempAnimal = nullptr;	// Temp object for checking duplicate tracker#
	bool isGood = false;			// Loop condition

	// Enter tracker number
	while (!isGood) {
		cout << "Tracker#: " << endl;
		cin >> tracker;

		// Validate input
		while (cin.fail() || tracker < 0 || tracker > 999999) {
			// Enter positive number smaller than six digits
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please pick a number between 0 and 999999" << endl;
			cin >> tracker;
		}

		if (g_list.empty()) {
			// Skip checking if vector is empty
			isGood = true;
			continue;
		}
		// Check for duplicates in list
		for (i = 0; i < g_list.size(); ++i) {
			if (tracker == g_list.at(i)->trackNum) {
				cout << "Tracker# already taken" << endl;
				tracker = -1;
				isGood = false;
				break;
			}
			else {
				// Exit main loop if IF statement does not execute
				isGood = true;
			}
		}
	}

	// Enter animal name
	cout << "Name: " << endl;
	cin >> name;
	while (name.size() > 15 || name.empty()) {
		// Validate something is entered and 15 or less characters
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please use less than 15 characters" << endl;
		cin >> name;
	}

	// Enter animal type
	cout << "Type: " << endl;
	while (type.empty()) {
		cin >> type;
		if (type == "Mammal") {
			break;
		}
		else if (type == "Oviparous") {
			break;
		}
		else {
			// Invalid input
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Enter \"Mammal\" or \"Oviparous\": " << endl;
			type = "";
		}
	}

	// Enter sub-type
	if (type == "Mammal") {
		// Enter mammal sub-type
		cout << "Sub-type: " << endl;
		while (subType.empty()) {
			cin >> subType;
			if (subType == "Bat") {
				break;
			}
			else if (subType == "Whale") {
				break;
			}
			else if (subType == "SeaLion") {
				break;
			}
			else {
				// Invalid input
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Enter \"Bat,\" \"Whale,\" or \"SeaLion\"" << endl;
				subType = "";
			}
		}

		cout << "Nurse: " << endl;
		while (nurse == -1) {
			// Ensure 0 or 1 is entered
			cin.clear();
			cin.ignore(100, '\n');
			cin >> nurse;
			if (cin.fail()) {
				// Non-number entered
				cout << "Enter 0 for no or 1 for yes: " << endl;
				nurse = -1;
				continue;
			}
			else if (nurse == 0) {
				// Success
				break;
			}
			else if (nurse == 1) {
				// Success
				break;
			}
			else {
				// Incorrect selection
				nurse = -1;
				cout << "Enter 0 for no or 1 for yes: " << endl;
			}
		}
	}
	else {
		// Enter oviparous sub-type
		cout << "Sub-type: " << endl;

		while (subType.empty()) {
			cin >> subType;
			if (subType == "Crocodile") {
				break;
			}
			else if (subType == "Goose") {
				break;
			}
			else if (subType == "Pelican") {
				break;
			}
			else {
				// Invalid entry
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Enter \"Crocodile,\" \"Goose,\" or \"Pelican\": " << endl;
				subType = "";
			}
		}

		cout << "Eggs: " << endl;
		while (eggs < 0) {
			// Ensure 0 or greater is entered
			cin.clear();
			cin.ignore(100, '\n');
			cin >> eggs;

			if (cin.fail()) {
				// Non-number entry
				cout << "Enter a number greater than 0: " << endl;
				eggs = -1;
			}
			else if (eggs >= 0) {
				// Success
				break;
			}
			else {
				// Negative number
				cout << "Enter a number greater than 0: " << endl;
			}
		}
	}

	// Cancel entry or create instance and append to g_list
	cout << "Save? (y/n): " << endl;
	while (saveCancel.empty()) {
		// Validate input
		cin >> saveCancel;
		if (saveCancel == "y") {
			break;
		}
		else if (saveCancel == "n") {
			break;
		}
		else {
			// Invalid input
			cin.clear();
			cin.ignore(100, '\n');
			cout << "y for save or n for cancel: " << endl;
			saveCancel = "";
		}
	}

	if (saveCancel == "y") {
		// Create instance with user inputs and append to g_list
		if (subType == "Bat") {
			Bat* tempBat = new Bat(tracker, name, nurse);
			g_list.emplace_back(tempBat);
			cout << "Bat added!" << endl;
		}
		else if (subType == "SeaLion") {
			SeaLion* tempSeaLion = new SeaLion(tracker, name, nurse);
			g_list.emplace_back(tempSeaLion);
			cout << "SeaLion added!" << endl;
		}
		else if (subType == "Whale") {
			Whale* tempWhale = new Whale(tracker, name, nurse);
			g_list.emplace_back(tempWhale);
			cout << "Whale added!" << endl;
		}
		else if (subType == "Crocodile") {
			Crocodile* tempCroc = new Crocodile(tracker, name, eggs);
			g_list.emplace_back(tempCroc);
			cout << "Crocodile added!" << endl;
		}
		else if (subType == "Goose") {
			Goose* tempGoose = new Goose(tracker, name, eggs);
			g_list.emplace_back(tempGoose);
			cout << "Goose added!" << endl;
		}
		else if (subType == "Pelican") {
			Pelican* tempPelican = new Pelican(tracker, name, eggs);
			g_list.emplace_back(tempPelican);
			cout << "Pelican added!" << endl;
		}
		else {
			// Somehow incorrect sub-type
			cout << "Something went wrong." << endl;
		}

	}
	else {
		// Return to main menu without adding animal
		cout << "Animal not added. Returning to menu..." << endl;
	}
}

void RemoveAnimal() {
	int userSelect = 0;			// Select instance to delete
	unsigned int i;				// Loop index
	string userConfirm = "";	// Confirm delete
	bool confirmDelete = false;	// Loop condition
	bool trackerFound = false;	// Show error if not found

	if (g_list.empty()) {
		// Need to load list
		cout << "No data is loaded..." << endl;
	}
	else {
		// g_list is populated
		cout << "Enter tracker# to be deleted: " << endl;
		cin >> userSelect;
		while (cin.fail()) {
			// Non-int entered
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Enter a number" << endl;
			cin >> userSelect;
		}

		for (i = 0; i < g_list.size(); ++i) {
			// Find user selection
			if (userSelect == g_list.at(i)->trackNum) {
				trackerFound = true;
				while (!confirmDelete) {
					cout << "Delete " << g_list.at(i)->trackNum << "? (y/n): ";
					cin >> userConfirm;
					if (userConfirm == "y") {
						confirmDelete = true;
						g_list.erase(g_list.begin()+i);
						cout << "Animal successfully deleted" << endl;
					}
					else if (userConfirm == "n") {
						confirmDelete = true;
						cout << "Animal not deleted" << endl;
					}
					else {
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please select y or n." << endl;
					}
				}
			}
		}
		if (!trackerFound) {
			// Tracker does not exist. User load list and double check
			cout << "Tracker not found. Please check list..." << endl;
		}
	}
}

void LoadDataFromFile() {
	int tracker = -1;			// Animal class variable
	int eggs = -1;				// Oviparous class variable
	int nurse = -1;				// Mammal class variable
	unsigned int i;				// Loop index
	int j;						// Loop index
	string name = "";			// Animal class variable
	string type = "";			// Inferred from sub-type
	string subType = "";		// Determine what type of instance to create
	string currLine = "";		// Temp variable for vector elements
	string tempNum = "";		// Temp variable for casting tracker
	ifstream inFS;				// Input from file
	vector<string> printData;	// Stores data from file
	string subTypeCheck[6] = {"Crocodile", "Goose", "Pelican", "Bat", "Sealion", "Whale"};	// Validate sub-type
	bool validIn = false;		// Stop condition for bad input

	printData.resize(0);		// Reset if called multiple times

	inFS.open("zoodata.txt", ios::in);
	if (!inFS.is_open()) {
		cout << "Could not open file" << endl;
	}
	else {
		while (getline(inFS, currLine)) {
			printData.emplace_back(currLine);
		}
		cout << "Load complete" << endl;
	}
	inFS.close();
	// Iterate through list
	for (i = 0; i < printData.size(); ++i) {
		// Re-initialize variables for reuse
		name = "";
		type = "";
		subType = "";
		tempNum = "";
		tracker = -1;
		eggs = -1;
		nurse = -1;

		currLine = printData.at(i);
		// Check sub-type first
		for (j = 41; j < 58; ++j) {
			if (currLine.at(j) != ' ') {
				// Remove whitespace
				subType += currLine.at(j);
			}
		}

		for (j = 0; j < 6; ++j) {
			// Compare subType to list of expected entries
			if (subType == subTypeCheck[j]) {
				validIn = true;
				if (j < 3) {
					// First three elements are oviparous
					type = "Oviparous";
				} else {
					// Last three are mammals
					type = "Mammal";
				}
			}
		}
		if (!validIn) {
			// No valid sub-type found
			cout << " invalid sub-type \"" << subType << "\" at line ";
			cout << i + 1 << ". Skipping..." << endl;
			continue;
		}

		// Get tracker# from currLine
		for (j = 0; j < 8; ++j) {
			if (currLine.at(j) != 0) {
				// Ignore 0's
				tempNum += currLine.at(j);
			}
		}
		// Cast tempNum to int
		tracker = stoi(tempNum);
		if (tracker < 1 || tracker > 999999) {
			// Failed
			cout << "Invalid tracker# at line " << i + 1 << ". Skipping..." << endl;
			continue;
		}

		// Get name - automatically 15 character max
		for (j = 7; j < 24; ++j) {
			if (currLine.at(j) != ' ') {
				// Ignore whitespace
				name += currLine.at(j);
			}
		}

		if (type == "Mammal") {
			// Get last column in string
			tempNum = currLine.at(61);
			nurse = stoi(tempNum);
			if (nurse > 1 || nurse < 0) {
				// Needs to be 1 or 0
				cout << "Invalid nurse entry at line " << i + 1 << ". Skipping..." << endl;
				continue;
			}
		}
		if (type == "Oviparous") {
			// Get second to last column in string
			tempNum = currLine.at(59);
			eggs = stoi(tempNum);
			if (eggs < 0) {
				cout << "Invalid eggs entry at line " << i + 1 << ". Skipping..." << endl;
				continue;
			}
		}

		// Create instance and append to g_list with validated data
		if (subType == "Bat") {
			Bat* tempBat = new Bat(tracker, name, nurse);
			g_list.emplace_back(tempBat);
		}
		if (subType == "SeaLion") {
			SeaLion* tempSeaLion = new SeaLion(tracker, name, nurse);
			g_list.emplace_back(tempSeaLion);
		}
		if (subType == "Whale") {
			Whale* tempWhale = new Whale(tracker, name, nurse);
			g_list.emplace_back(tempWhale);
		}
		if (subType == "Crocodile") {
			Crocodile* tempCroc = new Crocodile(tracker, name, eggs);
			g_list.emplace_back(tempCroc);
		}
		if (subType == "Goose") {
			Goose* tempGoose = new Goose(tracker, name, eggs);
			g_list.emplace_back(tempGoose);
		}
		if (subType == "Pelican") {
			Pelican* tempPelican = new Pelican(tracker, name, eggs);
			g_list.emplace_back(tempPelican);
		}
	}
}

void SaveDataToFile() {
	unsigned int i;	// Loop index
	ofstream outFS;	// Write to file

	// Open and overwrite file
	outFS.open("zoodata.txt");
	if (!outFS.is_open()){
		// Could not open
		cout << "Could not open file" << endl;
	}
	else {
		// Save instances from g_list
		for (i = 0; i < g_list.size(); ++i) {
			g_list.at(i)->SaveData(outFS);
		}
		cout << "Save successfully completed" << endl;
	}

	outFS.close();
}

void DisplayMenu() {
	// Print main menu
	// "ZOO"
	cout << "*****************************" << endl;
	cout << "******____****____***____****" << endl;
	cout << "*****/_  /***/__ /**/__ /****" << endl;
	cout << "******/ /***//*//**//*//*****" << endl;
	cout << "*****/ /_**//_//**//_//******" << endl;
	cout << "****/___/*/___/**/___/*******" << endl;
	cout << "*****************************" << endl << endl;
	cout << "*******MAKE A SELECTION******" << endl;
	cout << "*1 - Load animal data       *" << endl;
	cout << "*2 - Generate data          *" << endl;
	cout << "*3 - Display animal data    *" << endl;
	cout << "*4 - Add record             *" << endl;
	cout << "*5 - Delete record          *" << endl;
	cout << "*6 - Save animal data       *" << endl;
	cout << "*7 - Quit                   *" << endl;
	cout << "*****************************" << endl;

}

int main() {
	char menuSelect;		// User selection from menu
	unsigned int i;			// Loop index
	bool quitMenu = false;	// Loop condition

	while (!quitMenu) {
		DisplayMenu();
		cin >> menuSelect;
		switch (menuSelect) {
		case '1':
			LoadDataFromFile();
			break;
		case '2':
			GenerateData();
			break;
		case '3':
			cout << "TRACK#|NAME           |TYPE           |";
			cout << "SUB-TYPE       |EGGS|NURSE" << endl;
			for (i = 0; i < g_list.size(); ++i) {
				g_list.at(i)->PrintData();
			}
			break;
		case '4':
			AddAnimal();
			break;
		case '5':
			RemoveAnimal();
			break;
		case '6':
			SaveDataToFile();
			break;
		case '7':
			quitMenu = true;
			break;
		default:
			// Invalid selection
			cout << "Please choose a number from the menu:" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> menuSelect;
		}
	}
	return 0;
}
