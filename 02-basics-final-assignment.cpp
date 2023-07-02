#include <iostream> //c++ i/o
#include <stdio.h> //c commands
#include <cmath> //pow, sqrt
#include <cstdlib> //srand, rand
#include <ctime> //time
#include <iomanip>


int main()
{
    //exercise 1
    float rect_a, rect_b;
    std::cout<<"Enter first side of rectangle: ";
    std::cin>>rect_a;
    std::cout<<"Enter second side of rectangle: ";
    std::cin>>rect_b;
    float cricum_rect = rect_a*2 + rect_b*2;
    float area_rect = rect_a*rect_b;
    std::cout<<"Circumference of rectangle: "<<cricum_rect<<std::endl;
    std::cout<<"Area of rectangle: "<<area_rect<<std::endl;

    float tri_a, tri_b, tri_c;
    std::cout<<"Enter first side of triangle: ";
    std::cin>>tri_a;
    std::cout<<"Enter second side of triangle: ";
    std::cin>>tri_b;
    std::cout<<"Enter third side of triangle: ";
    std::cin>>tri_c;
    float cricum_tri = tri_a + tri_b + tri_c;
    float cricum_tri_s = cricum_tri/2;
    float area_tri = sqrt(cricum_tri_s*(cricum_tri_s-tri_a)*(cricum_tri_s-tri_b)*(cricum_tri_s-tri_c));
    std::cout<<"Circumference of triangle: "<<cricum_tri<<std::endl;
    std::cout<<"Area of triangle: "<<area_tri<<std::endl;

    const float pi = 3.14159265359;
    float cos_a = (-tri_a*tri_a+tri_b*tri_b+tri_c*tri_c)/(2*tri_b*tri_c);
    float deg_a = acos(cos_a)*180/pi;
    float cos_b = (-tri_b*tri_b+tri_a*tri_a+tri_c*tri_c)/(2*tri_a*tri_c);
    float deg_b = acos(cos_b)*180/pi;
    float cos_g = (-tri_c*tri_c+tri_a*tri_a+tri_b*tri_b)/(2*tri_a*tri_b);
    float deg_g = acos(cos_g)*180/pi;
    std::cout<<"angle alpha: "<<deg_a<<std::endl;
    std::cout<<"angle beta: "<<deg_b<<std::endl;
    std::cout<<"angle gamma: "<<deg_g<<std::endl;

    //exercise2
    int num1, num2;
    float numf1, numf2;
    std::cout<<"Enter fist integer: ";
    std::cin>>num1;
    std::cout<<"Enter second integer: ";
    std::cin>>num2;
    std::cout<<"add: "<<num1+num2<<" multiply: "<<num1*num2<<" subtract: "<<num1-num2<<" divide: "<<num1/num2<<std::endl;

    std::cout<<"Enter fist real number: ";
    std::cin>>numf1;
    std::cout<<"Enter second real number: ";
    std::cin>>numf2;
    std::cout<<"add: "<<numf1+numf2<<" multiply: "<<numf1*numf2<<
               " subtract: "<<numf1-numf2<<" divide: "<<numf1/numf2<<std::endl;

    //exercise3
    int number1,number2;
    std::cout<<"Enter number to see pre-incrementation: ";
    std::cin>>number1;
    int numPreI = ++number1;
    std::cout<<"Pre increment operation"<<std::endl;
    std::cout<<"numPreI= "<<numPreI<<std::endl;
    std::cout<<"num1= "<<number1<<std::endl;

    std::cout<<"Enter number to see post-incrementation: ";
    std::cin>>number2;
    int numPostI = number2++;
    std::cout<<"Post increment operation"<<std::endl;
    std::cout<<"numPostI= "<<numPostI<<std::endl;
    std::cout<<"num2= "<<number2<<std::endl;

    int num3,num4;
    std::cout<<"Enter number to see pre-decrementation: ";
    std::cin>>num3;
    int numPreD = --num3;
    std::cout<<"Pre decrement operation"<<std::endl;
    std::cout<<"numPreD= "<<numPreD<<std::endl;
    std::cout<<"num3= "<<num3<<std::endl;

    std::cout<<"Enter number to see post-decrementation: ";
    std::cin>>num4;
    int numPostD = num4--;
    std::cout<<"Post decrement operation"<<std::endl;
    std::cout<<"numPostD= "<<numPostD<<std::endl;
    std::cout<<"num4= "<<num2<<std::endl;

    //exercise4
    char name[20], s_name[20], father_name[20], mother_name[20], mother_family_name[20], birth_place[20];
    float father_age, mother_age, birth_year, birth_month, birth_day;
    std::cout<<"Enter first name: ";
    std::cin>>name;
    std::cout<<"Enter second name: ";
    std::cin>>s_name;
    std::cout<<"Enter father's first name: ";
    std::cin>>father_name;
    std::cout<<"Enter father's age: ";
    std::cin>>father_age;
    std::cout<<"Enter mother's first name: ";
    std::cin>>mother_name;
    std::cout<<"Enter mother's age: ";
    std::cin>>mother_age;
    std::cout<<"Enter mother's family name: ";
    std::cin>>mother_family_name;
    std::cout<<"Enter birth place: ";
    std::cin>>birth_place;
    std::cout<<"Enter birth year: ";
    std::cin>>birth_year;
    std::cout<<"Enter birth month: ";
    std::cin>>birth_month;
    std::cout<<"Enter birth day: ";
    std::cin>>birth_day;
    std::cout<<"Citizen "<<name<<" "<<s_name<<" was born in "<<birth_place<<" "<<2015-birth_year<<
               " years ago. His mother, mrs "<<mother_name<<" (of a "<<mother_family_name<<"), was "<<
               mother_age-(2015-birth_year)<<" years old then and his father "<< father_age-(2015-birth_year)<<
               " years old."<<std::endl<<std::endl;

    std::cout<<s_name<<" "<<name<<" till 12.10.2015 lived approximately "<<
               (2015-birth_year)*365+((10-birth_month)*31)<<" days."<<std::endl;
    std::cout<<"His father is "<<std::setprecision(3)<<father_age/30.0<<
               " times older than him and mother "<<mother_age/30.0<<" times."<<std::endl;
    std::cout<<"It is an old family, because together they have "<<father_age+mother_age+30<<" years."<<std::endl;

    return 0;
}
