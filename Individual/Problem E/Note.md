Suppose the number of ways to climb a section of <img src="http://latex.codecogs.com/gif.latex?n"/> stairs is <img src="http://latex.codecogs.com/gif.latex?s_n"/>. We have <img src="http://latex.codecogs.com/gif.latex?s_0=1,s_1=1,s_2=2"/> and <img src="http://latex.codecogs.com/gif.latex?s_n=s_{n-1}+s_{n-2}+s_{n-3}"/>. The official solution uses dynamic programming to calculate them one by one, which has a complexity of <img src="http://latex.codecogs.com/gif.latex?O(n)"/>. My algorithm has time complexity of <img src="http://latex.codecogs.com/gif.latex?O(\log{n})"/> but requires a memory 9 times as large as that solution.

We can write the recursive relation as

<img src="http://latex.codecogs.com/gif.latex?s_n=s_n"/>

<img src="http://latex.codecogs.com/gif.latex?s_{n+1}=s_{n+1}"/>

<img src="http://latex.codecogs.com/gif.latex?s_{n+2}=s_{n+1}+s_n+s_{n-1}"/>

which is equivalent to the matrix relation

/////

<img src="http://latex.codecogs.com/gif.latex?a_{n+1}=\frac{a_n+\frac{x}{a_n}}{2}."/>
