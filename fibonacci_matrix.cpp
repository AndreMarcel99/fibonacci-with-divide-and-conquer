#include <iostream>

using namespace std;

long fibonacci_matrix(int number)
{
    if(number <= 1){
        return number;
    }
    long matrix_base[2][2] = {{0,1},{1,1}};
    long fibonacci_matrix[2][2] = {{0,1},{1,1}};
    for(int i = 1; i < number - 1; i++){
        long a_P_e = fibonacci_matrix[0][0] * matrix_base[0][0];
        long b_P_g = fibonacci_matrix[0][1] * matrix_base[1][0];
        long a_P_f = fibonacci_matrix[0][0] * matrix_base[0][1];
        long b_P_h = fibonacci_matrix[0][1] * matrix_base[1][1];
        fibonacci_matrix[0][0] = a_P_e + b_P_g;
        fibonacci_matrix[0][1] = a_P_f + b_P_h;
        long c_P_e = fibonacci_matrix[1][0] * matrix_base[0][0];
        long d_P_g = fibonacci_matrix[1][1] * matrix_base[1][0];
        long c_P_f = fibonacci_matrix[1][0] * matrix_base[0][1];
        long d_P_h = fibonacci_matrix[1][1] * matrix_base[1][1];
        fibonacci_matrix[1][0] = c_P_e + d_P_g;
        fibonacci_matrix[1][1] = c_P_f + d_P_h;
    }
    return fibonacci_matrix[1][1];
}


int main()
{
    int n = 50;
    for(int i=0; i <= n;i++){
        cout << i << ":" << fibonacci_matrix(i) << endl ;
    }
    return 0;
}
