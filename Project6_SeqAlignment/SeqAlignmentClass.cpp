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



int SeqAlignment::optimalSequenceAlignment(vector <char> stringVector1, vector <char> stringVector2, int similarScore, int matchScore, int gapScore, int dissimilarScore, string stringXAxis, string stringYAxis) {

	vector<vector<int> > seqAlignmentTable;

	char vowelList[5] = { 'a', 'e', 'i', 'o', 'u' };

	char similarLetterList[24] = {'b','p','c','k','c','s','d','t','e','y','g','j','g','k','i','y','k','q','m','n','s','z','v','w'};

	vector<vector<char>> similarLettersVectorList;

	int similarLettersCtr = 0;

	similarLettersVectorList.resize(12);

	//fill the similarLettersList
	for (int i = 0; i < 12; i++)
	{
		similarLettersVectorList[i].resize(2);

		for (int j = 0; j < 2; j++)
		{
			similarLettersVectorList[i][j] = similarLetterList[similarLettersCtr];

			similarLettersCtr++;
		}
		similarLettersCtr++;
	}

	//assigning the lengths of the strings
	int xAxis = stringXAxis.length();
	int yAxis = stringYAxis.length();

	//reversing vector1 to correctly match up with how I do the problem on paper
	reverse(stringVector2.begin(), stringVector2.end());

	//resize the table using the x-axis
	seqAlignmentTable.resize(yAxis + 1);

	//fill the vector with the corresponding lengths
	for (int i = 0; i < yAxis + 1; i++)
	{
		//resize the y axis 
		seqAlignmentTable[i].resize(xAxis + 1);

		for (int j = 0; j < xAxis + 1; j++)
		{
			seqAlignmentTable[i][j] = 0;
		}
	}

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	//

	int yaxisCtr = 0;

	//this handles going from bottom to top
	for (int i = yAxis; i >= 0; i--)
	{
		

		int xAxisCtr = 0;
		//this handles going from left to right
		for (int j = 0; j <= xAxis; j++)
		{

			//ok first if you go right, you subtract 2

			//if you are the same, then you go diagonal, and add 2
			//if you are similar, then you go diagonal, and add 1

			//if you got a gap,  then you go up or right, and add -2

			//gap is here, so subtract 2
			//if you are at bottom row or at the most left column
			if ((i == yAxis) && (j == 0) )
			{
				//do nothing because the value at this point is 0, and want to keep it
			}
			else if (i == yAxis)
				seqAlignmentTable[i][j] = seqAlignmentTable[i][j - 1] + gapScore;

			else if (j == 0)
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j] + gapScore;

			//if you reach an index thats bigger than the word itself, then add to the gap score


			/////////
			//MATCH//
			/////////

			//if find a match add 2
 			else if (stringVector1[j - 1] == stringVector2[i])
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + matchScore;
			}

			/////////////
			//SIMILAR////
			//NONVOWELS//
			/////////////

			 //if you find a similar letter

			// {b,p}
			else if ( ( (stringVector1[j - 1] == 'b') || (stringVector1[j - 1] == 'p') ) && ( (stringVector2[i] == 'b') || (stringVector2[i] == 'p')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {c,k}
			else if (((stringVector1[j - 1] == 'c') || (stringVector1[j - 1] == 'k')) && ((stringVector2[i] == 'c') || (stringVector2[i] == 'k')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {c,s}
			else if (((stringVector1[j - 1] == 'c') || (stringVector1[j - 1] == 's')) && ((stringVector2[i] == 'c') || (stringVector2[i] == 's')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {c,s}
			else if (((stringVector1[j - 1] == 'd') || (stringVector1[j - 1] == 't')) && ((stringVector2[i] == 'd') || (stringVector2[i] == 't')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {e,y}
			else if (((stringVector1[j - 1] == 'e') || (stringVector1[j - 1] == 'y')) && ((stringVector2[i] == 'e') || (stringVector2[i] == 'y')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {g,j}
			else if (((stringVector1[j - 1] == 'g') || (stringVector1[j - 1] == 'j')) && ((stringVector2[i] == 'g') || (stringVector2[i] == 'j')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {g,k}
			else if (((stringVector1[j - 1] == 'g') || (stringVector1[j - 1] == 'k')) && ((stringVector2[i] == 'g') || (stringVector2[i] == 'k')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {i,y}
			else if (((stringVector1[j - 1] == 'i') || (stringVector1[j - 1] == 'y')) && ((stringVector2[i] == 'i') || (stringVector2[i] == 'y')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {k,q}
			else if (((stringVector1[j - 1] == 'k') || (stringVector1[j - 1] == 'q')) && ((stringVector2[i] == 'k') || (stringVector2[i] == 'q')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {m,n}
			else if (((stringVector1[j - 1] == 'm') || (stringVector1[j - 1] == 'n')) && ((stringVector2[i] == 'm') || (stringVector2[i] == 'n')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {s,z}
			else if (((stringVector1[j - 1] == 's') || (stringVector1[j - 1] == 'z')) && ((stringVector2[i] == 's') || (stringVector2[i] == 'z')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {v,w}
			else if (((stringVector1[j - 1] == 'v') || (stringVector1[j - 1] == 'w')) && ((stringVector2[i] == 'v') || (stringVector2[i] == 'w')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			// {s,z}
			else if (((stringVector1[j - 1] == 's') || (stringVector1[j - 1] == 'z')) && ((stringVector2[i] == 's') || (stringVector2[i] == 'z')))
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}


			//////////
			//VOWELS//
			//////////

																																													   //////
			else if (((stringVector1[j - 1] == 'a') || (stringVector1[j - 1] == 'e') || (stringVector1[j - 1] == 'i') || (stringVector1[j - 1] == 'o') || (stringVector1[j - 1] == 'u')) && ((stringVector2[i] == 'a') || (stringVector2[i] == 'e') || (stringVector2[i] == 'i') || (stringVector2[i] == 'o') || (stringVector2[i] == 'u')))
			{																																										   //////
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + similarScore;
			}

			//////////////
			//DISSIMILAR//
			//LETTERS/////
			//////////////
			
			//if the phrases being compared are of the same length
			else if ( (xAxisCtr == yaxisCtr) )
			{
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + dissimilarScore;
			}

			else 
			{																																										   //////
				//seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + dissimilarScore;

				seqAlignmentTable[i][j] = (max(seqAlignmentTable[i + 1][j], seqAlignmentTable[i][j - 1]) + gapScore);
			}

		
			xAxisCtr++;
		}

		yaxisCtr++;
	}

	return seqAlignmentTable[0][xAxis];
	
}




int SeqAlignment::max(int a, int b)
{
	return (a > b) ? a : b;
}

int SeqAlignment::longestCommonSubsequence(vector <char> stringVector1, vector <char> stringVector2, string stringXAxis, string stringYAxis)
{
	vector<vector<int> > seqAlignmentTable;

	//vector<vector<bool> > SeqAlignBoolTable;

	//assigning the lengths of the strings
	int xAxis = stringXAxis.length();
	int yAxis = stringYAxis.length();

	//reversing vector1 to correctly match up with how I do the problem on paper
	reverse(stringVector2.begin(), stringVector2.end());

	//resize the table using the x-axis
	seqAlignmentTable.resize(yAxis + 1);

	//fill the vector with the corresponding lengths
	for (int i = 0; i < yAxis + 1; i++)
	{
		//resize the y axis 
		seqAlignmentTable[i].resize(xAxis + 1);

		for (int j = 0; j < xAxis + 1; j++)
		{
			seqAlignmentTable[i][j] = 0;
		}
	}

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	//

	//int rowCounter = 5; //counts how many rows there are
	//int columnCounter; //counts how many columns there are

	//int winnerListCounter = 0; //to resize the vector when needed

	//this handles going from bottom to top
	for (int i = yAxis; i >= 0; i--)
	{
		//columnCounter = 0; //counts how many blocks there are in a row

		//this handles going from left to right
		for (int j = 0; j <= xAxis; j++)
		{
			//the very bottom row and left column are filled with 0s
			if (i == yAxis || j == 0)
				seqAlignmentTable[i][j] = 0;

			//if find a match add 1
			else if (stringVector1[j - 1] == stringVector2[i])
				seqAlignmentTable[i][j] = seqAlignmentTable[i + 1][j - 1] + 1;

			//otherwise find to see which value is bigger 1 box below it or 1 box to the left of it
			else
			{
				/*int vert = seqAlignmentTable[i + 1][j];
				int diag = seqAlignmentTable[i][j - 1];

				if (diag > vert) {
					seqAlignmentTable[i][j] = diag;
					SeqAlignBoolTable[i][j] = true;
				}
				else {
					seqAlignmentTable[i][j] = vert;
					SeqAlignBoolTable[i][j] = false;
				}*/

				seqAlignmentTable[i][j] = max(seqAlignmentTable[i + 1][j], seqAlignmentTable[i][j - 1]);
			}

			//columnCounter++;
		}

		//rowCounter--;
	}

	//int winnerListIndex = 0;

	//for (int i = 1; i < yAxis + 1; i++)
	//{
	//	//if the value in the choiceTable is true
	//	if (SeqAlignBoolTable[i][columnCounter - 1] == true)
	//	{
	//		winnerListCounter++; //resize counter
	//		optimalAlignList.resize(winnerListCounter + 1); //resize winnerList

	//		if (xAxis > yAxis)
	//		{
	//			optimalAlignList[winnerListCounter] = stringVector1[i];
	//		}
	//		else

	//		optimalAlignList[winnerListCounter] = stringVector2[i]; //reassigns the item at index i in the itemList to the winnerList at index i

	//		columnCounter = columnCounter - itemList[i].itemWeight; //reduce the counter
	//	}

	//}

	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	return seqAlignmentTable[0][xAxis];

	
}
