/******************************************************
 * Style feedback by Lydia Tse:
 * - Missing descriptive header (see syllabus for an example)
 * - Use 2 blank lines only when separating functions
 * - Avoid having lines that go past 80 columns in length
 * - Don't use global variables
 ******************************************************/
#include <iostream>
#include <cctype>       // For the letter checking functions
#include <fstream>      // For file input
#include <iomanip>      // For setw
#include <cstdlib>      // For exit and abs
using namespace std;

// Global variables
int numberOfLinesToDisplay = 3;
ifstream inputFileStream;

int totalQuizTries = 0;
int totalQuizWins = 0;

// The function below reads and returns the number of lines in the text file.
int readNumberOfLines(string fileName)
{  
    ifstream inputFileStream;  // Declare the input file stream
    // Open input file and verify that file was found
    inputFileStream.open( fileName.c_str() );
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << fileName << "  Exiting..." << endl;
        exit( -1);
    }
    
    // Read the number on the first line of the input file, which indicates how many subsequent
    // lines there are in the file.
    int numberOfLinesInFile = 0;
    inputFileStream >> numberOfLinesInFile;
    inputFileStream.close();
    
    //cout<<numberOfLinesInFile;
    return numberOfLinesInFile; //Returns total number of lines in the text file.
}

//Function that asks the user for number of lines to be displayed.
void setNumberOfLines() {
    cout << "Enter the number of lines you want to display -> ";
    cin >> numberOfLinesToDisplay;
}


string getLineFromFile(string filename, int lineNumber) {
    
    // Open input file and verify that file was found
    inputFileStream.open( filename.c_str() );
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << filename << "  Exiting..." << endl;
        exit( -1);
    }
    
    string line; // initializing a local string variable "string"...
    for (int i = 1; i <= lineNumber; i++) {
        getline(inputFileStream, line);
    }
       
    while(line.length() == 0 || line[0] == '#' || line[0] == ' '){
        getline(inputFileStream, line);        
    }
    
    inputFileStream.close();
    return line;
}

//Function to set the random lines...
void getRandomLines (string name)
{
    int totalLines = readNumberOfLines(name);
    int randomLine;
    
    for (int i=0; i<numberOfLinesToDisplay; i++) {
                randomLine = rand() % totalLines ;
           // cout << randomLine << endl; // FIXME DELETE
        cout << getLineFromFile(name, randomLine) << endl;
    }
}
// Gives us the final score and hardcoded string if tries = 0
double Final(int tries, int wins){
    double score;
    if(tries == 0){
        score = 0;
    }else{
     score = (double)totalQuizWins / totalQuizTries * 100;}
    return score;
}
//Quiz process takes place here...
void Quiz() {
    int randomCandidateNumber = (rand() % 2) + 1;
    int userGuess;
    
    if (randomCandidateNumber == 1)
        getRandomLines("Trump.txt");
    else
        getRandomLines("Warren.txt");
    
    cout << "\nEnter 1 for Trump, 2 for Warren: ";
    cin >> userGuess;
    
    totalQuizTries += 1;
    
    if (userGuess == randomCandidateNumber) {
        cout << "\nCorrect! ";
        totalQuizWins += 1;
    }
    else {
        cout << "\nWrong! ";
    }
    cout << "You got " << totalQuizWins << " out of " << totalQuizTries << ", which is " << Final(totalQuizTries,totalQuizWins) << "%\n";
}


//Starting main here...
int main() {
    
    char userInputCharacter;
    int numberOfLines;
    int score = 0;
    int counter = 0;

    // Initialize the random number generator
    srand( 1);    // You must leave it as srand( 1) for the version you turn in.
	              // Change this to srand( time(0))  if you want it to be different every time.
   
    //.............MENU STARTS FROM HERE..............................
    
    while (userInputCharacter !=5){
    
	// Display which program this is and display menu options to select program output to be displayed
	cout << endl
		 << "----  Program 2: Rally Songs  ----\n"
		 << "Select from the following:\n"
		 << "   1. Set number of lines to display\n"
		 << "   2. Get random lines from Trump.txt\n"
		 << "   3. Get random lines from Warren.txt\n"
		 << "   4. Rally song quiz\n"
		 << "   5. Exit the program\n"
		 << "Your choice --> \n";
    
    cin >> userInputCharacter;
	cout << endl;
    
    // Handle the "Exit" option
	if( userInputCharacter == '5') {
        cout << "You got " << totalQuizWins << " out of " << totalQuizTries << ", which is " << Final(totalQuizTries,totalQuizWins) << "%\n";

		exit( -1);  
	}
    
    //Handle the #1 option.. i.e. Setting the number of lines to display
    if( userInputCharacter == '1'){
        setNumberOfLines();
         }

    //Handle the #2 option.. i.e. Getting random lines from Trump.txt
    if(userInputCharacter == '2'){
         getRandomLines("Trump.txt");
    }
    
    if(userInputCharacter == '3'){
        getRandomLines("Warren.txt");
    }
    if(userInputCharacter == '4'){
        Quiz();        
    }
    }
    return 0;
}//end main()
