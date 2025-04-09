//A program that overloads + and > operator to add and compare between two time objects
#include<iostream>
using namespace std;
class Time{
    int hr, min, sec;
    public:
    Time(){
        hr = 0;
        min = 0;
        sec = 0;
    }
    void getData(){
        cout<<"Enter the hour: "<<endl;
        cin>>hr;
        while(hr>24){
            cout<<"Enter valid hour: "<<endl;
            cin>>hr;
        }
        cout<<"Enter the minute: "<<endl;
        cin>>min;
        while(min>60){
            cout<<"Enter valid minute: "<<endl;
            cin>>min;
        }
        cout<<"Enter the second: "<<endl;
        cin>>sec;
        while(sec>60){
            cout<<"Enter valid second: "<<endl;
            cin>>sec;
        }
    }
    Time operator+(Time T){
        Time temp;
        temp.sec = T.sec + sec;
        int ss = temp.sec / 60;
        temp.sec = temp.sec % 60;
        temp.min = ss + T.min + min;
        int mm = temp.min / 60;
        temp.min = temp.min % 60;
        temp.hr = mm + T.hr + hr;
        return (temp);
    }  
    bool operator>(Time T) {
        if (hr > T.hr)
            return true;
        else if (hr == T.hr && min > T.min)
            return true;
        else if (hr == T.hr && min == T.min && sec > T.sec)
            return true;
        else
            return false;
    }
    void display(){
        cout<<"Addition of two times: "<<hr<<" hr "<<min<<" min "<<sec<<" sec"<<endl;
    }
    void comparisonDisplay(){
        cout<<hr<<" hr "<<min<<" min "<<sec<<" sec";
    }
};
int main()
{
    Time T1;
    T1.getData();
    Time T2;
    T2.getData();
    Time T3 = T1 + T2;
    T3.display();
    if(T1 > T2){
        cout<<"Time 1(";
        T1.comparisonDisplay();
        cout<<") is greater than T2(";
        T2.comparisonDisplay();
        cout<<").";
    }
    else if(T2 > T1){
        cout<<"Time 2(";
        T2.comparisonDisplay();
        cout<<") is greater than T1(";
        T1.comparisonDisplay();
        cout<<").";
    }
    else{
        cout<<"Time 1(";
        T1.comparisonDisplay();
        cout<<") and T2";
        T2.comparisonDisplay();
        cout<<") are equal.";
    }
return 0;
}