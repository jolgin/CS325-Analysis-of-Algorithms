//
//  Assignment 4
//
//  Created by John Olgin on 7/21/18.
//  Description: Last-to-start activity selection

#include <iostream>
#include <fstream>
#include <sstream>
#include<stdio.h>
using namespace std;

void InsertionSort(int array[],int s[], int f[], int length)
{
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0 && s[j - 1] > s[j]; j--) {
            int tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
            
            int tmp1 = s[j];
            s[j] = s[j-1];
            s[j-1] = tmp1;
            
            int tmp2 = f[j];
            f[j] = f[j-1];
            f[j-1] = tmp2;
        }
    }
}

//  Lists the selected arrays starting from the last-to-start
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void activitySelect(int arrayList[], int s[], int f[], int n)
{
    int i, j;
    int selectedArray[1000];
    int selectedIndex = 0;
    
    printf ("The following activities selected are: ");
    
    // Select the activity with the latest start time
    i = n - 1;
    cout << arrayList[i] << " ";
    selectedArray[0] = arrayList[i];
    selectedIndex++;
    
    // Loop through the array starting from the end
    for (j = n-2; j >= 0; j--)
    {
        /* If this activity has start time greater than or equal to the finish time of the next
         activity then add it to the selected activities*/
        if (s[i] >= f[j])
        {
            cout << arrayList[j] << " ";
            i = j;
            selectedArray[selectedIndex];
            selectedIndex++;
        }
    }
    
    cout << endl << "Total activities selected: " << selectedIndex << endl;
    
}

// driver program to test above function
int main()
{
    ifstream file("act.txt");
    
    int setIndex = 1;
    while(!file.eof()){
        int startTimeArray[1000];
        int finishTimeArray[1000];
        int arrayNumber[1000];
        int size = 0;
        
        /*read in the first line and then convert it an integer as the array size*/
        string sizeString;
        getline(file, sizeString);
        stringstream sizeStream(sizeString);
        
        while(sizeStream) {
            sizeStream >> size;
        }
        
        /*read in the next lines equal to the size and convert them to integers. Fill the arrayNumber
         startTimeArray, and finishTimeArray arrays with these numbers*/
        int positionIndex = 0;
        
        for(int i = 0; i < size; i++) {
            string activityString;
            getline(file, activityString);
            stringstream activityStream(activityString);
            
            int holdArray[3];
            int index = 0;
            while(activityStream) {
                activityStream >> holdArray[index];
                index++;
            }
            
            arrayNumber[positionIndex] = holdArray[0];
            startTimeArray[positionIndex] = holdArray[1];
            finishTimeArray[positionIndex] = holdArray[2];
            
            positionIndex++;
        }
        
        /*sort the arrays by latest start time*/
        InsertionSort(arrayNumber, startTimeArray, finishTimeArray, size);
        
        /*run the arrays through the activity selector algorithm*/
        cout << "Set " << setIndex << endl;
        activitySelect(arrayNumber, startTimeArray, finishTimeArray, size);
        
        setIndex++;
    }
    
    return 0;
}
