#include<iostream>
#include<map>
#include<string>
using namespace std;
class Flyweight{
public:
    virtual ~Flyweight(){};
    virtual void Operator(int outStatus) = 0;
};
class ConcretFlyweight : public Flyweight{
public:
    void Operator(int outStatus){
        cout << "concret flyweight,status:" << outStatus << endl;
    }
};
class UnsharedConcretFlyweight : public Flyweight{
public:
    void Operator(int outStatus){
        cout << "unshared concret flyweight,status:" << outStatus << endl;
    }
};
class FlyweightFactor{
private:
    map<string, Flyweight*> m_mapFlyweights;
public:
    Flyweight* GetFlyweight(string key){
        if(NULL == m_mapFlyweights[key]){
            m_mapFlyweights[key] = new ConcretFlyweight();
        }
        return m_mapFlyweights[key];
    }
};
int main(){
    int outStatus = 10;
    FlyweightFactor *pFactory = new FlyweightFactor();
    Flyweight *pFly1 = pFactory->GetFlyweight("X");
    pFly1->Operator(--outStatus);
    
    Flyweight *pFly2 = pFactory->GetFlyweight("Y");
    pFly2->Operator(--outStatus);

    Flyweight *pFly3 = pFactory->GetFlyweight("Z");
    pFly3->Operator(--outStatus);
    delete pFly1;
    delete pFly2;
    delete pFly3;
    delete pFactory;
    UnsharedConcretFlyweight* uf = new UnsharedConcretFlyweight();
    uf->Operator(--outStatus);
    delete uf;
    return 0;
}