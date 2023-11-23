#include <stdio.h>
void scores(int *score1, int *score2, int *score3); //Function to read three test scores
char calculateGrade(int score1, int score2, int score3); //Function to calculate the grade
void printResults(char grade); //function to print the final grade

int main() 
{
    int score1, score2, score3;
    scores(&score1, &score2, &score3); //call the function to get test scores
    char grade = calculateGrade(score1, score2, score3); //Call the function to determine the grade
    printResults(grade); //call the function to display the final grade

    return 0;
}

void scores(int *score1, int *score2, int *score3) 
{
    printf("Enter the first test score (between 0 and 100): "); //user inputes
    scanf("%d", score1);

    printf("Enter the second test score (between 0 and 100): ");
    scanf("%d", score2);

    printf("Enter the third test score (between 0 and 100): ");
    scanf("%d", score3);
}

char calculateGrade(int score1, int score2, int score3) 
{
    //process
    int averageScore = (score1 + score2 + score3) / 3;
    int conditionC = (score2 + score3) / 2; //This is for the condition 'C' "if checks average of the second and third scores. if the average of the two is greater than 70, the grade isc; otherwise, it is D"

    if (averageScore >= 90)
    {
        return 'A';  
    }
    else if (averageScore >= 70 && averageScore < 90)
    {
        return 'B';
    }
    else if (score3 > 90) //This is for the condition 'B' "it checks the third score. If the third score is more than 90%, the grade is A; otherwise, the grade is B."
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

void printResults(char grade)
{
    //output
    printf("The student's grade is: %c\n", grade);
}
