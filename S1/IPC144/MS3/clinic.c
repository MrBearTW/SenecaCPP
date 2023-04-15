/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :CHI-WEI PERNG
Student ID#:121967228
Email      :cperng@myseneca.ca
Section    :NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

// Sor Appointment array
void sort(struct Appointment appoints[], int max)
{
    int i, j;
    struct Appointment temp;

    // Cgange date + time to tatal minutes for comparison
    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }

    // Sort by tatal minutes for small to big
    for (i = 0; i < max; i++)
    {
        for (j = i + 1; j < max - 1; j++)
        {
            if (appoints[j].time.min < appoints[i].time.min)
            {
                temp = appoints[j];
                appoints[j] = appoints[i];
                appoints[i] = temp;
            }
        }
    }

    // Restore date + time
    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, hasdata = 0;
    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            hasdata = 1;
        }
    }
    printf("\n");

    if (hasdata == 0)
    {
        printf("*** No records found ***\n\n");
    }
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Search Options\n"
               "==========================\n"
               "1) By patient number\n"
               "2) By phone number\n"
               "..........................\n"
               "0) Previous menu\n"
               "..........................\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, patientCount = 0, emptyIndex;

    // Count how many patient.
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            patientCount++;
        }
    }

    if (patientCount == max)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == 0)
            {
                emptyIndex = i;
            }
        }

        patient[emptyIndex].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[emptyIndex]);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int patientIndex;

    getPatientIndex(patient, max, &patientIndex);

    if (patientIndex == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[patientIndex]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patientIndex, removeResult = 0;
    char yesNo, newline;

    getPatientIndex(patient, max, &patientIndex);

    if (patientIndex == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        printf("Name  : %s\n", patient[patientIndex].name);
        printf("Number: %05d\n", patient[patientIndex].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[patientIndex].phone.number);
        printf(" (%s)", patient[patientIndex].phone.description);
        printf("\n\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");

        do
        {
            scanf(" %c%c", &yesNo, &newline);
            if (yesNo == 'n' && newline == '\n')
            {
                puts("Operation aborted.\n");
                removeResult = -1;
            }
            else if (yesNo == 'y' && newline == '\n')
            {
                patient[patientIndex].patientNumber = 0;
                puts("Patient record has been removed!");
                removeResult = 1;
            }
            else
            {
                printf("ERROR: Character must be one of [yn]: ");
            }
            clearInputBuffer();
        } while (removeResult == 0);
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data)
{
    int i, j;

    sort(data->appointments, data->maxAppointments);

    if (data != NULL)
    {
        displayScheduleTableHeader(&data->appointments->date, 1);
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
                {
                    if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                    }
                }
            }
        }
        printf("\n");
    }
    else
    {
        printf("ClinicData Error\n");
    }
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData *data)
{
    int i, j;
    struct Date inputdate = {0};

    sort(data->appointments, data->maxAppointments);

    getDate(&inputdate);

    if (data != NULL)
    {
        printf("\n");
        displayScheduleTableHeader(&inputdate, 0);
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
                {
                    if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                    {
                        if (data->appointments[i].date.year == inputdate.year && data->appointments[i].date.month == inputdate.month && data->appointments[i].date.day == inputdate.day)
                        {
                            displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    else
    {
        printf("ClinicData Error\n");
    }
}
// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *appointments, int maxAppointments, struct Patient *patients, int maxPatient)
{
    struct Appointment newAppointment = {0};
    int patientNumberExist = -1, validTime = 0, slotAvailable = -1, i, availableIndex = 0;

    // Get Patient Number
    do
    {
        printf("Patient Number: ");
        newAppointment.patientNumber = inputIntPositive();
        patientNumberExist = findPatientIndexByPatientNum(newAppointment.patientNumber, patients, maxPatient);

        if (patientNumberExist == -1)
        {
            printf("ERROR: Patient record not found!\n\n");
        }
    } while (patientNumberExist == -1);

    do
    {
        // Get date
        getDate(&newAppointment.date);

        do
        {
            slotAvailable = -1;
            printf("Hour (0-23)  : ");
            newAppointment.time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            newAppointment.time.min = inputIntRange(0, 59);

            if ((newAppointment.time.hour < START_HOUR || newAppointment.time.hour > END_HOUR) || (newAppointment.time.hour == END_HOUR && newAppointment.time.min > 0) || (newAppointment.time.min % MINUTE_INTERVAL != 0))
            {
                printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                validTime = 0;
            }
            else
            {
                validTime = 1;
            }

        } while (validTime == 0);

        // check appointment avaible
        for (i = 0; i < maxAppointments; i++)
        {
            if (newAppointment.date.year == appointments[i].date.year && newAppointment.date.month == appointments[i].date.month && newAppointment.date.day == appointments[i].date.day && newAppointment.time.hour == appointments[i].time.hour && newAppointment.time.min == appointments[i].time.min)
            {
                slotAvailable = 0;
            }
        }
        if (slotAvailable == 0)
        {
            printf("\nERROR: Appointment timeslot is not available!\n\n");
        }
        else
        {
            i = 0;
            // find available Index
            while (availableIndex == 0 && i < maxAppointments)
            {
                if (appointments[i].patientNumber < 1)
                {
                    availableIndex = 1;
                }
                i++;
            }
            appointments[i].date = newAppointment.date;
            appointments[i].time = newAppointment.time;
            appointments[i].patientNumber = newAppointment.patientNumber;
            printf("\n*** Appointment scheduled! ***\n\n");

            slotAvailable = 1;
        }

    } while (slotAvailable != 1);
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment *appointments, int maxAppointments, struct Patient *patients, int maxPatient)
{
    struct Appointment inputAppointment = {0};
    int patientNumberExist = 0, validAppointment = 0, i = 0;

    // Get Patient Number
    printf("Patient Number: ");
    inputAppointment.patientNumber = inputIntPositive();
    patientNumberExist = findPatientIndexByPatientNum(inputAppointment.patientNumber, patients, maxPatient);

    if (patientNumberExist == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {

        // Get date
        getDate(&inputAppointment.date);

        // Check Appointment valid or not?
        while (validAppointment == 0 && i < maxAppointments)
        {
            if ((appointments[i].patientNumber == inputAppointment.patientNumber) && (appointments[i].date.day == inputAppointment.date.day) && (appointments[i].date.month == inputAppointment.date.month) && (appointments[i].date.year == inputAppointment.date.year))
            {
                validAppointment = 1;
            }
            i++;
        }
        i = i - 1;

        if (i >= 0)
        {
            printf("\n");

            displayPatientData(&patients[patientNumberExist], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {
                appointments[i].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }
            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
}

// Get Patient Index in patient array
void getPatientIndex(struct Patient *patient, int max, int *patientIndex)
{
    int editPatientNimber = 0;

    printf("Enter the patient number: ");
    editPatientNimber = inputInt();
    printf("\n");
    *patientIndex = findPatientIndexByPatientNum(editPatientNimber, patient, max);
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int searchPatientNumber, result;
    printf("Search by patient number: ");
    searchPatientNumber = inputInt();
    result = findPatientIndexByPatientNum(searchPatientNumber, patient, max);
    printf("\n");
    if (result != -1)
    {
        displayPatientData(&patient[result], FMT_FORM);
    }
    else
    {
        puts("*** No records found ***");
    }
    printf("\n");
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int result = 1, i, find = 0;
    char searchPhoneNumber[PHONE_LEN + 1];
    printf("Search by phone number: ");
    inputCString(searchPhoneNumber, 10, 10);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        result = strcmp(patient[i].phone.number, searchPhoneNumber);
        if (result == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            find = 1;
        }
    }

    if (find == 0)
    {
        printf("\n");
        puts("*** No records found ***");
    }
    printf("\n");
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, nextPatientNumber = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > nextPatientNumber)
        {
            nextPatientNumber = patient[i].patientNumber;
        }
    }
    return nextPatientNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i = -1, searchPatientNumber = patientNumber;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == searchPatientNumber)
        {
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient *patient)
{
    printf("Patient Data Input\n"
           "------------------\n"
           "Number: %05d\n",
           patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone *phone)
{
    int choice;

    printf("Phone Information\n"
           "-----------------\n"
           "How will the patient like to be contacted?\n"
           "1. Cell\n"
           "2. Home\n"
           "3. Work\n"
           "4. TBD\n"
           "Selection: ");

    choice = inputIntRange(0, 4);
    printf("\n");
    switch (choice)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;

    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;

    case 4:
        strcpy(phone->description, "TBD");
        break;

    default:
        puts("Error!");
        break;
    }
    if (choice == 1 || choice == 2 || choice == 3)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        printf("\n");
    }
}

// Get user input for Date
void getDate(struct Date *date)
{
    int lastDay = 0;
    printf("Year        : ");
    date->year = inputIntPositive();
    printf("Month (1-12): ");
    date->month = inputIntRange(1, 12);
    printf("Day (1-");
    switch (date->month)
    {
    case 2:
        if ((date->year) % 4 == 0)
        {
            lastDay = 29;
        }
        else
        {
            lastDay = 28;
        }

        break;
    case 4:
    case 6:
    case 9:
    case 11:
        lastDay = 30;
        break;
    default: // 1, 3, 5, 7, 8, 10, 12
        lastDay = 31;
        break;
    }
    printf("%d)  : ", lastDay);
    date->day = inputIntRange(1, lastDay);
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char *datafile, struct Patient patients[], int max)
{
    FILE *fp = NULL;
    int i, count = 0;
    fp = fopen(datafile, "r");
    if (fp == NULL)
    {
        printf("cannot open %s\n", datafile);
    }
    else
    {
        for (i = 0; i < max && !feof(fp); i++)
        {
            fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
            if (!feof(fp))
            {
                count++;
            }
        }
        fclose(fp);
        fp = NULL;
    }
    return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    FILE *fp = NULL;
    int i, count = 0;
    fp = fopen(datafile, "r");
    if (fp == NULL)
    {
        printf("Cannot open %s\n", datafile);
    }
    else
    {
        for (i = 0; i < max && !feof(fp); i++)
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d]", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            if (!feof(fp))
            {
                count++;
            }
        }
        fclose(fp);
        fp = NULL;
    }

    return count;
}
