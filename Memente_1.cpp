#include <iostream>
#include <string>
using namespace std;
class Memente{  //备忘录
private:
    string m_strState;
public:
    Memente(string s){
        m_strState = s;
    }
    void SetState(string s){
        m_strState = s;
    }
    string GetState(){
        return m_strState;
    }
};
class Caretaker{  //管理者
private:
    Memente *m_pMemente;
public:
    ~Caretaker(){
        delete m_pMemente;
    }
    void SetMemento(Memente *pM){
        m_pMemente = pM;
    }
    Memente* GetMemente(){
        return m_pMemente;
    }
};
class Originator{  //发起人
private:
    string m_strState;
public:
    void SetState(string s){
        m_strState = s;
    }
    string GetState(){
        return m_strState;
    }
    Memente* CreateMemente(){  //创建备忘录对象, 保存发起人的信息
        return new Memente(m_strState);
    }
    void SetMemente(Memente* m){  //恢复备忘录
        m_strState = m->GetState();
    }
    void ShowState(){
        cout << "state: " << m_strState << endl;
    }
};
int main(){
    Originator *o = new Originator();
    o->SetState("on");
    o->ShowState();

    Caretaker *c = new Caretaker();
    c->SetMemento(o->CreateMemente()); //保存o的状态

    o->SetState("off");
    o->ShowState();

    o->SetMemente(c->GetMemente());//恢复状态
    o->ShowState();

    delete o; delete c;
    return 0;
}