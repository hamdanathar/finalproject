#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"

int main(void) {
    card *headp = NULL;
    card *tailp = NULL;
    card *temp = NULL;
    card newC;
    char userChoice[10];
    
    FILE *inp = fopen("database.txt", "r");     //reading file function from here
    
    while(!feof(inp)){
        fscanf(inp, "%s", newP.name);
        fscanf(inp, "%d", &newP.age);
        addCard(newP, tailp, &headp, &tailp); //till here
    }
    printList(headp);
    
    shuffleCards(); //before dealing out cards
    
    //choosing from discard pile or stack of cards:
    printf("Do you want to choose from the stack of cards or from the discard pile? Enter 'discard' or 'stack'.\n");
    scanf("%s", userChoice);
    //userCard is the card chosen from discard or stack pile
    //addMember(****);
    
    addCard(newC, headp, &headp, &tailp);
    printList(headp);
    
    printf("Which card do you want to discard? e.g. enter "2 h" for 2 of hearts.\n");
    scanf("%d %c", newC.value, newC.suit);
    temp = findCard(headp, newC.name);
    if (temp == NULL)
        printf("Card not found in the database.\n");
    else{
        deleteCard(temp, &headp, &tailp);
        printf("Card %d of %c was discarded from your stack.\n", newC.value, newC.suit);
    }
    
    printList(headp);
    return 0;
}
