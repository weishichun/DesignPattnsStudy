#include <iostream>
using namespace std;

class Cloth{ //服装生立商,相当于Subject
public:
    virtual void MakeCloth(const string strClothType) = 0;
    virtual ~Cloth(){}
};
class ManCloth : public Cloth{//=realSubject
public:
    void MakeCloth(string strType){
        cout << "Make " << strType << " Cloth" << endl;
    }
};
class WoManCloth : public Cloth{//=realSubject
public:
    void MakeCloth(string strType){
        cout << "Make " << strType << " Cloth" << endl;
    }
};
class ClothWholeSale : public Cloth{//服装批发商=Proxy
private:
    ManCloth *pMan;
    WoManCloth *pWoman;
public:
    ~ClothWholeSale(){
        delete pMan;
        delete pWoman;
    }
    void MakeCloth(string strType){
        if(strType == "Man"){
            if(NULL == pMan){
                pMan = new ManCloth();
            }
            pMan->MakeCloth(strType);
        }
        if(strType == "WoMan"){
            if(NULL == pWoman){
                pWoman = new WoManCloth();
            }
            pWoman->MakeCloth(strType);
        }
    }
};
int main(){
    ClothWholeSale *pSale = new ClothWholeSale();
    pSale->MakeCloth("Man");
    pSale->MakeCloth("WoMan"); 
    return 0;
}