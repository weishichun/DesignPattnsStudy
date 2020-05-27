#include <iostream>
#include <string>
using namespace  std;
class Vehicle{
public:
    Vehicle(){
        strBody = "";
        strTyre = "";
        strEngine = "";
    }
    void Show(){
        if(strBody == "" || strTyre == "" || strEngine == ""){
            cout << "车辆还未建造" << endl;
            return;
        }
        cout << "车辆建造完成: " << strBody << ", " << strTyre << ", " << strEngine << endl;
    }
public:
    string strBody;//车身,轮胎,引擎
    string strTyre;
    string strEngine;
};
class BuilderVehicle{
public:
    virtual ~BuilderVehicle(){}
    virtual void BuildBody() = 0;
    virtual void BuildTyre() = 0;
    virtual void BuildEngine() = 0;
};
class BuilderSUV : public BuilderVehicle{
private:
    Vehicle * m_pVehicle;
public:
    BuilderSUV(Vehicle *pV) : m_pVehicle(pV){}
    void BuildBody(){
        m_pVehicle->strBody = "SUV 车身";
    }
    void BuildTyre(){
        m_pVehicle->strTyre = "SUV 轮胎";
    }
    void BuildEngine(){
        m_pVehicle->strEngine = "SUV 引擎";
    }
};
class BuilderTruck : public BuilderVehicle{
private:
    Vehicle * m_pVehicle;
public:
    BuilderTruck(Vehicle *pV) : m_pVehicle(pV){}
    void BuildBody(){
        m_pVehicle->strBody = "卡车 车身";
    }
    void BuildTyre(){
        m_pVehicle->strTyre = "卡车 轮胎";
    }
    void BuildEngine(){
        m_pVehicle->strEngine = "卡车 引擎";
    }
};
class Director{
public:
    Director(){}
    void Build(BuilderVehicle *pBuild){
        pBuild->BuildBody();
        pBuild->BuildTyre();
        pBuild->BuildEngine();
    }
};
int main(){
    Vehicle V;
    BuilderTruck Truck(&V);
    Director D;
    D.Build(&Truck);
    V.Show();

    BuilderSUV SUV(&V);
    D.Build(&SUV);
    V.Show();
    return 0;
}



