#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* input_varlen_string();
int* create_data(int);
void input_data(int*, int);
void display_avg(int*, int);
char* input_var_len_string();

int main()
{
    int number_of_data,*data=NULL;
    /*
    char *str=NULL;
    str = input_varlen_string();
    printf("\n%s\n",str);


    printf("\nEnter the number of data : ");
    scanf("%d",&number_of_data);

    data = create_data(number_of_data);
    if(data!=NULL)
        input_data(data,number_of_data);
        display_avg(data,number_of_data);
    else
        printf("Memory Allocation Failed\n");
    */
    /*
    char *str=NULL;
    int l=0;
    str = input_var_len_string();
    if(str!=NULL)
    {
        printf("%s\n",str);
        l = strlen(str);
    }
    printf("Length : %d\n",l);
    free(str);
    str=NULL;
    */

    /*


    */

    return 0;
}
char* input_varlen_string()
{
    char str[201],*p=NULL;
    printf("Enter the String\n");
    fflush(stdin);
    fgets(str,201,stdin);
    str[strlen(str)-1]=0;
    p = (char*)calloc(strlen(str)+1,sizeof(char));
    strcpy(p,str);
    return p;
}
char* input_var_len_string()
{
    char *p=NULL,*temp=NULL,c;
    int i;
    printf("Enter a String\n");
    p = (char*)malloc(sizeof(char));
    scanf("%c",&c);
    for(i=1;c!='\n';i++)
    {
        p[i-1]=c;
        temp = (char*)realloc(p,sizeof(char)*(i+1));
        if(temp!=NULL)
        {
            p=temp;
            temp=NULL;
        }
        scanf("%c",&c);
    }
    if(i==1)
    {
        free(p);
        p=NULL;
        return p;
    }
    p[i-1]='\0';
    return p;

}
int* create_data(int size)
{
    return (int*)calloc(size,sizeof(int));
}
void input_data(int *p, int size)
{
    printf("Enter Data\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",p+i);
    }
}
void display_avg(int *p, int size)
{
    int sum=0,i;
    for(i=0;i<size;i++)
    {
        sum+=p[i];
    }
    if(size!=0)
        printf("Average : %.2f",sum*1.0/size);
    else
        printf("Average : %d",sum);
}
