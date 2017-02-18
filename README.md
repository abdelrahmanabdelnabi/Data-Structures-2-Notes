
#Welcome to Data Structures II

##Course Logistics
 - lecturer: Prof. Dr. Amr El-Masry
 - T.A:
	 - Eng. Sami Mamdouh
	 - Eng. Mohamed Ibrahim
	 - Eng. Mina Shafik

### Course Content
 - Complexity Analysis
 - Sorting
 - Priority Queues
	 - implementation with heaps
 - Balanced Trees
	 - AVL Trees
 - Hashing
 - File Structure
	  - B-Trees
 - Graphs
 	- Traversal
 	- Minimum Spanning Trees
	- Shortest Path
 
### Grading Policy
### References
CLRS, Introduction to Algorithms, 3rd Edition  
supplmentary reference: [Mathematics for Computer Science][mathcs]
[mathcs]: https://www.cs.princeton.edu/courses/archive/fall06/cos341/handouts/mathcs.pdf
[asymcheatsheet]: http://web.mit.edu/broder/Public/asymptotics-cheatsheet.pdf

## Table of Content
- [Course Logistics](#course-logistics)
	- [Course Content](#course-content)
	- [Grading Policy](#grading-policy)
	- [References](#references)
- [Table of Content](#table-of-content)
- [Week 1](#week 1)
	- [Complexity Analysis](#complexity-analysis)
- [Week 2](#week 2)

## Week 1
### Complexity Analysis
Computer scientists make heavy use of a specialized asymptotic notation to describe the growth of functions approximately. The notation involves six weird little symbols.

see the [mathematics for computer science][mathcs] reference section 11.3 and the [asymtotics cheat sheet][asymcheatsheet] for more details

## Week 2
### Priority Queues
Here is the definition of a priority queue as described in _CLRS_, section 6.5  
A priority queue is a data structure for maintaining a set _S_ of elements, each with an associated value called a _key_. A _max-priority_ queue supports the following operations:  
- INSERT(_S, x_)  
inserts the element _x_ into the set _S_, which is equivalent to the operation _S = S U {x}_. (_U_ means union)  
- MAXIMUM(_S_)  
returns the element of _S_ with the largest key.  
- EXTRACT-MAX(_S_)  
removes and returns the element of _S_ with the largest key.  
- INCREASE-KEY(_S, x, k_)  
increases the value of element _x_’s key to the new value _k_, which is assumed to be at least as large as _x_’s current key value.

### Priority Queues implementation with Heaps
### Solving Recurrence Relations
