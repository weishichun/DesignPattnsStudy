#include <iostream>
using namespace std;
class Target{
public:
    virtual ~Target(){}
    virtual void Request() = 0;
};
class Adaptee{
public:
    void SpecialRequest(){
        cout << "Adaptee's SpecialRequest" << endl;
    }
};
class Adapter : public Target,Adaptee{
public:
    void Request(){
        Adaptee::SpecialRequest();
    }
};
int main(){
    Target* pA = new Adapter();
    pA->Request();
    delete pA;
    return 0;
}