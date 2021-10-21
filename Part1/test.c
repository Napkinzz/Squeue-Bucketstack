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
  Name: test.c
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
  initSqueue (&s1);
  addFront (s1, "alpha");
  addFront (s1, "beta");
  addFront (s1, "gamma");
  addBack (s1, "delta");
  printf("This prints \"gamma beta alpha delta\" across four lines with a tab before each element, and preceded by\"squeue is:\" on its own line:\n");
  print (s1, 'f');
  printf("This prints \"delta alpha beta gamma\" across four lines with a tab before each element, and preceded by \"stack is:\" on its own line:\n");
  print (s1, 'r');
  mergeFront(s1, 'f');
  printf("This prints \"gammabeta alpha delta\" across three lines with a tab before each element, and preceded by \"squeue is:\" on its own line:\n");
  print(s1, 'f');
  mergeBack(s1, 'r');
  printf("This prints \"gammabeta deltaalpha\" across two lines with a tab before each element, and preceded by  \"squeue is:\" on its own line:\n");
  print(s1, 'f');
  leaveFront (s1);
  printf("This prints \"deltaalpha\" in one line with a tab before each element, and preceded by \"squeue is:\" on its own line:e\n");
  print(s1, 'f');
  addFront(s1, "zeta");
  addFront(s1, "eta");
  leaveBack (s1);
  printf("This prints \"eta zeta\" across two lines with a tab before each element, and preceded by \"squeue is:\" on its own line:\n");
  print(s1, 'f');
  printf("This prints \"eta zeta\" in one line \n");
  printf("%s %s\n", peekFront(s1), peekBack(s1));
  printf("This nuke has no output, but is good form to call when done\n");
  nuke (s1);
  printf("This assertion should succeed\n");
  assert (isEmpty (s1));
  printf("Illegal direction should cause error message\n");
  print (s1, 'k');
  addBack (s1, "alpha");
  addBack (s1, "beta");
  addBack (s1, "gamma");
  reverse(s1);
  printf("This prints \"gamma beta alpha\" across two lines with a tab before each element, and preceded by \"squeue is:\" on its own line:\n");
  print(s1, 'f');
  //we will always call this for any squeue we test with so make sure
  //it is implemented correctly
  //to free any allocated memory
  destroySqueue(&s1);
  return 0;
}