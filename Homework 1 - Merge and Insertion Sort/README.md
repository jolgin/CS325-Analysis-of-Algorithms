**List of files**
insertsort.cpp
mergesort.cpp
insertTime.cpp
mergeTime.cpp

Run with g++ on flip and it should work fine. 



(10pts) Merge Sort andInsertion SortPrograms
Implement merge  sort and  insertion  sort to sort anarray/vector  of integers.   Implement  your algorithms  in C++ and name your programs“mergesort.cpp”and “insertsort.cpp”.Your programs  should  compile  with the commands  g++ mergesort.cpp  and g++ insertsort.cpp. Bothprogramsshould  readinputs from a file called “data.txt” where the first value of each line is the number  of integers  that need  to be sorted,  followed by the integers.Examplevalues  for data.txt:4 19 2 5 11 8 1 2 3 4 5 6 1 2
The output  will be written to filescalled “merge.out”and “insert.out”.For the above example the output  would be:2 5 11 191 1 2 2 3 4 5 6 
To receive full credit all code must be commented.
Submit  a copy of your insertsort.cpp  and mergesort.cpp in a ZIP file to TEACH.We will  test execution with aninput file named data.txt.


10 pts 
Merge Sort vs Insertion Sort Running time analysis
The goal of this problem  is to compare the experimental  running  times of the two sorting algorithms.
a)  Now that you have proven  that your code runs  correctlyusing  the data.txt inputfile, you can modify the code to collect running  time  data.  Instead of reading  arrays from thefile data.txt and sorting,  you willnow generate  arrays of size n=5,000, 10,000, 15,000, ...70,000.containing random integer  values  from 0 to 10,000 to sort.  Output  the array size n and time in seconds to the terminal  using  printf or cout.  Name these  new programs  insertTime.cpp  and mergeTime.cpp.  
Submit a copy of the timing programs to TEACH  in the Zip file from problem 4, also include a “text” copy of the modified timing code in the written  HW  submitted in Canvas.

b) Use the systemclock to record the running  times  of each algorithm  for n = 5000, 10000, 15000, 20,000, ....  You may need to modify the values  of n if an algorithm  runs  too fast or too slowto collect the running  time data.  You will need at least sevenvalues of t (time)greater than 0.If there is variability  in the times  between  runs  of the same algorithm  you may want to take the average time ofseveral runs for each value of n.Collect your timing  data on the engineeringserver  flip.Create a table of running  times.
c) For each algorithm  plot the running  time data you collected on an individual  graphwith  n on the x-axis and time on the y-axis.You may use Excel, Matlab, Ror any other software.  Also plot the data from both algorithms  together  on a combined  graph.   Which  graphs  represent  the data best?
d)  What type  of curvebest  fits each data set?  Again  you can use Excel, Matlab,  any software or a graphing  calculator to calculate aregression equation.   Give the equation  of the curvethat best “fits” the data and draw that curve on the graphs  ofcreated in part c).  
e) How do your experimental  running  times compare to the theoretical running  times  of the algorithms?Remember, the experimental running times were “average case” since the input arrays contained  random integers.
