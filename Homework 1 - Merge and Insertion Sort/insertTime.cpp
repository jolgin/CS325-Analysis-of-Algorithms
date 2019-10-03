//
//  insertTime.cpp
//  insertTime
//
//  Name: John Olgin
//  Description: Insert sort algorithm run times
//  Date: 6/28/18

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

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



int main(int argc, const char * argv[]) {
    
    int arr1[5000], arr1size = 0;
    int arr2[10000], arr2size = 0;
    int arr3[15000], arr3size = 0;
    int arr4[20000], arr4size = 0;
    int arr5[35000], arr5size = 0;
    int arr6[50000], arr6size = 0;
    int arr7[70000], arr7size = 0;
    double runTimes[7];
    int arraySizes[7];
    
    
    srand(time(0));
    

    /*The next block of code is the same for the next 8 arrays, so the comments apply to each one*/
    /*Generate a random number and assign it to an array position until the array is filled.*/
    for(int i = 0; i < 5000; i++){
        int randNum = rand() % 5001;
        arr1[i] = randNum;
        arr1size++;
    }
    
    /*Run the insert sort algorithm and record the system clock time before and after*/
    clock_t beginning = clock();
    InsertionSort(arr1, arr1size);
    clock_t end = clock();
    
    /*Calculate the actual run time by calculating difference and dividing by 1000000 to convert to seconds*/
    double arr1time = (double)(end - beginning)/1000000;
    
    /*assign the array size and run time to a position in the array sizes array list and run times array list*/
    arraySizes[0] = arr1size;
    runTimes[0] = arr1time;
    
    
    
    
    for(int i = 0; i < 10000; i++){
        int randNum = rand() % 10001;
        arr2[i] = randNum;
        arr2size++;
    }
    beginning = clock();
    InsertionSort(arr2, arr2size);
    end = clock();
    double arr2time = (double)(end - beginning)/1000000;
    arraySizes[1] = arr2size;
    runTimes[1] = arr2time;
    
    
    
    
    for(int i = 0; i < 15000; i++){
        int randNum = rand() % 15001;
        arr3[i] = randNum;
        arr3size++;
    }
    beginning = clock();
    InsertionSort(arr3, arr3size);
    end = clock();
    double arr3time = (double)(end - beginning)/1000000;
    arraySizes[2] = arr3size;
    runTimes[2] = arr3time;
    
    
    
    
    for(int i = 0; i < 20000; i++){
        int randNum = rand() % 20001;
        arr4[i] = randNum;
        arr4size++;
    }
    beginning = clock();
    InsertionSort(arr4, arr4size);
    end = clock();
    double arr4time = (double)(end - beginning)/1000000;
    arraySizes[3] = arr4size;
    runTimes[3] = arr4time;
    
    
    
    for(int i = 0; i < 35000; i++){
        int randNum = rand() % 35001;
        arr5[i] = randNum;
        arr5size++;
    }
    beginning = clock();
    InsertionSort(arr5, arr5size);
    end = clock();
    double arr5time = (double)(end - beginning)/1000000;
    arraySizes[4] = arr5size;
    runTimes[4] = arr5time;
    
    
    
    
    for(int i = 0; i < 50000; i++){
        int randNum = rand() % 50001;
        arr6[i] = randNum;
        arr6size++;
    }
    beginning = clock();
    InsertionSort(arr6, arr6size);
    end = clock();
    double arr6time = (double)(end - beginning)/1000000;
    arraySizes[5] = arr6size;
    runTimes[5] = arr6time;
    
    
    
    for(int i = 0; i < 70000; i++){
        int randNum = rand() % 70001;
        arr7[i] = randNum;
        arr7size++;
    }
    beginning = clock();
    InsertionSort(arr7, arr7size);
    end = clock();
    double arr7time = (double)(end - beginning)/1000000;
    arraySizes[6] = arr7size;
    runTimes[6] = arr7time;
    
    /*print out the array size and run times for each array*/
    for(int i = 0; i < 7; i++){
        cout << "For array " << i + 1 << ": size = " << arraySizes[i] << ", run time = " << runTimes[i] << endl;
    }
}
