#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Vehicle{
    protected:
    int registration;
    string color;
    public:
    Vehicle(int regN, string clr){
        registration = regN;
        color = clr;
    }
    virtual void writeToFile(){
        ofstream file("vehicle.txt", ios::app);
        if(file.is_open()){
            file<<"Vehicle Details: "<<endl;
            file<<"Registration Number: "<<registration<<endl;
            file<<"Color: "<<color<<endl;
            file<<"-----------------------------"<<endl;
            file.close();
        }
    }
};
class Car : public Vehicle{
    private: 
    int numOfSeats;
    public:
    Car(int regN, string clr, int numSeat) : Vehicle(regN, clr){
        numOfSeats = numSeat;
    }
    void writeToFile() override{
        ofstream file("vehicle.txt", ios::app);
        if(file.is_open()){
            file<<"Car Details: "<<endl;
            file<<"Registration Number: "<<registration<<endl;
            file<<"Color: "<<color<<endl;
            file<<"Number of Seats: "<<numOfSeats<<endl;
            file<<"-----------------------------"<<endl;
            file.close();
        }
    }
};
class Bike : public Vehicle{
    private: 
    int engineCap;
    public:
    Bike(int regN, string clr, int eCap) : Vehicle(regN, clr){
        engineCap = eCap;
    }
    void writeToFile() override{
        ofstream file("vehicle.txt", ios::app);
        if(file.is_open()){
            file<<"Bike Details: "<<endl;
            file<<"Registration Number: "<<registration<<endl;
            file<<"Color: "<<color<<endl;
            file<<"Engine Capacity: "<<engineCap<<endl;
            file<<"-----------------------------"<<endl;
            file.close();
        }
    }
};
int main()
{
    Car c1(1,"Blue",4);
    Bike b1(2,"Red",350);
    c1.writeToFile();
    b1.writeToFile();
return 0;
}