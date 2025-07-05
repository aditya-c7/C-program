#include <stdio.h>
#include <windows.h>
#include <string.h>


void loadingEffect()
{
    printf("Encrypting");
    fflush(stdout);

    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
        Sleep(1000); //
    }
    printf("\r                                                                   \r");
}

int main()
{
    printf("Welcome to the Encryption [ME1.O]\n");

    char message[101], choice;
    int key, i;

    do
    {
        printf("\n\033[1;32mPress 'E' to Encrypt & 'D' to Decrypt: \033[0m");
        scanf(" %c", &choice);
        getchar(); //

        if (choice == 'E' || choice == 'e')
        {
            printf("\nEnter the message: ");
            fgets(message, sizeof(message), stdin);

            printf("\nEnter the E-Key: ");
            scanf("%d", &key);
            getchar(); //

            for (i = 0; message[i] != '\0'; i++)
            {
                char ch = message[i];

                if (ch >= 32 && ch <= 126)               //Ascii printable charecters onlyy.
                {
                    ch = ((ch - 32 + key) % 95) + 32;
                }
                message[i] = ch;
            }
            loadingEffect();
            printf("\n\033[36mEncrypted Message is:> %s\033[0m\n\n", message);
        }
        else if (choice == 'D' || choice == 'd')
        {
            printf("\nEnter the message: ");
            fgets(message, sizeof(message), stdin);

            printf("\nEnter the E-Key: ");
            scanf("%d", &key);
            getchar(); // flush

            for (i = 0; message[i] != '\0'; i++)
            {
                char ch = message[i];
                if (ch >= 32 && ch <= 126)
                {
                    ch = ((ch - 32 - key + 95) % 95) + 32;
                }
                message[i] = ch;
            }
            loadingEffect();
            printf("\n\033[36mDecrypted message is:> %s\033[0m\n\n", message);
        }
        else
        {
            break;
        }

    } while (1);

    return 0;
}
