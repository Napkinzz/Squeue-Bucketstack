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
  Name: squeue.c
  Author: Lukas Waschuk
  OneCard: 1660570
  CCID: lwaschuk
  Instructor: Ildar Akhmetov 
  Lecture Section: B1
  Lab Section: H04
  2021-04-07
*********************************/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct Node{
    char* val;
    struct Node* next;
    struct Node* prev;
};

typedef struct{
    struct Node* first;
    struct Node* last;
} Squeue;

void initSqueue (Squeue ** squeue){
/*  Purpose: To initalize the squeue
    Para: Squeue >> **squeue
    Returns: None
*/
    Squeue *init;
    init = malloc(sizeof(Squeue));
    init->first = NULL;
    init->last = NULL;
    *squeue = init;
}

bool isEmpty (const Squeue *squeue){
/*  Purpose: To check if the squeue is empty
    Para: const Squeue >> *squeue
    Returns: bool >> true: if nothing is in the squeue
                     false: if there are elements in the squeue
*/
    if (squeue->first == NULL){
        return true;
    }
    return false;
}

int size(Squeue *squeue){
/*  Purpose: Get the size (or number of elements) in the squeue
    Para: Squeue >> *squeue
    Returns: int >> size
*/
    int size = 0;
    struct Node *ptr = squeue->first;
    
    while(ptr != NULL){
        size++;
        ptr = ptr->next; // tranversing the linked list
    }
    return size;
}

void addFront (Squeue *squeue, char* val){
/*  Purpose: Add a item to the front of the squeue
    Para: Squeue >> *squeue
          char* >> val (item to be added)
    Returns: None 
*/
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));

    // setting the directions for new node 
    new_node->next = squeue->first;
    new_node->prev = NULL;
    // allocating space for the string 
    new_node->val = malloc(sizeof(val)*strlen(val));
    strcpy(new_node->val, val);
    // if there is a item in the linked list 
    if (squeue->first != NULL){
        squeue->first->prev = new_node;
    }
    //set pointer to our new node 
    squeue->first = new_node;
    // if last has not been assigned yet, make it point to the new node 
    if (squeue->last == NULL){
        squeue->last = new_node;
    }
}

void addBack (Squeue *squeue, char* val){
/*  Purpose: To add a item to the back of the squeue
    Para: Squeue >> *squeue
          char* >> val
    Returns: None
*/
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    // next will always be null 
    new_node->next = NULL;
    if (squeue->last != NULL){
        new_node->prev = squeue->last; // if there is something before
        squeue->last->next = new_node;
    } else {
        //new_node->prev = squeue->first;// if there is not anything before it 
        new_node->prev = NULL;
    }
    // allocating space for the stirng  
    new_node->val = malloc(sizeof(val)*strlen(val));
    strcpy(new_node->val, val);

    squeue->last = new_node;

    if (squeue->first == NULL){
        squeue->first = new_node;
    }
}

void leaveFront (Squeue *squeue){
/*  Purpose: Remove a item from the front of the squeue
    Para: Squeue >> *squeue
    Returns: None
*/
    assert (!isEmpty(squeue));
    struct Node *ptr = squeue->first;
    squeue->first = squeue->first->next;
    if (squeue->first != NULL){
        squeue->first->prev = NULL;
    }else{
        squeue->last = squeue->first = NULL;
    }
    free(ptr->val);
    free(ptr);
}

char* peekBack (const Squeue *squeue){
/*  Purpose: Check the last item in the squeue
    Para: Squeue >> *squeue 
    Returns: char* >> squeue->last->val (last item in the squeue)
*/
    assert (!isEmpty(squeue));
    return squeue->last->val;
}

void leaveBack (Squeue *squeue){
/*  Purpose: Remove the last item in the squeue
    Para: Squeue >> *squeue
    Returns: None
*/
    assert (!isEmpty(squeue));
    struct Node *ptr = squeue->last;
    squeue->last = squeue->last->prev;
    if (squeue->last != NULL){
        squeue->last->next = NULL;
    }else{ // if there is only 1 item
        squeue->last = squeue->first = NULL;;
    }
    free(ptr->val);
    free(ptr);
}

char* peekFront (const Squeue *squeue){
/*  Purpose: Checks the front item in the squeue
    Para: const Squeue >> *squeue
    Returns: char* >> squeue->first->val;
*/
    assert (!isEmpty(squeue));
    return squeue->first->val;
}

void print (const Squeue *squeue, char direction){
/*  Purpose: to print all the items of the squeue
    Para: const Squeue >> *squeue
          char >> direction
    Returns: None
*/
    struct Node *front_ptr = squeue->first;
    struct Node *back_ptr = squeue->last;

    if (direction == 'f'){
        fprintf(stdout, "squeue is:\n");
        while(front_ptr != NULL){
            fprintf(stdout, "\t%s\n", front_ptr->val);
            front_ptr = front_ptr->next; // tranversing the linked list
        }
    } else if (direction == 'r'){
        fprintf(stdout, "squeue is:\n");
        while(back_ptr != NULL){
            fprintf(stdout, "\t%s\n", back_ptr->val);
            back_ptr = back_ptr->prev; // tranversing the linked list
        }
    } else{
        fprintf(stderr, "Error, illegal direction %c\n", direction);
    }
}

