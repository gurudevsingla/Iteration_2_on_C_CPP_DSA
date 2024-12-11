#include<iostream>
#include<string.h>
using namespace std;

class Complex
{
    private :
        int a,b;
    public :
        void setData(int real,int imag)
        {
            a = real;
            b = imag;
        }
        void showData()
        {
            cout<<"Real : "<<a<<" Imaginary : "<<b<<"i"<<endl;
        }
        Complex add(Complex C)
        {
            C.a+=a;
            C.b+=b;
            return C;
        }
};
class Time
{
    private :
        int h=-1,m=-1,s=-1;
    public :
        void setTime(int hour,int minute,int second)
        {
            if(hour>=0 && hour<24 && minute>=0 && minute<60 && second>=0 && second<60)
            {
                h=hour;
                m=minute;
                s=second;
            }
            else
                cout<<"Invalid Time"<<endl;
        }
        void showTime()
        {
            cout<<"Hour : "<<h<<" Minute : "<<m<<" Second : "<<s<<endl;
        }
        void normalize()
        {
            if(h>=0 && h<12)
                cout<<"Hour : "<<h<<" Minute : "<<m<<" Second : "<<s<<" AM"<<endl;
            else if(h==12)
                cout<<"Hour : "<<h<<" Minute : "<<m<<" Second : "<<s<<" PM"<<endl;
            else
                cout<<"Hour : "<<h-12<<" Minute : "<<m<<" Second : "<<s<<" PM"<<endl;
        }
        Time add(Time T)
        {
            T.h+=h;
            T.m+=m;
            T.s+=s;
            if(T.s>=60)
            {
                T.m+=1;
                T.s-=60;
            }
            if(T.m>=60)
            {
                T.h+=1;
                T.m-=60;
            }
            if(T.h>=24)
                T.h-=24;

            return T;
        }
};
class Cube
{
    private:
        int a,vol=-1,flag=0;
    public :
        Cube(int side)
        {
            if(side>=0)
            {
                a=side;
                flag=1;
            }
            else
            {
                cout<<"Invalid Side of Cube"<<endl;
            }
        }
        void cal_volume()
        {
            if(flag==1)
                vol = a*a*a;
        }
        int get_volume()
        {
            return vol;
        }

};
class Counter
{
    private :
        static int count;
    public :
        Counter()
        {
            cout<<"Count : "<<++count<<endl;
        }
};
int Counter::count=0;
class Date
{
    int dt,mon,yr,flag=0;
    public :
        Date(int date,int month,int year)
        {
            if(date>=0 && month>=0 && year>=0)
                flag=1;
            dt=date;
            mon=month;
            yr=year;
        }
        void display()
        {
            if(flag==0)
                cout<<"Invalid Date"<<endl;
            cout<<dt<<"/"<<mon<<"/"<<yr<<endl;
        }
};
class Student
{
    private :
        int id,cls;
        char nm[20];
    public :
        Student(int roll_no,char name[],int classs)
        {
            id=roll_no;
            strcpy(nm,name);
            cls=classs;
        }
        void display()
        {
            cout<<"ID : "<<id<<" Name : "<<nm<<" Class : "<<cls<<endl;
        }

};
class Bank
{
    private :
        int p,year;
        static float r;
    public :
        Bank(int principal_amt,int years)
        {
            p=principal_amt;
            year=years;
        }
        void read_principal()
        {
            cout<<"Principal Amount : "<<p<<endl;
        }
        static void read_roi()
        {
            cout<<"ROI : "<<r<<" for 1 year"<<endl;
        }
        int get_year()
        {
            return year;
        }
        void display_SI()
        {
            cout<<"Simple Interest : "<<(p*r*year)/100.0<<endl;
        }
};
float Bank::r=8.2;

class Bill
{
    private :
        int id,units=0;
        float bill=0;
        char nm[20];
    public :
        void set_details()
        {
            cout<<"Enter Details of customer"<<endl;
            cout<<"Enter ID : ";
            cin>>id;
            cout<<"Enter Name : ";
            cin>>nm;
            cout<<"Enter Units : ";
            cin>>units;
        }
        void calculate_bill()
        {
            if(units>200)
                bill=((units-200)*3)+(100*1.20)+(100*2);
            else if(units<=200 && units>=100)
                bill=(units-100)*2+(100*1.2);
            else
                bill=units*1.20;
        }
        float get_bill()
        {
            return bill;
        }
};
class StaticCount
{
    private :
        static int x;
    public :
        void call()
        {
            x++;
        }
        static int get_count()
        {
            return x;
        }
};
int StaticCount::x=0;

int main()
{
    Complex C,C1;
    C.setData(5,10);
    C.showData();
    C1.setData(-5,10);
    C.add(C1).showData();

    Time T,T1;
    T.setTime(5,4,23);
    T.showTime();
    T.normalize();
    T1.setTime(23,2,59);
    T1.showTime();
    T1.normalize();
    T.add(T1).normalize();

    Cube Cu=Cube(-5);
    Cu.cal_volume();
    cout<<"Volume of Cube : "<<Cu.get_volume()<<endl;

    Counter cnt,cnt1;

    Date D(19,10,2004),D1(5,-2,5);
    D.display();
    D1.display();

    Student S1(65,"Gurudev",16),S2(64,"Yashank",16);
    S1.display();
    S2.display();

    Bank B(10000,5);
    B.read_principal();
    B.read_roi();
    B.display_SI();

    Bill B1;
    B1.set_details();
    B1.calculate_bill();
    cout<<"Bill : "<<B1.get_bill()<<endl;

    StaticCount Sc;
    Sc.call();
    Sc.call();
    Sc.call();
    cout<<"Count : "<<StaticCount::get_count()<<endl;
    return 0;
}
