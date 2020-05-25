#include <iostream>
using namespace std;
class AbstractProductA{
public:
    AbstractProductA(){}
    virtual ~AbstractProductA(){}
    void start(){
        cout << "ProductA start!  like this AAAAAAAAAAA" << endl;
    } 
    void Exit(){
        cout << "ProductA exit! like this aaaaaaaaaa" <<  endl;
    }
    virtual void Excute() = 0;
};
class ConcreteProductA1 : public AbstractProductA{
public:
    ConcreteProductA1(){};
    ~ConcreteProductA1(){};
    void Excute(){
        cout << "ConcreteProductA1 Excute!  like this  Excute A1A1A1A1A1" << endl;
    }
};
class ConcreteProductA2 : public AbstractProductA{
public:
    ConcreteProductA2(){};
    ~ConcreteProductA2(){};
    void Excute(){
        cout << "ConcreteProductA2 Excute!  like this  Excute A2A2A2A2A2A2" << endl;
    }
};
class AbstractProductB{
public:
    AbstractProductB(){}
    virtual ~AbstractProductB(){}
    void start(){
        cout << "ProductB start!  like this BBBBBBBBB" << endl;
    } 
    void Exit(){
        cout << "ProductB exit! like this bbbbbbbbbbbb" <<  endl;
    }
    virtual void Excute() = 0;
};
class ConcreteProductB1 : public AbstractProductB{
public:
    ConcreteProductB1(){};
    ~ConcreteProductB1(){};
    void Excute(){
        cout << "ConcreteProductB1 Excute!  like this  Excute B1B1B1B1B1" << endl;
    }
};
class ConcreteProductB2 : public AbstractProductB{
public:
    ConcreteProductB2(){};
    ~ConcreteProductB2(){};
    void Excute(){
        cout << "ConcreteProductB2 Excute!  like this  Excute B2B2B2B2B2" << endl;
    }
};
class AbstractFactory{
public:
    AbstractFactory(){}
    virtual ~AbstractFactory(){}
    virtual AbstractProductA * CreateProductA() = 0;
    virtual AbstractProductB * CreateProductB() = 0;
};
class ConcretFactory1 : public AbstractFactory{
public:
    ConcretFactory1(){}
    ~ConcretFactory1(){}
    AbstractProductA * CreateProductA(){
        return new ConcreteProductA1();
    }
    AbstractProductB * CreateProductB(){
        return new ConcreteProductB1();
    }
};
class ConcretFactory2 : public AbstractFactory{
public:
    ConcretFactory2(){}
    ~ConcretFactory2(){}
    AbstractProductA * CreateProductA(){
        return new ConcreteProductA2();
    }
    AbstractProductB * CreateProductB(){
        return new ConcreteProductB2();
    }
};
int main(){
    AbstractFactory * pFactory = new ConcretFactory1();
    AbstractProductA * pProductA = pFactory->CreateProductA();
    pProductA->start();
    pProductA->Excute();
    pProductA->Exit();
    AbstractProductB * pProductB = pFactory->CreateProductB();
    pProductB->start();
    pProductB->Excute();
    pProductB->Exit();
    delete pFactory;
    delete pProductA;
    delete pProductB;

    pFactory = new ConcretFactory2();
    pProductA = pFactory->CreateProductA();
    pProductA->start();
    pProductA->Excute();
    pProductA->Exit();
    pProductB = pFactory->CreateProductB();
    pProductB->start();
    pProductB->Excute();
    pProductB->Exit();
    delete pFactory;
    delete pProductA;
    delete pProductB;

    return 0;
}