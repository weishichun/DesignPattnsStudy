#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Singleton{
public:
    static T& GetInstance(){
        static T m_stiVlue;
        return m_stiVlue;
    }
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(Singleton&){}
};
class A{
public:
    A(){
        a = "create AAAAAAA";
    }
    void fun(){
        cout << "A.a = " << a << endl;
    }
private:
    string a;
};
class B{
public:
    B(){
        b = "create BBBBBBB";
    }
    void fun(){
        cout << "B.b = " << b << endl;
    }
private:
    string b;
};
int main(){
    Singleton<A>::GetInstance().fun();
    Singleton<B>::GetInstance().fun();
    return 0;
}