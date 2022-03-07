#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct micro
{
    char *name;
    char *vendor;
    float cost;
    int units;
    struct micro *next;
} micro;

micro *create(char *name, char *vendor, double cost, int units)
{
    micro *i = malloc(sizeof(micro));
    // since i is allocated (micro) as a pointer, access fields with ->
    i->name = strdup(name);
    i->vendor = strdup(vendor);
    i->cost = cost;
    i->units = units;
    i->next = NULL;
}

void display(micro *start)
{
    micro *i = start;

    for (; i != NULL; i = i->next)
    {
        printf("Micro: %s, Cost: %f\n", i->name, i->cost);
    }
}

void release(micro *start)
{
    micro *i = start;
    micro *next = NULL;

    for (; i != NULL; i = next)
    {
        next = i->next;
        free(i->name);
        free(i->vendor);
        // free(i->cost);
        // free(i->units);
        free(i);
    }
}

int main(void)
{
    micro *start = NULL;
    micro *i = NULL;
    micro *next = NULL;

    char name[80];
    char vendor[80];
    float cost;
    int units;

    printf("Please enter micro name: ");
    for (; fgets(name, 80, stdin) != NULL; i = next)
    {
        // enter micro details
        printf("Please enter vendor name: ");
        fgets(vendor, 80, stdin);
        printf("Please enter unit cost: ");
        scanf("%f", &cost);
        printf("Please enter units owned: ");
        scanf("%i", &units);

        // create and save into memory
        next = create(name, vendor, cost, units);
        if (start == NULL)
        {
            start = next;
        }
        if (i != NULL)
        {
            i->next = next;
        }
        printf("Please enter micro name: ");
    }

    display(start);
    release(start);

    return 0;
}