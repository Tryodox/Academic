#include <stdio.h>
#include <string.h>

struct Car {
    int id;
    char model[50];
    float ratePerDay;
};

int main() {
    struct Car cars[3];
    int days;

    for (int i = 0; i < 3; i++) {
        printf("Enter details for Car %d:\n", i + 1);

        printf("Car ID: ");
        scanf("%d", &cars[i].id);
        getchar();

        printf("Model: ");
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        cars[i].model[strcspn(cars[i].model, "\n")] = '\0';

        printf("Rate per day: ");
        scanf("%f", &cars[i].ratePerDay);
    }

    printf("\nEnter number of rental days: ");
    scanf("%d", &days);

    printf("\nCar Rental Summary:\n");
    for (int i = 0; i < 3; i++) {
        float totalCost = cars[i].ratePerDay * days;
        printf("Car ID: %d\nModel: %s\nRate per day: %.2f\nTotal cost for %d days: %.2f\n\n",
               cars[i].id, cars[i].model, cars[i].ratePerDay, days, totalCost);
    }

    return 0;
}
