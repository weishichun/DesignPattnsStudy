#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Iterator{
public:
    virtual ~Iterator(){}
    virtual string First() =0;
    virtual string Next() = 0;
    virtual string Current() = 0;
    virtual bool IsEnd() = 0;
};
class Aggregate{
public:
    virtual ~Aggregate(){}
    virtual int Count() = 0;
    virtual void Push(const string &str) = 0;
    virtual string Pop(const int index) = 0;
    virtual Iterator * CreateIterator() = 0;
};
class ConcretIterator : public Iterator{
private:
    Aggregate *m_Agre;
    int m_nCurrent;
public:
    ConcretIterator(Aggregate *a){
        m_Agre = a;
        m_nCurrent = 0;
    }
    ~ConcretIterator(){
        if(NULL != m_Agre)
            delete m_Agre;
    }
    string First(){
        return m_Agre->Pop(0);
    }
    string Next(){
        string strRet;
        m_nCurrent++;
        if(m_nCurrent < m_Agre->Count()){
            strRet =  m_Agre->Pop(m_nCurrent);
        }
        return strRet;
    }
    string Current(){
        return m_Agre->Pop(m_nCurrent);
    }
    bool IsEnd(){
        return m_nCurrent >= m_Agre->Count() ? true : false;
    }
};
class ConcretAggregate : public Aggregate{
private:
    vector<string> m_vecItems;
    Iterator *m_pIter;
public:
    ConcretAggregate(){
        m_vecItems.clear();
        m_pIter = NULL;
    }
    ~ConcretAggregate(){
        if(m_pIter != NULL)
            delete m_pIter;
    }
    Iterator* CreateIterator(){
        if(NULL == m_pIter){
            m_pIter = new ConcretIterator(this);
        }
        return m_pIter;
    }
    int Count(){
        return m_vecItems.size();
    }
    void Push(const string &str){
        m_vecItems.push_back(str);
    }
    string Pop(const int index){
        string strRet; 
        if(index < Count()){
            strRet = m_vecItems[index];
        }
        return strRet;
    }
};
int main(){
    ConcretAggregate *pCA = new ConcretAggregate();
    pCA->Push("AA");
    pCA->Push("BB");
    pCA->Push("CC");
    pCA->Push("DD");
    Iterator *Iter = pCA->CreateIterator();
    string strItem = Iter->First();
    while (!Iter->IsEnd())
    {
        cout << Iter->Current() << " is OK" << endl;
        Iter->Next();
    }
    return 0;
}
