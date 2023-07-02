/*
06 - Recursion, pointers and references
Homework
by Grzegorz Potocki
*/

#include <iostream>
#include <limits>
#include <string.h>

void small_to_capital(char a[]){
    for(int i=0; i<strlen(a); i++){     //as long as i from 0 is smaller than the length of an array a
        a[i]=toupper(a[i]);             //value of array a under index i is changed to capital letter
    }
}
void bubble_sort(char a[], int b){          //bubble sort
    for(int i=0; i<b-1; i++){               //as long as i from 0 is smaller than length of array minus 1
        for(int j=1;j<b-i; j++){            //as long as j from 1 is smaller than length of array minus actual value of i
            if(a[j-1]>a[j]){                //check if value at j-1(ex. value at index 1 is greater than value at index 2) is greater than value at j
                std::swap(a[j-1], a[j]);    //swap values
            }
        }
    }
    for(int i=0; i<b; i++){
        std::cout<<a[i]<<std::endl;
    }
}
void statistics(char a[]){
    int counter;
    int visited[strlen(a)];                //definition int array "visited" as long as length of array a
    for(int i=0; i<strlen(a); i++){        //as long as i from 0 is smaller than length of array a
        if(visited[i]==1){                 //check if value of array "visited" if value i is 1
            continue;                      //if it is equal to 1 then continue
        }
        else {
            counter=0;                          //if it is not equal to one then set counter to 0
            for(int j=0; j<strlen(a); j++){     //as long as j from 0 is smaller than length of array a
                if(a[i]==a[j]){                 //check if value of index at i is the same as value of index j
                    visited[j]=1;               //if it is then set value of j in array "visited" to 1
                    counter++;                  //and increment counter because we are counting every visited character
                }
            }
        }
        std::cout<<a[i]<<": "<<counter<<" ";
    }
}
void h_mean(int a[], int b){
    float den=0.0;                              //set float denominator on 0.0
    for(int i=0; i<b; i++){                     //as long as i form 0 is smaller than b - the sum
        den+=1/static_cast<float>(a[i]);        //calculating the harmonic mean
    }
    float mean=b/den;
    std::cout<<"harmonic mean: "<<mean<<std::endl;
}
void cipher(char a[]){
    for(int i=0; i<strlen(a); i++){             //as long as i from zero is smaller than length of the array
        if(a[i]>='A' && a[i]<='Z'){             //if character is between A and Z - is big letter
            a[i]=('Z'-(a[i]-'A'));              //calculating the ascii value of ciphered letter -
        }                                       //subtracting the ascii value of 'A' from character under index i and then subtracting it from 'Z'
        else if(a[i]>='a' && a[i]<='z'){        // the same algorithm as above but now it is for small letters
            a[i]=('z'-(a[i]-'a'));
        }
    }
    std::cout<<a;
}
void decipher(char a[]){
    for(int i=0; i<strlen(a); i++){             //the same algorithm as above but this time it is inverse to simply decipher message
        if(a[i]>='A' && a[i]<='Z'){
            a[i]=('A'-(a[i]-'Z'));
        }
        else if(a[i]>='a' && a[i]<='z'){
            a[i]=('a'-(a[i]-'z'));
        }
    }
    std::cout<<a;
}

int main()
{
    bool end_h=false;
    do{
        int user_choice;
        std::cout<<"Choose an option:\n1 - Exercise 1\n2 - Exercise 2\n3 - Exercise 3\n4 - Homework 1\n5 - Homework 2\nEverything else - Exit"<<std::endl;
        std::cin>>user_choice;
        switch(user_choice){
            case 1:{
                char arr[100];
                std::cout<<"Enter the letters to the array: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(arr, 100);
                small_to_capital(arr);
                std::cout<<arr<<std::endl;
                break;
            }
            case 2:{
                int size_arr;
                std::cout<<"Enter the size of an array: ";
                std::cin>>size_arr;
                char arr[size_arr];
                std::cout<<"Enter the values to an array: ";
                std::cin>>arr;
                bubble_sort(arr, size_arr);
                break;
            }
            case 3:{
                char text[100];
                std::cout<<"Enter text: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(text, 100);
                statistics(text);
                std::cout<<std::endl;
                break;
            }
            case 4:{
                int size_arr;
                std::cout<<"Enter the size of an array: "<<std::endl;
                std::cin>>size_arr;
                int arr[size_arr];
                std::cout<<"Enter the values into an array: "<<std::endl;
                for(int i=0; i<size_arr; i++){
                    std::cin>>arr[i];
                }
                h_mean(arr, size_arr);
                break;
            }
            case 5:{
                char text[100];
                std::cout<<"Enter text: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(text, 100);
                cipher(text);
                std::cout<<std::endl;
                decipher(text);
                std::cout<<std::endl;
                break;
            }
            default:{
                std::cout<<"Exiting homeworks"<<std::endl;
                end_h=true;
            }

        }

    }
    while(!end_h);
}
