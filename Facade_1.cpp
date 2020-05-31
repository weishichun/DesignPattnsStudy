#include<iostream>
using namespace std;
class Shop
{
public:
    void BuyFood(){
        cout << "买菜" << endl;
    }
};
class Cook
{
public:
    void doCook(){
        cout << "做菜" << endl;
    }
};
class Clean{
public:
    void doClean(){
        cout << "晚餐完毕,收拾餐盘,打扫卫生" << endl;
    }
};
class Facade_HaveDinner{
public:
    Shop objShop;
    Cook objCook;
    Clean objClean;
public:
    void doHaveDinner(){
        cout << "下午啦,开始准备晚餐" << endl;
        objShop.BuyFood();
        objCook.doCook();
        objClean.doClean();
    }
};
int main(){
    Facade_HaveDinner objHavedinner;
    objHavedinner.doHaveDinner();
    return 0;
}
