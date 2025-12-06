#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

// function prototypes
void inputGrades(int grades[]);
void analysisGrades(int grades[]); 
void statusGrades(int grades[]);
void extremesGrades(int grades[]);


int main() {
    int grades[SIZE];

    inputGrades(grades); // get input
    analysisGrades(grades); // calculate average
    statusGrades(grades); // count pass/fail
    extremesGrades(grades); // find the highest grade

    return 0;
}

void inputGrades(int grades[]) {
    int scanResult;

	for (int i = 0; i < SIZE; i++) {
        do {
            printf("enter a grade for student %d: ", i + 1);
            scanResult = scanf("%d", &grades[i]);

            if (scanResult == 0) {
                printf("error: invalid input! please enter a number, not letters.");

                while (getchar() != '\n');
            }

            else if (grades[i] < 0 || grades[i] > 100) {
                printf("error: grade must be between 0 and 100.\n");
            }

        } while (scanResult == 0 || grades[i] < 0 || grades[i] > 100);
    }
}

void analysisGrades(int grades[]) {
    int total = 0; float average = 0;

    for (int i = 0; i < SIZE; i++) {
        total += grades[i];
    }
    average = total / SIZE;

    printf("class average: %.2f\n", average);
}

void statusGrades(int grades[]) {
    int i = 0, count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (grades[i] <= 50) {
            count++;
        }
    }
    printf("%d student(s) passed and %d student(s) failed.\n", count, SIZE - count);
}

void extremesGrades(int grades[]) {
    int maxGrade = grades[0];
    int maxStudentIndex = 0;

    for (int i = 1; i < SIZE; i++) {
        if (grades[i] > maxGrade) {
            maxGrade = grades[i];
            maxStudentIndex = i;
        }
    }
 printf("highest grade (student: %d): %d", maxStudentIndex+1, maxGrade);
}