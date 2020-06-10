#include <iostream>
#include <vector>
using namespace std;
class Reciver{
public:
    virtual ~Reciver(){}
    virtual void Open()=0;
    virtual void Close()=0;
};
class TvRecier:public Reciver{
public:
    void Open(){cout << "开电视" << endl;}
    void Close(){cout << "关电视" << endl;}
};
class Command{
protected:
    Reciver* pReciver;
public:
    Command(Reciver* r):pReciver(r){}
    virtual ~Command(){}
    virtual void Excute()=0;
};
class OpenCommand : public Command{
public:
    OpenCommand(Reciver* r):Command(r){}
    void Excute(){
        pReciver->Open();
    }
};
class CloseCommand : public Command{
public:
    CloseCommand(Reciver* r):Command(r){}
    void Excute(){
        pReciver->Close();
    }
};
class RemoteControl{
public:
    void Excute(Command * pCmd){
        vecpCmd.push_back(pCmd);
        pCmd->Excute();
    }
private:
    vector<Command*> vecpCmd;
};
int main(){
    Reciver *pR = new TvRecier();
    Command *pOpen = new OpenCommand(pR);
    Command *pClose = new CloseCommand(pR);
    RemoteControl *pRemoteCtrl = new RemoteControl();
    pRemoteCtrl->Excute(pOpen);
    pRemoteCtrl->Excute(pClose);
    delete pRemoteCtrl;
    delete pClose;
    delete pOpen;
    delete pR;
    return 0;
}