#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define STUDENT_COUNT 15
#define GRADE_MIN 0
#define GRADE_MAX 100
#define PASS_THRESHOLD 50

// function prototypes
static void discardLine(void);
void inputGrades(int grades[], size_t count);
void analysisGrades(const int grades[], size_t count);
void statusGrades(const int grades[], size_t count);
void extremesGrades(const int grades[], size_t count);


int main() {
    int grades[STUDENT_COUNT];

    inputGrades(grades, STUDENT_COUNT); // get input
    analysisGrades(grades, STUDENT_COUNT); // calculate average
    statusGrades(grades, STUDENT_COUNT); // count pass/fail
    extremesGrades(grades, STUDENT_COUNT); // find the highest grade

    return 0;
}

void inputGrades(int grades[], size_t count) {
    int scanResult;

    for (size_t i = 0; i < count; i++) {
        do {
            printf("enter a grade for student %zu: ", i + 1);
            scanResult = scanf("%d", &grades[i]);

            if (scanResult == EOF) {
                printf("\nerror: no input detected, exiting.\n");
                exit(EXIT_FAILURE);
            } else if (scanResult == 0) {
                printf("error: invalid input! please enter a number, not letters.\n");
                discardLine();
                continue;
            } else if (grades[i] < GRADE_MIN || grades[i] > GRADE_MAX) {
                printf("error: grade must be between %d and %d.\n", GRADE_MIN, GRADE_MAX);
                discardLine();
                continue;
            }
            discardLine();
            break;
        } while (1);
    }
}

void analysisGrades(const int grades[], size_t count) {
    double total = 0.0;
    double average = 0.0;

    if (count == 0) {
        printf("no grades to analyze.\n");
        return;
    }

    for (size_t i = 0; i < count; i++) {
        total += grades[i];
    }
    average = total / (double)count;

    printf("class average: %.2f\n", average);
}

void statusGrades(const int grades[], size_t count) {
    size_t passed = 0;

    if (count == 0) {
        printf("no grades to evaluate pass/fail status.\n");
        return;
    }

    for (size_t i = 0; i < count; i++) {
        if (grades[i] >= PASS_THRESHOLD) {
            passed++;
        }
    }
    printf("%zu student(s) passed and %zu student(s) failed.\n", passed, count - passed);
}

void extremesGrades(const int grades[], size_t count) {
    int maxGrade;
    size_t maxStudentIndex = 0;

    if (count == 0) {
        printf("no grades to determine highest value.\n");
        return;
    }

    maxGrade = grades[0];

    for (size_t i = 1; i < count; i++) {
        if (grades[i] > maxGrade) {
            maxGrade = grades[i];
            maxStudentIndex = i;
        }
    }
    printf("highest grade (student: %zu): %d\n", maxStudentIndex + 1, maxGrade);
}

static void discardLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // discard until end of line
    }
}
