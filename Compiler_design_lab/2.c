#include <stdio.h>

int main()
{
    char str[1000], newStr[1000];
    int i, j = 0, spaceCount = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            spaceCount++;
        }
        else
        {
            newStr[j++] = str[i];
        }
    }

    newStr[j] = '\0';
    printf("\nTotal white spaces: %d\n", spaceCount);
    printf("String after removing white spaces: %s\n", newStr);

    return 0;
}
