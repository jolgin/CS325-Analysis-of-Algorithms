//
//  bin.cpp
//  CS325_HW8


#include <iostream>
#include <fstream>
#include <sstream>
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


void firstFit(int weight[], int binCapacity, int n)
{
    int binCount = 0;
    
    // Array to remember remaining capacity of each bin
    int binRemainingCapacity[n];
    
    // Iterate through the items
    for (int i = 0; i < n; i++)
    {
        // Iterate through bins to find the first fit
        int j;
        for (j = 0; j < binCount; j++)
        {
            if (binRemainingCapacity[j] >= weight[i])
            {
                binRemainingCapacity[j] = binRemainingCapacity[j] - weight[i];
                break;
            }
        }
        
        // Create a new bin if none can accomodate current weight
        if (j == binCount)
        {
            binRemainingCapacity[binCount] = binCapacity - weight[i];
            binCount++;
        }
    }
    
    cout << "First Fit bins required: " << binCount << endl;
}

void firstFitDecreasing(int weightArray[], int binCapacity, int n){
    MergeSort(weightArray, 0 , n - 1);
    
    int binCount = 0;
    
    // remember remaining capacity of each bin
    int binRemainingCapacity[n];
    
    /* Iterate through the items in reverse order, since the array is sorted in ascending order
     this should iterate through in descending order*/
    for (int i = n-1; i >= 0; i--)
    {
        // Iterate through bins to find the first fit
        int j;
        for (j = 0; j < binCount; j++)
        {
            if (binRemainingCapacity[j] >= weightArray[i])
            {
                binRemainingCapacity[j] = binRemainingCapacity[j] - weightArray[i];
                break;
            }
        }
        
        // Create a new bin if none could accomodate current weight
        if (j == binCount)
        {
            binRemainingCapacity[binCount] = binCapacity - weightArray[i];
            binCount++;
        }
    }
    
    cout << "First Fit Decreasing bins required: " << binCount << endl;
}




int main(){
    ifstream file("bin.txt");
    int testSets;
    file >> testSets;
    
    int testIndex = 1;
    for(int i = 0; i < testSets; i++){
        cout << "For Test " << testIndex << ":" << endl;
        int binCapacity, numOfItems;
        file >> binCapacity;
        file >> numOfItems;
        
        int weightArray[numOfItems];
        for (int i = 0; i < numOfItems; i++) {
            file >> weightArray[i];
        }
        
        firstFit(weightArray, binCapacity, numOfItems);
        firstFitDecreasing(weightArray, binCapacity, numOfItems);
        testIndex++;
        cout << endl << endl;
    }
    
    file.close();
}
