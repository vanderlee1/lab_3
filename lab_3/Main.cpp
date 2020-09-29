/*
Rebecca van der Lee
C++ Fall 2020
Due : 9/27/2020
Lab 3 User and File I/O
lab description: Write an interactive C++ program that computes and outputs the mean and  population standard deviation of a set of four integers that are inputted by a file
called “inMeanStd.dat” and the user (should handle both). Although the individual values are integers, the results are floating-point values. Be sure to use
proper formatting and appropriate comments in your code. Provide appropriate prompts to the user. The output should be to the screen for the user inputted
values and to a file called “outMeanStd.dat”. The programs output should be labeled clearly and formatted neatly. You must calculate the mean and standard
deviation in separate functions.

*/







#include <iostream>
#include <fstream> //needed for the input and output files
#include <cmath> //needed for the functions
using namespace std;

float meanFunction(int, int, int, int); //prototype for the mean functinon
float stdFunction(int, int, int, int, float); // prototype for the population standard deviation  function


int main()
{

	

	//input variables
	int value1;
	int value2;
	int value3;
	int value4;
	ifstream inputFileName;
	ofstream outputFileName;


	//open files
	inputFileName.open("inMeanStd.dat");
	outputFileName.open("outMeanStd.dat");



	//read values
	inputFileName >> value1 >> value2 >> value3 >> value4;

	//prompt for the user
	
	cout << "This program is going to calculate the mean and the population standard deviation of a set of four integers." << endl;

	//calculate values
	outputFileName << "This is the mean of the integers in the document: " << meanFunction(value1, value2, value3, value4) << endl;
	outputFileName << "This is the population standard deviation of the integers in the document: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl << endl << endl;

	

	//promt for the user
	cout << "Put in 4 integers. Afer you put in one integer you should press enter" << endl;
	cin >> value1 >> value2 >> value3 >> value4;

	//puts the calculated values in the document
	cout << endl;
	outputFileName << "This is the mean of the integers the user filled in:  " << meanFunction(value1, value2, value3, value4) << endl;
	outputFileName << "This is the population standard deviation of the integers the user filled in: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl;

	//Outputs the calculated values on the screen
	cout << "The program calculated the following values:"<< endl;
	cout << "Mean =  " << meanFunction(value1, value2, value3, value4) << endl;
	cout << "Population standard deviation =  " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl;

	//close the files
	inputFileName.close();
	outputFileName.close();

	return 0;
}

float meanFunction(int value1, int value2, int value3, int value4) //Function defintion of the mean function
{
	return (float(value1 + value2 + value3 + value4) / float(4));
}

float stdFunction(int value1, int value2, int value3, int value4, float average) //Function defintion of the population standard deviation
{
	return sqrt((float(pow((value1 - average), 2) + pow((value2 - average), 2) + pow((value3 - average), 2)) + pow((value4 - average), 2)) / 4);
}