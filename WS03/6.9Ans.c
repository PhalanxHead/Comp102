/* A solution to Ex 6.9 in the textbook
 * Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    18/08/2018
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* Defines */
    /* The set of valid coins */
    /* NOTE: Typically global arrays like this aren't ideal */
int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};
int coins_len = 8;

/* Functional Prototypes */
int try_one_coin(int *cents, int coin);
void print_change(int cents);
int round_to_5(int cents);

/****************************************************************************/

int
main(int argc, char* argv[]) {

    int total;

    printf("Enter an integer number of cents to divide up: ");

    if(scanf("%d", &total) != 1) {
        printf("Please enter an integer total of cents.\n");
        exit(EXIT_FAILURE);
    }

    /* Override the total inputted */
    total = round_to_5(total);

    print_change(total);
    return 0;
}

/****************************************************************************/

int
try_one_coin(int *cents, int coin) 
/* Takes a value of cents and reduces it by the maximum amount 
 * allowed by the coin type.
 * Inputs:
 *      int* cents - The pointer to the total value left to divvie up
 *      int coin - The type of coin to use.
 */
{
    int coin_count = 0;

    /* Reduce the amount of cents by coin until you can't anymore */
    while(*cents > (*cents % coin)) {
        *cents -= coin;
        coin_count++;
    }

    return coin_count;
}

/****************************************************************************/

void
print_change(int cents)
/* Prints the optimal number of coins needed to make up cents
 * Input:
 *      int cents - The number of cents to divide up
 */
{
    int i;
    int coin_num;
    for (i = 0; i < coins_len; i++) {
        if((coin_num = try_one_coin(&cents, coins[i])) > 0) {
            if(coins[i] == 200) {
                printf("%2d x 2 dollar coins are needed.\n", coin_num);
            } else if (coins[i] == 100) {
                printf("%2d x 1 dollar coins are needed.\n", coin_num);
            } else {
                printf("%2d x %2d cent coins are needed.\n", coin_num, coins[i]);
            }
        }
    }
}

/****************************************************************************/

int
round_to_5(int cents)
/* Returns the input value rounded to the nearest 5 cents 
 * Input:
 *      int cents - The number of cents to round
 */
{
    /* Typically these "Magic Numbers" are considered poor form
        but it's pretty obvious in this context what they are. */
    if((cents % 5) >= 3) {
        /* Want the difference between 5 and what we have */
        return cents + (5 - (cents % 5));

    } else {
        return cents - (cents % 5);

    }
}

/****************************************************************************/