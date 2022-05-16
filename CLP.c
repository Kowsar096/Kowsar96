#include "stdio.h"
char* strcat(char arr1[],char arr2[])
{
    int i=0,j=0,len=0;
    while(arr1[i]!='\0')
    {
        i++;
        len++;
    }
    while (arr2[j]!='\0')
    {
        arr1[len+j]=arr2[j];
        j++;
    }
    return arr1;
};
int strlen(char arr[])
{
    int i=0,len=0;
    while(arr[i]!='\0')
    {
        i++;
        len++;
    }
    return len;
};
char* strrev(char arr[])
{
    int i,j,len=strlen(arr);
    static char str[]= {};
    for(i=0,j=len-1; arr[i]!='\0'; i++,j--)
    {
        str[i]=arr[j];
    }
    return str;
};
int strcmp(char arr1[],char arr2[])
{
    int i=0,len1= strlen(arr1),len2 = strlen(arr2);
    if(len1==len2)
    {
        while(i<len1)
        {
            if(arr1[i]==arr2[i])
                i++;
            else
                break;
            if(i==len1)
                return 0;
        }
    }
    else
        return 1;
};
char* strcpy(char arr1[],char arr2[])
{
    int i,j=0;
    for(i=0; arr2[i]!='\0'; i++)
    {
        arr1[j++]=arr2[i];
    }
    arr1[j++]=NULL;
    return arr1;
};
char* strlwr(char arr[])
{
    int i;
    for (i=0; arr[i]!='\0'; i++)
    {
        if(arr[i]>=65 && arr[i]<=90)
            arr[i] = arr[i]+32;
    }
    return arr;
};
char* strupr(char arr[])
{
    int i;
    for (i=0; arr[i]!='\0'; i++)
    {
        if(arr[i]>=97 && arr[i]<=122)
            arr[i] = arr[i]-32;
    }
    return arr;
};
int main()
{
    int choice,start;
    char str1[10000],str3[10000],str4[10000];
    char str2[10000];
start:
    {
        printf("\n\n\n\t\t\t\t1. Concatenate String\n");
        printf("\t\t\t\t2. Length of a String\n");
        printf("\t\t\t\t3. String Reverse\n");
        printf("\t\t\t\t4. Compare two Strings\n");
        printf("\t\t\t\t5. Copy String\n");
        printf("\t\t\t\t6. Lowercase of a String\n");
        printf("\t\t\t\t7. Uppercase of a String\n");
        printf("\t\t\t\tEnter your choice : ");
        scanf("%d",&choice);
    }
    if (choice<1 || choice >7)
    {

        system("cls");
        printf("\t\t\t\tChoose the number from 1 to 7\n");
        goto start;
    }
    switch(choice)
    {
    case 1:
        system("cls");
        printf("\n\n\n\t\t\t\tEnter 1st string : ");
        fflush(stdin);
        gets(str1);
        printf("\t\t\t\tEnter 2nd string : ");
        fflush(stdin);
        gets(str2);
        printf("\t\t\t\tConcatenated string : %s\n",strcat(str1,str2));
        break;
    case 2:
        system("cls");
        printf("\n\n\n\t\t\t\tEnter a string to find the length of the string : ");
        fflush(stdin);
        gets(str1);
        printf("\t\t\t\tLength of the string is : %d\n",strlen(str1));
        break;
    case 3:
        system("cls");
        printf("\n\n\n\t\t\t\tEnter a string o reverse : ");
        fflush(stdin);
        gets(str1);
        printf("\t\t\t\tReverse String : %s\n",strrev(str1));
        break;
    case 4:
        system("cls");
        printf("\n\n\n\t\t\t\t\tEnter 2 strings to compare\n");
        printf("\t\t\t\tEnter 1st string : ");
        fflush(stdin);
        gets(str1);
        printf("\t\t\t\tEnter 2nd string : ");
        fflush(stdin);
        gets(str2);
        if(strcmp(str1,str2)==0)
            printf("\t\t\t\tBoth strings are same\n");
        else
            printf("\nBoth strings are not same\n");
        break;
    case 5:
        system("cls");
        printf("\n\n\n\t\t\t\tEnter a string to copy the string : ");
        fflush(stdin);
        gets(str2);
        /*strcpy(char [](the array that where you want to copy),char [](the array that which string you want to copy))*/
        printf("\t\t\t\tCopied string is : %s\n",strcpy(str1,str2));
        break;
    case 6 :
        system("cls");
        printf("\n\n\n\t\t\t\tEnter a string to show the lower characters of the string : ");
        fflush(stdin);
        gets(str1);
        printf("\t\t\t\tLowercase of the string : %s\n",strlwr(str1));
        break;
    case 7:
        system("cls");
        printf("\n\n\n\t\t\t\tEnter a string to show the upper characters of the string : ");
        fflush(stdin);
        gets(str1);
        printf("\t\t\t\tUppercase of the string : %s\n",strupr(str1));
        break;
    }
    printf("Do you want to perform again ?(y/n) ");
    char c = getch();
    if(c=='y') {system("cls");goto start;}
    else exit(0);
    return 0;
}
