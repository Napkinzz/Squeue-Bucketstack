#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>



struct Node{
    char* val;
    struct Node* next;
    struct Node* prev;
};

typedef struct{
    struct Node* first;
    struct Node* last;
} Squeue;



int main(void){
    Squeue *s1 = NULL;
    s1->first = NULL;
    s1->last  = NULL; 
    struct Node *add;
    struct Node item = {"HELLO", NULL, NULL};
    add = &item;

    return 0;
}