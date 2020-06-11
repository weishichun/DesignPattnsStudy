#include <iostream>
#include <string>
using namespace std;
class Context{
private:
    string input;
    string output;
public:
    void SetInput(string i){
        input = i;
    }
    string GetInput(){
        return input;
    }
    void SetOutput(string o){
        output = o;
    }
    string GetOutput(){
        return output;
    }
};
class AbstractExpression{
public:
    virtual void Interpret(Context* context) = 0;
    virtual ~AbstractExpression(){}
};
class TerminalExpression : public  AbstractExpression{
private:
    AbstractExpression* expression;
public:
    void Interpret(Context* context){
        cout << "TerminalExpression: " << context->GetInput() << ", " 
        << context->GetOutput() << endl;
    }
};
class NonterminalExpression : public  AbstractExpression{
private:
    AbstractExpression* expression;
public:
    NonterminalExpression(AbstractExpression * e){
        expression = e;
    }
    void Interpret(Context* context){
        cout << "NonterminalExpression: " << context->GetInput() << ", " 
        << context->GetOutput() << endl;
        expression->Interpret(context);
    }
};
int main(){
    Context *c = new Context();
    c->SetInput("Hello");
    c->SetOutput("world");
    AbstractExpression* exp1 = new TerminalExpression();
    AbstractExpression* exp2 = new NonterminalExpression(exp1);
    exp1->Interpret(c);
    exp2->Interpret(c);
    return 0;
}
