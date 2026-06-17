#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    int year;
    int speed;

public:
    void setModel(string m)
    {
        model = m;
    }

    void setYear(int y)
    {
        year = y;
    }

    void setSpeed(int s)
    {
        speed = s;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    int getSpeed()
    {
        return speed;
    }

    void display()
    {
        cout << "Model: " << getModel()
             << ", Year: " << getYear()
             << ", Speed: " << getSpeed() << " km/h" << endl;
    }
};

int main()
{
    Car car1, car2;

    car1.setModel("Tata Nexon");
    car1.setYear(2023);
    car1.setSpeed(180);

    car2.setModel("Hyundai Creta");
    car2.setYear(2022);
    car2.setSpeed(170);

    cout << "Car Details:" << endl;
    cout << "-------------------" << endl;
    car1.display();
    car2.display();
}