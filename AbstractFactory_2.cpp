#include <iostream>
using namespace std;
class CLinux{
public:
    virtual ~CLinux() {}
    virtual void Start() = 0;
};
class CWindows{
public:
    virtual ~CWindows() {}
    virtual void Start() = 0;
};
class CLinuxMobile : public CLinux{
public:
    CLinuxMobile(){
        cout << "Create a linux mobile." << endl;
    }
    virtual ~CLinuxMobile(){}
    void Start(){
        cout << "Linux mobile Start. " << endl;
    }
};
class CLinuxPC: public CLinux{
public:
    CLinuxPC(){
        cout << "Create a linux PC." << endl;
    }
    virtual ~CLinuxPC(){}
    void Start(){
        cout << "Linux PC Start. " << endl;
    }
};
class CWindowsMobile : public CWindows{
public:
    CWindowsMobile(){
        cout << "Create a Windows mobile." << endl;
    }
    virtual ~CWindowsMobile(){}
    void Start(){
        cout << "Windows mobile Start. " << endl;
    }
};
class CWindowsPC: public CWindows{
public:
    CWindowsPC(){
        cout << "Create a Windows PC." << endl;
    }
    virtual ~CWindowsPC(){}
    void Start(){
        cout << "Windows PC Start. " << endl;
    }
};
class CFactory{
public:
    virtual ~CFactory(){}
    virtual CLinux * CreateLinuxProduct() = 0;
    virtual CWindows * CreateWindowsProduct() = 0;
};
class CMobileFactory : public CFactory{
public:
   CMobileFactory(){
       cout << "Create a Mobile Factory! " << endl << endl;
   }
   virtual ~CMobileFactory(){} 
   CLinux * CreateLinuxProduct(){
       return new CLinuxMobile();
   }
   CWindows * CreateWindowsProduct(){
       return new CWindowsMobile();
   }
};
class CPCFactory : public CFactory{
public:
   CPCFactory(){
       cout << "Create a PC Factory! " << endl << endl;
   } 
   virtual ~CPCFactory(){}
   CLinux * CreateLinuxProduct(){
       return new CLinuxPC();
   }
   CWindows * CreateWindowsProduct(){
       return new CWindowsPC();
   }
};
void CreateProduct(CFactory * pFactory){
    CLinux *pLinux= pFactory->CreateLinuxProduct();
    pLinux->Start();
    cout << endl;
    CWindows *pWindows = pFactory->CreateWindowsProduct();
    pWindows->Start();
    delete pLinux;
    delete pWindows;
}
int main()
{
    CFactory *pFactory = new CMobileFactory();
    CreateProduct(pFactory);
    delete  pFactory;
    cout << endl;
    pFactory = new CPCFactory();
    CreateProduct(pFactory); delete pFactory; return 0;
}