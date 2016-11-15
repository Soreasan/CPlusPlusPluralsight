/*
Kenneth Adair
This is an answer I came up with to the exercise from 
"Learn How to Program With C++" by Kate Gregory on Pluralsight.
It's the question from the section titled "Exercise: Guess My Number".  
*/
#include <iostream>
using namespace std;

bool guess(int newGuess);
int answer = 7;

int main()
{
	bool keepGoing = true;
	int yourGuess = 0;
	while(keepGoing)
	{
		cout << "Guess a number between 1 and 10: ";
		cin >> yourGuess;
		keepGoing = !(guess(yourGuess));
	}	
	return 0;
}

bool guess(int newGuess)
{
	if(newGuess == answer){
		cout << "Your guess is CORRECT" << endl;
		return true;
	}else if(newGuess > answer){
		cout << "Your guess is LARGER than the correct answer." << endl;
		return false;
	}else{
		cout << "Your guess is SMALLER than the correct answer." << endl;
		return false;
	}	
}
