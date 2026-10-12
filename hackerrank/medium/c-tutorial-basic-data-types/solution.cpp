#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main() {
    int a;
    long b;
    char c;
    float d;
    double e;
    
    // Reading input using scanf
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    
    // Printing each element on a new line with exact precision requirements
    printf("%d\n", a);
    printf("%ld\n", b);
    printf("%c\n", c);
    printf("%.3f\n", d);
    printf("%.9lf\n", e);
    
    return 0;
}
