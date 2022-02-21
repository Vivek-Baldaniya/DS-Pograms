#include <iostream>

using namespace std;

template <class x>
class demo{
    public:
        int top;
        char stack[20];
        x result, exp;
        demo(x expresion){
            top = -1;
            exp = expresion;
            result = "";
        }
        void checkExp();
        void push(char ch);
        char pop();
        int checkPriority(char ch);
        void display(){
            cout<<"\nPostfix String is::"<<result;
        };
};

template <class x>
void demo<x>::checkExp(){
    int flag = 0;
    for(int i=0;i<exp.length();i++){
        char ch = exp[i];
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
            result += exp[i];
        }
        else if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            while(stack[top] != '('){
                result += pop();
                flag = 1;
            }
            pop();
        }
        else{
            while(top != -1 && checkPriority(ch) <= checkPriority(stack[top])){
                result += pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        result += stack[top];
        top--;
    }
     // done by vivek-21CP314
    if(flag == 1){
        cout<<"\nBalanced Expression.";
    }
    else{
        cout<<"Unbalanced expression";
    }
}

template <class x>
void demo<x>::push(char ch){
    if(top == 20){
        cout<<"Stack overflow";
    }
    else{
        top++;
        stack[top] = ch;
        // cout<<"\nPush::"<<ch;
    }
}

template <class x>
char demo<x>::pop(){
    if(top == -1){
        cout<<"Empty Stack";
        return 0;
    }else{
        char ch = stack[top];
        // cout<<"\nPop::"<<ch;
        top--;
        return ch;
    }
}

template <class x>
int demo<x>::checkPriority(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    demo<string> ob1("a+(b*c/d)+e*f");
    ob1.checkExp();
    ob1.display();
}