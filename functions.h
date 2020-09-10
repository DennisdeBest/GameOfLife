#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define TABLESIZE 40

//Create a structure for world
typedef struct world world;
struct world
{
    int table[TABLESIZE][TABLESIZE];
};

//Function prototypes
int randInt();
void randomWorld(world *newworld);
void displayWorld(world *thisworld);
void newGen(world *thisGen, int *counter);
void exampleWorld1(world *newworld);
void exampleWorld2(world *newworld);
void exampleWorld3(world *newworld);
void exampleWorld4(world *newworld);
#endif // FUNCTIONS_H
