/*************************************************************************
 * Program Name: merge4TimeMain.cpp
 * Author: Brittany Dunn
 * Date: Jan 20 2019
 * Description: 
 * I used http://www.cplusplus.com/forum/beginner/220444/ as a resource on
 * how to calculate time
 *************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "merge4.hpp"
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
	cout << "Number of clock ticks per second = " << CLOCKS_PER_SEC << endl;
	cout << "Time between clock ticks = " << 1.0 / CLOCKS_PER_SEC <<endl;

	//Set first n to 10,000
	int size = 20000;

	for(int x = 1; x <= 10; x++){
	    int array[size];
	    
	    //Fill array with random number 0 - 10,000
	    for(int i = 0; i < size; i++){
		    int number = rand() % (10000 - 0 + 1);
		    array[i] = number;
	    }
	
	    //start clock
	    clock_t c_start = clock();


	    //run merge sort on array
	    mergesort4(array,0,(size - 1));
	
	    //Stop clock
	    clock_t c_end = clock();

	    //Calculate seconds
	    float seconds = (float)(c_end - c_start) /CLOCKS_PER_SEC;

	    cout << "n=" << size << endl;  
	    cout << seconds << " seconds" <<endl;
	    
	    //Increase array size each loop
	    size += 20000;
	}
	
	return 0;

}
