#include <stdio.h>
#include <string.h>

#define MAX_TRAINS 100
#define MAX_NAME_LENGTH 50
#define MAX_STATION_LENGTH 50

typedef struct {
    int number;
    char name[MAX_NAME_LENGTH];
    char startStation[MAX_STATION_LENGTH];
    char endStation[MAX_STATION_LENGTH];
    char departureTime[6]; // Format HH:MM
    char arrivalTime[6];   // Format HH:MM
} Train;

Train trains[MAX_TRAINS];
int trainCount = 0;

void listTrainsByStation(const char *station) {
    printf("Trains at station %s:\n", station);
    for (int i = 0; i < trainCount; i++) {
        if (strcmp(trains[i].startStation, station) == 0 || strcmp(trains[i].endStation, station) == 0) {
            printf("Train Number: %d, Name: %s, From: %s, To: %s, Departure: %s, Arrival: %s\n",
                trains[i].number, trains[i].name, trains[i].startStation, trains[i].endStation, trains[i].departureTime, trains[i].arrivalTime);
        }
    }
}

void listTrainsByTime(const char *time) {
    printf("Trains departing at %s:\n", time);
    for (int i = 0; i < trainCount; i++) {
        if (strcmp(trains[i].departureTime, time) == 0) {
            printf("Train Number: %d, Name: %s, From: %s, To: %s, Departure: %s, Arrival: %s\n",
                trains[i].number, trains[i].name, trains[i].startStation, trains[i].endStation, trains[i].departureTime, trains[i].arrivalTime);
        }
    }
}

void editTrainDetails(int number) {
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].number == number) {
            printf("Editing details for train number %d\n", number);
            printf("Enter new train name: ");
            scanf("%s", trains[i].name);
            printf("Enter new start station: ");
            scanf("%s", trains[i].startStation);
            printf("Enter new end station: ");
            scanf("%s", trains[i].endStation);
            printf("Enter new departure time (HH:MM): ");
            scanf("%s", trains[i].departureTime);
            printf("Enter new arrival time (HH:MM): ");
            scanf("%s", trains[i].arrivalTime);
            printf("Train details updated successfully.\n");
            return;
        }
    }
    printf("Train with number %d not found.\n", number);
}

void addTrain() {
    if (trainCount >= MAX_TRAINS) {
        printf("Train list is full.\n");
        return;
    }
    Train t;
    printf("Enter train number: ");
    scanf("%d", &t.number);
    printf("Enter train name: ");
    scanf("%s", t.name);
    printf("Enter start station: ");
    scanf("%s", t.startStation);
    printf("Enter end station: ");
    scanf("%s", t.endStation);
    printf("Enter departure time (HH:MM): ");
    scanf("%s", t.departureTime);
    printf("Enter arrival time (HH:MM): ");
    scanf("%s", t.arrivalTime);
    trains[trainCount++] = t;
    printf("Train added successfully.\n");
}

void displayMenu() {
    printf("\nTrain Schedule Management System\n");
    printf("1. Add Train\n");
    printf("2. List Trains by Station\n");
    printf("3. List Trains by Departure Time\n");
    printf("4. Edit Train Details\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrain();
                break;
            case 2: {
                char station[MAX_STATION_LENGTH];
                printf("Enter station name: ");
                scanf("%s", station);
                listTrainsByStation(station);
                break;
            }
            case 3: {
                char time[6];
                printf("Enter departure time (HH:MM): ");
                scanf("%s", time);
                listTrainsByTime(time);
                break;
            }
            case 4: {
                int number;
                printf("Enter train number to edit: ");
                scanf("%d", &number);
                editTrainDetails(number);
                break;
            }
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