void nuke (Squeue *squeue){
/*  Purpose: To remove all the nodes from the squeue
    Para: Squeue >> *squeue
    Returns: None 
*/
    assert (!isEmpty(squeue));
    struct Node *ptr = squeue->first;
    struct Node *temp;
    while (ptr != NULL){
        temp = ptr;
        ptr = ptr->next; // travserses
        free(temp->val);
        free(temp);
    }
    squeue->first = NULL;
    squeue->last = NULL;
}

void mergeFront(Squeue *squeue, char direction ){
/*  Purpose: To merge the front two elements of the squeue
    Para: Squeue >> *squeue
          char >> direction
    Returns: None 
*/
    assert(squeue->first->next != NULL); // checks is there is 2 items
    struct Node *ptr = squeue->first->next; // this is the node we remove
    if (direction == 'f'){
        //squeue->first->val should equal 4 and times it by the strlen of the two being conbined
        squeue->first->val = realloc(squeue->first->val, (sizeof(squeue->first->val)*(strlen(squeue->first->val)+strlen(squeue->first->next->val))));
        strcat(squeue->first->val, squeue->first->next->val);
    
        if(squeue->last == ptr){ // if last points to the element we are removing
            squeue->last=squeue->first;
        } squeue->first->next = ptr->next;
        if (squeue->first->next != NULL){
            squeue->first->next->prev = squeue->first;
        }
        free(ptr->val);
        free(ptr);
    } else if (direction == 'r'){
        //squeue->first->val should equal 4 times it by the strlen of the two being conbined
        squeue->first->val = realloc(squeue->first->val, (sizeof(squeue->first->val)*(strlen(squeue->first->val)+strlen(squeue->first->next->val))));
        char *temp = malloc(sizeof(squeue->first->val)*strlen(squeue->first->val));
        strcpy(temp, squeue->first->val);
        strcpy(squeue->first->val, squeue->first->next->val);
        strcat(squeue->first->val, temp);

        if(squeue->last == ptr){ // if last points to the element we are removing
            squeue->last=squeue->first;
        } squeue->first->next = ptr->next;
   
        if (squeue->first->next != NULL){
            squeue->first->next->prev = squeue->first;
        }
        free(ptr->val);
        free(ptr);
        free(temp);
    } else {
        fprintf(stderr, "Error, illegal direction %c\n", direction);
    }   
}

void mergeBack(Squeue *squeue, char direction){
/*  Purpose: To merge the last two elements of a squeue
    Para: Squeue >> *squeue
          char >> direction
    Returns: None
*/
    assert(squeue->last->prev != NULL); // checks is there is 2 items
    struct Node *ptr; // this is the node we remove
    if (direction == 'f'){
        ptr = squeue->last->prev;
        //squeue->first->val should equal 4 times it by the strlen of the two being conbined
        squeue->last->prev->val = realloc(squeue->last->prev->val, (sizeof(squeue->last->val)*(strlen(squeue->last->val)+strlen(squeue->last->prev->val))));
        strcat(squeue->last->prev->val, squeue->last->val);
        leaveBack(squeue); // remove the last node of the linked list 
        squeue->last = ptr;
        if(squeue->first == ptr){ // if last points to the element we are removing
            squeue->first=squeue->last;
        }
    } else if (direction == 'r'){
        ptr = squeue->last->prev;
        //squeue->first->val should equal 4 
        // times it by the strlen of the two being conbined
        squeue->last->prev->val = realloc(squeue->last->prev->val, (sizeof(squeue->last->val)*(strlen(squeue->last->val)+strlen(squeue->last->prev->val))));

        char *temp = malloc(sizeof(ptr->val)*strlen(ptr->val));
        strcpy(temp, ptr->val);
        strcpy(ptr->val, squeue->last->val);
        strcat(ptr->val, temp);
        //remove the last node of the list 
        leaveBack(squeue);
        free(temp);
        squeue->last = ptr;
        if(squeue->first == ptr){ // if last points to the element we are removing
            squeue->first=squeue->last;
        }
    } else {
        fprintf(stderr, "Error, illegal direction %c\n", direction);
    }   
}

void reverse(Squeue *squeue){
/*  Purpose: To reverse all of the elements in the squeue
    Para: Squeue >> *squeue
    Returns: None
*/
    struct Node *temp = squeue->first;
    struct Node *temp2 = squeue->last;
    squeue->first = squeue->last;
    squeue->last = temp;
    while (squeue->first != NULL){
        temp = squeue->first->next;
        squeue->first->next = squeue->first->prev;
        squeue->first->prev = temp;
        squeue->first = squeue->first->next; // this will eventually make first null
    }squeue->first = temp2; // set back off of NULL
}

void destroySqueue(Squeue **squeue){
/*  Purpose: To destroy and free all the memory allocated to squeue
    Para: Squeue >> *squeue
    Returns: None
*/
    if (((*squeue)->first != NULL)){
        nuke(*squeue);
    }
    free(*squeue);
    *squeue = NULL;
}