#include <iostream>
using namespace std;
class Strategy
{
public:
    virtual void CommonInterface() = 0;
    virtual ~Strategy(){};
};
class StrategyA : public Strategy
{
public:
    void CommonInterface()
    {
        cout << "This s A's CommonInterface." << endl;
    }
};
class StrategyB : public Strategy
{
public:
    void CommonInterface()
    {
        cout << "This s B's CommonInterface." << endl;
    }
};
class StrategyC : public Strategy
{
public:
    void CommonInterface()
    {
        cout << "This s C's CommonInterface." << endl;
    }
};
class ContextStrFactory
{
public:
    ContextStrFactory(char cType)
    {
        switch (cType)
        {
        case 'A':
            m_pStrgy = new StrategyA();    
            break;
        case 'B':
            m_pStrgy = new StrategyB();    
            break;
        case 'C':
            m_pStrgy = new StrategyC();    
            break;
        default:
            break;
        }
    }
    ~ContextStrFactory()
    {
        if (NULL != m_pStrgy)
        {
            delete m_pStrgy;
            m_pStrgy = NULL;
        }
    }
    void ContextInterface()
    {
        m_pStrgy->CommonInterface();
    }
private:
    Strategy * m_pStrgy;
};

int main()
{
    ContextStrFactory *pStragy = new ContextStrFactory('A');
    pStragy->ContextInterface();
    delete pStragy;
    pStragy = new ContextStrFactory('B');
    pStragy->ContextInterface();
    delete pStragy;
    pStragy = new ContextStrFactory('C');
    pStragy->ContextInterface();
    delete pStragy;

    return 0;
}