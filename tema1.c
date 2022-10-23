#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "d_lists_functions.h"
#include <string.h>

void e1(Nod **head, int *nrp)
{
    Nod *curr = (*head)->next->next, *aux;
    curr->prev->prev->err = 0;
    curr->prev->err = 0;
    float medie, dev;
    int i = 3, ct_elim = 0, j;
    for (i = 3; i <= *nrp - 2; i++)
    {
        medie = 0;
        dev = 0;
        Nod *aux = curr->prev->prev;
        for (j = 1; j <= 5; j++)
        {
            medie = medie + aux->value;
            aux = aux->next;
        }
        medie = medie / 5;
        aux = curr->prev->prev;
        for (j = 1; j <= 5; j++)
        {
            dev = dev + pow(aux->value - medie, 2);
            aux = aux->next;
        }
        dev = dev / 5;
        dev = sqrt(dev);

        if (curr->value < (medie - dev) || curr->value > (medie + dev))
        {
            curr->err = 1;
            ct_elim++;
        }
        else
            curr->err = 0;

        if (curr->prev->prev->err == 1)
            elimPoz(head, curr->prev->prev);

        curr = curr->next;
    }
    if (curr->prev->prev->err == 1)
        elimPoz(head, curr->prev->prev);
    if (curr->prev->err == 1)
        elimPoz(head, curr->prev);

    *nrp = *nrp - ct_elim;
}

Nod *e2(Nod *head, int *nrp)
{
    Nod *new_list = NULL;
    int i, j, ct;
    float a1, a2, a3, a4, a5, aux;
    Nod *curr = head;
    for (ct = 3; ct <= *nrp - 2; ct++)
    {
        a1 = curr->value;
        a2 = curr->next->value;
        a3 = curr->next->next->value;
        a4 = curr->next->next->next->value;
        a5 = curr->next->next->next->next->value;

        if (a1 > a2)
        {
            aux = a1;
            a1 = a2;
            a2 = aux;
        }
        if (a4 > a5)
        {
            aux = a4;
            a4 = a5;
            a5 = aux;
        }
        if (a2 > a5)
        {
            aux = a2;
            a2 = a5;
            a5 = aux;
        }
        if (a3 > a5)
        {
            aux = a3;
            a3 = a5;
            a5 = aux;
        }

        if (a1 > a2)
        {
            aux = a1;
            a1 = a2;
            a2 = aux;
        }
        if (a3 > a4)
        {
            aux = a3;
            a3 = a4;
            a4 = aux;
        }
        if (a2 > a4)
        {
            aux = a2;
            a2 = a4;
            a4 = aux;
        }

        if (a1 > a2)
        {
            aux = a1;
            a1 = a2;
            a2 = aux;
        }

        if (a2 > a3)
        {
            aux = a2;
            a2 = a3;
            a3 = aux;
        }

        insertEnd(&new_list, curr->next->next->timestamp, a3);

        curr = curr->next;
    }
    *nrp = *nrp - 4;
    freeList(head);
    return new_list;
}

Nod *e3(Nod *head, int *nrp)
{
    Nod *new_list = NULL;
    int i, j, ct;
    float medie;

    Nod *curr = head;
    for (ct = 1; ct <= *nrp - 4; ct++)
    {
        medie = (curr->value + curr->next->value + curr->next->next->value + curr->next->next->next->value + curr->next->next->next->next->value) / 5;
        insertEnd(&new_list, curr->next->next->timestamp, medie);
        curr = curr->next;
    }
    *nrp = *nrp - 4;
    //printf("adasd\n");
    freeList(head);
    return new_list;
}

