#include<iostream>
using namespace std;
class Singleton{
private:
    Singleton(){
        cout << "Create Singleton." << endl;
    }
    Singleton(Singleton&){}
    static Singleton* m_pSingleton;
public:
    virtual ~Singleton(){}
    static Singleton* GetInstance(){
        if(NULL ==  m_pSingleton){
            m_pSingleton = new Singleton();
        }
        return m_pSingleton;
    }
};
Singleton* Singleton::m_pSingleton = NULL;
/*
1. 线程安全的问题,当多线程获取单例时有可能引发竞态条件：第一个线程在if中判断 m_pSingleton是空的，于是开始实例化单例;同时第2个线程也尝试获取单例，这个时候判断m_pSingleton还是空的，于是也开始实例化单例;这样就会实例化出两个对象,这就是线程安全问题的由来; 解决办法:加锁
1. 内存泄漏. 注意到类中只负责new出对象，却没有负责delete对象，因此只有构造函数被调用，析构函数却没有被调用;因此会导致内存泄漏。解决办法： 使用共享指针;
*/
/*懒汉式(Lazy-Initialization)的方法是直到使用时才实例化对象，也就说直到调用GetInstance() 方法的时候才 new 一个单例的对象。好处是如果被调用就不会占用内存。
*/
int main(){
    Singleton* instance1 = Singleton::GetInstance();
    Singleton* instance2 = Singleton::GetInstance();
    return 0;
}