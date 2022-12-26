#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<conio.h>


//code for create matrix
void createMatrix(int arr[][4])
{
    int n = 15;
    int num[n],i,j;
    for( i = 0; i < 15; i++ )
        num[i] = i + 1;

    srand(time(NULL));

    int lastindex = n-1,index;

    for( i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(lastindex >= 0)
            {
                index = rand() % (lastindex + 1);
                arr[i][j] = num[index];
                num[index] = num[lastindex--];
            }
        }
    }
    arr[i-1][j-1] = 0; //use for last number do zero.
}

//code for showmatrix

int showmatrix(int arr[][4])
{
    int i,j;
    printf("--------------------\n");
    for(i=0;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
                printf("%2d |", arr[i][j]); //for %2d use for gap between two numbers
            else
                printf("  | ");
        }
        printf("\n");
    } 
    printf("-------------------\n");
}

//code for check winning situation

int winner(int arr[][4])
{
    int i,j,k=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++,k++)
        {
            if(arr[i][j]!=k && k!=16)
                break;
        }
        if(j<4)
            break;
    }
    if(j<4)
        return 0;
    return 1;    
}

//make readenterkey function and call its in main function
int readenteredkey()
{
    char c;
    c = _getch();
    if(c == -32)
        c = _getch();
    return c;
}
//code for shiftup function
int shiftup(int arr[][4])
{
    int i,j,temp;
    for( i = 0; i < 4; i++)
    {
        for( j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if( j < 4)
            break;
    }
    if ( i == 3) //here number swapping not possible
        return 0;
    else{ //here the code of shifting
        temp=arr[i][j];
        arr[i][j]=arr[i+1][j];
        arr[i+1][j]=temp;
        return 1; // shift up successfully create
    }
} 
//code for shiftdown function
int shiftdown(int arr[][4])
{
    int i,j,temp;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(i==0) // here number swapping not possible
        return 0;
    else{ //here the code of shifting
        temp=arr[i][j];
        arr[i][j]=arr[i-1][j];
        arr[i-1][j]=temp;
        return 1; // shift down succesfully create
    }
}

//code for shiftleft function

int shiftleft(int arr[][4])
{
    int i,j,temp;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(j==3)  //number shifting not possible here
        return 0;
    else{ //here the code of shifting
        temp=arr[i][j];
        arr[i][j]=arr[i][j+1];
        arr[i][j+1]=temp;
        return 1; //shift left succesfully create
    }
}

//code for shiftright function

int shiftright(int arr[][4])
{
    int i,j,temp;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(j==0) //here number shifting not possible
        return 0;
    else
    { //code for shifting
        temp=arr[i][j];
        arr[i][j]=arr[i][j-1];
        arr[i][j-1]=temp;
        return 1;//shift right successfully create
    }
    
}

//create game rule function
void gamerule(int arr[][4])
{
    system("cls");
    int i,j,k=1;

    printf("\t\t    ** MATRIX PUZZLE GAME **     \n\n\n");
    printf("\n");
    printf("         *RULE OF THIS GAME*          \n");

    printf("\nRule-1. you can move only 1 step at a time by arrow key.\n");

    printf("\n\t Move up    :   by up arrow key.");
    printf("\n\t Move down  :   by down arrow key.");
    printf("\n\t Move right :   by right arrow key.");
    printf("\n\t Move left  :   by left arrow key.");

    printf("\nRule-2. you can move number at empty position only.\n");
    printf("\n");
    printf("Rule-3. For each valid move: your total number of move will decrease.\n");
    printf("\nRule-4. Winning situation : ");
    printf("Number in a 4*4 matrix should be in order of 1 to 15.\n");
    printf("\n\n                WINNING SITUATION        \n");
    
    printf("----------------------\n");
    for(i=0;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
                printf(" %2d |",4*i+j+1); // %2d use for space between two lines in matrix form
            else
                printf(" | ");
        }
        printf("\n");
    }
    
    printf("---------------------\n");
    printf("\nRule-5.you can exit the game at any time by entered 'E' or 'e'. \n");
    printf("\n*If you want to win this game, you should try minimum no of move*\n");

    printf("\nEnter any key to start..........");

    int x = readenteredkey(); //function call of eneterd key 
}

int main()
{
    int arr[4][4];// here it's a our matrix
    int maxtry=100; // no of maximum moves you gives to the user
    char name[20];
    for(int k=0;k<5;k++)
        printf("\n");
    printf("Player name: ");
    scanf("%s",name);

    system("cls");

    while(1)
    {
        createMatrix(arr); //function calling of 'createMatrix' function.
        gamerule(arr);     //function calling of 'gamerule' function.

        while(!winner(arr))
        {
            system("cls");
            if(!maxtry)
                break;

            printf("\n\n  player name:  %s , move remaining : %d\n\n", name,maxtry);

            showmatrix(arr);

            int key = readenteredkey();

            switch(key)
            {
                case 101: //ascii of e

                case 69: //ascii of E
                    printf("\a\a\a\a\a\a\n       THANKS FOR PLAYING !  \n\a");
                    printf("\nPress 'ENTER' to exit the game \n");
                    key = readenteredkey();
                    return 0;

                case 72: //Arrow up
                    if(shiftup(arr))
                        maxtry--;
                    break;
                case 80: //Arrow down
                    if(shiftdown(arr))
                        maxtry--;
                    break;
                case 77: //Arrow right
                    if(shiftright(arr))
                        maxtry--;
                    break;
                case 75: //Aroow left
                    if(shiftleft(arr))
                        maxtry--;
                    break;
                default:

                    printf("\n\n    \a\aNot Allowed \a");
            }

        }

        if(!maxtry)
            printf("\n\a          YOU LOSE !       \a\a\n");
        else
            printf("\n\a!!!!!!!!congrats %s for winning the game ",name);

            fflush(stdin);
            char check;
            printf("Want to play again ? \n");
            printf("Enter 'y' to play again: ");
            scanf("%c",&check);


            if((check != 'y' && check != 'Y'))
                break;

            maxtry=100;
    }
    return 0;
}

//  THANKS SIR GIVING ME THIS PROJECT !,,,BHUT KUCH NEW LEARN KRNE KO MILA.