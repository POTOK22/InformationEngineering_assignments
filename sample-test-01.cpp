#include <iostream>
#include <limits>
#include <string.h>
#include <cmath>
#include <ctime>
#include <cstdlib>

void change_to_undersores(char a[])
{
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i]>='A' && a[i]<='Z')
        {
            a[i]='_';
        }
        if(a[i]>='a' && a[i]<='z')
        {
            a[i]='_';
        }
        if(a[i]>='0' && a[i]<='9')
        {
            a[i]='_';
        }
    }
}
double& calculate_trig_from_series(float x, int n, double sin, double cos);

double polynomial(double arr[], int n, double x)
{
    double result=0;
    int m=n;
    for(int i=0; i<m-1; i++)
    {
        result+=arr[i]*pow(x, n-1);
        n-=1;
    }
    return result+arr[m-1];
}
float mean(int arr[], int n)
{
    float result=0.0;
    for(int i=0; i<n; i++)
    {
        result+=arr[i];
    }
    return result/n;
}
int main()
{
    bool end_loop=false;
    do{
        int user_choice;
        std::cout<<"Choose an option:\n1 - Task 1\n2 - Task 2\n3 - Task 3\n4 - Task 4\nEverything else - Exit"<<std::endl;
        std::cin>>user_choice;
        switch(user_choice){
            case 1:{
                char text[100];
                std::cout<<"enter the message: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(text, 100);
                change_to_undersores(text);
                std::cout<<text<<std::endl;
                break;
            }
            case 2:{
                double sin_val=0.0, cos_val=0.0;
                calculate_trig_from_series(0.52, 9, sin_val, cos_val);
                break;
            }
            case 3:{
                double coefs[4]={-3, 2, -3, 5};
                int n=4;
                double x=2;
                double result=polynomial(coefs, n, x);
                std::cout<<result<<std::endl;
                break;
            }
            case 4:{
                srand(time(NULL));
                int arr[100];
                for (int i=0; i<100; i++)
                {
                    arr[i]=(int)rand()% 100+50;
                }
                for (int i=0; i<100; i++)
                {
                    std::cout<<arr[i]<<std::endl;
                }
                double mean_val=mean(arr, 100);
                std::cout<<"Mean: "<<mean_val<<std::endl;
                break;
            }
            default:{
                std::cout<<"Exiting test"<<std::endl;
                end_loop=true;
            }
        }
    }while(end_loop==false);
    return 0;
}
double& calculate_trig_from_series(float x, int n, double sin, double cos)
{
    double cos_fact=1;
    for(double i=1; i<=n*2; i++)
    {
        cos_fact*=i;
    }
    double sin_fact=1;
    for(double i=1; i<=2*n+1; i++)
    {
        sin_fact*=i;
    }
    sin=pow(-1,n)*pow(x, 2*n+1)/sin_fact;
    std::cout<<sin<<std::endl;
    cos=pow(-1,n)*pow(x, 2*n)/cos_fact;
    std::cout<<cos<<std::endl;
}
