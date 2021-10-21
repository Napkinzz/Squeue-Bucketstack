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
#include "squeue.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>

int main(void){
    Squeue *s1 = NULL;
///////////////////////////////////////////////////////////////////////////////////////
    printf("TESTING ADDFRONT AND LEAVEBACK\n");
    initSqueue (&s1);
    for (int i=0; i < 15; i++){
        addFront(s1, "APLHA");
    }
    for (int i=0; i < 15; i++){
        leaveBack(s1);
    }
    print(s1, 'f');
    destroySqueue(&s1);
///////////////////////////////////////////////////////////////////////////////////////
    printf("TESTING ADDBACK AND LEAVEFRONT\n");
    initSqueue (&s1);
    for (int i=0; i < 15; i++){
        addBack(s1, "APLHA");
    }
    for (int i=0; i < 15; i++){
        leaveFront(s1);
    }
    print(s1, 'f');
    destroySqueue(&s1);
///////////////////////////////////////////////////////////////////////////////////////
    printf("TESTING MERGEFRONT AND MERGEBACK\n");
    initSqueue (&s1);
    for (int i=0; i < 15; i++){
        addBack(s1, "APLHA");
    }
    print(s1, 'f');
    mergeFront(s1, 'f');
    mergeFront(s1, 'f');
    mergeFront(s1, 'f');
    mergeFront(s1, 'r');
    mergeFront(s1, 'r');
    mergeFront(s1, 'r');
    mergeFront(s1, 'r');
    mergeFront(s1, 'r');
    mergeFront(s1, 'f');
    mergeFront(s1, 'f');
    mergeBack(s1, 'f');
    mergeBack(s1, 'f');
    mergeBack(s1, 'f');
    mergeBack(s1, 'f');
    print(s1, 'f');
    destroySqueue(&s1);
///////////////////////////////////////////////////////////////////////////////////////
    printf("TESTING reverse\n");
    initSqueue (&s1);
    addFront (s1, "alpha");
    addFront (s1, "beta");
    addFront (s1, "gamma");
    addFront(s1, "zeta");
    addFront(s1, "eta");
    printf("squeue before reverse\n");
    print(s1, 'f');
    reverse(s1);
    printf("squeue after reverse\n");
    print(s1, 'f');
    reverse(s1);
    printf("squeue after another reverse printed in reverse\n");
    print(s1, 'r');
    destroySqueue(&s1);

    return 0;
}