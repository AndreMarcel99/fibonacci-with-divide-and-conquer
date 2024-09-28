#include <iostream>
using namespace std;

int* multiply_matrix(int matrix_A[4], int matrix_B[4])
{
    int a,b,c,d;
    static int result[4];
    a = (matrix_A[0] * matrix_B[0]) + (matrix_A[1] * matrix_B[2]);
    b = (matrix_A[0] * matrix_B[1]) + (matrix_A[1] * matrix_B[3]);
    c = (matrix_A[2] * matrix_B[0]) + (matrix_A[3] * matrix_B[2]);
    d = (matrix_A[2] * matrix_B[1]) + (matrix_A[3] * matrix_B[3]);
    result[0] = a;
    result[1] = b;
    result[2] = c;
    result[3] = d;
    return result;
}


int* pow_by_squaring(int matrix[4], int potency)
{
    if(potency <= 1){
        return matrix;
    }else if(potency % 2 == 0){
        int* mat_aux = pow_by_squaring(matrix, potency/2);
        return multiply_matrix(mat_aux, mat_aux);
    }else{
        int* mat_aux = pow_by_squaring(matrix, (potency-1)/2);
        return multiply_matrix(multiply_matrix(mat_aux, mat_aux), matrix);
    }
}


int fibonacci_by_squaring(int number)
{
    int matrix_base[4] = {0,1,1,1};
    if(number == 0)
        return 0;
    int* response = pow_by_squaring(matrix_base, number-1);
    return response[3];
}

int main()
{
    int n = 15;
    cout << n << ":" << fibonacci_by_squaring(n) << endl;
    return 0;
}

/*    for(int i=0; i <= n;i++){
        cout << i << ":" << fibonacci_by_squaring(i) << endl ;
    }*/