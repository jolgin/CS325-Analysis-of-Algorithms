//
//  insertsort.cpp
//  InsertSort
//
//  Name: John Olgin
//  Description: Insert sort algorithm implementation
//  Date: 6/28/18

#include <iostream>
#include <fstream>
using namespace std;

/*This insertion sort algorithm will start in the second position of the array and compare the value with the previous value. If it's smaller, then it will swap with the previous position. It will then move on to the next position to repeat the process*/
void InsertionSort(int array[], int length)
{
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
            int tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
        }
    }
}


int main() {
    ifstream file("data.txt");
    int array[1000];
    int position = 0;
    int size = 0;
    
    /*This will read in the contents of the file to the array*/
    while(!file.eof()) {
        
        file >> array[position];
        position++;
        size++;
    }
    
    
    ofstream output("insert.out");
    output << "There are " << size << " integers to be sorted" << endl;
    
    InsertionSort(array, size);
    
    /*write in to a file the contents of the sorted array*/
    for(int i = 0; i < size; i++) {
        int x = array[i];
        output << x << endl;
    }
    
    file.close();
    output.close();
}
