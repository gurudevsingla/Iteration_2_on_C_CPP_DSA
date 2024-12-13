#include<iostream>
#include<string.h>
using namespace std;

class Numbers
{

    private:
        int x,y,z;
    public:
        Numbers(){}
        Numbers(int a,int b,int c){x=a;y=b;z=c;}
        Numbers operator-()
        {
            Numbers temp;
            temp.x=-x;
            temp.y=-y;
            temp.z=-z;
            return temp;
        }
        void show_num()
        {
            cout<<"x : "<<x<<" y : "<<y<<" z : "<<z<<endl;
        }
};
class CString
{
    private:
        char str[20];
    public:
        CString(char temp[])
        {
            strcpy(str,temp);
        }
        CString operator+(CString temp)
        {
            strcpy(temp.str,strcat(str,temp.str));
            return temp;
        }
        int operator==(CString temp)
        {
            return strcmp(str,temp.str);
        }
        void display()
        {
            cout<<str<<endl;
        }
};
class Matrix
{
    private:
        int a[3][3];
    public:
        void input()
        {
            cout<<"Enter the matrix elements"<<endl;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<"["<<i<<"]"<<"["<<j<<"] : ";
                    cin>>a[i][j];
                }
            }
        }
        void display()
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<a[i][j]<<"   ";
                }
                cout<<endl;
            }
        }
        Matrix operator+(Matrix M)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    (M.a)[i][j]+=a[i][j];
                }
            }
            return M;
        }
        Matrix operator-()
        {
            Matrix temp;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    (temp.a)[i][j]=-1*a[i][j];
                }
            }
            return temp;
        }


};
class Mystring
{
    private:
        char str[100]="\0";
    public:
        Mystring(){}
        Mystring(char temp[])
        {
            strcpy(str,temp);
        }
        void display()
        {
            cout<<str<<endl;
        }
        Mystring operator!()
        {
            Mystring temp;
            for(int i=0;i<strlen(str);i++)
            {
                if(str[i]>=97 && str[i]<=122)
                {
                    (temp.str)[i]=str[i]-32;
                }
                else if(str[i]>=65 && str[i]<=90)
                {
                    (temp.str)[i]=str[i]+32;
                }
                else
                {
                    (temp.str)[i]=str[i];
                }
            }
            return temp;
        }
};
int main()
{
    Numbers N(5,6,7);
    (-N).show_num();

    CString S1("Hello "),S2("Gurudev");
    (S1+S2).display();
    cout<<"String Compare : "<<(S1==S2)<<endl;

    Matrix M,M1;
    M.input();
    M.display();
    M1.input();
    M1.display();
    (M+M1).display();

    Mystring Ms("GuruDev SinGla");
    (!Ms).display();
    return 0;
}
