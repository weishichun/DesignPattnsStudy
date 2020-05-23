#include <iostream>
#include <vector>
#include <string>
using namespace std;
//微信公众号和关注微信公众号的众多人, 就是典型的观察者模式.
class IWeiXinUser  //关注该微信公众号的微信用户抽象类, Observer  
{
public:
    virtual void  ConsultArticle(string strTitle) = 0;   //查阅公众号文章
    virtual ~IWeiXinUser() {};
     void SetFansName(string strName){
        m_strName = strName;
    }
    string  m_strName;
};
class IWeiXinPublicAccount    //微信公众号抽象类, Subject
{
public:
    virtual void GainFans(IWeiXinUser *objWeiXin) = 0; //获得一个粉丝
    virtual void LoseFans(IWeiXinUser *objWeiXin) = 0; //失去一个粉丝
    virtual void PublishArticle(string strArticleTitle) = 0; //公众号发布文章, 即通知所有观察者
    virtual ~IWeiXinPublicAccount() {};
public:
    int m_iTotalUser; //粉丝总数
    int m_iPublishTotal; //发布文章总数
};
class Fans : public IWeiXinUser
{
public:
    Fans(IWeiXinPublicAccount *Obj):m_pPubAcnt(Obj){ }
    void ConsultArticle(string strTitle){
        cout << "粉丝: " << m_strName << "查阅了文章: " << strTitle << endl;
    }
   
public:
    IWeiXinPublicAccount *m_pPubAcnt;//粉丝关注的公众号 
};
class YouyouDuShan : public IWeiXinPublicAccount
{
public:
    void GainFans(IWeiXinUser *objWeiXin) ; //获得一个粉丝
    void LoseFans(IWeiXinUser *objWeiXin) ; //失去一个粉丝
    void PublishArticle(string strArticleTitle) ; //公众号发布文章, 即通知所有观察者
public:
    vector<IWeiXinUser *> m_vecFans; //粉丝容器
};
void YouyouDuShan::GainFans(IWeiXinUser *pobjWeiXin){
    m_vecFans.push_back(pobjWeiXin);
    m_iTotalUser++;
    cout << "粉丝: " << pobjWeiXin->m_strName << "关注了悠悠独山" << ", 目前粉丝数: " << m_iTotalUser << endl;
} 
void YouyouDuShan::LoseFans(IWeiXinUser *pobjWeiXin) {
    vector<IWeiXinUser*>::iterator iter = m_vecFans.begin();
    for(;iter != m_vecFans.end(); iter++)
    {
        if (*iter == pobjWeiXin)
        {
            m_vecFans.erase(iter);
            m_iTotalUser--;
            cout << "粉丝: " << pobjWeiXin->m_strName << "取关了悠悠独山" << ", 目前粉丝数: " << m_iTotalUser << endl;
            return;
        }
    }
    if (iter == m_vecFans.end())
    {
        cout << "粉丝: " << pobjWeiXin->m_strName << "并未关注悠悠独山, 无法取关" << endl;
    }
}
void YouyouDuShan::PublishArticle(string strArticleTitle){
    m_iPublishTotal++;
    cout << "悠悠独山发布了文章: " << strArticleTitle << ", 欢迎查阅, 目前共发布了: " << m_iPublishTotal << " 篇文章!" << endl;
    vector<IWeiXinUser*>::iterator iter = m_vecFans.begin();
    for(;iter != m_vecFans.end(); iter++)
    {
        (*iter)->ConsultArticle(strArticleTitle);
    } 
} 

int main()
{
    YouyouDuShan *pYou = new YouyouDuShan();
    IWeiXinUser *pA1 = new Fans(pYou); pA1->SetFansName("张三");
    IWeiXinUser *pA2 = new Fans(pYou); pA2->SetFansName("李四");
    IWeiXinUser *pA3= new Fans(pYou); pA3->SetFansName("王麻子");
    IWeiXinUser *pA4= new Fans(pYou); pA4->SetFansName("小春");
    IWeiXinUser *pA5= new Fans(pYou); pA5->SetFansName("丫头");
    IWeiXinUser *pA6= new Fans(pYou); pA6->SetFansName("小赵");
    IWeiXinUser *pA7= new Fans(pYou); pA7->SetFansName("小钱");
    IWeiXinUser *pA8= new Fans(pYou); pA8->SetFansName("小孙");
    IWeiXinUser *pA9= new Fans(pYou); pA9->SetFansName("小周");
    IWeiXinUser *pA10 = new Fans(pYou);pA10->SetFansName("小吴");
    pYou->GainFans(pA1);
    pYou->GainFans(pA2);
    pYou->PublishArticle("文章1");
    cout << "文章反响不错, 应该会涨粉, 好期待" << endl;
    pYou->GainFans(pA3);
    pYou->GainFans(pA5);
    pYou->PublishArticle("文章2");
    pYou->LoseFans(pA2);
    pYou->LoseFans(pA10); 
    pYou->LoseFans(pA1);
    cout << "文章质量不好吗? 怎么掉粉了, 下次要注重文章质量" << endl;
    pYou->PublishArticle("文章3");
    pYou->GainFans(pA1);
    pYou->GainFans(pA2);
    pYou->GainFans(pA4);
    pYou->GainFans(pA6);
    pYou->GainFans(pA7);
    pYou->GainFans(pA8);
    pYou->GainFans(pA9);
    pYou->GainFans(pA10);
    cout << "看来上一篇文章质量很好, 涨了这么多粉, 再来一篇" << endl;
    pYou->PublishArticle("文章4"); 
    delete pA1;
    delete pA2;
    delete pA3;
    delete pA4;
    delete pA5;
    delete pA6;
    delete pA7;
    delete pA8;
    delete pA9;
    delete pA10;
    delete pYou;
    return 0;
}