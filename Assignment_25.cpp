#include<iostream>
using namespace std;

class Complex
{
    private :
        int real=0,imag=0;
    public :
        void set_value(int x,int y)
        {
            real = x;
            imag = y;
        }
        void print()
        {
            cout<<"Real : "<<real<<endl<<"Complex : "<<imag<<"i"<<endl;
        }

};
class Time
{
private:
    int hour=0,minute=0,second=0;
public:
    void set_time(int hr,int min,int sec)
    {
        if(hr>0 && min>0 && sec>0)
        {
            hour = hr;
            minute = min;
            second = sec;
        }
        else
            cout<<"Invalid Time"<<endl;
    }
    void display()
    {
        cout<<hour<<" hr "<<minute<<" min "<<second<<" sec"<<endl;
    }
};
class Factorial
{
private :
    int num=0,fact=1;
public :
    void set_number(int x)
    {
        if(x>=0)
        {
            num = x;
            for(int i=2;i<=num;i++)
                fact=fact*i;
        }
        else
        {
            num = x;
            fact = -1;
            cout<<"Negative Number !!"<<endl;
        }


    }
    int get_factorial()
    {
        if(fact==-1)
            cout<<"Factorial Not Defined"<<endl;
        else
            cout<<"Number : "<<num<<" Factorial : "<<fact<<endl;
        return fact;
    }
};
class LargestNumber
{
private:
    int a=0,b=0,c=0,largest,flag=0;
public:
    void set_number(int x,int y,int z)
    {
        a=x;
        b=y;
        c=z;
        flag=1;
    }
    int get_largest()
    {
        if(flag==0)
        {
            cout<<"Set Numbers First !"<<endl;
            return -1;
        }
        if(a>b)
        {
            if(a>c)
                largest = a;
            else
                largest = c;
        }
        else
        {
            if(b>c)
                largest = b;
            else
                largest = c;
        }
        return largest;
    }
};
class ReverseNumber
{
private :
    int number=0,rev=0,flag=0;
public :
    void set_number(int x)
    {
        number = x;
        if(number<0)
        {
            number*=-1;
            flag=1;
        }
        while(number)
        {
            rev=rev*10+number%10;
            number/=10;
        }
    }
    int get_reverse()
    {
        if(flag==1)
            return -1*rev;
        else
            return rev;
    }
};
class Square
{
private :
    int number=0,sq=0;
    static int count;
public :
    void set_number(int x)
    {
        number = x;
        sq=number*number;
        count++;
    }
    int get_number()
    {
        return number;
    }
    int get_square()
    {
        return sq;
    }
    static int get_count()
    {
        return count;
    }

};
int Square::count=0;

class Rectangle
{
private :
    int length,breadth,area=0;
public :
    void set_length_breadth(int len,int br)
    {
        if(len>=0 && br>=0)
        {
            length = len;
            breadth = br;
            area = len*br;
        }
        else
        {
            cout<<"Invalid Length or Breadth"<<endl;
        }

    }
    int get_area()
    {
        return area;
    }
};
class Circle
{
private :
    int radius;
    float area=0;
public :
    void set_radius(int rad)
    {
        if(rad>=0)
        {
            radius = rad;
            area = 3.14*radius*radius;
        }
        else
        {
            cout<<"Invalid Radius"<<endl;
        }

    }
    float get_area()
    {
        return area;
    }
};
class Area
{
private :
    int side,length,breadth,radius;
    float ar_of_square,ar_of_rectangle,ar_of_circle;
public :
    void set_side(int s)
    {
        if(s>=0)
            side=s;
        else
            cout<<"Invalid Side"<<endl;
    }
    void set_length_breadth(int len,int br)
    {
        if(len>=0 && br>=0)
        {
            length = len;
            breadth = br;
        }
        else
            cout<<"Invalid Length or Breadth"<<endl;
    }
    void set_radius(int rad)
    {
        if(rad>=0)
        {
            radius = rad;
        }
        else
            cout<<"Invalid Radius"<<endl;
    }
    void cal_area_of_square()
    {
        ar_of_square = side*side;
    }
    void cal_area_of_rectangle()
    {
        ar_of_rectangle = length*breadth;
    }
    void cal_area_of_circle()
    {
        ar_of_circle = 3.14*radius*radius;
    }
    float get_area_of_square()
    {
        return ar_of_square;
    }
    float get_area_of_rectangle()
    {
        return ar_of_rectangle;
    }
    float get_area_of_circle()
    {
        return ar_of_circle;
    }
};

int main()
{
    Complex C;
    C.set_value(5,6);
    C.print();

    Time T;
    T.set_time(-5,6,7);
    T.display();

    Factorial F;
    F.set_number(-5);
    F.get_factorial();

    LargestNumber L;
    L.set_number(1,2,3);
    cout<<"Largest Number : "<<L.get_largest()<<endl;

    ReverseNumber RN;
    RN.set_number(-123);
    cout<<"Reverse : "<<RN.get_reverse()<<endl;

    Square S,S1,S2;
    S.set_number(5);
    S1.set_number(0);
    S2.set_number(-5);
    cout<<"Number : "<<S.get_number()<<" Square : "<<S.get_square()<<" Count : "<<Square::get_count()<<endl;
    cout<<"Number : "<<S1.get_number()<<" Square : "<<S1.get_square()<<" Count : "<<S1.get_count()<<endl;
    cout<<"Number : "<<S2.get_number()<<" Square : "<<S2.get_square()<<" Count : "<<S2.get_count()<<endl;

    Rectangle R;
    R.set_length_breadth(5,5);
    cout<<"Area of Rectangle : "<<R.get_area()<<endl;

    Circle Cr;
    Cr.set_radius(5);
    cout<<"Area of Circle : "<<Cr.get_area()<<endl;

    Area A;
    A.set_side(5);
    A.set_length_breadth(-4,3);
    A.set_radius(5);
    A.cal_area_of_circle();
    A.cal_area_of_rectangle();
    A.cal_area_of_square();
    cout<<"Area of Square : "<<A.get_area_of_square()<<"\nArea of Rectangle : "<<A.get_area_of_rectangle()<<"\nArea of Circle : "<<A.get_area_of_circle()<<endl;
    return 0;
}
