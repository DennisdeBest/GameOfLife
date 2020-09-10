#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    //initialize the variables
    int i, j, counter = 0, counter2 = 0;
    char userContinue, userChoice;
    world newworld;
    //Ask user to choose the world
    printf("Welcome to a C implementation of Conway's game of life\n\n");
    printf("Select a world to load !\n\n1. Simple glider\n2. The eye\n3. AAAAAAAAAH!!\n4. The cross\n\nOr press any key to create a random World : ");
    scanf("%s", &userChoice);
    printf("\n");
    if (userChoice == '1')
    {
        exampleWorld1(&newworld);
    }
    else if (userChoice == '2')
    {
        exampleWorld2(&newworld);
    }
    else if (userChoice == '3')
    {
        exampleWorld3(&newworld);
    }
    else if (userChoice == '4')
    {
        exampleWorld4(&newworld);
    }
    else
    {
        randomWorld(&newworld);
    }
    //display the chosen world
    displayWorld(&newworld);

    //Start a loop to show the generations
    while (1)
    {
        counter2 += counter;
        printf("\nGeneration %d\n", counter2);
        printf("\n");
        printf("Continue (Y/N) ? ");
        scanf("%s", &userContinue);
        printf("\n");
        if (userContinue == 'N' || userContinue == 'n')
        {
            break;
        }
        newGen(&newworld, &counter);
    }
    return 0;
}
