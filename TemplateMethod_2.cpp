#include <iostream>
using namespace std;

class AbstractClass {
// 抽象类，其实就是一个抽象模板，定义并实现了一个模板方法。
// 这个模板方法一般是一个具体方法，给出了一个顶级逻辑的骨架，而逻辑的组成步骤在相应的抽象操作中，推迟到了子类实现。
// 顶级逻辑也可能调用一些具体的方法。
public:
    void TemplateMethod() { // 模板方法，给出了逻辑骨架，而逻辑的组成是一些相应的抽象操作，推迟到子类实现.
        PrimitiveOperation1();
        PrimitiveOperation2();
    }
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0; // 一些抽象行为，放到子类实现
    virtual ~AbstractClass() {}
};

class ConcreteClassA : public AbstractClass {
// ConcreteClass实现父类所定义的一个或多个抽象方法。
// 每个AbstractClass都可以有任意多个ConcreteClass与之对应，
// 而每一个ConcreteClass都可以给出这些抽象方法的不同实现，从而使得顶级逻辑的实现各不相同。
public:
    void PrimitiveOperation1() {
        cout << "ConcreteClassA: PrimitiveOperation1 & ";
    }
    void PrimitiveOperation2() {
        cout << "PrimitiveOperation2" << endl;
    }
};

class ConcreteClassB : public AbstractClass {
public:
    void PrimitiveOperation1() {
        cout << "ConcreteClassB: PrimitiveOperation1 & ";
    }
    void PrimitiveOperation2() {
        cout << "PrimitiveOperation2" << endl;
    }
};

int main() {
    AbstractClass* aa = new ConcreteClassA();
    aa->TemplateMethod(); // ConcreteClassA: PrimitiveOperation1 & PrimitiveOperation2

    AbstractClass* ab = new ConcreteClassB();
    ab->TemplateMethod(); // ConcreteClassB: PrimitiveOperation1 & PrimitiveOperation2

    delete aa;
    delete ab;
    return 0;
}