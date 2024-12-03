#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char* input(char[],int);
int calculate_vowels(char[]);
int length(char[]);
int sort(char[],char[]);
int issymbol(char[],char);
bool is_palindrome(char[]);
//bool is_valid_ip(char[]);
//int str_to_int(char[],int,int);

int main()
{
    int n=5,size=51,i,j,temp;
    char str[n][size],temp_str[size],temp_str1[size];
    printf("Enter %d Cities\n",n,size);

    // Input String
    for(int i=0;i<n;i++)
    {
        input(str[i],size);
    }
    printf("\n\n");
    // 1. Vowels

    /*
    for(int i=0;i<n;i++)
        printf("Vowels in String %d : %d\n",i+1,calculate_vowels(str[i]));
    */

    //2. Sorting

    /*
    for(i=0;i<n;i++)
    {
        temp=i;
        for(j=i+1;j<n;j++)
        {
            if(sort(str[temp],str[j])==2)
            {
                temp=j;
            }
        }
        if(temp!=i)
        {
            strcpy(temp_str,str[temp]);
            strcpy(str[temp],str[i]);
            strcpy(str[i],temp_str);
        }
    }

    printf("After Sorting\n");
    */

    //3. Printing Strings

    /*
    for(int i=0;i<n;i++)
    {
        printf("%s\n",str[i]);

    }
    */

    //4. Search String

    /*
    printf("Enter a String for Search : ");
    fflush(stdin);
    fgets(temp_str,size,stdin);
    temp_str[length(temp_str)-1]=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(temp_str,str[i])==0)
        {
            printf("%s found at %d position\n",temp_str,i+1);
            break;
        }
    }
    if(i==n)
    {
        printf("%s not found\n",temp_str);
    }
    */

    //5. is @ in mail

    /*
    printf("String without @\n\n");
    for(i=0;i<n;i++)
    {
        if(issymbol(str[i],'@')==0)
        {
            printf("%s\n",str[i]);
        }
    }
    */

    //6. is palidrome

    /*
    printf("Palindrome Strings\n");
    for(i=0;i<n;i++)
    {
        if(is_palindrome(str[i])==true)
        {
            printf("%s\n",str[i]);
        }
    }
    */

    //7. is valid IP

    /*
    Raw Implementation failed cases
    See below implimentation

    printf("Invalid IP\n");
    for(i=0;i<n;i++)
    {
        if(is_valid_ip(str[i])==false)
        {
            printf("%s\n",str[i]);
        }
    }
    */

    //7. is valid IP

    /*
    printf("IP addresses\n");
    for(i=0;i<n;i++)
    {
        int count=0;
        char*a=strtok(str[i],".");
        while(a!=NULL)
        {
            int x = atoi(a);
            if((x>=0)&&(x<=255))
                count++;
            else
                break;
            a=strtok(NULL,".");
        }
        if(a==NULL)
        {
            if(count==4)
                printf("Valid\n");
            else
                printf("Not Valid\n");
        }
        else
            printf("Not Valid\n");
    }
    */

    //8. Distance between two words

    /*
    printf("Enter two strings\n");
    input(temp_str,size);
    input(temp_str1,size);
    int position_temp=-1,position_temp1=-1;
    for(i=0;i<n;i++)
    {
        if(strcmp(temp_str,str[i])==0)
        {
            position_temp=i;
        }
        if(strcmp(temp_str1,str[i])==0)
        {
            position_temp1=i;
        }
    }
    if(position_temp==-1||position_temp1==-1)
    {
        printf("String Missing\n\n");
    }
    else
    {
        printf("Difference is %d\n\n",position_temp1-position_temp);
    }
    */

    return 0;
}

/*bool is_valid_ip(char str[])
{
    int i,temp,token,num_dots=0;
    temp=0;
    for(i=0;str[i]&&num_dots<4;i++)
    {
        if(str[i]=='.')
        {
            num_dots+=1;
            token = str_to_int(str,temp,i);
            if(token>=0 && token <= 255)
            {
                temp=i+1;
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if(str[i]==0 && str[temp]!=0)
    {
        token = str_to_int(str,temp,i);
        if(token>=0 && token <= 255 && num_dots==3)
            return true;
        else
            return false;
    }
    return false;
}
int str_to_int(char str[],int start,int end)
{
    int int_from_char,int_from_str=0;
    for(int i=start;i<end;i++)
    {
        int_from_char = ((int)str[i])-48;
        int_from_str+=(int_from_str*10)+int_from_char;
    }
    return int_from_str;
}*/

bool is_palindrome(char str[])
{
    int size = length(str);
    for(int i=0;i<size/2;i++)
    {
        if(str[i]!=str[size-1-i])
            return false;
    }
    return true;
}

int issymbol(char str[],char symbol)
{
    for(int i=0;str[i];i++)
    {
        if(str[i]==symbol)
            return 1;
    }
    return 0;
}

int length(char str[])
{
    int i;
    for(i=0;str[i];i++);
    return i;
}

char* input(char str[],int size)
{
    fflush(stdin);
    fgets(str,size,stdin);
    str[length(str)-1]=0;
    return str;
}

int calculate_vowels(char str[])
{
    int count=0;
    char vowels[]={'a','e','i','o','u','A','E','I','O','U'};
    for(int i=0;str[i];i++)
    {
        for(int j=0;vowels[j];j++)
        {
            if(str[i]==vowels[j])
                count++;
        }
    }
    return count;
}

int sort(char str1[],char str2[])
{
    int i;
    for(i=0;str1[i];i++)
    {
        if(str1[i]>str2[i])
            return 2;
        else if(str1[i]<str2[i])
            return 1;
    }
    if(str2[i]==0)
        return 0;
    return 1;
}

