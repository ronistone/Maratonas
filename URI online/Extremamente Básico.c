#include <stdio.h>
 
int main() {
 
    double area,raio;
    scanf("%2f", &raio);
    area = 3.14159 * (raio*raio);
    printf("A=%.4f\n", area);
 
    return 0;
}
