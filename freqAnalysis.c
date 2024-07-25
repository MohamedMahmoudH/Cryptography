#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char key;
    int freq;
}freqAnalysis;

int compare(const void *a ,const void *b)
{
    freqAnalysis *v1 = (freqAnalysis *)a;
    freqAnalysis *v2 = (freqAnalysis *)b;
    return (v2->freq - v1->freq);
}

int main()
{
    int maxSize = 0;
    printf("what is tha max size of your text ?\n");
    scanf("%d",&maxSize);
    getchar();

    printf("\n*************************************** WELCOME TO FREQUANCY ANALYSIS ***************************************\n\n");

    printf("enter the text : ");
    char *text = (char *)calloc(maxSize + 1 , sizeof(char));
    fgets(text , maxSize , stdin);
    size_t len = strlen(text);
    if(len > 0 && text[len - 1] == '\n')text[--len] = '\0';

    freqAnalysis *cipher = (freqAnalysis *)calloc(27 , sizeof(freqAnalysis));
    for(int i = 0 ; i < len ; ++i)
    {
        if(isalpha(text[i]))
        {
            char temp = tolower(text[i]);
            cipher[temp - 'a'].freq++;
        }
    }
    for(char i = 'A' ; i <= 'Z' ; ++i)cipher[i - 'A'].key = i;

    qsort(cipher , 26 , sizeof(freqAnalysis) , compare);

    printf("\nchar   freq\n");
    for(char i = 0 ; i < 26 ; ++i)printf("  %c  :  %d\n",cipher[i].key,cipher[i].freq);
    printf("\nthis is the Key : ");
    for(char i = 0 ; i < 26 ; ++i)printf("%c",cipher[i].key);
    printf("\n\n");


    /***************************************
    /// TEMPLATE FOR ENCRIPTION

    for(int i = 0 ; i < len ; ++i)
    {
        if(isalpha(text[i]))
        {
            char temp = tolower(text[i]);
            switch(temp)
            {
                case 'a': text[i] += '' - 'a'; break;
                case 'b': text[i] += '' - 'b'; break;
                case 'c': text[i] += '' - 'c'; break;
                case 'd': text[i] += '' - 'd'; break;
                case 'e': text[i] += '' - 'e'; break;
                case 'f': text[i] += '' - 'f'; break;
                case 'g': text[i] += '' - 'g'; break;
                case 'h': text[i] += '' - 'h'; break;
                case 'i': text[i] += '' - 'i'; break;
                case 'j': text[i] += '' - 'j'; break;
                case 'k': text[i] += '' - 'k'; break;
                case 'l': text[i] += '' - 'l'; break;
                case 'm': text[i] += '' - 'm'; break;
                case 'n': text[i] += '' - 'n'; break;
                case 'o': text[i] += '' - 'o'; break;
                case 'p': text[i] += '' - 'p'; break;
                case 'q': text[i] += '' - 'q'; break;
                case 'r': text[i] += '' - 'r'; break;
                case 's': text[i] += '' - 's'; break;
                case 't': text[i] += '' - 't'; break;
                case 'u': text[i] += '' - 'u'; break;
                case 'v': text[i] += '' - 'v'; break;
                case 'w': text[i] += '' - 'w'; break;
                case 'x': text[i] += '' - 'x'; break;
                case 'y': text[i] += '' - 'y'; break;
                case 'z': text[i] += '' - 'z'; break;
            }
        }
        printf("%c",text[i]);
    }

    /**********************************************/
    /**********************************************

    /// TEMPLATE FOR DECRIPTION

    for (int i = 0; i < len; ++i) {
        if (isalpha(text[i])) {
            char temp = tolower(text[i]);
            switch (temp)
            {
                case '': text[i] += 'a' - ''; break;
                case '': text[i] += 'b' - ''; break;
                case '': text[i] += 'c' - ''; break;
                case '': text[i] += 'd' - ''; break;
                case '': text[i] += 'e' - ''; break;
                case '': text[i] += 'f' - ''; break;
                case '': text[i] += 'g' - ''; break;
                case '': text[i] += 'h' - ''; break;
                case '': text[i] += 'i' - ''; break;
                case '': text[i] += 'j' - ''; break;
                case '': text[i] += 'k' - ''; break;
                case '': text[i] += 'l' - ''; break;
                case '': text[i] += 'm' - ''; break;
                case '': text[i] += 'n' - ''; break;
                case '': text[i] += 'o' - ''; break;
                case '': text[i] += 'p' - ''; break;
                case '': text[i] += 'q' - ''; break;
                case '': text[i] += 'r' - ''; break;
                case '': text[i] += 's' - ''; break;
                case '': text[i] += 't' - ''; break;
                case '': text[i] += 'u' - ''; break;
                case '': text[i] += 'v' - ''; break;
                case '': text[i] += 'w' - ''; break;
                case '': text[i] += 'x' - ''; break;
                case '': text[i] += 'y' - ''; break;
                case '': text[i] += 'z' - ''; break;
            }
        }
        printf("%c", text[i]);
    }

    /**********************************************/
