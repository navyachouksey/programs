#include <stdio.h>
int main () {
    float weight;
    printf("Enter vehicle weight (in kg): ");
    scanf("%f", &weight);
    if (weight > 500.0) {
        printf("Access Granted: Warehouse security gate opening.\n");
    }
    if (weight <= 500.0) {
        printf("Access Denied: Vehicle weight below minimum safety threshold (500 kg).\n");
    }
    return 0;
}
