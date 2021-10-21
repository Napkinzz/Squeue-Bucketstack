/*CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Lukas Waschuk

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the 
author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology 
at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. 
The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the 
duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will 
be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this 
software is found in any public website or public repository, the person finding it is kindly requested to immediately report, 
including the URL or other repository locating information, to the following email addresses:

//nadi@ualberta.ca
//ildar@ualberta.ca
*/
/*********************************
  Name: test2.c
  Author: Lukas Waschuk
  OneCard: 1660570
  CCID: lwaschuk
  Instructor: Ildar Akhmetov 
  Lecture Section: B1
  Lab Section: H04
  2021-04-07
*********************************/
#include <stdio.h>
#include <stdbool.h>
#include "bucketstack.h"

int main(int argc, char **argv){
    Stack *s = NULL;
    initStack (3, &s);
////////////////////////////////////////////////////////////////////////////////////////////
    printf("TESTING SWAP OVER 2 BUCKETS\n");
    push("alpha", s);
    push("beta", s);
    push("ceta", s);
    push("deta", s);
    print(s);
    swap(s);
    printf("after swap:\n");
    print(s);
    destroyStack(&s); 
    printf("\n\n");
////////////////////////////////////////////////////////////////////////////////////////////
    printf("TESTING BUCKET LEN 1\n");
    initStack (1, &s);
    push("alpha", s);
    push("beta", s);
    push("ceta", s);
    push("deta", s);
    print(s);
    destroyStack(&s);
////////////////////////////////////////////////////////////////////////////////////////////
    /*
    //commented out cause it dumps core 
    //assertion error works when trying to pop from a empty stack
    printf("TESTING POP FROM EMPTY BUCKET\n");
    initStack (10, &s);
    push("alpha", s);
    push("beta", s);
    push("ceta", s);
    push("deta", s);
    print(s);
    for (int i = 0; i <=5; i++){
        pop(s);
    } destroyStack(&s);
    */
////////////////////////////////////////////////////////////////////////////////////////////
    printf("TESTING BUCKET LEN 100\n");
    initStack (1, &s);
    for (int i=0; i<=100; i++){
        push("alpha", s);
        push("beta", s);
        push("ceta", s);
        push("deta", s);
    } //print(s); // print is toxic with this many elements
    destroyStack(&s);
////////////////////////////////////////////////////////////////////////////////////////////
    /*
    // commented out cause it dumps core
    // assertion error confirmed working 
    printf("TESTING SWAP ON 1 ELEMENT\n");
    initStack (1, &s);
    push("alpha", s);
    print(s);
    swap(s);
    destroyStack(&s);
    */
    printf("TESTING LARGE STACK AND PUSHING TO IT 10000 times\n");
    initStack (100, &s);
    for (int i = 0; i <=10000; i++){
        push("APLHA", s);
    }
    destroyStack(&s);
    return 0;
}