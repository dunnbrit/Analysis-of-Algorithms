/*************************************************************************
 * Program Name: merge4Main.cpp
 * Author: Brittany Dunn
 * Date: Jan 20 2019
 *************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "merge4.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

int main()
{
	
	string fileName = "data.txt";
	ifstream readFile;
	int number;
	int counter = -1;
	int size = 0;

	//Vector to store array from file
	vector<int> myArr;

	//Open file
	readFile.open(fileName, std::ios::in);
	
	//If file cannot be opened exit program
	if(!readFile)
	{
		cout << "Error opening file." << endl;;
		return 0;
	}

	else{
	    while(readFile >> number && counter < size){
		if(size == 0){
		    size = number;
		    counter++;
		}
		else{
		    myArr.push_back(number);
		    counter++;
		}
	    }
	}
	
	
	//Close file
	readFile.close();
	
	//Copy vector to array
	int arr[size];
	std::copy(myArr.begin(), myArr.end(), arr);
	
	
	cout << "Unsorted array from data.txt:  ";
	
	for(int i = 0; i < size; i++){
	    cout << arr[i] << " ";
	}

	cout << endl;
	
	//merge sort array
	mergesort4(arr,0,(size - 1));
	
	
	string tempFile = "merge4.txt";
	ofstream outputFile;

	//Open output file
	outputFile.open(tempFile, std::ios::out);

	//if error opening file
	if(outputFile.fail())
	{
		cout << "Error opening file.";
	}

	// call output letter function to add letter frequency to file
	else
	{
	    outputFile << "The sorted array is:  ";
	
	    for(int i = 0; i < size; i++){
		    outputFile << arr[i] << " ";
	    }
	

	    //Close file
	    outputFile.close();
	
	cout << "Sorted array written to file merge4.txt" << endl;
	}
	
	return 0;

}
