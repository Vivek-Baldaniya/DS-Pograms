#include <iostream>

using namespace std;

class factorial{
    public:
        int n, fact;
        factorial(int n){
            this->n = n;
        }
        
        int findFact(int n){
            if(n>1){
                return(n * findFact(n-1));
            }
            return 1;
        }
        // done by vivek-21CP314
        static int findFactorial(int n){
            if(n>1){
                return(n * findFactorial(n-1));
            }
            return 1;
        }
};


int main(){
    int fact;
    factorial ob1(5);
    fact = ob1.findFact(5);
    cout<<"\nFactorial Of No. is::"<<fact;
    //call static function
    fact = factorial::findFactorial(3);
    cout<<"\nFactorial Of No. is::"<<fact;
    return 0;
}