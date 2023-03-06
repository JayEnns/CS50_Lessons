#include <stdio.h>
#include <string.h>

int main(void)
{
    while (1)
    {
        char numstr[20]; // capped at 18 digits

        // input number as string
        printf("CC#: "); 
        fgets(numstr, 20, stdin);

        // count digits
        int digits = strlen(numstr) - 1;
        printf("digits: %i\n", digits);
        
        // convert string number to int array
        int num[digits];
        for (int i = 0; i < digits; i++) 
        {
            num[i] = numstr[i] - 48;
        }
        
        // starting from end, add 1st digits to sum, 2nd digits *2, add digits, add to sum.
        int sum = 0;
        int iter = 0;
        for (int i = digits - 1; i >= 0; i--) 
        {
            if (iter % 2 == 0)
            {
                sum += num[i];
                iter++;
            }
            else
            {
                int n = num[i] * 2;
                if (n >= 10)
                {
                    n -= 9;
                }
                sum += n;
                iter++;
            }
        }

        //If the total’s last digit is 0 (if the total modulo 10 is congruent to 0), the number is valid
        // VISA:             13, 16 digits, starts 4
        // AMERICAN EXPRESS: 15 digits, starts 34, 37
        // MASTERCARD:       16 digits, starts 51, 52, 53, 54, 55
        if (sum % 10 == 0)
        {
            if ((digits == 13 || digits == 16) && (num[0] == 4))
            {
                printf("VISA");
            }
            else if ((digits == 15) && (num[0] == 3) && (num[1] == 4 || num[1] == 7))
            {
                printf("AMERICAN EXPRESS");
            }
            else if ((digits == 16) && (num[0] == 5) && (num[1] >= 1) && (num[1] <= 5))
            {
                printf("MASTERCARD");
            }
            else
            {
                printf("INVALID");
            }
        }
        else
        {
            printf("INVALID");
        }
        printf("\n\n");
    }
}
