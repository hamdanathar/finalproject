typedef struct card_s {
    char suit[20];
    int face_value;
    struct card_s *next, *previous;
} card;

void printStack(card *pt);

card *findCard(person *h, char query[]);

void addCard(card data, card *loc, card **h, card **t);

void deleteCard(card *loc, card **h, card **t);
