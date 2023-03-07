#include <stdio.h>
#include <string.h>

int msglen = 30; //message length limit

int main(void) 
{
    // get message and key
    char msg[msglen];
    int key = 0;
    printf("MSG: ");
    fgets(msg, msglen, stdin);

    do
    {
        printf("Key 1-25: ");
        scanf("%i", &key);
    } while ((key > 25) || (key < 1));
    
    

    // caeser encrypt message
    char crypt[strlen(msg)];
    for (int i = 0; i < strlen(msg); i++)
    {
        if ((msg[i] >= 48) && (msg[i] <= 57)) // if number
        {
            int k = key;
            while (k > 9) // wrap number list
            {
                k -= 10;
            }
            if ((msg[i] + k) > 57) // final wrap
            {
                crypt[i] = (msg[i] + k) - 10;
            }
            else
            {
                crypt[i] = msg[i] + k;
            }
        }
        else if ((msg[i] >= 65) && (msg[i] <= 90)) // if uppercase letter
        {
            if ((msg[i] + key) > 90) // wrap letter list
            {
                crypt[i] = (msg[i] + key) - 26;
            }
            else
            {
                crypt[i] = msg[i] + key;
            }
        }
        else if ((msg[i] >= 97) && (msg[i] <= 122)) // if lowercase letter
        {
            if ((msg[i] + key) > 122) // wrap letter list
            {
                crypt[i] = (msg[i] + key) - 26;
            }
            else
            {
                crypt[i] = msg[i] + key;
            }
        }
        else
        {
            crypt[i] = msg[i];
        }
    }

    printf("MSG: %s\n", crypt);
    return 0;
}
