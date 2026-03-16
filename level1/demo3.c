#include <stdio.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

void input(int n, Rectangle rects[n]);
void calculate_area(int n, Rectangle rects[n]);
int findLargestArea(int n, Rectangle rects[n]);
void output(int largestIndex, Rectangle rects[]);

int main() {
    int n;

    printf("Enter the number of rectangles: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for the number of rectangles. Please enter a positive integer.\n");
        return 1;
    }

    Rectangle rects[n];

    input(n, rects);

    calculate_area(n, rects);

    int largestIndex = findLargestArea(n, rects);
    output(largestIndex, rects);

    return 0;
}

void input(int n, Rectangle rects[n]) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Rectangle %d:\n", i + 1);
        printf("  Enter length: ");
        scanf("%f", &rects[i].length);
        printf("  Enter width: ");
        scanf("%f", &rects[i].width);
    }
}

void calculate_area(int n, Rectangle rects[n]) {
    printf("\n--- Rectangle Areas ---\n");
    for (int i = 0; i < n; i++) {
        rects[i].area = rects[i].length * rects[i].width;
        printf("Rectangle %d: Length = %.2f, Width = %.2f, Area = %.2f\n",
               i + 1, rects[i].length, rects[i].width, rects[i].area);
    }
}

int findLargestArea(int n, Rectangle rects[n]) {
    int largestIndex = 0;
    float maxArea = rects[0].area;

    for (int i = 1; i < n; i++) {
        if (rects[i].area > maxArea) {
            maxArea = rects[i].area;
            largestIndex = i;
        }
    }
    return largestIndex;
}

void output(int largestIndex, Rectangle rects[]) {
    printf("\n--- Largest Rectangle ---\n");
    printf("Rectangle %d has the largest area:\n", largestIndex + 1);
    printf("  Length: %.2f\n", rects[largestIndex].length);
    printf("  Width: %.2f\n", rects[largestIndex].width);
    printf("  Area: %.2f\n", rects[largestIndex].area);
}
