files:
act.cpp

Instruction:
Runs correctly with g++ act.cpp


Problem 4: (10points)Activity Selection Last-to-StartImplementation

Submit  a copy of all your files including  the txt files and  a README  file that explains  how to compile  and run your  code in a ZIP file to TEACH.  We will only  test execution  with an input file named act.txt.

Using  C++, implement the activity selection last-to-start algorithm described  in problem 3. Your program named “act.cpp”should  compile on the OSU servers.Include a verbal  description  of your algorithm,  pseudocode and analysis  of the theoretical running  time. You do not need to collected experimental running times.

The program  should read input from a file named “act.txt”.  The file contains lists of activity sets with number  of activities in the set in the first line followed by lines containing  the  activity number,  start time & finish time.

Example act.txt:   11
1 14
2 3 5
3 0 6
4 5 7
5 3 9
6 5 9
 
CS 325-Homework Assignment 4

7 6 10
8 8 11
9 8 12
10 2 14
11 12 16
3
3 6 8
1 7 9
2 1 2
In the above example  the first activity set contains 11 activities with activity 1 starting  at time 1 and finishing  at time 4, activity 2 starting  at time 3 and finishing  at time 5, etc..   The second activity set contains 3 activities with activity 3 starting  at time 6and finishing  at time  8 etc.The activities in the file are not in any sorted order.

Your results including  the number  of activities selected and  their order should  be outputted  to the terminal.   For the above example  the results  are:

Set 1
Number  of activities selected = 4
Activities:  2 4 9 11

Set2
Number  of activities selected = 2
Activities: 2 1
Note: There is an alternative  optimal solution  for Set 1.Since activities 8 and 9 have the same start time of 8, a2 a4 a8a11would be an alternative  solution.Your program  only needs  to find one of the optimal solutions. For either  solution the activities differ from the solution  presented  in the text which  uses the earliest-finish  time  criteria.
