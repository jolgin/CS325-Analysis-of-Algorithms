//
//  mergesort.cpp
//  MergeSort
//
//  Name: John Olgin
//  Description: Insert sort algorithm implementation
//  Date: 6/28/18

#include <iostream>
#include <fstream>
using namespace std;



void Merge(int *array, int low, int high, int mid) {
    int a, b, c, temp[high - low + 1];
    a = low;
    b = 0;
    c = mid + 1;
    
    
    while (a <= mid && c <= high) {
        if(array[a] < array[c]) {
            temp[b] = array[a];
            b++;
            a++;
        }
        
        else {
            temp[b] = array[c];
            b++;
            c++;
        }
    }
    
    while(a <= mid) {
        temp[b] = array[a];
        b++;
        a++;
    }
    
    while(c <= high) {
        temp[b] = array[c];
        c++;
        b++;
    }
    
    for(a = low; a <= high; a++) {
        array[a] = temp[a - low];
    }
    
    
}

/*This section will recursively split the array until there is no more than 1 element in each*/
void MergeSort(int *array, int low, int high) {
    int middle;
    
    if(low < high)
    {
        middle =(low + high)/2;
        MergeSort(array, low, middle);
        MergeSort(array, middle + 1, high);
        
        /*call the function to sort the array*/
        Merge(array, low, high, middle);
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
    
    MergeSort(array, 0, size - 1);
    
    ofstream output("merge.out");
    output << "There are " << size << " integers to be sorted" << endl;
    
    /*write in to a file the contents of the sorted array*/
    for(int i = 0; i < size; i++) {
        int x = array[i];
        output << x << endl;
    }
    
    file.close();
    output.close();
    
    return 0;
}
