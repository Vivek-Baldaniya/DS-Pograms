#include <iostream>

using namespace std;

class fibonacci{
    public:
        int n, a, b;
        fibonacci(int n){
            this->n = n;
            a = 0;
            b = 1;
            cout<<a<<" ";
            cout<<b<<" ";
            n -= 2;
        }
        void findFibonacci(int n, int a, int b){
            if(n>0){
                cout<<a+b<<" ";
                findFibonacci((n-1), b, a+b);
            }
        } 
        // done by vivek-21CP314
        static void findFib(int n, int a, int b){
            if(n>0){
                cout<<a+b<<" ";
                findFib((n-1), b, a+b);
            }
        }
};

int main(){
    fibonacci ob1(10);    
    ob1.findFibonacci(10,0,1);
    cout<<endl;
    //call static method
    fibonacci::findFib(8, 0, 1);
}