files:
	change.cpp
	amount.txt
	change.txt

Instructions:
	To run, use g++ change.cpp. This works successfully. 

CS 325 -Homework Assignment 3 

Problem 5: (10points)Making ChangeImplementation
Implement the DP change algorithm using C++ and name the file change.cpp.Your program should compile with g++ change.cpp on the OSU servers.  The program should read input from a file named “amount.txt”.  The file contains lists of denominations (V) followed on the next line by the amount A.  Example amount.txt:   
1 2 5
10 
1 3 7 12
29
1 2 4 8 
15

In the above example the first line contains the denominations V=(1, 2, 5) and the next line contains the amount A = 10 for which we need change.  There are three different denomination sets and amounts in the above example.  A denomination set will be on a single line and will always start with the 1 “coin”.

The results should be written to a file named change.txt and should contain the denomination set, the amount A, the change result array and the minimum number of coins used. Example change.txt:1 2 5
10
002
2
1 3 7 12
29
0121
4
1 2 4 8
15
1 1 1 1
4

In the above example, to make 29 cents change from the denomination set (1, 3, 7, 12) you need0: 1 cent coin, 1: 3 cent coin, 2: 7 cent coins and 1: 12 cent coin for a total of 4 coins.Submit a copy of all your files including the txt files in a ZIP file to TEACH.  We will only test execution with an input file named amount.txt.Problem 6: 

(4points)Making ChangeExperimental Running time
a)Collect experimental running time data for your algorithm in Problem 4. Explain in detail how you collected the running times.
b)On three separate graphs plot the running time as a function of A, running time as a function of n and running time as a function of nA. Fit trend lines to the data. How do these results compare to the theoretical running time?(Note: n is the number of denominations in the denomination set and A is the amount to make change)