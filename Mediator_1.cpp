#include <iostream>
using namespace std;
class Collegue;
class Mediator{
public:
    virtual ~Mediator(){}
    virtual void SendMsg(string strMsg,Collegue *pCollegue) = 0;
};
class Collegue{
protected:
    Mediator *pMediator;
public:
    Collegue(Mediator* pM){
        pMediator = pM;
    }
};
class ConcretCollegueA : public Collegue{
public:
    ConcretCollegueA(Mediator *pM):Collegue(pM){}
    void SendMsg(string strMsg){
        pMediator->SendMsg(strMsg,this);
    }
    void Notyfy(string strMsg){
        cout << "ConcretCollegueA recevie " << strMsg << endl;
    }
};
class ConcretCollegueB : public Collegue{
public:
    ConcretCollegueB(Mediator *pM):Collegue(pM){}
    void SendMsg(string strMsg){
        pMediator->SendMsg(strMsg,this);
    }
    void Notyfy(string strMsg){
        cout << "ConcretCollegueB recevie " << strMsg << endl;
    }
};
class ConcretMediator : public Mediator{
private:
    ConcretCollegueA *pA;
    ConcretCollegueB *pB;
public:
    void Set(ConcretCollegueA* a){
        pA = a;
    }
    void Set(ConcretCollegueB* b){
        pB = b;
    }
    void SendMsg(string strMsg,Collegue *pCol){
       if(pCol == pA) pB->Notyfy(strMsg);
       else pA->Notyfy(strMsg);
    }
};
int main(){
    ConcretMediator *pM = new ConcretMediator();
    ConcretCollegueA *pA = new ConcretCollegueA(pM);
    ConcretCollegueB *pB = new ConcretCollegueB(pM);
    pM->Set(pA);
    pM->Set(pB);
    pA->SendMsg("Hello ");
    pB->SendMsg("World! ");
    delete pM;
    delete pA;
    delete pB;
    return 0;
}