void u(Nod *head)
{
    Nod *curr = head->next;
    while (curr != NULL)
    {
        if (abs(curr->timestamp - curr->prev->timestamp) <= 1000 && abs(curr->timestamp - curr->prev->timestamp) >= 100)
        {
            curr->timestamp = (curr->prev->timestamp + curr->timestamp) / 2;
            curr->value = (curr->prev->value + curr->value) / 2;
        }

        curr = curr->next;
    }
}
void st(Nod *head, int delta)
{
    float mini = 1000000, maxi = -1000000;
    Nod *curr = head;
    int inf, sup;
    while (curr->next != NULL)
    {
        if (curr->value > maxi)
            maxi = curr->value;
        if (curr->value < mini)
            mini = curr->value;

        curr = curr->next;
    }
    if (maxi / delta == 1)
    {
        sup = (int)maxi * delta;
    }
    else
    {
        sup = (int)(maxi / delta) + 1;
        sup = sup * delta;
    }

    if (mini / delta == 1)
    {
        inf = (int)mini * delta;
    }
    else
    {
        inf = (int)(mini / delta) - 1;
        inf = inf * delta;
    }

    int ct = inf + delta;
    while (ct <= sup)
    {
        int nr = 0;

        Nod *curr2 = head;
        while (curr2 != NULL)
        {

            if (curr2->value >= inf && curr2->value <= ct)
                nr++;

            curr2 = curr2->next;
        }
        if (nr != 0)
            printf("[%d, %d] %d\n", inf, ct, nr);
        inf = ct;
        ct = inf + delta;
    }
}
float sum(float i, float k)
{
    float s = 0;
    while (i <= k)
    {
        s = s + pow(i / k, 2) * 0.9 + 0.1;
        i = i + 1;
    }
    return s;
}
void c(Nod *head, int *nrp)
{
    float C, w0, w1, w2, f;
    Nod *curr = head;
    while (curr->next != NULL)
    {
        if (curr->next->timestamp - curr->timestamp > 1000)
        {
            float left3 = curr->value;
            float left2 = curr->prev->value;
            float left1 = curr->prev->prev->value;
            float right3 = curr->next->value;
            float right2 = curr->next->next->value;
            float right1 = curr->next->next->next->value;
            float r = curr->next->timestamp;
            float l = curr->timestamp;
            while (curr->timestamp + 200 < curr->next->timestamp)
            {
                float c = curr->timestamp + 200;
                C = (c - l) / (curr->next->timestamp - l);
                w0 = (pow(0.0 / 2, 2) * 0.9 + 0.1) / sum(0.0, 2.0);
                w1 = (pow(1.0 / 2, 2) * 0.9 + 0.1) / sum(0.0, 2.0);
                w2 = (pow(2.0 / 2, 2) * 0.9 + 0.1) / sum(0.0, 2.0);
                f = (1 - C) * (w0 * left1 + w1 * left2 + w2 * left3) + C * (w0 * right1 + w1 * right2 + w2 * right3);
                insertAfter(curr, curr->timestamp + 200, f);
                curr = curr->next;
                *nrp = *nrp + 1;
            }
        }
        curr = curr->next;
    }
}
int main(int argc, char *argv[])
{
    Nod *head = NULL;
    int nrp, i, tstamp, ok = 0;
    float value;
    scanf("%d", &nrp);
    for (i = 1; i <= nrp; i++)
    {
        scanf("%d%f", &tstamp, &value);

        insertEnd(&head, tstamp, value);
    }
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--e1") == 0)
            e1(&head, &nrp);
        else if (strcmp(argv[i], "--e2") == 0)
        {
            head = e2(head, &nrp);
        }
        else if (strcmp(argv[i], "--e3") == 0)
        {

            head = e3(head, &nrp);
        }
        else if (strcmp(argv[i], "--u") == 0)
            u(head);
        else if (strcmp(argv[i], "--c") == 0)
            c(head, &nrp);
        else if (strstr(argv[i], "st"))
        {
            int delta = atoi(argv[i] + 4);
            st(head, delta);
            ok = 1;
        }
    }

    if (ok == 0)
    {
        printf("%d\n", nrp);
        printLinc(head);
    }
    freeList(head);
}
