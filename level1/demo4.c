#include <stdio.h>
#include <string.h>

typedef struct {
    int flight_number;
    char destination[50];
    int available_seats;
} Flight_t;

void readFlights(int n, Flight_t f[]) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Flight %d:\n", i + 1);

        printf("Flight Number: ");
        scanf("%d", &f[i].flight_number);

        printf("Destination: ");
        scanf("%s", f[i].destination);

        printf("Available Seats: ");
        scanf("%d", &f[i].available_seats);
    }
}

void searchByDestination(int n, Flight_t f[], char searchDest[]) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(f[i].destination, searchDest) == 0) {
            printf("\nFlight available!\n");
            printf("Flight Number: %d\n", f[i].flight_number);
            printf("Available Seats: %d\n", f[i].available_seats);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo flights available to %s\n", searchDest);
    }
}

int main() {
    int n = 4;
    Flight_t flights[4];
    char searchDest[50];


    readFlights(n, flights);

    printf("\nEnter destination to search: ");
    scanf("%s", searchDest);

    searchByDestination(n, flights, searchDest);

    return 0;
}