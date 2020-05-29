#include <iostream>
#include <vector>
using namespace std;
class Flyweight{
public:
    Flyweight(){ cout << "构造Flyweight" << endl;}
    virtual ~Flyweight(){ cout << "析构Flyweight" << endl;}
    virtual void Operator() = 0;
};
class ConcretFlyweight : public Flyweight{
public:
    ConcretFlyweight(){ cout << "构造ConcretFlyweight" << endl;}
    ~ConcretFlyweight(){ cout << "析构ConcretFlyweight" << endl;}
    void Operator(){
        cout << "I am ConcretFlyweight" << endl;
    }
};
class FlyweightFactory{
private:
    vector<Flyweight*> m_vecpWeights;
public:
    FlyweightFactory(){
        Flyweight *tmp =new ConcretFlyweight();
        m_vecpWeights.push_back(tmp);
        cout << "构造FlyweightFactory" << endl;
    }
    ~FlyweightFactory(){
        Flyweight *tmp = m_vecpWeights.at(0);
        delete tmp;
        tmp = NULL;
        cout << "析构FlyweightFactory" << endl;
    }
    Flyweight* GetFlyweight(int key){
        return m_vecpWeights.at(key);
    }
};
int main(){
    FlyweightFactory* pFactory = new FlyweightFactory();
    Flyweight * pFly = pFactory->GetFlyweight(0);
    pFly->Operator();
    delete pFactory;//一定要释放内存
    delete pFly;
    return 0;
}