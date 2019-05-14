/*************************************************************************
 * Program Name: merge4.cpp
 * Author: Brittany Dunn
 * Date: Jan 20 2019
 * Description: 
 *************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "merge4.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

 
void merge4(int* myArr, int left, int right, int mid){
    //Create a temp array to hold numbers as the two arrays are merged
    int tempArr[right - left +1];
    
    //Declare counters for the beginnings of the left and right subarrays
    //and the index of the temp array
    int leftCounter = left;
    int rightCounter = mid + 1;
    int index = 0;
    
    //While the end of either array has not yet been reached
    //compare the numbers and sort the smaller one in temp array
    
    while(leftCounter <= mid && rightCounter <= right){
	//if the left array element is smaller then store it in temp array
	if(myArr[leftCounter] < myArr[rightCounter]){
	    tempArr[index] = myArr[leftCounter];
	    ++index;
	    ++leftCounter;
	}
	else{
	    tempArr[index] = myArr[rightCounter];
	    ++index;
	    ++rightCounter;
	}
    }
    
    //Once end of one subarray is reached,
    //Add numbers left in each array to the temp array
    while(leftCounter <= mid){
	tempArr[index] = myArr[leftCounter];
	    ++index;
	    ++leftCounter;
    }
    
    while(rightCounter <= right){
	    tempArr[index] = myArr[rightCounter];
	    ++index;
	    ++rightCounter;	
    }
    
    //Copy sorted temp array back to myArr
    for(int i = left; i <= right; ++i){
	myArr[i]= tempArr[i - left];
    }

}


void mergesort4(int* myArr, int left, int right){
    
    //If only one number then return
    if(right - left < 1){
	return;
		
    }
    
    //Find midpoints for the sub arrays
    int mid1 = left + ((right - left)/4);
    int mid2 = left + 2*((right - left)/4);
    int mid3 = left + 3*((right - left)/4);
    
    //Call mergesort for each sub array
    mergesort4(myArr, left, mid1);
    mergesort4(myArr, mid1+1, mid2);
    mergesort4(myArr, mid2+1, mid3);
    mergesort4(myArr, mid3+1, right);
    
    //Merge the sub arrays,
    //first the left
    merge4(myArr, left, mid2, mid1);    
    //then the right 
    merge4(myArr, mid2+1, right, mid3);    
    //then left and right together
    merge4(myArr, left, right, mid2);
}



