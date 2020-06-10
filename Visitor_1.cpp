#include <iostream>
#include <list>
using namespace std;
class Classroom;
class Playground;
class Visitor{ //角色=visitor类
public:
    virtual ~Visitor(){}
    virtual void Visit(Classroom *classroom) = 0;
    virtual void Visit(Playground *playground) = 0;
};
class Student : public Visitor{
public:
    void Visit(Classroom *classroom){
        cout << "Student Study in classroom" << endl;
    }
    void Visit(Playground *playground){
        cout << "Student play in playground" << endl;
    }
};
class Teacher: public Visitor{
public:
    void Visit(Classroom *classroom){
        cout << "Teacher teach in classroom" << endl;
    }
    void Visit(Playground *playground){
        cout << "Teacher watch in playground" << endl;
    }
};
class Place{
public:
    virtual ~Place(){}
    virtual void Accept(Visitor *v) = 0;
};
class Classroom : public Place{
public:
    void Accept(Visitor *v){
        v->Visit(this);
    }
};
class Playground: public Place{
public:
    void Accept(Visitor *v){
        v->Visit(this);
    }
};
class School{
public:
    void Add(Place* place){
        listPlace.push_back(place);
    }
    void Remove(Place* place){
        listPlace.remove(place);
    }
    void Accept(Visitor *v){
        list<Place*>::iterator iter = listPlace.begin();
        for(;iter != listPlace.end();iter++){
            (*iter)->Accept(v);
        }
    }
private:
    list<Place*> listPlace;
};
int main(){
    School *pSchool = new School;
    Place *pclassroom = new Classroom;
    Place *pplaygroud = new Playground;
    Visitor *pStu = new Student();
    Visitor *pTeacher = new Teacher();
    pSchool->Add(pclassroom);
    pSchool->Add(pplaygroud);
    pSchool->Accept(pStu);
    pSchool->Accept(pTeacher);
    delete pTeacher;
    delete pStu;
    delete pplaygroud;
    delete pclassroom; 
    delete pSchool; 
    return 0;
}