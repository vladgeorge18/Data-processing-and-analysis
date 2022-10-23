#ifndef D_LISTS_FUNCTIONS_H
#define D_LISTS_FUNCTIONS_H
typedef struct nod
{
    int timestamp,err;
    float value;
    struct nod *next;
    struct nod *prev;
}Nod;



void freeList(Nod* head);
void printLinc(Nod *head);
void printLsf(Nod *head);
void insertBeg(Nod **head, int val,float val2);
void insertAfter(Nod *nod,int val,float val2);
void elimPoz(Nod **head,Nod *nod);
void insertEnd(Nod **head,int val,float val2);
#endif