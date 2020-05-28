#include<iostream>
using namespace std;
/*
最推荐的懒汉式单例(magic static )——局部静态变量,
并发线程在获取静态局部变量的时候一定是初始化过的，所以具有线程安全性。
C++静态变量的生存期是从声明到程序结束，这也是一种懒汉式。
这是最推荐的一种单例实现方式：
通过局部静态变量的特性保证了线程安全 (C++11, GCC > 4.3, VS2015支持该特性);
不需要使用共享指针，代码简洁；
注意在使用的时候需要声明单例的引用 Single& 才能获取对象。
*/
class Singleton{
public:
    ~Singleton(){
        cout << "单例对象销毁" << endl;
    }
    Singleton(const Singleton&){}
    static Singleton& GetInstance(){
        /*饿汉式的特点是一开始就加载了，如果说懒汉式是“时间换空间”，
        那么饿汉式就是“空间换时间”，因为一开始就创建了实例，
        所以每次用到的之后直接返回就好了。饿汉模式是线程安全的。*/
        static Singleton instance;
        return instance;
    }
private:
    Singleton(){
        cout << "单例对象创建" << endl;
    }
};
int main(){
    Singleton& instance1 = Singleton::GetInstance();
    Singleton& instance2 = Singleton::GetInstance();
    return 0;
}