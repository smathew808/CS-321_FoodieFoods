#include <iostream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "SeqAlignmentHeader.h"


//Name: Sean Mathews
//Class: CS340
//Instructor: Ercal
//Project: SeqAlignment

using namespace std;

char algChoice();


int main(){

//user picks which alg they want to use
char userAlgChoice;

string userStringChoice1;
string userStringChoice2;

//user picks the scores that they wnant to use for the optimal seq alignment
int userMatchScore; //example would be 2
int userGapScore; //exmaple would be -2
int userSimilarScore; //example would be 1, all vowels and the pdf specific pairs are all similar
int userDissimilarScore; //example would be -1

SeqAlignment seqAligmentObject;

	
userAlgChoice = algChoice();

//least common subsequnce
if (userAlgChoice == '1')
{
	cout << "Pick a word with no capital letters" << endl;
	cin >> userStringChoice1;

	cout << "Pick another word with no capital letters" << endl;
	cin >> userStringChoice2;

	//i want to make a vecotr of chars, and fill it
	vector<char> stringChoice1Vector;

	for (int i = 0; i < userStringChoice1.length(); i++)
	{
		//resize the vecotor by 1
		stringChoice1Vector.resize(i + 1);

		//assign the character in the string at index i to the char vector at index i
		stringChoice1Vector[i] = userStringChoice1[i];
	}

	vector<char> stringChoice2Vector;

	for (int i = 0; i < userStringChoice2.length(); i++)
	{
		//resize the vecotor by 1
		stringChoice2Vector.resize(i + 1);

		//assign the character in the string at index i to the char vector at index i
		stringChoice2Vector[i] = userStringChoice2[i];
	}



	int LcsWinner = seqAligmentObject.longestCommonSubsequence(stringChoice1Vector, stringChoice2Vector, userStringChoice1, userStringChoice2);

	cout << "The Total score is: " << LcsWinner<< endl << endl;


}

//optimal sequence Alignment
else if (userAlgChoice == '2')
{
	cout << "Pick a word with no capital letters" << endl;
	cin >> userStringChoice1;

	cout << "Pick another word with no capital letters" << endl;
	cin >> userStringChoice2;

	vector<char> stringChoice1Vector;

	for (int i = 0; i < userStringChoice1.length(); i++)
	{
		//resize the vecotor by 1
		stringChoice1Vector.resize(i + 1);

		//assign the character in the string at index i to the char vector at index i
		stringChoice1Vector[i] = userStringChoice1[i];
	}

	vector<char> stringChoice2Vector;

	for (int i = 0; i < userStringChoice2.length(); i++)
	{
		//resize the vecotor by 1
		stringChoice2Vector.resize(i + 1);

		//assign the character in the string at index i to the char vector at index i
		stringChoice2Vector[i] = userStringChoice2[i];
	}






	cout << "Please choose a substitution score" << endl;
	cin >> userSimilarScore; // c

	while (userSimilarScore < 0)
	{
		cout << "Im sorry, that value must be greater than 0" << endl << "Please Try again" << endl;
		cin >> userSimilarScore;
	}

	cout << "Please choose a match score" << endl;
	cin >> userMatchScore; // a

	//while a > c > 0
	//while the userMatchScore is greater than substitution score and the matchscore is greater than 0, it can be a valid value
	while ((userMatchScore < 0) || (userMatchScore <= userSimilarScore) )
	{
		cout << "Im sorry, that value must be greater than the 0 and greater than the similar score" << endl << "Please Try again" << endl;
		cin >> userMatchScore;
	}

	cout << "Please choose a gap score" << endl;
	cin >> userGapScore; // a


	while (userGapScore > 0)
	{
		cout << "Im sorry, the gap score must be less than 0" << endl << "Please Try again" << endl;
		cin >> userGapScore;
	}

	cout << "Please choose a dissimilar score" << endl;
	cin >> userDissimilarScore; // a

	while (userDissimilarScore > 0)
	{
		cout << "Im sorry, the Dissimilar score score must be less than 0" << endl << "Please Try again" << endl;
		cin >> userDissimilarScore;
	}

	//calls optseq
	int OptWinner = seqAligmentObject.optimalSequenceAlignment(stringChoice1Vector, stringChoice2Vector, userSimilarScore, userMatchScore, userGapScore, userDissimilarScore, userStringChoice1, userStringChoice2);


	cout << "The Total score is: " << OptWinner << endl << endl;

	
}

system("pause");

return 0;
}



char algChoice() {

	char algChoice;

	cout << "What Algorithm would you like to choose?" << endl;
	cout << "1) longest common subsequence" << endl << "2) optimal sequence alignment" << endl;
	cin >> algChoice;

	return algChoice;
}