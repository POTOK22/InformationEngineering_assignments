#include <iostream>
#include <stdio.h>

int main()
{
    //final assignments
    char choice;
    std::cout<<"Choose an option:\n1 - Exercise 1\n2 - Exercise 2\n3 - Exercise 3\nx - exit"<<std::endl;
    std::cin>>choice;
    int choice_int=static_cast<int>(choice);
    while (choice=='x' || choice=='X'){
        return 0;
    }
    switch(choice_int) {
        case 49:
            int choice_1;
            float iterations;
            std::cout<<"Choose an approximation method:\n1 - Leibniz\n2 - Wallis"<<std::endl;
            std::cin>>choice_1;
            std::cout<<"Enter the number of iterations: ";
            std::cin>>iterations;
            switch(choice_1){
                case 1: {
                    float pi=1;
                    for(int i=0; i<iterations; i++) {
                        float den=i*2+3;
                        if(i%2 == 0){
                            pi-=(1/den);
                        } else {
                            pi+=(1/den);
                        }
                    }
                    std::cout<<pi*4;
                    return 0;
                }
                case 2: {
                    float pi=1;
                    for(int i=1; i<iterations; i++){
                        float num=2*i;
                        float den1=2*i-1;
                        float den2=2*i+1;
                        pi*=((num/den1)*(num/den2));
                    }
                    std::cout<<pi*2;
                    return 0;
                }
            }
    }
    switch(choice_int){
        case 50:{
            int n=0;
            while(n<=255){
                printf("DEC: %d CHAR: %c\n",n,n);
                n++;
                if (n%40==0){
                    char stop;
                    std::cin>>stop;
                    if(stop == '%'){
                        continue;
                    } else {
                        break;
                    }
                }
            }
            break;
        }
        case 51:{
            int n;
            int result=1;
            std::cout<<"Enter the number of factorial(must be a positive integer and not bigger than 13): ";
            std::cin>>n;
            if (n==0 || n==1){
                result=1;
                std::cout<<n<<"!= "<<result;
            } else if (n<0) {
                std::cout<<"The value is not a positive integer!";
            } else {
                int i=1;
                while (i<=n){
                    result *= i;
                    i++;
                    if(i>13){
                        std::cout<<"The value is too big!";
                        return 0;
                    }
                }
                std::cout<<n<<"!= "<<result;
            }
            break;
        }
        default:
            std::cout<<"Value of expression is out of scope";
            break;
    }
    return 0;
}
