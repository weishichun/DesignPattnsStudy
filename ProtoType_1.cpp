#include <iostream>
#include <string>
using namespace std;
class ProtoType{
public:
    virtual ~ProtoType(){
        delete [] m_pDescribe;
    }
    ProtoType(string str,const char *pSrc){
        m_strName = str;
        int nLen = strlen(pSrc);
        m_pDescribe = new char[nLen + 1];
        cout << "Describe内存地址:" << &m_pDescribe << endl; 
        strcpy(m_pDescribe,pSrc);//深度克隆
        m_pDescribe[nLen] = '\0';
    }
    virtual ProtoType* Clone() = 0;
    char *GetDescribe(){
        return m_pDescribe;
    }
    string GetName(){
        return m_strName;
    }
private:
    string m_strName;
    char *m_pDescribe;
};
class ConcretProtoTypeA : public ProtoType{
public:
    ConcretProtoTypeA(string str,const char *pSrc):ProtoType(str,pSrc){}
    ConcretProtoTypeA(ConcretProtoTypeA &other):ProtoType(other.GetName(),other.GetDescribe()){}
    ProtoType* Clone(){
        return new ConcretProtoTypeA(*this);
    }
};
class ConcretProtoTypeB : public ProtoType{
public:
    ConcretProtoTypeB(string str,const char *pSrc):ProtoType(str,pSrc){}
    ConcretProtoTypeB(ConcretProtoTypeA &other):ProtoType(other.GetName(),other.GetDescribe()){}
    ProtoType* Clone(){
        return new ConcretProtoTypeB(*this);
    }
};
int main(){
    const char *pDescribe = "I Love You";
    ProtoType *pProto = new ConcretProtoTypeA("Honey", pDescribe);
    ProtoType *pClone = pProto->Clone();
    cout << pClone->GetName() << ", Hi, " << pClone->GetDescribe() << endl;
    return 0;
}