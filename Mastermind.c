#include<stdio.h>//C standard input and output library
#include<stdlib.h> // C Standard library
#include<time.h> //C standard time library
#include<math.h> //C Standard math library
int uniqueRand(int a[],int size);//Prototype of function to generate unique random numbers
int foundnum(int a[],int size,int value);//Prototype of function to check whether generated random numbers are repeated or not.
int main(void)//Main function
{
    int code[7],n,i,j,k,a,rand_code,rand_num,x,y,size,count,chances;//Declaration of variables
    int guess[7],correct_location[8]={0},correct_number[8]={0},check[9]={0};//Initialization and declaration of arrays
    int corr_loc=0,corr_num=0,playAgain=1;//Initialization of variables

    printf("**********************************************************************\n");
    printf("*                                                                    *\n"); //Welcome Mesage to Player
    printf("*                    WELCOME To MASTERMIND GAME                      *\n");
    printf("*                     Programmer: DHWANI PATEL                       *\n");
    printf("*                                                                    *\n");
    printf("**********************************************************************\n\n");
    printf("!!!!*LET'S START THE GAME AND HAVE SOME FUN*!!!!\n");

    while(playAgain==1)//Starting of while loop
    {
        printf("Enter the number(from 1 to 7) that indicates RAND NUMBERS you want to generate: ");//prompt
        scanf("%1d",&size);//reading the variable size
        rand_code= uniqueRand(code,size);//calling the function uniqueRand
        printf("Random Code is: ");
        for(i=0;i<size;i++)//Loop to print hidden digits of random numbers
        {
            printf("* ",i);
        }//end
        puts("");
        rand_num=rand_code;
        for(i=size-1;i>=0;i--)//LOOP to separate the digits of random numbers
        {
            x=rand_code%10;
            code[i]=x;
            rand_code/=10;
        }//end
        printf("Enter the number(from 1 to 100) that indicates maximum guesses you want to have?: ");
        scanf("%d",&chances);//Reading the number for chances that user wants to guess
        if(chances<0 || chances>100)//Condition to check that chances should be between 1 to 100
        {
            printf(" Please Enter the number from (1 t0 100): ");
            scanf("%d",&chances);
        }
        //For Loop to check the digits and give correct feedback to user
        for(count=1;count<=chances;count++)
        {
            corr_loc=0,corr_num=0;//Initializing the variables inside the loop
            printf("Enter your %d guess with spaces: ",count);//Prompt
            for(i=0;i<size;i++)//for loop to read the digits from player
            {
                scanf("%1d",&guess[i]);
            }
            for(i=0;i<8;i++)//For loop to initiazlize the arrays to give feedback
            {
                correct_location[i]=0;
                correct_number[i]=0;
            }
            for(i=0;i<9;i++)//For loop to initialize the randomly created check array
            {
                check[i]=0;
            }
            for(i=0;i<size;i++)//for loop to check the digits wheather they are in correct location
            {

               if(code[i]==guess[i])//condition to give feedback for correct location
                {
                    correct_location[i]+=1;//if condition is true increament variable
                    check[guess[i]-1]=1;//Also inialize the check array of that digiit to 1 so no further feedback is given for that number
                }
            }

            for(j=0;j<size;j++)//For loop to check the digits if the are the correct numbers
            {
                for(k=0;k<size;k++)//For loop to check all digits of guess with code
                {
                    if(code[j]==guess[k] && check[guess[k]-1]!=1)//Conditions to give feedback for correct numbers
                    {
                        correct_number[k]+=1;//incrementing the variable
                        check[guess[k]-1]=1;//inialize the variable to 1 to avoid repetation of feedabck
                    }
                }
            }

            for(i=0;i<size;i++)//For Loop to add the Corr_LOcation and numbers to variables
            {
                corr_loc+=correct_location[i];
                corr_num+=correct_number[i];
            }
            printf("Correct Location & Number: %d \t Correct Number: %d\n\n",corr_loc,corr_num);//Prompt to give feedback
            if(corr_loc==size)//Condition to check if all digits are correct
            {
                printf("CONGRATULATIONS!! YOU GUESS CORRECT!! YOU WON THE GAME!!\n\n");
                break;
            }
            if(count==chances)//Condition to know the user at the end about what code was
            {
                printf("SORRY!! You Lose the Game! Better Luck next time!!\n");
                printf("The correct guess was %d\n\n",rand_num);
            }

        }//End of MAIN For loop
        printf("DO YOU WANT TO PLAYAGAIN?????\n");//Asking the user to paly again
        printf("PRESS 1 to PLAYAGAIN or 0 to EXIT: ");
        scanf("%d",&playAgain);//Read the variable
        puts("");
        if(playAgain==0)
        {
            printf("\nGOOD BYE!!! HAVE A NICE DAY!!!\n");
        }
    }//End of while loop

}//End of the main
int uniqueRand(int code[],int size)//Defining the function uniqueRand
{
    srand(time(0));//to indicate different time
    int i,j,rand_num;//Declartion
    double rand_code=0;
    for(i=0;i<size;i++)//Loop to genearte the random numbers
    {
        rand_num=rand()%9+1;
        while(foundnum(code,i,rand_num)==1)//Condition to check whether the number is repeated by calling the function foundnum
        {
            rand_num=rand()%9+1;//genrate again the digit
        }
        code[i]=rand_num;//initializing numbers to array
    }
    for(j=size-1;j>=0;j--)//loop to make all different digits as one digit
    {
        rand_code+=code[j]*pow(10,j);
    }

    return rand_code;//Return the code to main
}//end
int foundnum(int code[],int size,int value)//Defining the function found num
{
    int i;
    for(i=0;i<size;i++)//LOOP to check repeated random numbers
    {
        if(value==code[i])
        {
            return 1;//Return 1 to uniqueRand if number is found
        }
    }
    return -1;//Return -1 if number is not found
}//end
