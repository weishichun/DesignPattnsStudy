#include <iostream>
#include <list>
using namespace std;
class Observer {
public:
    virtual void UpdateStatus(int nStatus) = 0;
    virtual ~Observer() { };
};
class Subject {
public:
    virtual void Attach(Observer *) = 0;
    virtual void Dettach(Observer *) = 0;
    virtual void Notify() = 0;
    virtual ~Subject() { }
};
class ConcreteObserverA : public Observer {
public:
    ConcreteObserverA(Subject *pObj) :m_pSubject(pObj) { }
    void UpdateStatus(int nStatus) {
        cout << "Observer A Update status, now status is " << nStatus << endl;
    }
private:
    Subject * m_pSubject;
};
class ConcreteObserverB : public Observer {
public:
    ConcreteObserverB(Subject *pObj) :m_pSubject(pObj) { }
    void UpdateStatus(int nStatus) {
        cout << "Observer B Update status, now status is " << nStatus << endl;
    }
private:
    Subject * m_pSubject;
};
class ConcreteSubject : public Subject {
public:
    void Attach(Observer *pOb);
    void Dettach(Observer *pOb);
    void Notify();
    void SetStatus(int nStatus) { m_nStatus = nStatus; }
private:
    int m_nStatus;
    list<Observer *>  m_listObserver;  
};
void ConcreteSubject::Attach(Observer *pOb) {
    m_listObserver.push_back(pOb);
}
void ConcreteSubject::Dettach(Observer *pOb) {
    m_listObserver.remove(pOb);
}
void ConcreteSubject::Notify() {
   list<Observer *>::iterator it= m_listObserver.begin();
   while(it != m_listObserver.end()) {
       (*it)->UpdateStatus(m_nStatus);
       ++it; 
   }
}
int main() {
    ConcreteSubject *pSubject = new ConcreteSubject();
    Observer *pObserverA = new ConcreteObserverA(pSubject);
    Observer *pObserverB = new ConcreteObserverB(pSubject);
    pSubject->SetStatus(2);
    pSubject->Attach(pObserverA);
    pSubject->Attach(pObserverB);
    pSubject->Notify();
    pSubject->SetStatus(3);
    pSubject->Dettach(pObserverB);
    pSubject->Notify();
    delete pSubject; delete pObserverA; delete pObserverB;
    return 0;
}