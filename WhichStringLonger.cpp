/*
Kenneth Adair
Problem from Pluralsight course.
"Write a program that asks the user for two words and tells them which is longer.
This app can run until the user says to stop, or just once: your choice"
*/

#include <iostream>
#include <string>
using namespace std;

string whichWordIsLonger(string word1, string word2){
    if(word1.length() == word2.length())
        return word1 + " and " + word2 + " are equal lengths.";
    if(word1.length() > word2.length())
        return word1 + " is longer.";
    return word2 + " is longer.";
}

bool loop(){
    string word1, word2, again;
    bool tryAgain = false;
    cout << "You will enter two words and we will tell you which word is longer." << endl;
    cout << "Enter the first word:";
    cin >> word1;
    cout << "Enter the second word:";
    cin >> word2;
    cout << endl << whichWordIsLonger(word1, word2) << endl;
    cout << "Would you like to try again? (y for yes, n for no)" << endl;
    cin >> again;
    if(again == "y" || again == "Y")
        tryAgain = true;
    return tryAgain;
}

int main(){
    while(loop());
    return 0;
}
