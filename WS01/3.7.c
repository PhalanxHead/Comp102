/*  Author: Luke Hedt
    Date: 04/08/2016
    Name: Converter.c
    Purpose: Converts measurements from varying scales.

    Comments:
*/

// Header files
#include <stdio.h>
#include <stdlib.h>


// Constant Definitions
/* Take a note of the solution in 2.7, using (9.0/5.0)
 * and vice-versa isn't the optimal solution, but it lets me
 * show you how '#define' works in this context.
 */
#define cel2farfact (9.0/5.0)
#define far2celfact (5.0/9.0)
#define tempoffset 32
#define distfact 1.609
#define massfact 454


// Main
int main(int argc, char *argv[])
{
    double sfrom, sto = 0;
    char scale = '\0';

    printf("Please enter a measurement to convert: ");
    /* This is error checking, and a good habit to get into.
     * HOWEVER: It's been brought to my attention that this will never execute.
     * This is because the %c is looking for any character, including a '\n'.
     * Be aware of this side affect, and have a plan around it.
     */
    if(scanf("%lf%c", &sfrom, &scale) != 2) {
        printf("Please enter measurements as follows: 212F\n");
        // Returns 1 to the kernel - implies something wasn't right.
        exit(EXIT_FAILURE);

    } else if(scale == 'F') {
        sto = ((sfrom - tempoffset) * far2celfact);
        printf("The temperature %.1fF converts to %.1fC \n",
            sfrom, sto);

    } else if(scale == 'C') {
        sto = ((sfrom * cel2farfact) + tempoffset);
        printf("The temperature %.1fC converts to %.1fF \n",
            sfrom, sto);

    } else if(scale == 'M') {
        sto = sfrom * distfact;
        printf("The distance %.3f miles converts to %.3f kilometers \n",
                sfrom, sto);

    } else if(scale == 'K') {
        sto = (sfrom / distfact);
        printf("The distance %.3f kilometers converts to %.3f miles \n",
                sfrom, sto);

    } else if(scale == 'P') {
        sto = (sfrom  * massfact);
        printf("The mass %.3f pounds converts to %.0f grammes \n",
            sfrom, sto);

    } else if(scale == 'G') {
        sto = (sfrom / massfact);
        printf("The mass %.3f grammes converts to %.3f pounds \n",
            sfrom, sto);

    /* This executes if all else fails, ie if "scale" isn't valid.
     * ALWAYS have some kind of 'else' as a failsafe.
     */
    } else {
        printf("Please enter measurements as follows: 212F\n");
    }

    return 0;
}
