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
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct NodeBucket {
    char** val;
    struct NodeBucket* next;
};

typedef struct {
    struct NodeBucket* firstBucket;
    int topElt;
    int bucketSize;
} Stack;

void initStack (int bucketSize, Stack **stack){
/*  Purpose: to initalize the stack and make it usable (i.e change from NULL to a actual stack structure)
    Para: int >> bucketsize
          Stack >> **stack
    Returns: None
*/
    Stack *init;
    init = malloc(sizeof(Stack));
    init->bucketSize = bucketSize;
    init->firstBucket = NULL;
    init->topElt = -1;
    *stack = init; // save the newly created stack to the pointer that will point to it 
}

bool isEmpty (const Stack *stack){
/*  Purpose: To check if the stack is empty 
    Para: Stack >> *stack
    Returns: bool >> true if empty
                     false if it has items in the stack
*/
    if (stack->firstBucket == NULL){
        return true;
    }else{
        return false;
    }
}

void push (char* val, Stack *stack){
/*  Purpose: To add items onto the top of the stack, when bucketsize is reached a new bucket is made and filled
    Para: char* >> val (a string)
          Stack >> *stack
    Returns: None
*/
    if (stack->firstBucket == NULL){
        stack->topElt = -1; // setting it back to one 
        //creating the new node 
        struct NodeBucket *new_node;
        new_node = malloc(sizeof(struct NodeBucket));
        //creating the new array to be attached to value
        char** array;
        array = malloc(sizeof(char*) * stack->bucketSize);
        array[0] = malloc(sizeof(char) * strlen(val)+1);
        strcpy(array[0], val);
        stack->topElt += 1;
        //setting the values of next and value and setting the first bucket to point to new_node
        new_node->next = NULL;
        new_node->val = array;
        stack->firstBucket = new_node;   
    } else{
        if (stack->topElt < stack->bucketSize - 1) {
            char **ptr = stack->firstBucket->val;
            ptr[stack->topElt + 1] = malloc(sizeof(char) * strlen(val)+1);
            strcpy(ptr[stack->topElt + 1], val);
            stack->topElt++;
        } else { // when the bucket size is filled add a new bucket node 
            stack->topElt = -1;
            struct NodeBucket *new_node;
            new_node = malloc(sizeof(struct NodeBucket));
            //creating the new array to be attached to value
            char** array;
            array = malloc(sizeof(char*) * stack->bucketSize);
            array[0] = malloc(sizeof(char) * strlen(val)+1);
            strcpy(array[0], val);
            stack->topElt += 1;
            //setting the values of next and value and setting the first bucket to point to new_node
            new_node->next = stack->firstBucket;
            new_node->val = array;
            stack->firstBucket = new_node;
        }
    }
}

void pop(Stack *stack){
/*  Purpose: To remove one item from the top of the stack
    Para: Stack >> *stack
    Returns: None
*/
    assert(!isEmpty(stack));
    struct NodeBucket *ptr = stack->firstBucket;
    free(ptr->val[stack->topElt]);
    stack->topElt--;
    // if after the item is removed and top element equals -1 (empty bucket) move the first bucket pointer to the 
    // next bucket and free everything related to the now empty bucket.
    if (stack->topElt == -1){
        stack->firstBucket = ptr->next;
        free(ptr->val);
        free(ptr);
        stack->topElt = stack->bucketSize-1;
    }
}

int size (const Stack *stack){
/*  Purpose: To get the size of the stack
    Para: const Stack >> *stack
    Returns: int >> size
*/
    int count = 0;
    struct NodeBucket *ptr = stack->firstBucket; // points to the first bucket

    count += stack->topElt +1; // added +1 becuase we start counting at 0 index
    ptr = ptr->next;
    while (ptr != NULL){
        count += stack->bucketSize;
        ptr = ptr->next; // traverses all buckets
    }
    return count;
}

char* top (const Stack *stack){
/*  Purpose: Shows the top element of the stack
    Para: const Stack >> *stack
    Returns: char* >> stack->firstBucket->val[stack->topElt] (which is the top element of the stack)
*/
    return stack->firstBucket->val[stack->topElt];
}

void swap (Stack *stack){
/*  Purpose: Swaps the first two elements of the stack
    Para: Stack >> *stack
    Returns: None
*/
    assert(!((stack->firstBucket->next == NULL) && (stack->topElt < 1))); // making sure there is atleast 2 elements
    // need to add case then there is only 1 in first bucketstack and 5 in another 
    struct NodeBucket *first = stack->firstBucket;
    char *temp;
    if (stack->topElt >= 1){
        temp = first->val[stack->topElt]; // puts top element in temp
        first->val[stack->topElt] = first->val[stack->topElt -1]; // saves second element in first spot
        first->val[stack->topElt -1] = temp; // saves temp(first element) in second spot 
    } else{ // if we need to swap over multiple bucketstacks
        struct NodeBucket *next = stack->firstBucket->next;
        char *temp = first->val[stack->topElt];
        first->val[stack->topElt] = next->val[stack->bucketSize -1];
        next->val[stack->bucketSize -1] = temp;
    } 
}

void print (const Stack *stack){
/*  Purpose: To print all the elements in the stack
    Para: Stack >> *stack
    Returns: None
*/
    struct NodeBucket *ptr = stack->firstBucket;
    //first bucket
    fprintf(stdout, "stack is:\n");
    if (isEmpty(stack)){
        return;
    }   
    for (int i=stack->topElt; i>=0; i--){
            fprintf(stdout, "\t%s\n", ptr->val[i]);
        } ptr = ptr->next; // advance to the next bucket
    while (ptr != NULL){
        for (int i=stack->bucketSize-1; i>=0; i--){
            fprintf(stdout, "\t%s\n", ptr->val[i]);
        } ptr = ptr->next;
    }   
}

void clear(Stack *stack){
/*  Purpose: Frees all the elements in the stack and clears their values
    Para: Stack >> *stack
    Returns: None
*/
    struct NodeBucket *ptr = stack->firstBucket;
    struct NodeBucket *temp = ptr;
    //first bucket
    for (int i=stack->topElt; i>=0; i--){
        free(ptr->val[i]);
    }free(ptr->val);
    temp = ptr->next;
    free(ptr);
    ptr = temp;
    // if there is more then 1 bucket
    while (ptr != NULL){
        for (int i=stack->bucketSize-1; i>=0; i--){
            free(ptr->val[i]);
        }free(ptr->val);
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    } stack->firstBucket = NULL;
}

void destroyStack(Stack **stack){
/*  Purpose: To destroy the entire stack and free all the memory allocated to it 
    Para: Stack >> *stack
    Returns: None
*/
    if ((*stack)->firstBucket != NULL){
        clear(*stack);
    } free(*stack);
    *stack = NULL;
}