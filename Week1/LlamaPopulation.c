#include <stdio.h>

int main(void)
{
    while (1) // loop program
    {
        // TODO: Prompt for start size and end size
        int n, nn;
    
        do
        {
            printf("How many llamas do you have? ");
            scanf("%i", &n);
            if (n < 9)
            {
                printf("That's not enough llamas, get more.\n");
            }
        } while (n < 9);
        
        do
        {
            printf("How many llamas do you want? ");
            scanf("%i", &nn);
            if (nn <= n)
            {
                printf("You want MORE llamas.\n");
            }
        } while (nn <= n);

        // TODO: Calculate number of years until we reach threshold
        // Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
        int y = 0;
        while (n < nn)
        {
            n = n + (n / 3) - ( n / 4);
            y++;
            printf("Y: %i, LL: %i\n", y, n);
        }
        

        // TODO: Print number of years
        printf("Years to get to %i llamas: %i\n\n", nn, y);
    }
}
