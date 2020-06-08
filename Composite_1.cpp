#include <iostream>
#include <list>
#include <string>
using namespace std;
class Component{
protected:
    string m_strName;
public:
    virtual ~Component(){}
    Component(string n){
        m_strName = n;
    }
    virtual void Add(Component* c) = 0;
    virtual void Delete(Component* c) = 0;
    virtual void Display(int depth) = 0;
};
class Leaf : public Component{
public:
    Leaf(string name):Component(name){}
    void Add(Component* c){}
    void Delete(Component* c){}
    void Display(int depth){
        cout << m_strName << "  " << depth << endl;
    } 
};
class Composite : public Component{
private:
    list<Component*> listChild;
public:
    Composite(string name):Component(name){}
    void Add(Component* c){
        listChild.push_back(c);
    }
    void Delete(Component* c){
        listChild.remove(c);
    }
    void Display(int depth){
        cout << m_strName << "  " << depth << endl;

        for (list<Component*>::iterator iter = listChild.begin();
        iter != listChild.end();iter++)
        {
            (*iter)->Display(depth+2);
        }
    }
};
int main(){
    Composite* root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));
    
    Composite *com1 = new Composite("Composite one");
    com1->Add(new Leaf("Leaf C1A"));
    com1->Add(new Leaf("Leaf C1B"));
    root->Add(com1);
    
    Composite *com2 = new Composite("Composite two");
    com2->Add(new Leaf("Leaf C2A"));
    com2->Add(new Leaf("Leaf C2B"));
    root->Add(com2);

    root->Display(1);
    delete root;
    delete com1;
    delete com2;
    return 0;
}