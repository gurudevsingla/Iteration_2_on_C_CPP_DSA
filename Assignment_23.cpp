#include<iostream>
using namespace std;

inline int sum(int,int);
inline float area_of_circle(int);
inline int volume_of_cuboid(int,int,int);
inline float average(int,int,int);
inline int square(int);
inline void swap(int*,int*);
inline int max(int,int);
svoid input_array(int*,int);
int sum_array(int*,int);

int main()
{
    int a,b,c,radius,length,breadth,height,size=10,arr[size];
    cout<<"Hello"<<endl<<"Mysirg"<<endl;
    cout<<"Enter two numbers for sum : ";
    cin>>a>>b;
    cout<<"Sum is : "<<sum(a,b)<<endl;
    cout<<"Enter radius for area: ";
    cin>>radius;
    cout<<"Area of Circle : "<<area_of_circle(radius)<<endl;
    cout<<"Enter length, breadth, height for volume : ";
    cin>>length>>breadth>>height;
    cout<<"Volume of Cuboid : "<<volume_of_cuboid(length,breadth,height)<<endl;
    cout<<"Enter three numbers for average : ";
    cin>>a>>b>>c;
    cout<<"Average : "<<average(a,b,c)<<endl;
    cout<<"Enter a number for square : ";
    cin>>a;
    cout<<"Square : "<<square(a)<<endl;
    cout<<"Enter two no. a and b for swapping : ";
    cin>>a>>b;
    swap(&a,&b);
    cout<<"After swapping a and b : "<<a<<" "<<b<<endl;
    cout<<"Enter two no. for max : ";
    cin>>a>>b;
    cout<<"Max : "<<max(a,b)<<endl;
    input_array(arr,size);
    cout<<"Sum of Array : "<<sum_array(arr,size)<<endl;
    return 0;
}
int sum(int x,int y)
{
    return x+y;
}
float area_of_circle(int r)
{
    return 3.14*r*r;
}
int volume_of_cuboid(int l,int b,int h)
{
    return l*b*h;
}
float average(int x,int y,int z)
{
    return (x+y+z)/3.0;
}
int square(int x)
{
    return x*x;
}
void swap(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
int max(int x,int y)
{
    return x>y?x:y;
}
void input_array(int *p,int size)
{
    cout<<"Enter "<<size<<" numbers"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>p[i];
    }
}
int sum_array(int *p,int size)
{
    int sum = 0;
    for(int i=0;i<size;i++)
    {
        sum+=p[i];
    }
    return sum;
}
