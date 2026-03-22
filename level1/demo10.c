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
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

int main()
{
    Student students1[MAX], students2[MAX];
    int n, count;
    char filename[] = "students.dat";

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputStudents(students1, n);

    writeToBinaryFile(students1, n, filename);

    count = readFromBinaryFile(students2, filename);

    printf("\nData read from binary file:\n");
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

void writeToBinaryFile(Student students[], int n, const char *filename)
{
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(students, sizeof(Student), n, fp);

    fclose(fp);
    printf("\nData successfully written to binary file.\n");
}

int readFromBinaryFile(Student students[], const char *filename)
{
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }

    int count = fread(students, sizeof(Student), MAX, fp);

    fclose(fp);
    return count; 
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