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
  Name: bucketstack.c
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
    push("alpha", s);
    printf("This prints \"alpha\":\n");
    printf("%s\n", top(s));
    push("beta", s);
    printf("This prints \"beta\":\n");
    printf("%s\n", top(s));
    push ("gamma", s);
    printf("This prints \"gamma\":\n");
    printf("%s\n", top(s));
    push ("delta", s);
    printf("This prints \"delta\":\n");
    printf("%s\n", top(s));
    printf("This will print the whole stack with a tab before each element: \"delta gamma beta alpha\" across 4 lines, preceded by \"stack is:\" on a line on its own line\n");
    print(s);
    clear(s);
    printf("This will print an empty stack so just \"stack is:\"\n");
    print(s);
    push ("alice", s);
    printf("This will print a stack that only contains \"alice\" preceded by stack is on its own line\n");
    print(s);
    pop (s);
    printf("This will print an empty stack so just \"stack is:\"\n");
    print(s);
    push ("bob", s);
    push ("bob", s);
    printf("This will print the whole stack with a tab before each element: \"bob bob\" across 2 lines preceded by \"stack is:\" on a line on its own\n");

    print(s);
    push("mike", s);
    printf("This will print the whole stack with a tab before each element: \"mike bob bob\" across 3 lines, preceded by \"stack is:\" on a line on its own\n");
    print(s);
    swap(s);
    printf("This will print the whole stack after swapping first two with a tab before each element:\"bob mike bob\" across 3 lines, preceded by \"stack is:\" on a line on its own\n");

    print(s);
    clear(s);
    printf("This will print an empty stack so just \"stack is:\"\n");
    print(s);
    //we will always call this for any stack we test with so
    //make sure it is implemented correctly to free any allocated memory
    destroyStack(&s); 


    return 0;
}