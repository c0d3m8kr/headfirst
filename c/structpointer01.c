#include <stdio.h>

typedef struct island
{
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void display_islands(island *start);

int main(void)
{
    island amity = {"Amity", "09:00", "17:00", NULL};
    island craggy = {"Craggy", "09:00", "17:00", NULL};
    island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
    island shutter = {"Shutter", "09:00", "17:00", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    display_islands(&amity);

    return 0;
}

void display_islands(island *start)
{
    for (island *i = start; i != NULL; i = i->next)
    {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}