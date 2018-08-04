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
    if(scanf("%lf%c", &sfrom, &scale) != 2) {
        printf("Please enter measurements as follows: 212F\n");
        // Return 1 to the kernel - implies something wasn't right.
        return 1;

    } else if(scale == 'F') {
        sto = ((sfrom - tempoffset) * far2celfact);
        printf("The temperature %.1fF converts to %.1fC \n",
            sfrom, sto);
        return 1;

    } else if(scale == 'C') {
        sto = ((sfrom * cel2farfact) + tempoffset);
        printf("The temperature %.1fC converts to %.1fF \n",
            sfrom, sto);
        return 1;

    } else if(scale == 'M') {
        sto = sfrom * distfact;
        printf("The distance %.3f miles converts to %.3f kilometers \n",
                sfrom, sto);
        return 1;

    } else if(scale == 'K') {
        sto = (sfrom / distfact);
        printf("The distance %.3f kilometers converts to %.3f miles \n",
                sfrom, sto);
        return 1;

    } else if(scale == 'P') {
        sto = (sfrom  * massfact);
        printf("The mass %.3f pounds converts to %.0f grammes \n",
            sfrom, sto);
        return 1;

    } else if(scale == 'G') {
        sto = (sfrom / massfact);
        printf("The mass %.3f grammes converts to %.3f pounds \n",
            sfrom, sto);
        return 1;

    } else {
        printf("Please enter measurements as follows: 212F\n");
    }

    return 0;
}
