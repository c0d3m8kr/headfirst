#include <stdio.h>

struct fish
{
    const char *name;
    const char *species;
    int teeth;
    int age;
};

int main()
{
    struct fish carnivorous = {"Black", "Pirahna", 88, 4};

    printf("The %s %s has %i teeth and is %i years old.\n", carnivorous.name,
           carnivorous.species, carnivorous.teeth, carnivorous.age);

    printf("The third letter in Black is: %c\n", carnivorous.name[2]);

    printf("Another letter: %c\n", *(carnivorous.name + 0));

    return 0;
} 