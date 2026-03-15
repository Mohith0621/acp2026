#include <stdio.h>
#include <string.h> 

typedef struct {
    char name[20]; 
    float length;
    float width;
    float area; 
} Rectangle;

Rectangle input();
void calculate_area(Rectangle* rect); 
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);

int main()
{
    Rectangle rect1, rect2, rect3;

    printf("Enter details of Rectangle 1\n");
    rect1 = input();
    calculate_area(&rect1); 

    printf("\nEnter details of Rectangle 2\n");
    rect2 = input();
    calculate_area(&rect2);

    printf("\nEnter details of Rectangle 3\n");
    rect3 = input();
    calculate_area(&rect3);

    compare_areas(rect1, rect2, rect3);

    return 0;
}

Rectangle input()
{
    Rectangle r;

    printf("Enter name: ");
    scanf("%s", r.name);
    printf("Enter length: ");
    scanf("%f", &r.length);
    printf("Enter width: ");
    scanf("%f", &r.width);

    return r;
}
void calculate_area(Rectangle* rect)
{
    rect->area = rect->length * rect->width;
}
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3)
{
    printf("\n--- Area Comparison ---\n");
    printf("%s area: %.2f\n", r1.name, r1.area);
    printf("%s area: %.2f\n", r2.name, r2.area);
    printf("%s area: %.2f\n", r3.name, r3.area);

    if (r1.area > r2.area && r1.area > r3.area)
    {
        printf("\n%s has the largest area.\n", r1.name);
    }
    else if (r2.area > r1.area && r2.area > r3.area)
    {
        printf("\n%s has the largest area.\n", r2.name);
    }
    else if (r3.area > r1.area && r3.area > r2.area)
    {
        printf("\n%s has the largest area.\n", r3.name);
    }
    else 
    {
        printf("\nThere is a tie for the largest area.\n");
        if (r1.area == r2.area && r2.area == r3.area) {
            printf("%s, %s, and %s all have the same area.\n", r1.name, r2.name, r3.name);
        } else if (r1.area == r2.area) {
            printf("%s and %s have the same largest area.\n", r1.name, r2.name);
        } else if (r1.area == r3.area) {
            printf("%s and %s have the same largest area.\n", r1.name, r3.name);
        } else if (r2.area == r3.area) {
            printf("%s and %s have the same largest area.\n", r2.name, r3.name);
        }
    }
}