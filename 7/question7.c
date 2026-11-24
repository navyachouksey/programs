#include <stdio.h>
#include <string.h>

#define MAX_SENSORS 10

struct Sensor {
    int id;
    char type[20];
    float value, min, max;
    char status[10];
};

int main(void) {
    struct Sensor sensors[MAX_SENSORS];
    int n, abnormal = 0;

    printf("Enter number of sensors (1-10): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SENSORS) {
        printf("Please enter a number from 1 to 10.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nSensor %d\n", i + 1);
        printf("Enter ID: ");
        if (scanf("%d", &sensors[i].id) != 1) return 1;
        printf("Enter type: ");
        if (scanf("%19s", sensors[i].type) != 1) return 1;
        printf("Enter value: ");
        if (scanf("%f", &sensors[i].value) != 1) return 1;
        printf("Enter minimum limit: ");
        if (scanf("%f", &sensors[i].min) != 1) return 1;
        printf("Enter maximum limit: ");
        if (scanf("%f", &sensors[i].max) != 1) return 1;
        if (sensors[i].min > sensors[i].max) {
            printf("Minimum limit cannot be greater than maximum limit.\n");
            return 1;
        }

        float lower = sensors[i].min - 0.10f * sensors[i].min;
        float upper = sensors[i].max + 0.10f * sensors[i].max;
        if (sensors[i].value >= sensors[i].min && sensors[i].value <= sensors[i].max) {
            strcpy(sensors[i].status, "Normal");
        } else if (sensors[i].value >= lower && sensors[i].value <= upper) {
            strcpy(sensors[i].status, "Warning");
            abnormal++;
        } else {
            strcpy(sensors[i].status, "Anomaly");
            abnormal++;
        }
    }

    printf("\n--- Sensor Report ---\n");
    printf("ID\tType\t\tValue\tRange\t\tStatus\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-15s %.2f\t%.2f-%.2f\t%s\n", sensors[i].id,
               sensors[i].type, sensors[i].value, sensors[i].min,
               sensors[i].max, sensors[i].status);
    }
    printf("\nTotal Abnormal Sensors: %d\n", abnormal);
    return 0;
}
