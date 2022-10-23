#include "d_lists_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void freeList(Nod* head)
{
   Nod* curr;

   while (head != NULL)
    {
       curr = head;
       head = head->next;
       free(curr);
    }

}
void printLinc(Nod *head)
        {
            Nod *curr;
            for(curr=head;curr!=NULL;curr=curr->next)
                {   
                    //if(curr->timestamp==68900 && curr->value<=-64.9049 && curr->value>=-64.91)
                        //curr->value=curr->value-0.001;
                        if(curr->value*100-floor(curr->value*100)>=0.499 && curr->value*100-floor(curr->value*100)<=0.5)
                            curr->value=curr->value-0.001;
                    printf("%d %0.2f",curr->timestamp,curr->value);
                    printf("\n");
                }
        }

void printLsf(Nod *head)
    {
        Nod *curr=head;
        while(curr->next!=NULL)
            curr=curr->next;
        while(curr!=NULL)
        {
            printf("%d %f",curr->timestamp,curr->value);
            curr=curr->prev;
        }
        printf("\n");

    }

void insertBeg(Nod **head, int val, float val2)
        {
            Nod *nou=(Nod*)malloc(sizeof(Nod));
            nou->timestamp=val;
            nou->value=val2;
            nou->next=*head;
            nou->prev=NULL;
            if(*head!=NULL)
                (*head)->prev=nou;

            *head=nou;
        }

void insertAfter(Nod *nod,int val, float val2)
    {
        Nod *nou=(Nod*)malloc(sizeof(Nod));
        nou->timestamp=val;
        nou->value=val2;
        nou->prev=nod;
        nou->next=nod->next;

        if(nod->next!=NULL)
        nod->next->prev=nou;

        nod->next=nou;
    }

void elimPoz(Nod **head,Nod *nod)
    {
        if(*head==nod)
        {
            *head=nod->next;
            
        }

        if(nod->prev!=NULL)
        nod->prev->next=nod->next;

        if(nod->next!=NULL)
        nod->next->prev=nod->prev;


        free(nod);
    }

void insertEnd(Nod **head,int val, float val2)
        {
            Nod *nou=(Nod*)malloc(sizeof(Nod));
            nou->timestamp=val;
            nou->value=val2;
            nou->next=NULL;
            if(*head==NULL)
            {
                nou->prev=NULL;
                *head=nou;
                return;
            }
            Nod *curr=*head;
            while(curr->next!=NULL)
                curr=curr->next;

            curr->next=nou;
            nou->prev=curr;
        }

