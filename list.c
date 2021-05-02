#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"

void printStack(card *pt){ //prints the entire list
    
    while(pt != NULL){
        printf("%s %d\n", pt->suit, pt->value);
        pt = pt->next;
    }
}

card *findCard(card *h, char query[]){
    
    while(strcmp(h->suit, query) != 0 && h != NULL){
        h = h->next;
    }
    return h;
}

void addCard(card data, card *loc, card **h, card **t){ // adds an element at the end of the  list, updates list head and tail pointers
    
    person *temp = NULL;
    temp = (card *)malloc(sizeof(card)); // memory alloc
    temp->suit=data.suit; //scan for the age
    strcpy(temp->suit, data.suit);
    
    if (*h == NULL){ 
        temp->previous = NULL;
        temp->next = NULL;
        *h = temp;
        *t = temp;
    }
    else if (loc == *t){ 
        temp->next = NULL;
        temp->previous = loc;
        loc->next = temp;
        *t = temp;
    }
    else if (loc == *h){     
        temp->next = *h; 
        temp->previous = NULL; 
        (*h)->previous = temp;
        *h = temp;
    }
    else{
         temp->next = loc->next;
         temp->previous = loc;
         loc->next->previous = temp;
         loc->next = temp;

    }
}



void deleteCard(card *loc, card **h, card **t) {
    if (loc == *h)         // if deleting the first element
        *h = loc->next;     // update the left headp
    else
        loc->previous->next = loc->next;
    
    if (loc == *t)
        *t = loc->previous;     // if deleting the last element
    else
        loc->next->previous = loc->previous;
    
    free(loc); // free memory
}
