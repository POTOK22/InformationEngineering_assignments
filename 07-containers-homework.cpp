#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <time.h>
#include <numeric>
#include <algorithm>

using namespace std;

void at_end_vector(){
    cout<<"insert 100 000 elements at the end of vector:";
    auto start = std::chrono::steady_clock::now();
    for(int i=0; i<100000; i++){
        vector<int> v1;
        v1.emplace_back(i);
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
}
void at_end_list(){
    cout<<"insert 100 000 elements at the end of list:";
    auto start = std::chrono::steady_clock::now();
    for(int i=0; i<100000; i++){
        list<int> l1;
        l1.emplace_back(i);
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
}
void at_beg_vector(){
    cout<<"insert 100 000 elements at the beggining of vector:";
    auto start = std::chrono::steady_clock::now();
    for(int i=0; i<100000; i++){
        vector<int> v2;
        v2.insert(v2.begin(),i);
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
}
void at_beg_list(){
    cout<<"insert 100 000 elements at the beggining of list:";
    auto start = std::chrono::steady_clock::now();
    for(int i=0; i<100000; i++){
        list<int> l2;
        l2.emplace_front(i);
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
}
void avg_vector(const vector<float> &v){
    float sum=accumulate(v.begin(), v.end(), 0.0);
    float avg=sum/v.size();
    cout<<"Result: "<<avg<<endl;
}
bool divisibleBy5(int i){
    if(i%5==0){
        return true;
    }
    else{
        return false;
    }
}
void devide_by_5(vector<int> &v){
    int result=count_if(v.begin(), v.end(), divisibleBy5);
    cout<<"Result: "<<result<<endl;
}
bool isPrime(int a){
    bool flag=true;
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}
void bubble_sort(vector<int> &a, int b){
    for(int i=0; i<b-1; i++){
        for(int j=1;j<b-i; j++){
            if(a[j-1]>a[j]){
                swap(a[j-1], a[j]);
            }
        }
    }
    for(int i=0; i<b; i++){
        cout<<a[i]<<endl;
    }
}

int main()
{
    bool end_loop=false;
        do{
            int user_choice;
            cout<<"Choose an option:\n1 - Assignment 1\n2 - Assignment 2\n3 - Assignment 3\n4 - Homework 1\n"
                  "5 - Homework 2\nEverything else - Exit"<<endl;
            cin>>user_choice;
            switch(user_choice){
                case 1:{
                    at_end_vector();
                    at_end_list();
                    at_beg_vector();
                    at_beg_list();
                    break;
                }
                case 2:{
                    srand(time(nullptr));
                    vector<float>v1;
                    for(int i=0; i<10; i++){
                        v1.emplace_back((static_cast<float>(rand())/static_cast<float>(RAND_MAX))*10-5);
                    }
                    for(auto value: v1){
                        cout<<value<<endl;
                    }
                    avg_vector(v1);
                    break;
                }
                case 3:{
                    srand(time(nullptr));
                    vector<int>v2;
                    for(int i=0; i<10; i++){
                        v2.emplace_back(rand()%100+0);
                    }
                    for(auto value: v2){
                        cout<<value<<endl;
                    }
                    devide_by_5(v2);
                    break;
                }
                case 4:{
                    vector<int> v3{1,2,3,4,5,6,7,8,9,10};
                    v3.erase(v3.begin());
                    v3.erase(v3.begin());
                    v3.erase(v3.begin());
                    v3.erase(v3.begin()+1);
                    v3.erase(v3.begin()+2);
                    for(auto value: v3){
                        cout<<value<<endl;
                    }
                    break;
                }
                case 5:{
                    int userChoice;
                    cout<<"Choose an option:\n1-one hundred elements\n2-one thousand elements\n"
                          "3-ten thousand elements\n4-one hundred thousand elements\nEverything else - Exit"<<endl;
                    cin>>userChoice;
                    switch(userChoice){
                        case 1:{
                            srand(time(nullptr));
                            vector<int>vHundred;
                            for(int i=0; i<100; i++){
                                vHundred.emplace_back(rand()%100+0);
                            }
                            cout<<"sorting 100 elements:";
                            auto start = std::chrono::steady_clock::now();
                                bubble_sort(vHundred, vHundred.size());
                            auto end = std::chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
                            break;
                        }
                        case 2:{
                            srand(time(nullptr));
                            vector<int>vThousand;
                            for(int i=0; i<1000; i++){
                                vThousand.emplace_back(rand()%100+0);
                            }
                            cout<<"sorting 1000 elements:";
                            auto start = std::chrono::steady_clock::now();
                                bubble_sort(vThousand, vThousand.size());
                            auto end = std::chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
                            break;
                        }
                        case 3:{
                            srand(time(nullptr));
                            vector<int>vTenThousand;
                            for(int i=0; i<10000; i++){
                                vTenThousand.emplace_back(rand()%100+0);
                            }
                            cout<<"sorting 10000 elements:";
                            auto start = std::chrono::steady_clock::now();
                                bubble_sort(vTenThousand, vTenThousand.size());
                            auto end = std::chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
                            break;
                        }
                        case 4:{
                            srand(time(nullptr));
                            vector<int>vHundredThousand;
                            for(int i=0; i<100000; i++){
                                vHundredThousand.emplace_back(rand()%100+0);
                            }
                            cout<<"sorting 100000 elements:";
                            auto start = std::chrono::steady_clock::now();
                                bubble_sort(vHundredThousand, vHundredThousand.size());
                            auto end = std::chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << endl;
                            break;
                        }
                    }
                    break;
                }
                default:{
                    cout<<"Exiting"<<endl;
                    end_loop=true;
                }
            }
        }while(end_loop==false);
    return 0;
}
