#include <iostream>
#include <cmath>

int main()
{
//    //homework
    int mini, maxi;
    std::cout<<"Enter the minimum number of interval: ";
    std::cin>>mini;
    std::cout<<"Enter the maximum number of interval: ";
    std::cin>>maxi;
    if(mini<maxi){
        for (int i=mini; i<maxi; i++){
            if(i==2){
                std::cout<<i<<std::endl;
                continue;
            }
            for (int j=2; j<i; j++){
                if(i%j == 0){
                    break;
                }
                else if(i==j+1){
                    std::cout<<i<<std::endl;
                }
            }
        }
    }else{
        std::cout<<"The minimal number is bigger than maximum number!";
    }
    int a, b;
    std::cout<<"Enter first number: ";
    std::cin>>a;
    std::cout<<"Enter second number: ";
    std::cin>>b;
    for (int i=1; i<2147483647; i++){
        if(i%a==0 && i%b==0){
            std::cout<<i<<std::endl;
        i=0;
            if (i==0){
                break;
            }
        }
    }

    short int n_short;
    short int result_short=1;
    std::cout<<"Enter the number of factorial(must be a positive integer and not bigger than 7): ";
    std::cin>>n_short;
    if (n_short==0 || n_short==1){
        result_short=1;
        std::cout<<n_short<<"!= "<<result_short;
    } else if (n_short<0) {
        std::cout<<"The value is not a positive integer!";
    } else {
        int j_short=1;
        while (j_short<=n_short){
            result_short *= j_short;
            j_short++;
        }
    }
    std::cout<<n_short<<"!= "<<result_short<<std::endl;

    unsigned int n_un;
    unsigned int result_un=1;
    std::cout<<"Enter the number of factorial(must be a positive integer and not bigger than 13): ";
    std::cin>>n_un;
    if (n_un==0 || n_un==1){
        result_un=1;
        std::cout<<n_un<<"!= "<<result_un;
    } else if (n_un<0) {
        std::cout<<"The value is not a positive integer!";
    } else {
        int j_un=1;
        while (j_un<=n_un){
            result_un *= j_un;
            j_un++;
        }
    }
    std::cout<<n_un<<"!= "<<result_un<<std::endl;


    unsigned long n_long;
    unsigned long result_long=1;
    std::cout<<"Enter the number of factorial(must be a positive integer and not bigger than 13): ";
    std::cin>>n_long;
    if (n_long==0 || n_long==1){
        result_long=1;
        std::cout<<n_long<<"!= "<<result_long;
    } else if (n_long<0) {
        std::cout<<"The value is not a positive integer!";
    } else {
        int j_long=1;
        while (j_long<=n_long){
            result_long *= j_long;
            j_long++;
        }
    }
    std::cout<<n_long<<"!= "<<result_long<<std::endl;

    unsigned long long n_long2;
    unsigned long long result_long2=1;
    std::cout<<"Enter the number of factorial(must be a positive integer and not bigger than 20): ";
    std::cin>>n_long2;
    if (n_long2==0 || n_long2==1){
        result_long2=1;
        std::cout<<n_long2<<"!= "<<result_long2;
    } else if (n_long2<0) {
        std::cout<<"The value is not a positive integer!";
    } else {
        int j_long2=1;
        while (j_long2<=n_long2){
            result_long2 *= j_long2;
            j_long2++;
        }
    }
    std::cout<<n_long2<<"!= "<<result_long2<<std::endl;


    double e, fctr=1, z;
    int i;
    const double euler = 2.71828182845904523536;
    std::cout<<"Enter z value: ";
    std::cin>>z;
    std::cout<<"Enter the number of iterations: ";
    std::cin>>i;
    for (int k=1; k<=i; k++){
        if (k==0 && k==1){
            fctr=1;
        }else {
            fctr*=k;
        }
        e+=(pow(z, k))/fctr;
    }
    if(i==2 || i==5 || i==10){
        std::cout<<"error"<<std::endl;
    }else{
    std::cout<<e+1<<std::endl;
    std::cout<<pow(euler, z)<<std::endl;
    }

    return 0;
}
