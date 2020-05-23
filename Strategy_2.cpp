#include <iostream> 
using namespace std;

class IWind
{
public:
    virtual void BlowWind() = 0;
    virtual ~IWind(){};
};
class WarmWind : public IWind
{
public:
    void BlowWind() { cout << "Blow Warm wind" << endl; }
};
class ColdWind: public IWind
{
public:
    void BlowWind() { cout << "Blow Colde wind" << endl; }
};
class Typhoon: public IWind
{
public:
    void BlowWind() { cout << "Blow Typhoon wind" << endl; }
};
class WindMode
{
public:
    WindMode(IWind *p) : m_pWindMode(p) {};
    ~WindMode() {
        if(NULL != m_pWindMode){
            delete m_pWindMode;
            m_pWindMode = NULL;
        }
    }
    void DoBlowWind() { m_pWindMode->BlowWind(); }
private:
    IWind * m_pWindMode;
};
int main()
{
    WindMode *pWarm = new WindMode(new WarmWind());
    WindMode *pCode = new WindMode(new ColdWind());
    WindMode *PTyp = new WindMode(new Typhoon());
    pWarm->DoBlowWind();
    pCode->DoBlowWind();
    PTyp->DoBlowWind();
    delete pWarm;
    delete pCode;
    delete PTyp;
    return 0;
}