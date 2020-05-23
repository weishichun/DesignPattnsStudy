#include <iostream>
using namespace std;
class Strategy
{
public:
    virtual void CommonInterface() = 0;
    virtual ~Strategy(){};
};
class ConcreteStrategyA : public Strategy
{
public:
    void CommonInterface(){ cout << "This is A's Interface." << endl; }
};
class ConcreteStrategyB : public Strategy
{
public:
    void CommonInterface(){ cout << "This is B's Interface." << endl; }
};
class Context
{
public:
    Context(Strategy *p):m_pStrategy(p) {}
    void ContextInterface()
    {
        m_pStrategy->CommonInterface();
    }
private:
    Strategy * m_pStrategy;
};
int main()
{
    ConcreteStrategyA *pA = new ConcreteStrategyA();
    Context *pC = new Context(pA);
    pC->ContextInterface();
    delete pA;
    delete pC;

    ConcreteStrategyB *pB = new ConcreteStrategyB();
    pC = new Context(pB);
    pC->ContextInterface();
    delete pB;
    delete pC;
    return 0;
}