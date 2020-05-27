#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Product{
private:
    vector<string> vecParts;
public:
    void AddAPart(const string strPart){
       vecParts.push_back(strPart); 
    }
    virtual void Show() const{
        for(int i = 0; i<vecParts.size(); i++){
            cout << vecParts[i] <<  ", ";
        }
        cout << endl;
    }
};
class Builder{
public:
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildHand() = 0;
    virtual void BuildFeet() = 0;
    virtual ~Builder(){}
    virtual Product* GetProduct() = 0;
};
class FatPersonBuilder : public Builder{
private:
    Product * m_pProduct;
public:
    FatPersonBuilder(Product* pPro):m_pProduct(pPro){}
    void BuildHead() {
        m_pProduct->AddAPart("胖子的头");
    }
    void BuildBody() {
        m_pProduct->AddAPart("胖子的身体");
    }
    void BuildHand() {
        m_pProduct->AddAPart("胖子的手");
    }
    void BuildFeet() {
        m_pProduct->AddAPart("胖子的脚");
    }
    Product* GetProduct(){
        return m_pProduct;
    }
};
class ThinPersonBuilder : public Builder{
private:
    Product * m_pProduct;
public:
    ThinPersonBuilder(Product* pPro):m_pProduct(pPro){}
    void BuildHead() {
        m_pProduct->AddAPart("瘦子的头");
    }
    void BuildBody() {
        m_pProduct->AddAPart("瘦子的身体");
    }
    void BuildHand() {
        m_pProduct->AddAPart("瘦子的手");
    }
    void BuildFeet() {
        m_pProduct->AddAPart("瘦子的脚");
    }
    Product* GetProduct(){
        return m_pProduct;
    }
};
class Director{
public:
    Director(){}
    void CreatPerson(Builder *pBuilder)
    {
        pBuilder->BuildHead();
        pBuilder->BuildBody();
        pBuilder->BuildHand();
        pBuilder->BuildFeet();
    }
};
int main(){
    Product objProduct;
    FatPersonBuilder *pFat = new FatPersonBuilder(&objProduct);
    ThinPersonBuilder *pThin = new ThinPersonBuilder(&objProduct);
    Director objDirector;
    objDirector.CreatPerson(pFat);
    pFat->GetProduct()->Show();
    objDirector.CreatPerson(pThin);
    pThin->GetProduct()->Show();
    delete pFat;
    delete pThin; 
    return 0;
}