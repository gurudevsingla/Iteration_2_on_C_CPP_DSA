#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char* input(char[],int);
int length(char[]);
char* reverse(char[]);
char* upper(char[]);
char* lower(char[]);
int compare(char[],char[]);
bool isalphanum(char[]);
bool is_palindrome(char[]);
int num_words(char[]);
void rev_word_wise(char[]);
char* reverse_word_wise(char[]);
char* reverse_for_revword(char[],int,int);
void duplicates(char[]);

int main()
{
    int size=51;
    char str[size];
    printf("Enter a string : ");
    input(str,size);
    printf("\n\nLength of String : %d\n\n",length(str));
    printf("Reversed String : %s\n\n",reverse(str));
    printf("Reversed String : %s\n\n",reverse(str));
    printf("Upper String : %s\n\n",upper(str));
    printf("Lower String : %s\n\n",lower(str));
    printf("Compare : %d %d %d\n\n",strcmp("A","Ab"),strcmp("Ab","Ab"),strcmp("Ab","A"));
    printf("Compare String : %d %d %d\n\n",compare("A","Ab"),compare("Ab","Ab"),compare("Ab","A"));
    printf("Alphanumeric : %d %d %d %d\n\n",isalphanum("a1"),isalphanum("1a"),isalphanum("aa"),isalphanum("11"));
    printf("Palindrome : %d\n\n",is_palindrome(str));
    printf("Number of words : %d\n\n",num_words(str));
    rev_word_wise(str);
    printf("Reverse word wise returned : %s\n\n",reverse_word_wise(str));
    duplicates(str);
    return 0;
}

char* input(char str[],int size)
{
    fgets(str,size,stdin);
    str[length(str)-1]=0;
    return str;
}

int length(char str[])
{
    int i;
    for(i=0;str[i];i++);
    return i;
}

char* reverse(char str[])
{
    int size = length(str),temp;
    for(int i=0;i<size/2;i++)
    {
        temp=str[i];
        str[i]=str[size-1-i];
        str[size-1-i]=temp;
    }
    return str;
}

char* upper(char str[])
{
    for(int i=0;str[i];i++)
    {
        if(str[i]>96&&str[i]<123)
        {
            str[i]-=32;
        }
    }
    return str;
}

char* lower(char str[])
{
    for(int i=0;str[i];i++)
    {
        if(str[i]>64&&str[i]<91)
        {
            str[i]+=32;
        }
    }
    return str;
}

int compare(char str1[],char str2[])
{
    for(int i=0;str1[i]||str2[i];i++)
    {
        if(str1[i]<str2[i])
            return -1;
        else if(str1[i]>str2[i])
            return 1;
    }
    if(length(str1)==length(str2))
        return 0;
    else if(length(str2)>length(str1))
        return -1;
    else
        return 1;
}

bool isalphanum(char str[])
{
    bool flagalpha=0,flagnum=0;
    for(int i=0;str[i];i++)
    {
        if(flagnum==0)
        {
            if(str[i]>47&str[i]<58)
            {
                flagnum=1;
                goto check;
            }

        }
        if(flagalpha==0)
        {
            if((str[i]>64&str[i]<91)|(str[i]>96&str[i]<123))
                {
                    flagalpha=1;
                }
        }
        check : if(flagalpha&flagnum)
                    return 1;
    }
    return 0;
}

bool is_palindrome(char str[])
{
    int size = length(str);
    for(int i=0;i<size/2;i++)
    {
        if(str[i]!=str[size-1-i])
            return 0;
    }
    return 1;
}

int num_words(char str[])
{
    int count=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]==32&&str[i+1]!=32)
            count++;
    }
    return count+1;
}

void rev_word_wise(char str[])
{
    int size=length(str),temp,i,j;
    char new_str[size+1];
    temp=0;
    new_str[size]=0;
    for(i=0;str[i];i++)
    {
        if(str[i]==' ')
        {
            new_str[size-i-1]=' ';
            for(j=size-i;temp!=i;j++)
            {
                new_str[j]=str[temp];
                temp++;
            }
            temp=i+1;
        }
    }
    for(j=0;str[temp];j++)
    {
        new_str[j]=str[temp];
        temp++;
    }
    printf("Reversed word wise Printing : %s\n\n",new_str);
}

char* reverse_word_wise(char str[])
{
    int temp=0,i;
    for(i=0;str[i];i++)
    {
        if(str[i]==' ')
        {
            reverse_for_revword(str,temp,i);
            temp=i+1;
        }
    }
    reverse_for_revword(str,temp,i);
    return reverse(str);
}

char* reverse_for_revword(char str[],int start,int end)
{
    int size = end+start,temp;
    for(int i=start;i<size/2;i++)
    {
        temp=str[i];
        str[i]=str[size-1-i];
        str[size-1-i]=temp;
    }
    return str;
}

void duplicates(char str[])
{
    int hashmap[256]={0},i;
    for(i=0;str[i];i++)
    {
        hashmap[str[i]]++;
    }
    printf("Dupicates are : ");
    for(i=0;i<256;i++)
    {
        if(hashmap[i]>1)
            printf("%c ",i);
    }
    printf("\n\n");
}
