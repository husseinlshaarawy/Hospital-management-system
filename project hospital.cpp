#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

typedef struct {
    char firstName[50];
    char lastName[50];
    char gender[50];
    char mobile[50];  // Increased the size to accommodate mobile number
    int totalNoOfMedicine;
    float totalPayment;
} Patient;

Patient patients[MAX_PATIENTS];
int numPatients = 0;

void readPatientData() {
    if (numPatients >= MAX_PATIENTS) {
        printf("Maximum number of patients reached.\n");
        return;
    }

    Patient patient;
    printf("Enter patient details:\n");
    printf("First Name: ");
    scanf("%s", patient.firstName);
    printf("Last Name: ");
    scanf("%s", patient.lastName);
    printf("Gender: ");
    scanf("%s", patient.gender);
    printf("Mobile: ");
    scanf("%s", patient.mobile);
    printf("Total No of Medicine: ");
    scanf("%d", &patient.totalNoOfMedicine);
    printf("Total Payment: ");
    scanf("%f", &patient.totalPayment);

    patients[numPatients] = patient;
    numPatients++;
}

void printPatientData() {
    printf("Patient Details:\n");
    for (int i = 0; i < numPatients; i++) {
        printf("Patient %d:\n", i + 1);
        printf("First Name: %s\n", patients[i].firstName);
        printf("Last Name: %s\n", patients[i].lastName);
        printf("Gender: %s\n", patients[i].gender);
        printf("Mobile: %s\n", patients[i].mobile);
        printf("Total No of Medicine: %d\n", patients[i].totalNoOfMedicine);
        printf("Total Payment: %.2f\n", patients[i].totalPayment);
        printf("----------------------------\n");
    }
}

void sortAndApplyBonus() {
    for (int i = 0; i < numPatients; i++) {
        if (patients[i].totalNoOfMedicine > 5) {
            patients[i].totalPayment *= 0.85;  // Apply 15% bonus
        }
    }

    // Sort based on totalNoOfMedicine using bubble sort algorithm
    for (int i = 0; i < numPatients - 1; i++) {
        for (int j = 0; j < numPatients - i - 1; j++) {
            if (patients[j].totalNoOfMedicine > patients[j + 1].totalNoOfMedicine) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

void searchPatient(char* firstName, char* lastName) {
    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].firstName, firstName) == 0 &&
            strcmp(patients[i].lastName, lastName) == 0) {
            found = 1;
            printf("Patient Found:\n");
            printf("First Name: %s\n", patients[i].firstName);
            printf("Last Name: %s\n", patients[i].lastName);
            printf("Gender: %s\n", patients[i].gender);
            printf("Mobile: %s\n", patients[i].mobile);
            printf("Total No of Medicine: %d\n", patients[i].totalNoOfMedicine);
            printf("Total Payment: %.2f\n", patients[i].totalPayment);
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

void sortAndRetrieveTopPatients() {
    // Sort based on totalPayment using bubble sort algorithm
    for (int i = 0; i < numPatients - 1; i++) {
        for (int j = 0; j < numPatients - i - 1; j++) {
            if (patients[j].totalPayment < patients[j + 1].totalPayment) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    printf("Top 5 Patients:\n");
    for (int i = 0; i < numPatients && i < 5; i++) {
        printf("%d. %s %s - Total Payment: %.2f\n", i + 1, patients[i].firstName,
               patients[i].lastName, patients[i].totalPayment);
    }
}

int main() {
    int choice;
    char firstName[50];
    char lastName[50];

    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Print All Patients\n");
        printf("3. Apply Bonus and Sort Patients\n");
        printf("4. Search Patient\n");
        printf("5. Retrieve Top 5 Patients\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readPatientData();
                break;
            case 2:
                printPatientData();
                break;
            case 3:
                sortAndApplyBonus();
                printf("Bonus applied and patients sorted based on total No of Medicine.\n");
                break;
            case 4:
                printf("Enter first name of the patient: ");
                scanf("%s", firstName);
                printf("Enter last name of the patient: ");
                scanf("%s", lastName);
                searchPatient(firstName, lastName);
                break;
            case 5:
                sortAndRetrieveTopPatients();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

