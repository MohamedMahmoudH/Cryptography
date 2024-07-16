#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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
