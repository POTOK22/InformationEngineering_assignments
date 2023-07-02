/*
05 - Functions
Homework
by Grzegorz Potocki
*/

#include <iostream>
#include <cmath>
#include <limits>
#include <string.h>

using namespace std;

int mini_of_2(int a, int b){
    if(a<b){                        //if a is smaller than b then return a
        return a;
    }
    else{                           //else return b - simple
        return b;
    }
}
int mini_of_4(int a, int b, int c, int d){
    int result1 = mini_of_2(a, b);              //declaration variable int "result1" which is the same function as function above
    int result2 = mini_of_2(c, d);              //the same function as above
    if(result1<result2){                        //if result1 is smaller than result2 then return result1
        return result1;
    }
    else{                                       //else return result2
        return result2;
    }
}
float g_mean(int a, int b, int c){
    return cbrt(a*b*c);                         //geometric mean of three elements which is the result of multiplying three elements and then taking cube root of result
}
void round1(float &a){
    int result=static_cast<int>(a*10)%10;       //forcing an float variable which is a to be an integer and then multiplying it 10 times and then getting result modulo 10 to get as the result the rest of dividing which is equal to decimal place value
    if(result>=5){                              //check if decimal place value is greater than 5
        a=ceil(a);                              //then round number up
    }
    else{                                       //in every other case(when decimal value is smaller than 5)
        a=floor(a);                             //then round number down
    }
}
bool is_prime(int n){
    if(n==0 || n==1){                           //check if value of n is equal to 0 or 1
        return false;                           //if it is then n is not a prime number because 0 and 1 are not prime
    }
    if(n==2){                                   //check if value of n is equal to 2
        return true;                            //if it is then n is a prime because 2 is one and only even number which is prime
    }
    else{                                       //in every other case(when n is not 0, 1 or 2)
        for(int i=2; i<100; i++){               //for loop as long as i form 2 is smaller than 100
            if(n%i==0){                         //check if value of n modulo i is equal to 0(loop is checking that it is possible to divide n by every i up to n)
                return false;                   //if it is then the value of n is not prime
            }
            else{
                return true;                    //if it is not then the value of n is prime
            }
        }
    }
}
void sphere(float &r){
    float area=4*M_PI*pow(r, 2);                //calculating the value of area of sphere from formula
    float volume=(4*M_PI*pow(r, 3))/3;          //calculating the value of volume of sphere from formula
    std::cout<<"area: "<<area<<std::endl;
    std::cout<<"volume: "<<volume<<std::endl;
}
float h_mean(int a, int b, int c){
    float result=3/(pow(a, -1)+pow(b, -1)+pow(c, -1));  //calculating the harmonic mean of 3 elements from formula
    return result;
}
int GCD_of_2(int a, int b){                     //euclidean algorithm
    do{
        int temp= a%b;                          //at least once create variable int temp(temporary) which is equal to a modulo b
        a=b;                                    //then just change a with b
        b=temp;                                 //and change b with temp
    }
    while(b!=0);                                //and do it as long as b is not equal zero
    if (b==0){                                  //but if b is equal to zero
        return a;                               //then return the result which is the greatest common divisor
    }
}
int GCD_of_3(int a, int b, int d){
    int result=GCD_of_2(a, b);                  //variable int result is equal to the greatest common divisor of a and b
    do{
        int temp=d%result;                      //at least once create variable int temp which is d mod result
        d=result;                               //change d with result
        result=temp;                            //change result with temp
    }
    while(result!=0);                           //as long as result is not equal to zero
    if (result==0){                             //check if result is equal to zero
        return d;                               //if it is then return d which is the greatest common divisor of a, b and d
    }
}
void cipher(char a[]){
    for(int i=0; i<strlen(a); i++){
        if(a[i]>='A' && a[i]<='Z'){
            a[i]=('Z'-(a[i]-'A'));
        }
        else if(a[i]>='a' && a[i]<='z'){
            a[i]=('z'-(a[i]-'a'));
        }
    }
}
void decipher(char a[]){
    for(int i=0; i<strlen(a); i++){
        if(a[i]>='A' && a[i]<='Z'){
            a[i]=('A'-(a[i]-'Z'));
        }
        else if(a[i]>='a' && a[i]<='z'){
            a[i]=('a'-(a[i]-'z'));
        }
    }
}
int main()
{
    char choice;
    std::cout<<"Choose an option:\n1 - Exercise 1\n2 - Exercise 2\n3 - Exercise 3\n4 - Exercise 4\n5 - Exercise 5\n6 - Exercise 6\n"<<std::endl;
    std::cout<<"7 - Homework 1\n8 - Homework 2\n9 - Homework 3\nA - Homework 4\nx - exit"<<std::endl;
    std::cin>>choice;
    int choice_int=static_cast<int>(choice);
    while (choice=='x' || choice=='X'){
        return 0;
    }
    switch(choice_int) {
        case 49:{   //ex1
            int number1, number2;
            cout<<"Enter number 1: ";
            cin>>number1;
            cout<<"Enter number 2: ";
            cin>>number2;
            int result=mini_of_2(number1, number2);
            cout<<result;
            break;
        }
        case 50:{   //ex2
            int number1, number2, number3, number4;
            cout<<"Enter number 1: ";
            cin>>number1;
            cout<<"Enter number 2: ";
            cin>>number2;
            cout<<"Enter number 3: ";
            cin>>number3;
            cout<<"Enter number 4: ";
            cin>>number4;
            int result=mini_of_4(number1, number2, number3, number4);
            cout<<result;
            break;
        }
        case 51:{   //ex3
            int number1, number2, number3;
            cout<<"Enter number 1: ";
            cin>>number1;
            cout<<"Enter number 2: ";
            cin>>number2;
            cout<<"Enter number 3: ";
            cin>>number3;
            float result=g_mean(number1, number2, number3);
            cout<<result;
            break;
        }
        case 52:{   //ex4
            float number1;
            cout<<"Enter number to round: ";
            cin>>number1;
            round1(number1);
            cout<<number1;
            break;
        }
        case 53:{   //ex5
            int number1;
            cout<<"Enter number to check is it a prime (smaller than 100): ";
            cin>>number1;
            int result=is_prime(number1);
            cout<<result;
            break;
        }
        case 54:{   //ex6
            float r;
            cout<<"Enter radius: ";
            cin>>r;
            sphere(r);
            break;
        }
        case 55:{   //homework1
            int number1, number2, number3;
            cout<<"Enter number 1: ";
            cin>>number1;
            cout<<"Enter number 2: ";
            cin>>number2;
            cout<<"Enter number 3: ";
            cin>>number3;
            float result=h_mean(number1, number2, number3);
            cout<<result;
            break;
        }
        case 56:{   //homework2
            int number1, number2;
            cout<<"Enter number 1: ";
            cin>>number1;
            cout<<"Enter number 2: ";
            cin>>number2;
            int result=GCD_of_2(number1, number2);
            cout<<result;
            break;
        }
        case 57:{   //homework3
            int number1, number2, number3;
            cout<<"Enter number 1: ";
            cin>>number1;
            cout<<"Enter number 2: ";
            cin>>number2;
            cout<<"Enter number 3: ";
            cin>>number2;
            int result=GCD_of_3(number1, number2, number3);
            cout<<result;
            break;
        }
        case 65:{   //homework4
            char text[100];
            cout<<"Enter message to cipher: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.getline(text, 100);
            cipher(text);
            cout<<text<<endl;
            decipher(text);
            cout<<text<<endl;
            break;
        }
        default:{
            std::cout<<"Value of expression is out of scope";
            break;
        }
    }
    return 0;
}
