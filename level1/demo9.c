#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int id;
    char name[50];
    float marks;
} Student;

void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

int main()
{
    Student students1[MAX], students2[MAX];
    int n, count;
    char filename[] = "students.txt";

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputStudents(students1, n);

    writeToTextFile(students1, n, filename);

    count = readFromTextFile(students2, filename);

    printf("\nData read from file:\n");
    printStudents(students2, count);

    return 0;
}

void inputStudents(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &students[i].id);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void writeToTextFile(Student students[], int n, const char *filename)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].marks);
    }

    fclose(fp);
    printf("\nData successfully written to file.\n");
}

int readFromTextFile(Student students[], const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int i = 0;

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }

    while (fscanf(fp, "%d %s %f",
                  &students[i].id,
                  students[i].name,
                  &students[i].marks) != EOF)
    {
        i++;
    }

    fclose(fp);
    return i; 
}

void printStudents(Student students[], int n)
{
    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Marks");
    printf("------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-10d %-20s %-10.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks);
    }
}