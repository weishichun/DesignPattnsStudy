#include <iostream>
#include <string>
using namespace std;

class ICar
{
public:
    virtual string Name() = 0;
    virtual ~ICar() {}
};
class Benze : public ICar
{
public:
    string Name()
    {
        return "Benze Car";
    }
};
class Bmw : public ICar
{
public:
    string Name()
    {
        return "Bmw Car";
    }
};
class Audio : public ICar
{
public:
    string Name()
    {
        return "Audio Car";
    }
};
class IFactory
{
public:
    virtual ICar *CreateCar() = 0;
    virtual ~IFactory() {}
};
class BenzeFactory : public IFactory
{
public:
    ICar *CreateCar()
    {
        return new Benze();
    }
};
class BmwFactory : public IFactory
{
public:
    ICar *CreateCar()
    {
        return new Bmw();
    }
};
class AudioFactory : public IFactory
{
public:
    ICar *CreateCar()
    {
        return new Audio();
    }
};
int main()
{
    IFactory *pF = new BenzeFactory();
    ICar *pCar = pF->CreateCar();
    cout << "Benze Factory create: " << pCar->Name() << endl;
    delete pF;
    delete pCar;
    pF = new BmwFactory();
    pCar = pF->CreateCar();
    cout << "Bmw Factory create: " << pCar->Name() << endl;
    delete pF;
    delete pCar;
    pF = new AudioFactory();
    pCar = pF->CreateCar();
    cout << "Audio Factory create: " << pCar->Name() << endl;
    return 0;
}