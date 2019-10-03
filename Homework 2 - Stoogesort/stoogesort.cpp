//
//
//  Assignment 2 - CS 325
//  Name: John Olgin
//  Date: 7/7/18.
//  Description: Stooge Sort algorithm implementation
//

#include <iostream>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void stoogesort(int array[], int low, int high){
    
    /*This section swaps the two elements*/
    if (array[low] > array[high]){
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
    
    /*This section recursively calls stoogesort to focus on specific thirds of the array*/
    if ((high - low + 1) > 2) {
        int x = (high - low + 1)/3;
        stoogesort(array, low, high - x);
        stoogesort(array, low + x, high);
        stoogesort(array, low, high - x);
    }
}

int main() {
    ifstream file("data.txt");
    ofstream output("stooge.out");
    
    
    int arraySizes[1000];
    int writeArray[1000];
    int writeArraySize = 0;
    int arraySizeIndex = 0;
    
    /*This will read in the contents of the file to the array*/
    while(!file.eof()) {
        int n;
        file >> n;
        /*Maintains a record of array sizes for writing it to the ouput file later*/
        arraySizes[arraySizeIndex] = n;
        arraySizeIndex++;
        
        int array[n];
        /*read in the integers from the text file to the array*/
        for(int i = 0; i < n; i++) {
            int newElement;
            file >> newElement;
            array[i] = newElement;
        }
    
        
        stoogesort(array, 0, n-1);
        
        /*This will write the sorted arrays into a larger array to be written to a file*/
        for(int i = 0; i < n; i++) {
            writeArray[writeArraySize] = array[i];
            writeArraySize++;
        }
    }
    
    /*This code will actually write the array to the output file*/
    int writeArrayIndex = 0;
    for(int i = 0; i < arraySizeIndex; i++){
        int newArraySize = arraySizes[i];
        
        for(int j = 0; j < newArraySize; j++){
            output << writeArray[writeArrayIndex] << " ";
            writeArrayIndex++;
        }
        output << endl;
    }
    
    file.close();
    output.close();
    return 0;
}
    
    
    

