//
//  change.cpp
//  Assignment 3
//
//  Created by John Olgin on 7/14/18.
//  Description: Change Made Implementation

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;


#define MAX 1000

/*  int n is the size of the denomination array
    int A is the amount of change to be made
    denArray is the array of the different denominations to be used
 */
int *makeChange(int denArray[], int n, int A){
    int i, j, k;
    int minCoinsRequired[MAX];
        
    int grid[MAX][n];
    int min;
        
    //For the case that change made is to be zero, which would require 0 coins
    minCoinsRequired[0] = 0;
    
    for (i=1; i <= A; i++){
        min = 999;
        
        for (j = 0; j<n; j++){
            
            if (denArray[j] <= i){
                
                //check if minimum is greater current than minimum number at this index
                if (min > minCoinsRequired[i-denArray[j]]+1){
                    min = minCoinsRequired[i-denArray[j]]+1;
                    
                    //This will copy the coins counts
                    for(k = 0; k < n; ++k){
                        grid[i][k] = grid[i-denArray[j]][k];
                    }
                    
                    //increment the count of a coin if it used
                    grid[i][j]++;
                }
            }
        }
        
        minCoinsRequired[i] = min;
    }
    
    
    int coinIndexArray[n];
    
    //create a new array that holds the index of each coin used
    for(int i = 0; i<n; i++){
        coinIndexArray[i] = grid[A][i];
    }
    
    
    return coinIndexArray;
}




int main() {
    ifstream file("amount.txt");
    ofstream output("change.txt");
    int array[1000];
    int numArray[1000];
    
    /*This will read in the contents of the file to the array*/
    
    while(!file.eof()){
        //get the next line from the file
        string newString;
        getline(file, newString);
        stringstream numberStream(newString);
        int size = 0;
    
        //convert the string of integers to an integer array
        while(numberStream) {
            int x;
        
            numberStream >> x;
            array[size] = x;
            size++;
        }
    
        //Fix the incorrect array by placing all but the last element in a new array
        int newSize = 0;
        for (int i = 0; i < size-1; i++) {
            numArray[i] = array[i];
            output << numArray[i] << " ";
            newSize++;
        }
        output << endl;
    
        //read in and convert change to be made value
        string anotherString;
        getline(file, anotherString);
        stringstream changeStream(anotherString);
        
        int y;
        while(changeStream){
            changeStream >> y;
        }
        
        output << y << endl;
        
        int *coinArray = makeChange(numArray, newSize, y);
    
        //Add up to get the minimum number of coins required
        int sum = 0;
        for(int i = 0; i < newSize; i++){
            sum = sum + coinArray[i];
        }
        
        //write the coin index array to the output file
        for(int i = 0; i < newSize; i++){
            output << coinArray[i] << " ";
        }
        
        
        output << endl;
        output << sum << endl;
    }
    
    cout << "Done, please check change.txt" << endl;
    file.close();
    output.close();
}
