#include <stdio.h>
#include <string.h>

int msglen = 30; //message length limit

int main(void) 
{
    // get message
    char msg[msglen];
    printf("MSG: ");
    fgets(msg, msglen, stdin);
    
    for (int key = 1; key < 26; key++) // brute force all keys
    {
        // caeser decrypt message in reverse
        char decrypt[strlen(msg)];
        for (int i = 0; i < strlen(msg); i++)
        {
            if ((msg[i] >= 48) && (msg[i] <= 57)) // if number
            {
                int k = key;
                while (k > 9) // wrap number list
                {
                    k -= 10;
                }
                if ((msg[i] - k) < 48) // final wrap
                {
                    decrypt[i] = (msg[i] - k) + 10;
                }
                else
                {
                    decrypt[i] = msg[i] - k;
                }
            }
            else if ((msg[i] >= 65) && (msg[i] <= 90)) // if uppercase letter
            {
                if ((msg[i] - key) < 65) // wrap letter list
                {
                    decrypt[i] = (msg[i] - key) + 26;
                }
                else
                {
                    decrypt[i] = msg[i] - key;
                }
            }
            else if ((msg[i] >= 97) && (msg[i] <= 122)) // if lowercase letter
            {
                if ((msg[i] - key) < 97) // wrap letter list
                {
                    decrypt[i] = (msg[i] - key) + 26;
                }
                else
                {
                    decrypt[i] = msg[i] - key;
                }
            }
            else
            {
                decrypt[i] = msg[i];
            }
        }
        printf("KEY: %i MSG: %s", key, decrypt);
    }

    return 0;
}
