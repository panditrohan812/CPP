#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    string brand;
    int powerConsumption;
    double price;

public:
    void setBrand(string b)
    {
        brand = b;
    }

    void setPowerConsumption(int p)
    {
        powerConsumption = p;
    }

    void setPrice(double pr)
    {
        price = pr;
    }

    string getBrand()
    {
        return brand;
    }

    double getPrice()
    {
        return price;
    }

    void displayDeviceInfo()
    {
        cout << "Brand: " << brand
             << ", Power Consumption: " << powerConsumption << "W"
             << ", Price: Rs." << price << endl;
    }

    virtual double calculateDiscount()
    {
        return 0.0;
    }

    virtual ~Device() {}
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

    double calculateDiscount() override
    {
        if (price > 50000)
            return price * 0.10;
        else
            return price * 0.05;
    }

    void display()
    {
        cout << "[Laptop] ";
        displayDeviceInfo();
        cout << "         Processor: " << processor << ", RAM: " << ramGB << "GB" << endl;
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

    double calculateDiscount() override
    {
        if (batteryMah >= 5000)
            return price * 0.15;
        else
            return price * 0.08;
    }

    void display()
    {
        cout << "[Smartphone] ";
        displayDeviceInfo();
        cout << "             OS: " << os << ", Battery: " << batteryMah << "mAh" << endl;
    }
};

int main()
{
    Laptop laptop1;
    laptop1.setBrand("Dell");
    laptop1.setPowerConsumption(65);
    laptop1.setPrice(60000);
    laptop1.setProcessor("Intel i7");
    laptop1.setRam(16);

    Smartphone phone1;
    phone1.setBrand("Samsung");
    phone1.setPowerConsumption(15);
    phone1.setPrice(25000);
    phone1.setOS("Android 14");
    phone1.setBattery(5000);

    Device *devices[2];
    devices[0] = &laptop1;
    devices[1] = &phone1;

    cout << "Device Discount Details:" << endl;
    cout << "-------------------------" << endl;

    for (int i = 0; i < 2; i++)
    {
        devices[i]->displayDeviceInfo();
        cout << "Discount: Rs." << devices[i]->calculateDiscount() << endl;
        cout << endl;
    }
}