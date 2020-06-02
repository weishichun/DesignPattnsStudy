#include<iostream>
using namespace std;
class Mediator;
class Person{
protected:
    Mediator *m_pMediator;
public:
    virtual void SetMediator(Mediator* pM) = 0;
    virtual void GetMsg(string strMsg) = 0;//从中介获取消息
    virtual void SendMsg(string strMsg) = 0;//向中介发消息
};
class Mediator{//抽象中介
public:
    virtual ~Mediator(){}
    virtual void Send(string strMsg, Person *pPerson) = 0; 
    virtual void SetA(Person *pA) = 0;
    virtual void SetB(Person *pB) = 0;
};
class Renter : public Person{
public:
    void SetMediator(Mediator* pM) {
        m_pMediator = pM; 
    }
    void GetMsg(string strMsg){
        cout << "租客收到消息: " << strMsg << endl;
    } 
    void SendMsg(string strMsg) {
        m_pMediator->Send(strMsg,this);
    }
};
class Landlord: public Person{
public:
    void SetMediator(Mediator* pM) {
        m_pMediator = pM; 
    }
    void GetMsg(string strMsg){
        cout << "房东收到消息: " << strMsg << endl;
    } 
    void SendMsg(string strMsg) {
        m_pMediator->Send(strMsg,this);
    }
};
class HoseMediator : public Mediator{
private:
    Person *m_pA;
    Person *m_pB;
public:
    HoseMediator(){
        m_pA = NULL;
        m_pB = NULL;
    }
    void SetA(Person *pA){
        m_pA = pA;
    } 
    void SetB(Person *pB){
        m_pB = pB;
    } 
    void Send(string strMsg, Person *pPerson){
        if(m_pA == pPerson){
            m_pB->GetMsg(strMsg);
        }
        else{
            m_pA->GetMsg(strMsg);
        }
    }
};
int main(){
    Mediator *pM = new HoseMediator();
    Person * pR = new Renter();
    Person * pL = new Landlord();
    pM->SetA(pR);
    pM->SetB(pL);
    pR->SetMediator(pM);
    pL->SetMediator(pM);
    pR->SendMsg("我想租房! 可有?");
    pL->SendMsg("这有一套性价比高的一房一厅待出租,欢迎看房" );
    return 0;
}