#include <stdio.h>

// Function to read three test scores
void scores(int *score1, int *score2, int *score3);

// Function to calculate the grade
char calculateGrade(int score1, int score2, int score3);

// Function to print the final grade
void printResults(char grade);

// Main function
int main() {
    int score1, score2, score3;

    // Call the read_scores function to get test scores
    scores(&score1, &score2, &score3);

    // Call the calculateGrade function to determine the grade
    char grade = calculateGrade(score1, score2, score3);

    // Call the printResults function to display the final grade
    printResults(grade);

    return 0;
}

void scores(int *score1, int *score2, int *score3) {
    printf("Enter the first test score (between 0 and 100): ");
    scanf("%d", score1);

    printf("Enter the second test score (between 0 and 100): ");
    scanf("%d", score2);

    printf("Enter the third test score (between 0 and 100): ");
    scanf("%d", score3);
}

char calculateGrade(int score1, int score2, int score3) {
    int averageScore = (score1 + score2 + score3) / 3;
    int conditionC = (score2 + score3) / 2;

if (averageScore >= 90)
{
    return 'A';  
}
else if (averageScore >= 70 && averageScore < 90)
{
    return 'B';
}
else if (score3 > 90)
{
    return 'A';
}
else if (averageScore >= 50 && averageScore < 70)
{
    return 'D';
}
else if (conditionC > 70)
{
    return 'C';
}
else if (averageScore < 50)
{
    return 'F';
}

    
        

}

void printResults(char grade) {
    printf("The student's grade is: %c\n", grade);
}
