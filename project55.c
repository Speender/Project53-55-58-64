#include <stdio.h>

void angleInput(int *angle1); //Function to read angle
void printsQuadrant(int angle); //Function to print what quadrant the angle is in and prints it

int main() {
    int angle1;
    angleInput(&angle1); // all to read the angle given by the user
    printsQuadrant(angle1); //Call to determine what quadrant the angle is in and prints it

    return 0;
}

void angleInput(int *angle1) {
    printf("Enter angle (0 - 360): "); // User input
    scanf("%d", angle1); 
}

void printsQuadrant(int angle) {
    //Process and output
    if (angle < 0 && angle < 90) {
        printf("Quadrant I");
    } else if (angle > 90 && angle < 180) {
        printf("Quadrant II");
    } else if (angle > 180 && angle < 270) {
        printf("Quadrant III");
    } else if (angle > 270 && angle < 360) {
        printf("Quadrant IV");
    } else if (angle == 0) {
        printf("It is not in a quadrant but lies on the positive X-axis");
    } else if (angle == 90) {
        printf("It is not in a quadrant but lies on the positive Y-axis");
    } else if (angle == 180) {
        printf("It is not in a quadrant but lies on the negative X-axis");
    } else if (angle == 270) {
        printf("It is not in a quadrant but lies on the negative Y-axis");
    }
}
