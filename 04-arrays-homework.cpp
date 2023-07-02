/*
04 - Arrays and text
Homework
by Grzegorz Potocki
*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <algorithm>

int main ()
{
    char choice;
    std::cout<<"Choose an option:\n1 - Exercise 1\n2 - Exercise 2\n3 - Exercise 3\n"<<std::endl;
    std::cout<<"4 - Homework 1\n5 - Homework 2\n6 - Homework 3\n7 - Homework 4\n8 - Homework 5\nx - exit"<<std::endl;
    std::cin>>choice;
    int choice_int=static_cast<int>(choice);
    while (choice=='x' || choice=='X'){
        return 0;
    }
    switch(choice_int) {
        case 49:{           //assignment 1
            char text[100];
            std::cout<<"Enter text: "<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(text, 100);
            for (int i=0; i<100; ++i){
                text[i]=toupper(text[i]);
            }
            std::cout<<text<<std::endl;
            break;
        }
        case 50:{           //assignment 2
            int n, maximal=0, minimal=10000000000000;
            float mean=0.0;
            std::cout<<"Enter the value which is the length of the array: ";
            std::cin>>n;
            int arr[n];
            for (int i=0; i<n; i++){
                std::cout<<"Enter the value at index "<<i<<" :";
                std::cin>>arr[i];
            }
            for(int i=0; i<n; i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<std::endl;
            for(int i=0; i<n; i++){
                if(arr[i]>maximal){
                    maximal=arr[i];
                }
            }
            std::cout<<"Maximal value: "<<maximal<<std::endl;
            for(int i=0; i<n; i++){
                if(arr[i]<minimal){
                    minimal=arr[i];
                }
            }
            std::cout<<"Minimal value: "<<minimal<<std::endl;
            for(int i=0; i<n; i++){
                mean+=arr[i];
            }
            std::cout<<mean/static_cast<float>(n)<<std::endl;
            break;
        }
        case 51:{           //assignment 3
            char text[100];
            std::cout<<"Enter text: "<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(text, 100);
            int counter;
            int visited[strlen(text)];
            for(int i=0; i<strlen(text)-1; i++){              //bubble sort
                for(int j=1; j<strlen(text)-i; j++){
                    if(text[j-1]>text[j]){
                        std::swap(text[j-1], text[j]);
                    }
                }
            }
            for(int i=0; i<strlen(text); i++){
                std::cout<<text[i]<<" ";
            }
            std::cout<<std::endl;
            std::cout<<"statistics: "<<std::endl;
            for(int i=0; i<strlen(text); i++){
                if(visited[i]==1){
                    continue;
                }
                else {
                    counter=0;
                    for(int j=0; j<strlen(text); j++){
                        if(text[i]==text[j]){
                            visited[j]=1;
                            counter++;
                        }
                    }
                }
                std::cout<<text[i]<<": "<<counter<<std::endl;
            }
            break;
        }
        case 52:{           //homework 1
            srand(time(NULL));
            float arr_rand[20];
            for(int i=0; i<20; i++){
                arr_rand[i]=static_cast<float>(static_cast<int>((((float)rand())/((float)RAND_MAX)*(100-10)+10)*10.))/10;
            }
            int j;
            float h;
            for (int i=1; i<20; i++){   //insertion sort
                h=arr_rand[i];
                j=i-1;
                while(j>=0 && arr_rand[j]>h){
                    arr_rand[j+1]=arr_rand[j];
                    j--;
                }
                arr_rand[j+1]=h;
            }
            for(int i=0; i<20; i++){
                std::cout<<arr_rand[i]<<std::endl;
            }
            break;
        }
        case 53:{           //homework 2
            srand(time(NULL));
            int arr[20], x, l, r, mid;
            for(int i=0; i<20; i++){
                arr[i]=rand()%100+1;
            }
            for(int i=0; i<20; i++){
                for(int j=1; j<20-i; j++){
                    if(arr[j-1]>arr[j]){
                        std::swap(arr[j-1], arr[j]);
                    }
                }
            }
            std::cout<<"Values of array: "<<std::endl;
            for(int i=0; i<20; i++){
                std::cout<<arr[i]<<std::endl;
            }
            std::cout<<"Enter the value: ";
            std::cin>>x;
            l=0, r=19;
            while(l<=r){
                mid=(l+r)/2;
                if(arr[mid]==x){
                    std::cout<<"The index in array of provided number:"<<mid;
                    break;
                }
                if(arr[mid]>x){
                    r=mid-1;
                }
                if(arr[mid]<x){
                    l=mid+1;
                }
                if(l>r){
                    int avg=(arr[l]+arr[r])/2;
                    if(avg>x){
                        std::cout<<"The index in array of nearest provided number:"<<r;
                    }
                    else{
                        std::cout<<"The index in array of nearest provided number:"<<l;
                    }
                }
            }
            break;
        }
        case 54:{           //homework 3
            std::string sentence;
            int counter=0;
            std::cout<<"Enter the sentence: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin, sentence);
            for(int i=0; sentence[i]!='\0'; i++){
                if(sentence[i]==' ' && i!=sentence.length()-1){
                    counter++;
                }
            }
            counter ++;
            std::string words[counter];
            std::stringstream ss(sentence);
            for(int i=0; i<counter; i++){
                ss>>words[i];
            }
            for(int i=counter-1; i>=0; i--){
                std::cout<<words[i]<<" ";
            }
            break;
        }
        case 55:{           //homework 4
            char text[100], word;
            char *pch;
            std::cout<<"Enter text: "<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(text, 100);
            std::cout<<"Enter word to find: "<<std::endl;
            std::cin>>word;
            pch=strchr(text, word);
            while (pch!=NULL){
                std::cout<<pch-text<<" ";
                pch=strchr(pch+1, word);
            }
            break;
        }
        case 56:{           //homework 5
            char text[100], word1[10], word2[10];
            char *pch;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(text, 100);
            std::cin>>word1;
            std::cin>>word2;
            pch = strstr(text, word1);
            if (pch != NULL){
                strncpy (pch, word2, strlen(word2));
            }
            std::cout<<text<<std::endl;
            break;
        }
        default:{
            std::cout<<"Value of expression is out of scope";
            break;
        }
    }
    return 0;
}
