#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>



//Name: Sean Mathews
//Class: CS340
//Instructor: Ercal
//Project: SeqAlginement

using namespace std;

class SeqAlignment {

private:

public:

	vector<char> optimalAlignList;


	int max(int a, int b);
	int longestCommonSubsequence(vector <char> stringVector1, vector <char> stringVector2, string stringXAxis, string stringYAxis);
	int optimalSequenceAlignment(vector <char> stringVector1, vector <char> stringVector2, int similarScore, int matchScore, int gapScore, int dissimilarScore, string stringXAxis, string stringYAxis);

};
