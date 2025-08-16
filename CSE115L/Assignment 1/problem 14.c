#include <stdio.h>
#define PI 3.1416

float CalArea(float radius) {
    return PI * radius * radius;
}

int main() {
    float r;
    printf("Enter radius: ");
    scanf("%f", &r);

    float area = CalArea(r);
    printf("Area: %.3f\n", area);

    return 0;
}
