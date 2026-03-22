#include <stdio.h>

void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    input(str1);

    printf("Enter second string: ");
    input(str2);

    concatenate_strings(str1, str2);

    printf("Concatenated string: ");
    display(str1);

    return 0;
}

void input(char *str)
{
    scanf("%s", str);
}

void concatenate_strings(char *str1, char *str2)
{
    int i = 0, j = 0;

    while (str1[i] != '\0')
    {
        i++;
    }

    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';
}

void display(char *str)
{
    printf("%s\n", str);
}