#include<iostream>
using namespace std;
class Subject{
public:
    virtual void Request() = 0;//公共接口
    virtual ~Subject(){}
};
class RealSubject : public Subject {
public:
    void Request() {
        cout << "I am RealSubject" << endl;
    }
};
class Proxy : public Subject{
private:
    RealSubject* realSubject;//代理通过该指针访问实体
public:
    void Request(){
        if(NULL == realSubject){
            realSubject = new RealSubject();
        }
        realSubject->Request();
    }
};
int main(){
    Proxy* p = new Proxy();
    p->Request();
    delete p;
    return 0;
}