#include<iostream>
using namespace std;

class Complex
{
    private :
        int a,b;
    public :
        friend Complex operator+(Complex,Complex);
        Complex(int real,int imag)
        {
            a = real;
            b = imag;
        }
        void showData()
        {
            cout<<"Real : "<<a<<" Imaginary : "<<b<<"i"<<endl;
        }
        /*
        Complex operator+(Complex C)
        {
            C.a+=a;
            C.b+=b;
            return C;
        }
        */
        Complex operator-(Complex C)
        {
            C.a=a-C.a;
            C.b=b-C.b;
            return C;
        }
        Complex operator*(Complex C)
        {
            C.a*=a;
            C.b*=b;
            return C;
        }
        bool operator==(Complex C)
        {
            if(C.a==a && C.b==b)
                return true;
            else
                return false;
        }
        Complex operator++()
        {
            a+=1;
            b+=1;
            Complex temp(a,b);
            return temp;
        }
        Complex operator--()
        {
            a-=1;
            b-=1;
            Complex temp(a,b);
            return temp;
        }
        Complex operator++(int _)
        {
            Complex temp(a,b);
            a+=1;
            b+=1;
            return temp;
        }
        Complex operator--(int _)
        {
            Complex temp(a,b);
            a-=1;
            b-=1;
            return temp;
        }

};
Complex operator+(Complex C1,Complex C2)
{
    C1.a+=C2.a;
    C1.b+=C2.b;
    cout<<"Friend"<<endl;
    return C1;
}

int main()
{
    Complex C(2,-5),C1(2,-5);
    C.showData();
    C1.showData();
    (C+C1).showData();
    (C-C1).showData();
    (C*C1).showData();
    cout<<(C==C1)<<endl;
    (--C).showData();
    (++C).showData();
    (C--).showData();
    (C++).showData();
    C.showData();
    return 0;
}
