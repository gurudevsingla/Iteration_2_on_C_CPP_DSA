#include<iostream>
using namespace std;

bool is_prime(int);
int highest_val_dig(int);
float power(int,int);
inline void swap(int&,int&);
inline int add(int,int,int=0);
inline float area(int);
inline float area(int,int);
inline int max(int,int);
inline float max(float,float);
inline float add(float,float);

inline float add(float,float);
inline float add(float,int);
inline float add (int,float);

int main()
{
    float num;
    int pow,num2;

    cout<<"Enter a number for checking prime : ";
    cin>>num;
    cout<<(is_prime(num)?"Prime":"Not Prime")<<endl;

    cout<<"Enter a number to find highest digit : ";
    cin>>num;
    cout<<"Highest digit : "<<highest_val_dig(num)<<endl;

    cout<<"Enter a number and it's power : ";
    cin>>num>>pow;
    cout<<"Result : "<<power(num,pow)<<endl;

    cout<<"Enter two numbers for swapping : ";
    cin>>num>>pow;
    swap(num,pow);
    cout<<"After Swapping : "<<num<<" "<<pow<<endl;

    cout<<"Enter 2 numbers for addition : ";
    cin>>num>>pow;
    cout<<"Sum : "<<add(num,pow)<<endl;

    cout<<"Enter 3 numbers for addition : ";
    cin>>num>>pow>>num2;
    cout<<"Sum : "<<add(num,pow,num2)<<endl;

    cin>>num>>pow;
    cout<<add(num,pow);
    //cout<<(area(num))<<" "<<area(num,pow);



    return 0;
}

bool is_prime(int x)
{
    if(x==1)
        return false;
    for(int i=2;i*i<x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int highest_val_dig(int x)
{
    int max=-999999;
    if(x<0)
        x*=-1;
    while(x)
    {
        if(x%10>max)
            max=x%10;
        x/=10;
    }
    return max;
}
float power(int x,int n)
{
    float result=1;
    bool flag=0;
    if(n<0)
    {
        n*=-1;
        flag=1;
    }
    for(int i=0;i<n;i++)
    {
        result = result*x;
    }
    if(flag)
        return 1/result;
    return result;
}
void swap(int &m,int &n)
{
    int temp;
    temp = m;
    m = n;
    n = temp;
}
int add(int x,int y,int z)
{
    return x+y+z;
}
float area(int r)
{
    return 3.14*r*r;
}
float area(int l,int b)
{
    return l*b;
}
int max(int x,int y)
{
    return x>y?x:y;
}
float max(float x,float y)
{
    return x>y?x:y;
}

float add(float x,float y)
{
    return x+y;
}
float add(float x,int y)
{
    return x+y;
}
float add (int x,float y)
{
    return x+y;
}
