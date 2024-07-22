#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
/// USE IT IF YOU WANNA KNOW THE ENCRYPTED TEXT WITH ALL KEYS POSSIBLE
int main()
{
    int max_size = 0;
    printf("What is the maximum size do you want?\n");
    scanf("%d", &max_size);

    char *text = (char *)calloc(max_size + 1, sizeof(char));
    getchar();
    printf("\n***************************** WELCOME TO CAESAR CIPHER *****************************\n\n");

    printf("Enter The Text: ");
    fgets(text, max_size + 1, stdin);
    size_t len = strlen(text);
    if ((len > 0) && (text[len - 1] == '\n')) text[--len] = '\0';

    char *text_copy = (char *)calloc(max_size + 1, sizeof(char));
    for (int key = 1; key <= 26; key++)
    {
        strcpy(text_copy, text);
        for (int i = 0; i < len; ++i)
        {
            if (isalpha(text_copy[i]))
            {
                char base = isupper(text_copy[i]) ? 'A' : 'a';
                text_copy[i] = (text_copy[i] - base + key) % 26 + base;
            }
        }
        printf("This is the Encrypted text with Key %2d: %s\n", key, text_copy);
    }
    free(text);
    free(text_copy);
    return 0;
}
*/

/// USE IT IF YOU WANNA KNOW THE ENCRYPTED/DECREPTED TEXT FOR SPECIFIC KEY
int main()
{
    int key = 0;
    char op;

    printf("what is the maximum size do you want?\n");
    scanf("%d",&key);
    const int max_size = key;
    printf("\n***************************** WELCOME TO CAESER CIPHER *****************************\n\n");

    getchar();
    printf("Enter The Text : ");
    char *text = (char *)calloc(max_size + 10 , sizeof(char));
    fgets(text , max_size , stdin);
    size_t len = strlen(text);
    if((len > 0) && (text[len - 1] == '\n'))text[--len] = '\0';
    do
    {
        printf("which is the operator e/d : ");
        scanf(" %c",&op);
        op = tolower(op);
    }while('e' != op && 'd' != op);
    printf("Enter The Key : ");
    scanf("%d",&key);
    key %= 26;

    if('e' == op)key *= -1;
    for(int i = 0 ; i < len ; ++i)
    {
        if(' ' == text[i])continue;
        if(isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] + key - base + 26) % 26 + base;
        }
    }
    printf("\nthis is the %scrypted text : %s" , 'e' == op? "En" : "De" , text);
    free(text);
    return 0;
}
