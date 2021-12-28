#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//import libraries to the program 


char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //set an array for each room of the square

int checkwin(); //Prototype of the check win function
void board(); //Prototype of the syntax graphical form function

int ai()
{
    int move = 0,choice; //
    char mark = '@';

    while (move == 0)
    {
        srand(clock());
        choice = rand() % 9 + 1; //generating random numbers for our ai (it's not ai actully it's just a random generator between 1 and 9)

        if (choice == 1 && square[1] == '1') //here and next 8 commands look alike are doing the check for the generated number which published in the prev commands
        {
            square[1] = mark;
            move++;
        }
        else if (choice == 2 && square[2] == '2')
        {
            square[2] = mark;
            move++;
        }
        else if (choice == 3 && square[3] == '3')
        {
            square[3] = mark;
            move++;
        }
        else if (choice == 4 && square[4] == '4')
        {
            square[4] = mark;
            move++;
        }
        else if (choice == 5 && square[5] == '5')
        {
            square[5] = mark;
            move++;
        }
        else if (choice == 6 && square[6] == '6')
        {
            square[6] = mark;
            move++;
        }
        else if (choice == 7 && square[7] == '7')
        {
            square[7] = mark;
            move++;
        }
        else if (choice == 8 && square[8] == '8')
        {
            square[8] = mark;
            move++;
        }
        else if (choice == 9 && square[9] == '9')
        {
            square[9] = mark;
            move++;
        }
    }

    return 0;
}

int user(int user) //here we tracking the user movement in each move 
{
    int choice;
    char mark;
    mark = (user == 1) ? '#' : '@'; //users can be # or @ 
    printf("Player user %d, enter a number:  ",user);
    scanf("%d", &choice);

    if (choice == 1 && square[1] == '1')//same as the ai one this command and next 8 commands will track what room user wants to fill
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;

    else
    {
        printf("Invalid move "); //if the number was less then 1 or more then 9 program will type this error for the user 
        return 0;
    }
    return 0;
}

int main()//the main function which controls the maintace of the game
{
    int player = 1, i,status;

    printf("Play Game with Bot Or User ? (Bot => 1 & User => 2)  :  ");//output an message for the user
    scanf("%d",&status); // scan the move

    do
    {
        board();//calling the syntax graphical form of the game before showing the next move
        player = (player % 2) ? 1 : 2; //define players turn 

        if (status == 1)
        {
            if (player == 1)
            {
                user(player);//in case of playing 1 v AI call this function for user
            }
            else
            {
                ai();//in case of calling 1 v AI call this function for AI
            }
        }
        else
        {
            user(player);//and if user wants to play 1 v 1 call this function
        }

        i = checkwin(); // check win function after rounds

        player++; //counter turns
    }while (i ==  - 1);

    board();//calling the syntax graphical form 

    if (i == 1) //define whcih player won 
        printf("==>\aPlayer %d win ", --player);
    else//or after 9 moves without any win print this message 
        printf("==>\aGame draw");



    return 0;
}
int checkwin() // check win function in case of calling it
{
    if (square[1] == square[2] && square[2] == square[3]) //check win in a row
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])//check win in a row
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])//check win in a row
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])//check win in a column
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])//check win in a column
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])//check win in a column
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])//check win in a diameter
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])//check win in a diameter
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
                                                                         != '7' && square[8] != '8' && square[9] != '9')//in other inputs rooms will be shown by the default

        return 0;
    else
        return  - 1;//this command won't effect in the program it's just for make sure that program works clearly
}
void board()//simple syntax form of the board 
{

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}