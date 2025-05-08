#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    char ch;
    int chars = 0, words = 0, lines = 0;
    int in_word = 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        chars++;
        if (ch == '\n')
            lines++;
        if (isspace(ch))
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            words++;
        }
    }

    fclose(fp);
    printf("Characters: %d\nWords: %d\nLines: %d\n", chars, words, lines);
    return 0;
}
