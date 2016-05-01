#define TABLESIZE 10
#include <time.h>

typedef struct world world;
struct world {
    int table[TABLESIZE][TABLESIZE];
};
//Random function
int randInt() {
    int r = rand() %3;
//we create 2 cases for dead to avoid overcrowding
    switch (r) {
case 0 :
    r = 48;//0 newborn
    break;
case 1 :
    r = 45;//- dead
    break;
case 2 :
    r = 45;//- dead
    break;
    }
    return r;
  }
//Create a world randomly
void randomWorld(world* newworld)
{
    int i, j;
    //Change the random seed to get different worlds each time the program is launched
    time_t t;
    srand(time(NULL));

    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            newworld->table[i][j] = randInt();
        }
    }
}
//An example world to show everything works as it's supposed to
void exampleWorld1(world* newworld)
{
    int i, j;
    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            if (
                ((i==0)&&(j==1))||((i==1)&&(j==2))||((i==2)&&(j==0))||((i==2)&&(j==1))||((i==2)&&(j==2))
                )
            {
                newworld->table[i][j] = 48;
            }
            else {newworld->table[i][j] = 45;}
        }
    }
}
void exampleWorld2(world* newworld)
{
    int i, j;
    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            if (
                ((i==2)&&(j==3))||((i==2)&&(j==4))||((i==2)&&(j==5))||((i==4)&&(j==4))||((i==6)&&(j==3))||((i==6)&&(j==4))||((i==6)&&(j==5))

                )
            {
                newworld->table[i][j] = 48;
            }
            else {newworld->table[i][j] = 45;}
        }
    }
}
void exampleWorld3(world* newworld)
{
    int i, j;
    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            if (
                ((i==0)&&(j==4))||((i==0)&&(j==5))||((i==4)&&(j==0))||((i==5)&&(j==0))||((i==9)&&(j==4))||((i==9)&&(j==5))||((i==4)&&(j==9))||((i==5)&&(j==9))
                ||((i==1)&&(j==3))||((i==2)&&(j==3))||((i==3)&&(j==3))||((i==1)&&(j==6))||((i==2)&&(j==6))||((i==3)&&(j==6))||((i==2)&&(j==4))||((i==2)&&(j==5))
                ||((i==3)&&(j==1))||((i==6)&&(j==1))||((i==3)&&(j==8))||((i==6)&&(j==8))
                ||((i==6)&&(j==3))||((i==6)&&(j==6))||((i==7)&&(j==3))||((i==7)&&(j==6))||((i==7)&&(j==4))||((i==7)&&(j==5))||((i==8)&&(j==3))||((i==8)&&(j==6))
                )
            {
                newworld->table[i][j] = 48;
            }
            else {newworld->table[i][j] = 45;}
        }
    }
}
void exampleWorld4(world* newworld)
{
    int i, j;
    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            if (
                ((i==3)&&(j==4))||((i==4)&&(j==3))||((i==4)&&(j==4))||((i==4)&&(j==5))||((i==5)&&(j==4))
                )
            {
                newworld->table[i][j] = 48;
            }
            else {newworld->table[i][j] = 45;}
        }
    }
}
//The display function
void displayWorld(world* thisworld)
{
    int i, j;
    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            printf(" %c", thisworld->table[i][j]);
        }
        printf("\n");
    }
}
//Function with all the rules to get the next generation
void newGen(world* thisGen, int* counter)
{
    world nextGen;
    int i, j, checkSum=0;
    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            if (thisGen->table[i][j]==45) //if cell is dead
            {
                if ((thisGen->table[i-1][j-1]==43 || thisGen->table[i-1][j-1] ==48 )&& (i-1) >= 0 && (j-1) >= 0){checkSum++ ;}
                if ((thisGen->table[i-1][j]==43  || thisGen->table[i-1][j] ==48 )&& (i-1) >= 0){checkSum++ ;}
                if ((thisGen->table[i-1][j+1]==43  || thisGen->table[i-1][j+1] ==48 )&& (i-1) >= 0 && (j+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i][j-1]==43  || thisGen->table[i][j-1] ==48 )&& (j-1) >= 0 ){checkSum++ ;}
                if ((thisGen->table[i][j+1]==43  || thisGen->table[i][j+1] ==48 )&& (j+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i+1][j-1]==43  || thisGen->table[i+1][j-1] ==48 )&&(j-1) >= 0 && (i+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i+1][j]==43  || thisGen->table[i+1][j] ==48 )&& (i+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i+1][j+1]==43  || thisGen->table[i+1][j+1] ==48  )&& (i+1) < TABLESIZE && (j+1) < TABLESIZE){checkSum++ ;}
                //printf("deads : %d \n", checkSum);//Debug only
                if (checkSum == 3){nextGen.table[i][j]=48 ;} //dead to newborn
                else {nextGen.table[i][j]=45;}
                checkSum=0;
            }
            else if (thisGen->table[i][j]==43 || thisGen->table[i][j]==48) //if cell is alive or newborn
            {
                if ((thisGen->table[i-1][j-1]==43 || thisGen->table[i-1][j-1] ==48 )&& (i-1) >= 0 && (j-1) >= 0){checkSum++ ;}
                if ((thisGen->table[i-1][j]==43  || thisGen->table[i-1][j] ==48 )&& (i-1) >= 0){checkSum++ ;}
                if ((thisGen->table[i-1][j+1]==43  || thisGen->table[i-1][j+1] ==48 )&& (i-1) >= 0 && (j+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i][j-1]==43  || thisGen->table[i][j-1] ==48 )&& (j-1) >= 0 ){checkSum++ ;}
                if ((thisGen->table[i][j+1]==43  || thisGen->table[i][j+1] ==48 )&& (j+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i+1][j-1]==43  || thisGen->table[i+1][j-1] ==48 )&&(j-1) >= 0 && (i+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i+1][j]==43  || thisGen->table[i+1][j] ==48 )&& (i+1) < TABLESIZE){checkSum++ ;}
                if ((thisGen->table[i+1][j+1]==43  || thisGen->table[i+1][j+1] ==48  )&& (i+1) < 10 && (j+1) < TABLESIZE){checkSum++ ;}
                //printf("alives : %d \n", checkSum); //debug only
                if (checkSum < 2 || checkSum > 3 ){nextGen.table[i][j]=45 ;} //alive to dead
                else if (checkSum == 2 || checkSum == 3){nextGen.table[i][j]=43 ;} //cell stays alive or newborn to alive
                else {nextGen.table[i][j]=thisGen->table[i][j];}
                checkSum=0;
            }
            else {nextGen.table[i][j]=thisGen->table[i][j];}
        }
    }
    displayWorld(&nextGen); //display the new generation
    //set thisGen to nextGen to calculate the next generation when the function is called again
    for (i=0 ; i<TABLESIZE; i++)
    {
        for (j=0 ; j<TABLESIZE; j++)
        {
            thisGen->table[i][j]=nextGen.table[i][j];
        }
    }
        *counter = 1;
}
