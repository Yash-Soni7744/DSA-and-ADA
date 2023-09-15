#include <iostream>

int main() {
    
    int rows1,columns1,rows2,columns2,i,j;
    std::cout<<"enter the no. of rows for A: ";
    std::cin>>rows1;
    std::cout<<"enter the no. of columns for A: ";
    std::cin>>columns1;
    
    while(true){
        std::cout<<"enter the no. of rows for B: ";
        std::cin>>rows2;
        if(columns1!=rows2){
            printf("rows of second matrix must be equal to columns of first matrix \n");
        }
        else{
            break;
        }
    }
    
    std::cout<<"enter the no. of columns for B: ";
    std::cin>>columns2;
    
    int A[rows1][columns1];
    printf("enter values for A matrix:\n");
    for ( i=1;i<=rows1;i++){
        for(j=1;j<=columns1;j++){
            std::cout<<"value for "<<i<<"x"<<j<<": ";
            std::cin>>A[i][j];
        }
    }
    
    int B[rows2][columns2];
    printf("enter values for B matrix:\n");
    for (i=1;i<=rows2;i++){
        for(j=1;j<=columns2;j++){
            std::cout<<"value for "<<i<<"x"<<j<<": ";
            std::cin>>B[i][j];
        }
    }
    
    int C[rows1][columns2];
    for(i=1; i<=rows1; i++){
        for (j=1; j<=columns2; j++){
            C[i][j] = 0;
            for(int k=1; k<=rows2; k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    std::cout<<"Multiplied Matrix C: ";
    for (i=1; i<=rows1; i++){
        std::cout<<"[";
        for (j=1; j<=columns2; j++){
            std::cout<<"["<<C[i][j]<<"]";
        }
        std::cout<<"]\n";
    }
    return 0;
}
