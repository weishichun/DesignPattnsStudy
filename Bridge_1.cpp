#include <iostream>
using namespace std;
class Software{
public:
    virtual void Run() = 0;
    virtual ~Software(){}
};
class Computer{
protected:
    Software *m_pSoft;
public:
    Computer() {
        m_pSoft = NULL;
    }
    virtual void Run() = 0;
    virtual ~Computer(){
        if (NULL != m_pSoft)
        {
            delete m_pSoft;
            m_pSoft = NULL;
        }
    }
    void SetSoftware(Software *pSoft) {
       m_pSoft = pSoft; 
    }
};
class Game : public Software{
public:
    void Run() { cout << "运行游戏!" << endl; }
};
class Office : public Software{
public:
    void Run() { cout << "运行办公软件!" << endl; }
};
class Lenovo : public Computer{
public:
    void Run() { 
        cout << "Lenovo 电脑:"; 
        m_pSoft->Run();
    }
};
class Apple : public Computer{
public:
    void Run() { 
        cout << "Apple Macbook Pro:"; 
        m_pSoft->Run();
    }
};
int main()
{
    Computer *pC = new Lenovo();
    pC->SetSoftware(new Game());
    pC->Run();
    delete pC;
    pC = NULL;
    pC = new Apple();
    pC->SetSoftware(new Office());
    pC->Run();
    delete pC;
    pC = NULL; 
    return 0;
}