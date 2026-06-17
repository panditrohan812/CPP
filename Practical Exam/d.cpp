#include <iostream>
#include <string>
using namespace std;

class Device
{
private:
    string brand;
    int powerConsumption;

public:
    void setBrand(string b)
    {
        brand = b;
    }

    void setPowerConsumption(int p)
    {
        powerConsumption = p;
    }

    string getBrand()
    {
        return brand;
    }

    int getPowerConsumption()
    {
        return powerConsumption;
    }

    void displayDeviceInfo()
    {
        cout << "Brand: " << getBrand()
             << ", Power Consumption: " << getPowerConsumption() << "W" << endl;
    }
};

class Laptop : public Device
{
private:
    string processor;
    int ramGB;

public:
    void setProcessor(string p)
    {
        processor = p;
    }

    void setRam(int r)
    {
        ramGB = r;
    }

    void display()
    {
        cout << "[Laptop] ";
        displayDeviceInfo();
        cout << "         Processor: " << processor
             << ", RAM: " << ramGB << "GB" << endl;
    }
};

class Smartphone : public Device
{
private:
    string os;
    int batteryMah;

public:
    void setOS(string o)
    {
        os = o;
    }

    void setBattery(int b)
    {
        batteryMah = b;
    }

    void display()
    {
        cout << "[Smartphone] ";
        displayDeviceInfo();
        cout << "             OS: " << os
             << ", Battery: " << batteryMah << "mAh" << endl;
    }
};

int main()
{
    Laptop laptop1;
    laptop1.setBrand("Dell");
    laptop1.setPowerConsumption(65);
    laptop1.setProcessor("Intel i7");
    laptop1.setRam(16);

    Smartphone phone1;
    phone1.setBrand("Samsung");
    phone1.setPowerConsumption(15);
    phone1.setOS("Android 14");
    phone1.setBattery(5000);

    cout << "Device Information:" << endl;
    cout << "--------------------" << endl;

    laptop1.display();
    cout << endl;
    phone1.display();
}