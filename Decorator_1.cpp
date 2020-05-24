#include <iostream>
#include <string>
using namespace std;

class ICake {  //蛋糕基类
public:
    virtual void ShowCake() = 0;
    virtual ~ICake() {}
public:
    string m_strName; 
    int m_nCost;
    int m_nTotalCost;
};
class OriginalCake : public ICake { //定义一个原味蛋糕,用装饰器给这个蛋糕加各种料
public:
    OriginalCake(){
        m_strName = "原味蛋糕";
        m_nCost = 10;
    }
    void ShowCake(){
        m_nTotalCost += m_nCost;
        cout << m_strName << ": " << m_nCost << "元" << endl;
    }
};
class DecoratorCake : public ICake { //装饰器基类
public:
    virtual void ShowCake() = 0; //装饰类和被装饰的类有相同接口
    virtual ~DecoratorCake(){};
protected:
    ICake * m_pCake;  //装饰类包含被装饰类的一个指针
};
class DecoratorCakeMilk : public DecoratorCake{ //给原味蛋糕加奶油
public:
    DecoratorCakeMilk(ICake *pCake){
        m_pCake = pCake;
    }
    void ShowCake(){
        this->m_strName = m_pCake->m_strName + ",加奶油";
        this->m_nCost = m_pCake->m_nCost + 2;
        m_nTotalCost += this->m_nCost;
        cout << this->m_strName << ",2元,共需要 " << m_nTotalCost <<  "元" << endl;
    }
};
class DecoratorCakePeanut : public DecoratorCake{ //给原味蛋糕加花生粒
public:
    DecoratorCakePeanut(ICake *pCake){
        m_pCake = pCake;
    }
    void ShowCake(){
        this->m_strName = m_pCake->m_strName + ",加花生粒";
        this->m_nCost = m_pCake->m_nCost + 3;
        m_nTotalCost += m_nCost;
        cout << this->m_strName << ",3元,共需要 " << m_nTotalCost <<  "元" << endl;
    }
};
int main()
{
    OriginalCake *pCake = new OriginalCake();
    pCake->ShowCake();
    DecoratorCakeMilk *pMilk = new DecoratorCakeMilk(pCake);
    pMilk->ShowCake();
    DecoratorCakePeanut *pPeanut = new DecoratorCakePeanut(pCake);
    pPeanut->ShowCake();
    delete pCake;
    delete pMilk;
    delete pPeanut;
    return 0;
}