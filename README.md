# ASSIGNMENT 3
## The Information of the Creator:

***ASSIGNMENT 3***                                                           
  **Author:** Lukas Waschuk   
  **CCID:** lwaschuk   
  **Date:** 04-15-2021                           

### The Purpose of Your Program:
These programs were made to help the student to visualize / conceptualize various topics related to memory management, linked lists, queues, and stacks in the C programming language. There is two parts to this assignment and both parts include a emphasis on memory management. Part1 directly deals with a ADT called a squeue, which is both a stack and a queue. Part2 is based on another ADT called a bucketStack and is used to save space in larger applications of linked lists and stacks. Using the bucketStack we only waste a maximum of bucketsize-1 elements at any given time.

### The Exact Commands We Need to Run Your Code:
The program was written in C and is optimally compiled using GNU compiler (GCC). The program is ran by simply typing "make" inside the respective folders on the command line and the Makefile will create all the required files and it will create an executable called squeue for part 1, and bucketstack for part 2. To run the executable type:  


           <./squeue              (for part1, remember to be in part 1's folder)
           <./bucketstack         (for part2, remember to be in part 2's folder)



which will print various tests provided by the instructor.   


### The Files Submitted In Your Assignment, How They Are Structured, And What They Do:
The files uploaded are:    
##### PART 1  
**squeue.h:** Header file containing all the function prototypes provided by instructor.  
**squeue.c:** This file contains the definitions of all the functions declared in squeue.h . This is the file that contains all the implementation code.   
**squeue_client.c:** Testing file provided by instructor.  
**test.c:** Additional tests for the squeue, from the assignment outline.  
**test2.c:** Additional tests for the squeue, made by me.  
**Makefile:** Makefile for Part1.   

##### PART 2   
**bucketstack.h:** Header file containing all the function prototypes provided by instructor.  
**bucketstack.c:** This file contains the definitions of all the functions declared in bucketstack.h. This is the file that contains all the implementation code.  
**bucketstack_client.c:** Testing file provided by instructor.    
**test.c:** Additional testing file, from the assignment outline.   
**test2.c:** Additional testing file, made by me.    
**Makefile:** Makefile for Part2. (make test, and make test2, to use the other testing files).    

### References (e.g., any online resources you used in accordance to the course policy):
My references come from CMPUT 201 lecture slides and the textbook C PROGRAMMING by K N KING.
