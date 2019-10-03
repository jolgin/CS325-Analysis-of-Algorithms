file list:
stoogesort.cpp

It will run successfully with g++ stoogesort.cpp on flip

Consider the following pseudocode  for a sortingalgorithm.
StoogeSort(A[0 ... n -1])
if n = 2 and A[0] > A[1] 
	swap A[0] and A[1] 
else if n > 2 
	m= ceiling(2n/3) 
	StoogeSort(A[0 ... m-1]) 
	StoogeSort(A[n -m... n -1]) 
	Stoogesort(A[0 ... m-1]) 

a)Would  STOOGESORT still sort correctly if we replaced  k = ceiling(2n/3)  with k= floor(2n/3)?   If yes prove if no give  a counterexample.  (Hint:  what happens  when n = 4?) 
b)State a recurrence  for the number  of comparisons  executed  by STOOGESORT. 
c)Solve the recurrence  to determine  the asymptotic  running  time. 


a)Implement  STOOGESORT  from Problem4to sort an array/vector  of integers.   Implement  the algorithmin C++, your program  should  compile with g++ stoogesort.cpp.Your program  should be able to read inputs from a file called “data.txt” where the first value of each line is the number  of integers  that need  to be sorted,  followed by the integers(like  in HW 1).The output will be written  to a file called “stooge.out”.

b)Now that you have proven  that your code runs  correctly using  the data.txt input  file, you can modify the code to collect running  time  data.  Instead of reading  arrays from a file to sort, you will now generate  arrays of size n containing  random  integer  values and then time how long it takes to sort the arrays. We will not be executing  the code that generates  the running  time data so it does not have tobe submitted to TEACH or even execute on flip. Include a “text” copy of the modified  code in the written  HW submitted  in Canvas.You will need at least seven  values of t (time)  greater than  0.  If there  is variability  in the  times between  runs  of the algorithm  you may want to take the average  time of several runs  for each value of n.

c)Plotthe running  time data you collected on an individual  graph  with  n on the x-axis and time on the y-axis.  You may use Excel, Matlab,  R or any other software.  Also plot the data from Stoogealgorithmtogether  on a combined  graphwith  your results  for merge  and  insertion  sort from HW1.  

d)What type of curve best fits the StoogeSortdata set?  Give the equation  of the curve  that best “fits” the data and draw that curve on the graphs  of created in part c).    How does your experimental  running  timecompare to the theoretical  running  timeof the algorithm?   