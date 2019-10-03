Files: 
bin.cpp

Instructions:
Runs successfully with g++ bin.cpp


CS 325-Homework Assignment 8

Problem:Inthebin packing problem, itemsof different weights (or sizes) must be packed into a finite number of bins each with the capacity Cin a way that minimizes the number of bins used.Thedecision version of the bin packing problem(deciding if objects will fitinto <= kbins) isNP-complete.Thereis no known polynomial time algorithm to solve the optimization version of the bin packing problem.  In this homework you will be examiningtwo greedy approximation algorithmsto solve the bin packing problem.
First-Fit:Put each item as you come to it into the first (earliest opened) bin into which it fits.  If there is no available bin then open a new bin.
First-Fit-Decreasing: First sort the items in decreasing order by size, then use First-Fit on the resulting list.

a)  Give pseudo code and the running time for each of the approximation algorithms.
b) Implementin C++.  Both algorithmsshould be in a program called bin.cpp.  Your program should read in a text filenamed bin.txt with multiple test cases as explained below and output tothe terminal the number of bins each algorithm calculated for each test case.Your programshould run with the command g++bin.cpp

Example bin.txt:   The first line is the number of test cases,followed by the capacity of bins for thattest case, the number of itemsand then the weight of each item.  You can assume that the weight of an item does not exceed the capacity of a bin for that problem.
2
10
6
5 10 2 5 4 4
10
20
4 4 4 4 4 4 4 4 4 4 6 6 6 6 6 6 6 6 6 6
Sample output:Test Case 1 First Fit : 4-First Fit Decreasing : 3Test Case 2First Fit : 15-First Fit Decreasing : 10c) Summarize your results onrandomly generatedsample input.Which algorithm performs better?  How often?EXTRA CREDIT:An exactsolutionto the bin packing optimization problem can be found using 0-1 integer programming(IP)see the formaton the Wikipedia page. Write a program named binIP.cpp that takes as input the bin.txt file and produces as output the correspondingproblems in integer programmingformatthat can be solved using LINDO orMatlab.Compare the optimal solutionsfrom the integer programming solutionsto your results using the approximation algorithms. Submit binIP.cpp and the IPfiles along with a verbal description, running time and README file.