#include <iostream>
using namespace std;

int pow_by_squaring(int number, int potency)
{
    if(potency == 1){
        return number;
    }
    while(potency > 1){
        if(potency % 2 == 0){
            return pow_by_squaring((number * number),(potency/2));
        }
        else{
            return number * pow_by_squaring((number * number), ((potency-1)/2));
        }
    }
}


int main()
{
    int n = 5;
    int pow = 5;
    cout << pow_by_squaring(n , pow);
    return 0;
}
