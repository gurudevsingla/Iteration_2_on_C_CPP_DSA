#include<iostream>
using namespace std;

class Time
{
    private:
        int hr,min,sec;
    public:
        friend istream& operator>>(istream &,Time &);
        friend ostream& operator<<(ostream &,Time);
        bool operator==(Time T)
        {
            if(hr==T.hr && min==T.min && sec==T.sec)
                return true;
            else
                return false;
        }
};
istream& operator>>(istream &cin,Time &T)
{
    cout<<"Enter Hour : ";
    cin>>T.hr;
    cout<<"Enter Minute : ";
    cin>>T.min;
    cout<<"Enter second : ";
    cin>>T.sec;
    return cin;
}
ostream& operator<<(ostream &cout,Time T)
{
    cout<<"Hour : "<<T.hr<<" Minute : "<<T.min<<" Second : "<<T.sec<<endl;
    return cout;
}
int main()
{
    Time T1,T2;
    cin>>T1;
    cin>>T2;
    cout<<T1;
    cout<<T2;
    cout<<(T1==T2);
    return 0;
}
