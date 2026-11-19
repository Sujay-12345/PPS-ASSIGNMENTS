#include <stdio.h>
#include <stdlib.h>

// Define the structure for agricultural robot field data[cite: 2]
typedef struct {
    int id;                // Field/Plot ID[cite: 2]
    float moisture;        // Soil moisture (%)[cite: 2]
    float temperature;     // Temperature (°C)[cite: 2]
    float humidity;        // Humidity (%)[cite: 2]
    int cropHealth;        // Crop health (%)[cite: 2]
    float latitude;        // GPS latitude[cite: 2]
    float longitude;       // GPS longitude[cite: 2]
} FieldRecord;

// Function to add/store a new field record into the file
void addRecord(const char *filename) {
    FILE *file = fopen(filename, "ab"); // Open in binary append mode
    if (file == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }

    FieldRecord r;
    printf("\nEnter Field/Plot ID: ");
    scanf("%d", &r.id);
    printf("Enter Soil Moisture (%%): ");
    scanf("%f", &r.moisture);
    printf("Enter Temperature (°C): ");
    scanf("%f", &r.temperature);
    printf("Enter Humidity (%%): ");
    scanf("%f", &r.humidity);
    printf("Enter Crop Health (%%): ");
    scanf("%d", &r.cropHealth);
    printf("Enter GPS Latitude: ");
    scanf("%f", &r.latitude);
    printf("Enter GPS Longitude: ");
    scanf("%f", &r.longitude);

    fwrite(&r, sizeof(FieldRecord), 1, file);
    fclose(file);
    printf("Field record stored successfully!\n");
}

// Function to read stored data, identify irrigation needs, and generate report[cite: 2]
void generateReport(const char *filename) {
    FILE *file = fopen(filename, "rb"); // Open in binary read mode
    if (file == NULL) {
        printf("Error: Could not open file for reading or file does not exist!\n");
        return;
    }

    FieldRecord r;
    printf("\n=================================================================================\n");
    printf("                       AGRICULTURAL FIELD-MONITORING REPORT                      \n");
    printf("=================================================================================\n");
    printf("ID\tMoist(%%)\tTemp(°C)\tHum(%%)\tHealth(%%)\tGPS Coordinates\t\tStatus\n");
    printf("---------------------------------------------------------------------------------\n");

    while (fread(&r, sizeof(FieldRecord), 1, file)) {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t%d\t\t(%.2f, %.2f)\t", 
               r.id, r.moisture, r.temperature, r.humidity, r.cropHealth, r.latitude, r.longitude);
        
        // Identify areas requiring irrigation (Threshold set below 30.0% soil moisture)
        if (r.moisture < 30.0) {
            printf("[REQUIRES IRRIGATION]\n");
        } else {
            printf("[SUFFICIENT MOISTURE]\n");
        }
    }
    printf("=================================================================================\n");
    fclose(file);
}

int main() {
    int choice;
    const char *filename = "robot_field_data.dat";

    do {
        printf("\n--- Agricultural Robot Monitoring System ---\n");
        printf("1. Store Field Data Record\n");
        printf("2. Generate Field-Monitoring & Irrigation Report\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(filename);
                break;
            case 2:
                generateReport(filename);
                break;
            case 3:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}