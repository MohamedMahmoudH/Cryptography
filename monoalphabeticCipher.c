#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int maxSize = 0;
    printf("what is tha max size of your text ?\n");
    scanf("%d",&maxSize);

    printf("\n*************************************** WELCOME TO MONOALPHABETIC CIPHER ***************************************\n\n");

    char *text = (char *)calloc(maxSize + 1 , sizeof(char));
    getchar();
    printf("Enter The Text: ");
    fgets(text, maxSize + 1, stdin);
    size_t len = strlen(text);
    if ((len > 0) && (text[len - 1] == '\n')) text[--len] = '\0';

    char op = '0';
    do
    {
        printf("which is the operator e/d : ");
        scanf(" %c",&op);
        op = tolower(op);
    }while('e' != op && 'd' != op);

    char key[27] , temp;
    key[26] = '\0';
    printf("Enter the Key : ");
    for(char i = 'a' ; i <= 'z' ; ++i)
    {
        scanf(" %c",&temp);
        temp = tolower(temp);
        if('d' == op) key[temp - 'a'] = i;
        else key[i - 'a'] = temp;
    }

    for(int i = 0 ; i < len ; ++i)
    {
        if(isalpha(text[i]))
        {
            temp = tolower(text[i]);
            text[i] += key[temp - 'a'] - temp; // this handle small and capital char
        }
        printf("%c",text[i]);
    }
}
