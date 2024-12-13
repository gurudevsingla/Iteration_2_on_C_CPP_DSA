#include<iostream>
using namespace std;

class Complex
{
    private:
        int a,b;
    public:
        friend istream& operator>>(istream&,Complex&);
        friend ostream& operator<<(ostream&,Complex);
        Complex(){}
        Complex(int real,int imag)
        {
            a=real;
            b=imag;
        }
        void setData(int a,int b)
        {
            (*this).a=a;
            this->b=b;
        }
};
istream& operator>>(istream &cin,Complex &C)
{
    cout<<"Enter Real : ";
    cin>>C.a;
    cout<<"Enter Imag : ";
    cin>>C.b;
    return cin;
}
ostream& operator<<(ostream &cout,Complex C)
{
    cout<<"Real : "<<C.a<<" Imag : "<<C.b<<endl;
    return cout;
}
class Array
{
    private :
        int *a=NULL;
        int size = 0,index =0;
    public :
        Array(int temp[],int length)
        {
            a=(int*)malloc(length*sizeof(int));
            size=length;
            for(int i=0;i<size;i++)
            {
                a[i]=temp[i];
            }
        }
        int operator[](int index)const
        {
            if(index>=size || index<0)
            {
                cout<<"Array Index Out of Bound"<<endl;
                exit(0);
            }
            else
            {
                return a[index];
            }
        }
        int& operator[](int index)
        {
            if(index>=size || index<0)
            {
                cout<<"Array Index Out of Bound"<<endl;
                exit(0);
            }
            else
            {
                return a[index];
            }
        }
        void operator=(int value)
        {
            if(index>=size || index<0)
            {
                cout<<"Array Index Out of Bound"<<endl;
            }
            else
            {
                a[index]=value;
            }
        }

        void display()
        {
            for(int i=0;i<size;i++)
                cout<<a[i];
        }
};
class Coordinate
{
    private:
        int x,y,z;
    public:
        Coordinate(int x,int y,int z)
        {
            this->x=x;
            this->y=y;
            this->z=z;
        }
        Coordinate operator,(Coordinate &temp)
        {
            return temp;
        }
        void display()
        {
            cout<<"X : "<<x<<" Y : "<<y<<" Z : "<<z<<endl;
        }
};
class Integer
{
    private:
        int x;
    public:
        Integer(int x){this->x=x;}
        operator int()
        {
            return x;
        }
};
class Distance
{
    private:
        float feet,inches;
    public:
        friend ostream& operator<<(ostream&,Distance);
        Distance(){}
        Distance(float feet,float inches)
        {
            this->feet=feet;
            this->inches=inches;
        }
        Distance operator()(int a,int b,int c)
        {
            feet=a+c+5;
            inches=a+b+15;
            return *this;
        }
};
ostream& operator<<(ostream &cout,Distance D)
{
    cout<<"Feet : "<<D.feet<<" Inch : "<<D.inches<<endl;
    return cout;
}
class Marks
{
    private:
        int marks;
    public:
        Marks(int m)
        {
            marks = m;
        }
        Marks* operator->()
        {
            return this;
        }
        void display()
        {
            cout<<marks<<endl;
        }
};
int main()
{
    Complex C,C1;
    C1.setData(0,0);
    cin>>C;
    cout<<C1;

    int a[]={1,2,3,4,5};
    Array arr(a,5);
    arr[4]=6;
    cout<<(arr[2])<<endl;
    arr.display();

    Coordinate C1(1,2,3),C2(4,5,6),C3(7,8,9);
    C3=(C1,C2);
    C2=C1;
    C3.display();

    Integer I(5);
    cout<<int(I);

    Distance D1;
    cout<<D1(1,2,3);

    Marks M(50);
    M.display();
    M->display();

    return 0;
}
