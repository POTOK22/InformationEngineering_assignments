#include "header.h"

int main()
{
    Time t1(200);
//    t1.print();
    cout<<"t1 "<<t1<<endl;
    Time t2;
    cin>>t2;
    cout<<"t2 "<<t2<<endl;

    Time t3=t1+t2;
    cout<<"t3(addition) "<<t3<<endl;

    Time t4=t1-t2;
    cout<<"t4(substraction) "<<t4<<endl;

    Time t5=6*t2;
    cout<<"t5(multiplication) "<<t5<<endl;

    int t2s = t2;
    cout<<"t2s conversion "<<t2s<<endl;

    return 0;
}
