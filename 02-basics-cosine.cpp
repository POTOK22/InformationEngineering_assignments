#include <iostream>
#include <stdio.h> //c commands
#include <cmath> // cos
#include <cstdlib> //srand, rand
#include <ctime> //time

using namespace std;

int main()
{
    //assignment
    srand(time(nullptr));
    double degrees = rand() % 181 + (-180);
    const double pi = 3.14159265359;
    double cosine_value = cos(degrees * pi/180);
    printf("cosine value is: %f\n", cosine_value);
    printf("cosine value to power 1 over 5 is: %f\n", pow(cosine_value, 0.2));
    return 0;
}
