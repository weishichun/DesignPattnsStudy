#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
class Tool
{ //=Flyweight
public:
    //内部状态
    string m_strName;
public:
    virtual void Use(string strPerson, string strWork) = 0; //外部状态
    Tool() { cout << "构造Tool" << endl; }
    virtual ~Tool() { cout << "析构Tool" << endl; }
};
class Hammer : public Tool
{ //=ConcretFlyWeight
public:
    Hammer()
    {
        m_strName = "hammer";
        cout << "构造Hammer" << endl;
    }
    ~Hammer() { cout << "析构Hammer" << endl; }
    void Use(string strPersion, string strWork)
    {
        cout << strPersion << "用" << m_strName << "去" << strWork << endl;
    }
};
class Screwdrive : public Tool
{ //=ConcretFlyWeight
public:
    Screwdrive()
    {
        m_strName = "screwdrive";
        cout << "构造screwdrive" << endl;
    }
    ~Screwdrive() { cout << "析构Scredrive " << endl; }
    void Use(string strPersion, string strWork)
    {
        cout << strPersion << "用" << m_strName << "去" << strWork << endl;
    }
};
class Saw : public Tool
{ //=ConcretFlyWeight
public:
    Saw()
    {
        m_strName = "saw";
        cout << "构造Saw" << endl;
    }
    ~Saw() { cout << "析构Saw" << endl; }
    void Use(string strPersion, string strWork)
    {
        cout << strPersion << "用" << m_strName << "去" << strWork << endl;
    }
};
class ToolBox
{ //=FlyweightFactory
private:
    map<string, Tool *> m_mapTools;

public:
    ToolBox() { cout << "构造ToolBox" << endl; }
    ~ToolBox() { 
        cout << "析构ToolBox" << endl; 
    }
    Tool *GetTool(string strName)
    {
        map<string, Tool *>::iterator it = m_mapTools.find(strName);
        if (it != m_mapTools.end())
        {
            return (Tool *)it->second;
        }
        else
        {
            Tool *pTemp;
            if (strName == "hammer")
                pTemp = new Hammer();
            else if (strName == "screwdrive")
                pTemp = new Screwdrive();
            else if (strName == "saw")
                pTemp = new Saw();
            else
            {
                cout << "工具箱中没有:" << strName << endl;
            }
            if (NULL != pTemp)
            {
                m_mapTools.insert(pair<string, Tool *>(strName, pTemp));
            }
            return pTemp;
        }
    }
};
int main()
{
    ToolBox objToolBox;
    Tool *pToolA = objToolBox.GetTool("hammer");
    pToolA->Use("张三", "修桌子");
    Tool *pToolB = objToolBox.GetTool("screwdrive");
    pToolB->Use("李四", "修自行车");
    Tool *pToolC = objToolBox.GetTool("saw");
    pToolC->Use("王五", "锯树子");
    delete pToolA;
    delete pToolB;
    delete pToolC;
    return 0;
}