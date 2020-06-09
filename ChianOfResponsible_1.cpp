#include <iostream>
#include <string>
using namespace std;
class Request{
public:
    int m_nNumber;
};
class Manager{
protected:
    Manager *m_pManager;
    string m_strName;
public:
    Manager(string name){
        m_strName = name;
    }
    virtual ~Manager(){}
    void SetHandler(Manager *pM){
        m_pManager = pM; //设置处理人
    }
    virtual void GetRequest(Request *pRequest) = 0;
};
class ManagerC : public Manager{ 
public:
    ManagerC(string name):Manager(name){}
    void GetRequest(Request * pRequest){
        if(pRequest->m_nNumber > 0 && pRequest->m_nNumber < 1000 ){
            cout << m_strName << "处理了: " << pRequest->m_nNumber << endl;
        }else{
            m_pManager->GetRequest(pRequest);
        }
    }
};
class ManagerB : public Manager{
public:
    ManagerB(string name):Manager(name){}
    void GetRequest(Request * pRequest){
        if(pRequest->m_nNumber > 1000 && pRequest->m_nNumber < 5000 ){
            cout << m_strName << "处理了: " << pRequest->m_nNumber << endl;
        }else{
            m_pManager->GetRequest(pRequest);
        }
    }
};
class ManagerA : public Manager{
public:
    ManagerA(string name):Manager(name){}
    void GetRequest(Request * pRequest){
        if(pRequest->m_nNumber >= 5000){
            cout << m_strName << "处理了: " << pRequest->m_nNumber << endl;
        }
    }
};
int main(){
    Manager* pMC = new ManagerC("主管");
    Manager* pMB = new ManagerB("经理");
    Manager* pMA = new ManagerA("总监");
    pMC->SetHandler(pMB);
    pMB->SetHandler(pMA);
    Request *pR = new Request();
    pR->m_nNumber = 100;
    pMC->GetRequest(pR);
    pR->m_nNumber = 1500;
    pMC->GetRequest(pR);
    pR->m_nNumber = 6500;
    pMC->GetRequest(pR);
    delete pMC;delete pMB; delete pMA; delete pR;
    return 0;
}