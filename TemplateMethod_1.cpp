#include <iostream>
using namespace std;
class Computer
{
public:
    void Product()
    {
        InstallCPU();
        InstallRam();
        InstallGPU();
    }
    virtual void InstallCPU() = 0;
    virtual void InstallRam() = 0;
    virtual void InstallGPU() = 0;
    virtual ~Computer(){};
};
class AppleComputer : public Computer
{
public:
    void InstallCPU() { cout << "Apple Install a itel i7" << endl; }
    void InstallRam() { cout << "Apple Install a 8G Ram" << endl; }
    void InstallGPU() { cout << "Apple Install a High speed GPU" << endl; }
};
class LenovoComputer : public Computer
{
public:
    void InstallCPU() { cout << "Lenovo Install a itel i5" << endl; }
    void InstallRam() { cout << "Lenovo Install a 4G Ram" << endl; }
    void InstallGPU() { cout << "Lenovo Install a powerfull GPU" << endl; }
};
int main()
{
    Computer * pApp = new AppleComputer();
    pApp->Product();
    delete pApp;

    Computer * pLenevo = new LenovoComputer();
    pLenevo->Product();
    delete pLenevo;
    return 0;
}