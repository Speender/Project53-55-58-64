#include <stdio.h>

// Function declarations
void input(char *vehicle, int *hr, int *min, int *hrOut, int *minOut);
char *vehicleType(char vehicle);
int actualTime(int hr, int min, int hrOut, int minOut);
float calculateCharge(char vehicle, int actualTime);
void output(char vehicle, int hr, int min, int hrOut, int minOut, int actualTime, float Charge);

int main() {
    // Variables for user input
    int hr, min, hrOut, minOut;
    char vehicle;

    // Get user input
    input(&vehicle, &hr, &min, &hrOut, &minOut);

    // Get the vehicle type as a string
    char *typeVehicle = vehicleType(vehicle);

    // Calculate the actual time the vehicle spent in the parking lot
    int actual = actualTime(hr, min, hrOut, minOut);

    // Calculate the parking charge
    float charge = calculateCharge(vehicle, actual);

    // Display the parking lot charge details
    output(vehicle, hr, min, hrOut, minOut, actual, charge);

    return 0;
}

// Function to get user input
void input(char *vehicle, int *hr, int *min, int *hrOut, int *minOut) {
    printf("Enter type of vehicle (C for car, B for Bus, T for): ");
    scanf(" %c", vehicle);
    printf("Hour vehicle entered lot (0 - 24): ");
    scanf("%d", hr);
    printf("Minute vehicle entered lot (0 - 60): ");
    scanf("%d", min);
    printf("Hour vehicle left lot (0 - 24): ");
    scanf("%d", hrOut);
    printf("Minute vehicle left lot (0 - 60): ");
    scanf("%d", minOut);
}

// Function to determine the type of vehicle
char *vehicleType(char vehicle) {
    switch (vehicle) {
        case 'C':
            return "Car";
        case 'T':
            return "Truck";
        case 'B':
            return "Bus";
        default:
            return "Unknown";
    }
}

// Function to calculate the actual time spent in the parking lot
int actualTime(int hr, int min, int hrOut, int minOut) {
    if (minOut < min) {
        minOut += 60;
        hrOut--;
    }

    int actualHr = hrOut - hr;
    int actualMin = minOut - min;

    if (actualMin > 0) {
        actualHr++;
    }

    return actualHr;
}

// Function to calculate the parking charge
float calculateCharge(char vehicle, int actualTime) {
    float charge = 0;
    switch (vehicle) {
        case 'C':
            if (actualTime > 3) {
                charge = actualTime * 1.50;
            }
            break;
        case 'B':
            if (actualTime > 1) {
                charge = actualTime * 3.70;
            }
            break;
        case 'T':
            if (actualTime > 2) {
                charge = actualTime * 2.30;
            }
            break;
        default:
            break;
    }
    return charge;
}

// Function to display the parking lot charge details
void output(char vehicle, int hr, int min, int hrOut, int minOut, int actualTime, float Charge) {
    // Additional calculations for output formatting
    int inHour = hr;
    int inMin = min;
    int outHour = hrOut;
    int outMin = minOut;
    int parkTime = actualTime * 60;
    int parkHour = parkTime / 60;
    int parkMin = parkTime % 60;
    int roundedTime = actualTime;

    // Display the parking lot charge details
    printf("\n\tPARKING LOT CHARGE\n\n");
    printf("Type of vehicle:\t%s\n", vehicleType(vehicle));
    printf("TIME-IN\t\t\t%02d:%02d\n", inHour, inMin);
    printf("TIME-OUT\t\t%02d:%02d\n", outHour, outMin);
    printf("\t\t\t--------\n");
    printf("PARKING TIME\t\t%02d:%02d\n", parkHour, parkMin);
    printf("ROUNDED TIME\t\t%02d\n", roundedTime);
    printf("\t\t\t--------\n");
    printf("TOTAL CHARGE\t\t$%.2f\n", Charge);
}
