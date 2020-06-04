#include <iostream>
using namespace std;
class Context;
class Status{
public:
    virtual ~Status() {}
    virtual void Handle(Context*) = 0;
};
class Context{
private:
    Status *m_pStatus;    
public:
    Context(Status *pS){
        m_pStatus = pS;
    }
    void Request(){
        m_pStatus->Handle(this);
    }
    void SetStatus(Status *s){
        m_pStatus  = s;
    }
};
class ConcretStatusA : public Status{
public:
    void Handle(Context* c);
};
class ConcretStatusB : public Status{
public:
    void Handle(Context* c);
};
class ConcretStatusC : public Status{
public:
    void Handle(Context* c);
};
void ConcretStatusA::Handle(Context *c){
    cout << "Handle A " << endl;
    c->SetStatus(new ConcretStatusB());
}
void ConcretStatusB::Handle(Context *c){
    cout << "Handle B " << endl;
    c->SetStatus(new ConcretStatusC());
}
void ConcretStatusC::Handle(Context *c){
    cout << "Handle C " << endl;
    c->SetStatus(new ConcretStatusC());
}
int main(){
    Status * s = new ConcretStatusA();
    Context *c =  new Context(s);
    c->Request();
    c->Request();
    c->Request();
    delete s;
    delete c;
    return 0;
};