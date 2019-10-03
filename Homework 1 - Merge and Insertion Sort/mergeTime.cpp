//
//  mergeTime.cpp
//  mergeTime
//
//  Name: John Olgin
//  Description: Merge sort algorithm implementation
//  Date: 6/28/18

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*This function is copied straight from the mergesort.cpp file*/
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

/*This function is copied straight from the mergesort.cpp file*/
void MergeSort(int *array, int low, int high) {
    int middle;
    
    if(low < high)
    {
        middle =(low + high)/2;
        MergeSort(array, low, middle);
        MergeSort(array, middle + 1, high);
        
        Merge(array, low, high, middle);
    }
}



int main() {
    /*create all the arrays and initialize their sizes*/
    int arr1[5000], arr1Size = 0;
    int arr2[10000], arr2Size = 0;
    int arr3[15000], arr3Size = 0;
    int arr4[20000], arr4Size = 0;
    int arr5[35000], arr5Size = 0;
    int arr6[50000], arr6Size = 0;
    int arr7[70000], arr7Size = 0;
    int arr8[90000], arr8Size = 0;
    int arr9[12000], arr9Size = 0;
    double runTimes[9];
    int arraySizes[9];
    
    
    srand(time(0));
    
    /*The next block of code is the same for the next 8 arrays, so the comments apply to each one*/
    /*Generate a random number and assign it to an array position until the array is filled.*/
    for(int i = 0; i < 5000; i++){
        int randNum = rand() % 5001;
        arr1[i] = randNum;
        arr1Size++;
    }
    
    /*Run the merge sort algorithm and record the system clock time before and after*/
    clock_t beginning = clock();
    MergeSort(arr1, 0, arr1Size - 1);
    clock_t end = clock();
    
    /*Calculate the actual run time by calculating difference and dividing by 1000000 to convert to seconds*/
    double arr1time = (double)(end - beginning)/1000000;
    
    /*assign the array size and run time to a position in the array sizes array list and run times array list*/
    arraySizes[0] = arr1Size;
    runTimes[0] = arr1time;
    
    
    
    for(int i = 0; i < 10000; i++){
        int randNum = rand() % 10001;
        arr2[i] = randNum;
        arr2Size++;
    }
    beginning = clock();
    MergeSort(arr2, 0, arr2Size - 1);
    end = clock();
    double arr2time = (double)(end - beginning)/1000000;
    arraySizes[1] = arr2Size;
    runTimes[1] = arr2time;

    
    
    
    for(int i = 0; i < 15000; i++){
        int randNum = rand() % 15001;
        arr3[i] = randNum;
        arr3Size++;
    }
    beginning = clock();
    MergeSort(arr3, 0, arr3Size-1);
    end = clock();
    double arr3time = (double)(end - beginning)/1000000;
    arraySizes[2] = arr3Size;
    runTimes[2] = arr3time;

    
    
    
    for(int i = 0; i < 20000; i++){
        int randNum = rand() % 20001;
        arr4[i] = randNum;
        arr4Size++;
    }
    beginning = clock();
    MergeSort(arr4, 0, arr4Size-1);
    end = clock();
    double arr4time = (double)(end - beginning)/1000000;
    arraySizes[3] = arr4Size;
    runTimes[3] = arr4time;

    
    
    for(int i = 0; i < 35000; i++){
        int randNum = rand() % 35001;
        arr5[i] = randNum;
        arr5Size++;
    }
    beginning = clock();
    MergeSort(arr5, 0, arr5Size-1);
    end = clock();
    double arr5time = (double)(end - beginning)/1000000;
    arraySizes[4] = arr5Size;
    runTimes[4] = arr5time;

    
    
    
    for(int i = 0; i < 50000; i++){
        int randNum = rand() % 50001;
        arr6[i] = randNum;
        arr6Size++;
    }
    beginning = clock();
    MergeSort(arr6, 0, arr6Size-1);
    end = clock();
    double arr6time = (double)(end - beginning)/1000000;
    arraySizes[5] = arr6Size;
    runTimes[5] = arr6time;

    
    
    for(int i = 0; i < 70000; i++){
        int randNum = rand() % 70001;
        arr7[i] = randNum;
        arr7Size++;
    }
    beginning = clock();
    MergeSort(arr7, 0, arr7Size-1);
    end = clock();
    double arr7time = (double)(end - beginning)/1000000;
    arraySizes[6] = arr7Size;
    runTimes[6] = arr7time;
    
    
    
    for(int i = 0; i < 90000; i++){
        int randNum = rand() % 90001;
        arr8[i] = randNum;
        arr8Size++;
    }
    
    beginning = clock();
    MergeSort(arr8, 0, arr8Size - 1);
    end = clock();
    double arr8time = (double)(end - beginning)/1000000;
    arraySizes[7] = arr8Size;
    runTimes[7] = arr8time;
    
    
    
    for(int i = 0; i < 120000; i++){
        int randNum = rand() % 120001;
        arr9[i] = randNum;
        arr9Size++;
    }
    
    beginning = clock();
    MergeSort(arr9, 0, arr9Size - 1);
    end = clock();
    double arr9time = (double)(end - beginning)/1000000;
    arraySizes[8] = arr9Size;
    runTimes[8] = arr9time;
    
    
    /*print out the array size and run times for each array*/
    for(int i = 0; i < 9; i++){
        cout << "For array " << i + 1 << ": size = " << arraySizes[i] << ", run time = " << runTimes[i] << endl;
    }

}
