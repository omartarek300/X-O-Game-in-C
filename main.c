#include <stdio.h>
#include <stdlib.h>
/****************** functions declaration ******************/
void table();
void edit_table();
char check_winner();
/************************************************************/
/***************** Global variables *************************/
char sqrs_values[9] = {'0','1','2','3','4','5','6','7','8'}; // define array hold the values of each square in the table
char player = 1;
char invMov_flag =0; //invalid movement flag
char places = 9;
/************************************************************/
int main()
{
    do
    {
        system("cls"); // clear console
        table (); // draw table with updated values
        edit_table(); // update table values
        if(places == 0)
        {
            break;
        }
    }while( check_winner()!= 1 );
     if(places == 0)
    {
        system("cls");
        table ();
        printf("\n no winner(equality)\n\n");
    }
    else
    {
        system("cls");
        table ();
        printf("\nPlayer %d wins\n\n",player);
    }
    return 0;
}
void table() // function to draw the table of the game
{
    printf("\nPlayer 1 -> X   |   Player 2 -> O \n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |   %c  \n",sqrs_values[0], sqrs_values[1], sqrs_values[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |   %c  \n",sqrs_values[3], sqrs_values[4], sqrs_values[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |   %c  \n",sqrs_values[6], sqrs_values[7], sqrs_values[8]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    if(invMov_flag == 1) // check if the player entered a wrong movement and ask him to try again
    {
        invMov_flag = 0;
        printf("invalid movement try again\n\n");
    }
}
void edit_table() //function to get input from user and edit values of sqrs_values array
{
    char sqr_num, sign;
    printf("player %d enter number of square\n", player); // get the specified square number from user
    scanf("%d",&sqr_num);
    sign = (player == 1)? 'X':'O';  // assign the value of mark regarding the user
    if(sqr_num == 0 && sqrs_values[0] == '0') // check if the choose square is available or not to prevent over writing
    {
        sqrs_values[0] = sign;
        places --;
    }
    else if(sqr_num == 1 && sqrs_values[1] == '1')
    {
        sqrs_values[1] = sign;
        places --;
    }
    else if(sqr_num == 2 && sqrs_values[2] == '2')
    {
        sqrs_values[2] = sign;
        places --;
    }
    else if(sqr_num == 3 && sqrs_values[3] == '3')
    {
        sqrs_values[3] = sign;
        places --;
    }
    else if(sqr_num == 4 && sqrs_values[4] == '4')
    {
        sqrs_values[4] = sign;
        places --;
    }
    else if(sqr_num == 5 && sqrs_values[5] == '5')
    {
        sqrs_values[5] = sign;
        places --;
    }
    else if(sqr_num == 6 && sqrs_values[6] == '6')
    {
        sqrs_values[6] = sign;
        places --;
    }
    else if(sqr_num == 7 && sqrs_values[7] == '7')
    {
        sqrs_values[7] = sign;
        places --;
    }
    else if(sqr_num == 8 && sqrs_values[8] == '8')
    {
        sqrs_values[8] = sign;
        places --;
    }
    else
    {
       invMov_flag = 1;
    }

    if(player == 1 && invMov_flag == 0 && check_winner()!= 1) // if the user entered choose invalid square program asks him to try again and will not switch the users
    {
        player ++;
    }
    else if(player == 2 && invMov_flag == 0 && check_winner()!= 1 )
    {
        player --;
    }
}
char check_winner() // function to specify the winner player by estimating all the possible patterns of win
{
    if(sqrs_values[0] == sqrs_values[1]&& sqrs_values[1] == sqrs_values[2])
    {
        return 1;
    }
    else if(sqrs_values[3] == sqrs_values[4]&& sqrs_values[4] == sqrs_values[5])
    {
        return 1;
    }
    else if(sqrs_values[6] == sqrs_values[7]&& sqrs_values[7] == sqrs_values[8])
    {
        return 1;
    }
    else if(sqrs_values[0] == sqrs_values[3]&& sqrs_values[3] == sqrs_values[6])
    {
        return 1;
    }
    else if(sqrs_values[1] == sqrs_values[4]&& sqrs_values[4] == sqrs_values[7])
    {
        return 1;
    }
    else if(sqrs_values[2] == sqrs_values[5]&& sqrs_values[5] == sqrs_values[8])
    {
        return 1;
    }
    else if(sqrs_values[0] == sqrs_values[4]&& sqrs_values[4] == sqrs_values[8])
    {
        return 1;
    }
    else if(sqrs_values[2] == sqrs_values[4]&& sqrs_values[4] == sqrs_values[6])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
