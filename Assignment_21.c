//Question No. 8 and 9 logics are already implemented. So not doing again !!
#include<stdio.h>
#include<string.h>

struct Employee
{
    int id,salary;
    char name[20];
};
struct Marks
{
    int roll_no,chem_marks,maths_marks,phy_marks;
    char name[20];
};
struct Time
{
    int hour,minute,second;
};

void inputemp(struct Employee*);
void displayemp(struct Employee*);
int max_salary(struct Employee*,int);
void sort_by_salary(struct Employee*,int);
void structcpy(struct Employee*,struct Employee*);
void sort_by_name(struct Employee*,int);
void input_multi_stud(struct Marks*,int);
void display_multistuds_percentage(struct Marks*,int);
void input_time(struct Time*);
struct Time get_time_difference(struct Time*,struct Time*);
void copy_time(struct Time*,struct Time*);
void display_time(struct Time*);

int main()
{
    /*
    int i,size=5;
    struct Employee emps[size];
    printf("Enter Detail of Employees\n");
    for(i=0;i<size;i++)
    {
        inputemp(&emps[i]);
    }
    printf("\nHighest Salary Employee\n");
    displayemp(&emps[max_salary(emps,size)]);
    sort_by_salary(emps,size);
    printf("\nAfter Sorting By Salaries\n");
    for(i=0;i<size;i++)
    {
        displayemp(&emps[i]);
    }
    sort_by_name(emps,size);
    printf("\nAfter Sorting By Names\n");
    for(i=0;i<size;i++)
    {
        displayemp(&emps[i]);
    }
    */

    //Student Marks

    /*
    int num_studs=3;
    struct Marks students[num_studs];

    printf("Enter Marks Out of 100\n");
    input_multi_stud(students,num_studs);
    display_multistuds_percentage(students,num_studs);
    */

    //Time difference

    struct Time time1,time2,difference_in_time;
    printf("Enter Time 1 and Time 2\n\n");
    input_time(&time1);
    input_time(&time2);
    difference_in_time=get_time_difference(&time1,&time2);
    printf("\nDifference in Time\n");
    display_time(&difference_in_time);
    return 0;
}
void display_time(struct Time *p)
{
    printf("\n");
    printf("Hour : %d ",p->hour);
    printf("Minute : %d ",p->minute);
    printf("Second : %d ",p->second);
    printf("\n");
}
void copy_time(struct Time *time1,struct Time *time2)
{
    time1->hour=time2->hour;
    time1->minute=time2->minute;
    time1->second=time2->second;
}
struct Time get_time_difference(struct Time *p,struct Time *q)
{
    //Better approach is return nothing and take difference structure
    //pointer as an argument and assign difference in that
    struct Time differece,*bigger,*smaller;
    differece.hour=0;
    differece.minute=0;
    differece.second=0;
    if(p->hour > q->hour)
    {
        bigger = p;
        smaller = q;
    }
    else if(q->hour > p->hour)
    {
        bigger = q;
        smaller = p;
    }
    else
    {
        if(p->minute > q->minute)
        {
            bigger = p;
            smaller = q;
        }
        else if(q->minute > p->minute)
        {
            bigger = q;
            smaller = p;
        }
        else
        {
            if(p->second > q->second)
            {
                bigger = p;
                smaller = q;
            }
            else if(q->second > p->second)
            {
                bigger = q;
                smaller = p;
            }
            else
            {

                return differece;
            }

        }
    }
    if(bigger->second < smaller->second)
    {
        bigger->minute-=1;
        bigger->second+=60;
    }
    differece.second = bigger->second - smaller->second;
    if(bigger->minute < smaller->minute)
    {
        bigger->hour-=1;
        bigger->minute+=60;
    }
    differece.minute = bigger->minute - smaller->minute;
    differece.hour = bigger->hour - smaller->hour;

    return differece;
}

void input_time(struct Time *p)
{
    printf("Enter hour : ");
    scanf("%d",&p->hour);
    printf("Enter minute : ");
    scanf("%d",&p->minute);
    printf("Enter second : ");
    scanf("%d",&p->second);
    printf("\n");
}
void input_multi_stud(struct Marks *p,int size)
{
    printf("Enter Details of %d Students\n\n",size);
    for(int i=0;i<size;i++)
    {
        printf("Enter Roll Number : ");
        scanf("%d",&(p[i]).roll_no);
        printf("Enter Name : ");
        fflush(stdin);
        fgets((p[i]).name,20,stdin);
        (p[i]).name[strlen((p[i]).name)-1]=0;
        printf("Enter Chemistry Marks : ");
        scanf("%d",&(p[i]).chem_marks);
        printf("Enter Mathematics Marks : ");
        scanf("%d",&(p[i]).maths_marks);
        printf("Enter Physics Marks : ");
        scanf("%d",&(p[i]).phy_marks);
        printf("\n");
    }
}

void display_multistuds_percentage(struct Marks *p,int size)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("Roll Number : %d\n",p[i].roll_no);
        printf("Name : %s\n",p[i].name);
        printf("Percentage : %.2f\n",((p[i].chem_marks)+(p[i].maths_marks)+(p[i].phy_marks))/3.0);
        printf("\n\n");
    }
}

void inputemp(struct Employee *emp)
{
    printf("Enter emp id : ");
    scanf("%d",&emp->id);
    printf("Enter emp name : ");
    fflush(stdin);
    fgets(emp->name,20,stdin);
    emp->name[strlen(emp->name)-1]=0;
    printf("Enter emp salary : ");
    scanf("%d",&emp->salary);
}
void displayemp(struct Employee *emp)
{
    printf("\nId : %d\nName : %s\nSalary : %d\n\n",emp->id,emp->name,emp->salary);
}
int max_salary(struct Employee *p,int size)
{
    int i=0,max_salary=0,high_salary_ind;
    for(;i<size;i++)
    {
        if(p[i].salary>max_salary)
        {
            max_salary=p[i].salary;
            high_salary_ind=i;
        }
    }
    return high_salary_ind;
}
void sort_by_salary(struct Employee *p,int size)
{
    int i,j,smallest_sal_ind;
    struct Employee temp;
    for(i=0;i<size;i++)
    {
        smallest_sal_ind=i;
        for(j=i+1;j<size;j++)
        {
            if(p[j].salary<(p+smallest_sal_ind)->salary)
            {
                smallest_sal_ind=j;
            }
        }
        if(smallest_sal_ind!=i)
        {
            structcpy(&temp,p+i);
            structcpy(p+i,p+smallest_sal_ind);
            structcpy(p+smallest_sal_ind,&temp);
        }
    }
}
void sort_by_name(struct Employee *p,int size)
{
    int i,j,smallest_name_ind;
    struct Employee temp;
    for(i=0;i<size;i++)
    {
        smallest_name_ind=i;
        for(j=i+1;j<size;j++)
        {
            if(strcmp(p[j].name,(p+smallest_name_ind)->name)==-1)
            {
                smallest_name_ind=j;
            }
        }
        if(smallest_name_ind!=i)
        {
            structcpy(&temp,p+i);
            structcpy(p+i,p+smallest_name_ind);
            structcpy(p+smallest_name_ind,&temp);
        }
    }
}
void structcpy(struct Employee *p,struct Employee *q)
{
    p->id=q->id;
    strcpy(p->name,q->name);
    p->salary=q->salary;
}
