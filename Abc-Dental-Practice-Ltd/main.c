#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include<conio.h>
// patient details structure
struct node {
	int ppsNumber;
	char firstName[20];
	char lastName[20];
	int yearBorn;
	char gender[7];
	char email[40];
	char nextOfKinName[30];
	char lastAppointment[10];
	int weight;// in kg
	float height;// in M
	char AllergiesToAnyMedications[20];
	char cigarettesSmokePerDay[30];
	char alcoholWouldYouDrinkPerWeek[30];
	char activity[30];

	struct node* NEXT;
};
// login information structure
struct user {
	char username[7];
	char password[7];
}*pUser;

// function redefnitions
void userlogin(void);
void menu();
void AddPatientAtStart(struct node** top);
void AddPatientAtEnd(struct node* top);
void DisplayAllPatients(struct node* top);
void DisplayPatientDetailsByPps(struct node* top, int pps);
void DisplayPatientDetailsByName(struct node* top, char lastName[20]);
int searchName(struct node* top, char lastName[20]);
void stringLwr(char *s);

//*******************************************************************************************************************
// main function
void main()
{
	userlogin();
}//main

//*******************************************************************************************************************
// add patient at start function
void AddPatientAtStart(struct node** top)
{
	struct node* newPatient;
	int pps;
	int option;
	char mail[30];
	printf("Please enter the Patient's PPS Number (must be unique)\n");
	scanf("%d", &pps);

	if (searchList(*top, pps) == 1)
	{
		printf("Sorry the pps already exists already exists\n");
		return;
	}

	newPatient = (struct node*)malloc(sizeof(struct node));

	printf("Please enter the Patient's First Name\n");
	scanf("%s", &newPatient->firstName);
	printf("Please enter the Patient's Second Name\n");
	scanf("%s", &newPatient->lastName);
	newPatient->ppsNumber = pps;
	printf("Please enter the Patient's Year Born\n");
	scanf("%d", &newPatient->yearBorn);
	printf("Please enter the Patient's Gender\npress 1 for Male\n2 for Female\n");
	scanf("%d", &option);
	if (option == 1)
	{

		strcpy(newPatient->gender, " Male");
	}
	else if (option == 2)
	{
		strcpy(newPatient->gender, "Female");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("Please enter the Patient's Gender\npress 1 for Male\n2 for Female\n");
		scanf("%d", &option);
	}
	printf("Please enter the Patient's Email Address (must contain an @, a full stop and a .com)\n");
	scanf("%s", &mail);
	if (((strchr(mail, '@')) && (strchr(mail, '.'))) && ((strstr(mail, ".com") != NULL) || (strstr(mail, ".ie") != NULL)))
	{
		strcpy(newPatient->email, mail);
	}
	else
	{
		printf("invalid Email Address");
		return;
	}
	printf("Please enter the Patient's Next of Kin Name \n");
	scanf("%s", &newPatient->nextOfKinName);
	printf("Please enter the Patient's Last Appointment\n");
	scanf("%s", &newPatient->lastAppointment);
	printf("Please enter the Patient's Weight in Kg\n");
	scanf("%d", &newPatient->weight);
	printf("Please enter the Patient's Height in m\n");
	scanf("%f", &newPatient->height);
	printf("Does the patient has any allergies to any medications?\npress 1 for yes\n2 for no\n");
	scanf("%d", &option);
	if (option == 1)
	{

		strcpy(newPatient->AllergiesToAnyMedications, " yes");
	}
	else if (option == 2)
	{
		strcpy(newPatient->AllergiesToAnyMedications, " no");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("Does the patient has any allergies to any medications?\npress 1 for yes\n2 for no\n");
		scanf("%d", &option);
	}
	printf("How many cigarettes would you smoke per day?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
	scanf("%d", &option);
	if (option == 1)
	{
		strcpy(newPatient->cigarettesSmokePerDay, " None");
	}
	else if (option == 2)
	{
		strcpy(newPatient->cigarettesSmokePerDay, " Less than ten cigarettes");
	}
	else if (option == 3)
	{
		strcpy(newPatient->cigarettesSmokePerDay, " More than ten cigarettes");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("How many cigarettes would you smoke per day?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
		scanf("%d", &option);
	}
	printf("How much alcohol would you drink per week?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
	scanf("%d", &option);
	if (option == 1)
	{
		strcpy(newPatient->alcoholWouldYouDrinkPerWeek, " None");
	}
	else if (option == 2)
	{
		strcpy(newPatient->alcoholWouldYouDrinkPerWeek, " Less than ten units");
	}
	else if (option == 3)
	{
		strcpy(newPatient->alcoholWouldYouDrinkPerWeek, " More than ten units");
	}
	else
	{
		printf("Invalid Option Try Again\n");
		printf("How much alcohol would you drink per week?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
		scanf("%d", &option);
	}
	printf("How often do you exercise?\npress 1 for never\n2 for less than twice per week\n3 for more than twice per week \n");
	scanf("%d", &option);
	if (option == 1)
	{
		strcpy(newPatient->activity, " Never");
	}
	else if (option == 2)
	{
		strcpy(newPatient->activity, " Less than twice per week");
	}
	else if (option == 3)
	{
		strcpy(newPatient->activity, " More than twice per week");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("How often do you exercise?\npress 1 for never\n2 for less than twice per week\n3 for more than twice per week \n");
		scanf("%d", &option);
	}
	
	newPatient->NEXT = *top;
	*top = newPatient;
}// add at start

//**************************************************************************************************************//
// search list function
int searchList(struct node* top, int searchID)
{
	int found = 0;
	struct node* temp = top;

	while (temp != NULL)
	{
		if (temp->ppsNumber == searchID)
		{
			found = 1;
			return found;
		}

		temp = temp->NEXT;
	}

	return found;
}// search list

//*********************************************************************************************************************
// search by entring name function
int searchName(struct node* top, char lastName[20])
{
	int found = 0;
	struct node* temp = top;

	while (temp != NULL)
	{
		stringLwr(temp->lastName);
		if (strcmp(temp->lastName, lastName)==0)
		{
			found = 1;
			return found;
		}
		
		temp = temp->NEXT;
	}

	return found;
}// search name

//***********************************************************************************************************************
// add patient at end of list function
void AddPatientAtEnd(struct node* top)
{
	struct node* temp = top;
	struct node* newPatient;
	int pps;
	int option;
	char mail[30];
	printf("Please enter the Patient's PPS Number (must be unique)\n");
	scanf("%d", &pps);

	if (searchList(top, pps) == 1)
	{
		printf("Sorry the pps already exists already exists\n");
		return;
	}

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newPatient = (struct node*)malloc(sizeof(struct node));

	printf("Please enter the Patient's First Name\n");
	scanf("%s", &newPatient->firstName);
	printf("Please enter the Patient's Second Name\n");
	scanf("%s", &newPatient->lastName);
	newPatient->ppsNumber = pps;
	printf("Please enter the Patient's Year Born\n");
	scanf("%d", &newPatient->yearBorn);
	printf("Please enter the Patient's Gender\npress 1 for Male\n2 for Female\n");
	scanf("%d", &option);
	if (option == 1)
	{

		strcpy(newPatient->gender, " Male");
	}
	else if (option == 2)
	{
		strcpy(newPatient->gender, "Female");
	}
	else
	{
		printf("Invalid Option Try Again\n");
		printf("Please enter the Patient's Gender\npress 1 for Male\n2 for Female\n");
		scanf("%d", &option);
	}
	printf("Please enter the Patient's Email Address (must contain an @, a full stop and a .com)\n");
	scanf("%s", &mail);
	if (((strchr(mail, '@')) && (strchr(mail, '.'))) && ((strstr(mail, ".com") != NULL) || (strstr(mail, ".ie") != NULL)))
	{
		strcpy(newPatient->email, mail);
	}
	else
	{
		printf("invalid Email Address");
		return;
	}
	printf("Please enter the Patient's Next of Kin Name \n");
	scanf("%s", &newPatient->nextOfKinName);
	printf("Please enter the Patient's Last Appointment\n");
	scanf("%s", &newPatient->lastAppointment);
	printf("Please enter the Patient's Weight in Kg\n");
	scanf("%d", &newPatient->weight);
	printf("Please enter the Patient's Height in cm\n");
	scanf("%f", &newPatient->height);
	printf("Does the patient has any allergies to any medications?\npress 1 for yes\n2 for no\n");
	scanf("%d", &option);
	if (option == 1)
	{

		strcpy(newPatient->AllergiesToAnyMedications, " yes");
	}
	else if (option == 2)
	{
		strcpy(newPatient->AllergiesToAnyMedications, " no");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("Does the patient has any allergies to any medications?\npress 1 for yes\n2 for no\n");
		scanf("%d", &option);
	}
	printf("How many cigarettes would you smoke per day?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
	scanf("%d", &option);
	if (option == 1)
	{
		strcpy(newPatient->cigarettesSmokePerDay, " None");
	}
	else if (option == 2)
	{
		strcpy(newPatient->cigarettesSmokePerDay, " Less than ten cigarettes");
	}
	else if (option == 3)
	{
		strcpy(newPatient->cigarettesSmokePerDay, " More than ten cigarettes");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("How many cigarettes would you smoke per day?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
		scanf("%d", &option);
	}
	printf("How much alcohol would you drink per week?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
	scanf("%d", &option);
	if (option == 1)
	{
		strcpy(newPatient->alcoholWouldYouDrinkPerWeek, " None");
	}
	else if (option == 2)
	{
		strcpy(newPatient->alcoholWouldYouDrinkPerWeek, " Less than ten units");
	}
	else if (option == 3)
	{
		strcpy(newPatient->alcoholWouldYouDrinkPerWeek, " More than ten units");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("How much alcohol would you drink per week?\nPress 1 for none\n2 for less than ten\n3 for more than ten\n");
		scanf("%d", &option);
	}
	printf("How often do you exercise?\npress 1 for never\n2 for less than twice per week\n3 for more than twice per week \n");
	scanf("%d", &option);
	if (option == 1)
	{
		strcpy(newPatient->activity, " Never");
	}
	else if (option == 2)
	{
		strcpy(newPatient->activity, " Less than twice per week");
	}
	else if (option == 3)
	{
		strcpy(newPatient->activity, " More than twice per week");
	}
	else
	{
		printf("Invalid Option Try Again");
		printf("How often do you exercise?\npress 1 for never\n2 for less than twice per week\n3 for more than twice per week \n");
		scanf("%d", &option);
	}

	newPatient->NEXT = NULL;
	temp->NEXT = newPatient;
}// adding employee at end

void DisplayAllPatients(struct node* top)
{
	struct node* temp = top;
	while (temp != NULL)
	{

		printf("PPS Number: %d\n", temp->ppsNumber);
		printf("First Name: %s\n", temp->firstName);
		printf("Second Name: %s\n", temp->lastName);
		printf("Year Born: %d\n", temp->yearBorn);
		printf("Gender: %s\n", temp->gender);
		printf("Email Address: %s\n", temp->email);
		printf("Next of Kin Name: %s\n", temp->nextOfKinName);
		printf("Last Appointment: %s\n", temp->lastAppointment);
		printf("Weight: %dKg\n", temp->weight);
		printf("Height: %.1fm\n", temp->height);
		printf("Does the patient has any allergies to any medications:%s\n", &temp->AllergiesToAnyMedications);
		printf("How many cigarettes would you smoke per day? :  %s\n", temp->cigarettesSmokePerDay);
		printf("How much alcohol would you drink per week? : %s\n", temp->alcoholWouldYouDrinkPerWeek);
		printf("How often do you exercise? :%s\n", temp->activity);
		temp = temp->NEXT;
	}
}// display list

// display Patient details matching the PPS number entered by user
void DisplayPatientDetailsByPps(struct node* top, int pps)
{
	struct node* temp = top;
	while (temp != NULL)
	{
		if (searchList(top, pps) == 0)
		{
			printf("No Records Found Make sure to enter correct Pps number\n");
			return;
		}
		if (temp->ppsNumber == pps)
		{
			printf("PPS Number: %d\n", temp->ppsNumber);
			printf("First Name: %s\n", temp->firstName);
			printf("Second Name: %s\n", temp->lastName);
			printf("Year Born: %d\n", temp->yearBorn);
			printf("Gender: %s\n", temp->gender);
			printf("Email Address: %s\n", temp->email);
			printf("Next of Kin Name: %s\n", temp->nextOfKinName);
			printf("Last Appointment: %s\n", temp->lastAppointment);
			printf("Weight: %dKg\n", temp->weight);
			printf("Height: %.1fm\n", temp->height);
			printf("Does the patient has any allergies to any medications:%s\n", &temp->AllergiesToAnyMedications);
			printf("How many cigarettes would you smoke per day? :  %s\n", temp->cigarettesSmokePerDay);
			printf("How much alcohol would you drink per week? : %s\n", temp->alcoholWouldYouDrinkPerWeek);
			printf("How often do you exercise? :%s\n", temp->activity);
		}
			temp = temp->NEXT;
	}
}// patient details by pps

// display Patient details matching the Patient Name entered by user
void DisplayPatientDetailsByName(struct node* top, char lastName[20])
{
	struct node* temp = top;
	while (temp != NULL)
	{
		if (searchName(top, lastName) == 0)
		{
			printf("No Records Found Make sure to enter correct name\n");
			return;
		}
		if (strcmp(temp->lastName, lastName) == 0)
		{
			printf("PPS Number: %d\n", temp->ppsNumber);
			printf("First Name: %s\n", temp->firstName);
			printf("Second Name: %s\n", temp->lastName);
			printf("Year Born: %d\n", temp->yearBorn);
			printf("Gender: %s\n", temp->gender);
			printf("Email Address: %s\n", temp->email);
			printf("Next of Kin Name: %s\n", temp->nextOfKinName);
			printf("Last Appointment: %s\n", temp->lastAppointment);
			printf("Weight: %dKg\n", temp->weight);
			printf("Height: %.1fm\n", temp->height);
			printf("Does the patient has any allergies to any medications:%s\n", &temp->AllergiesToAnyMedications);
			printf("How many cigarettes would you smoke per day? :  %s\n", temp->cigarettesSmokePerDay);
			printf("How much alcohol would you drink per week? : %s\n", temp->alcoholWouldYouDrinkPerWeek);
			printf("How often do you exercise? :%s\n", temp->activity);
		}
		temp = temp->NEXT;
	}
}// patient details by name

//****************************************************************************************************************
// to lower case function
void stringLwr(char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] + 32;
		}
		++i;
	}
}// stringlwr

//****************************************************************************************************************
// login fuction 
void userlogin(void) {

	// file variable
	FILE *fp;
	// initializing file variable
	char uName[7], pwd[7];
	int i, j=1;
	char c,ch;

	pUser = (struct user *)malloc(sizeof(struct user));

	printf("1. Login Through An Existing Account\n2. Create New account\n");
	scanf("%d", &i);
	//system("cls");
	switch (i) {
	case 1:
		if ((fp = fopen("login.dat", "r+")) == NULL) {
			if ((fp = fopen("login.dat", "w+")) == NULL) {
				printf("Could not open file\n");
				exit(1);
			}
		}
		printf("Username: ");
		scanf("%6s", uName);
		// getting password and masking with *
		printf("Password: ");
		for (j = 0; j < 6; j++)
		{
			ch = getch();
			pwd[j] = ch;
			ch = '*';
			printf("%c", ch);
		}
		pwd[j] = '\0';
		// reading from login file and comparing the username and passwords
		while (fread(pUser, sizeof(struct user), 1, fp) == 1) {
			if (strcmp(pUser->username, uName) == 0) {
				printf("\nMatch username\n");
				if (strcmp(pUser->password, pwd) == 0) {
					printf("Match password\n");
					printf("\n");
					printf("%s logged in\n\n",uName);
					menu();
				}
			}
		}
		break;

	case 2:
		do
		{
			if ((fp = fopen("login.dat", "a+")) == NULL) {
				if ((fp = fopen("login.dat", "w+")) == NULL) {
					printf("Could not open file\n");
					exit(1);
				}
			}
			printf("Choose A Username: ");
			scanf("%6s", pUser->username);
			printf("Choose A Password: ");
			scanf("%6s", pUser->password);
			fwrite(pUser, sizeof(struct user), 1, fp);
			printf("Add another account? (Y/N): ");
			scanf(" %c", &c);//skip leading whitespace
		} while (c == 'Y' || c == 'y');
		break;
	}
	free(pUser);//free allocated memory
	fclose(fp);
}// login function

//*************************************************************************************************************************
// menu options
void menu()
{
	struct node* headPtr = NULL;
	int choice;
	int chkId;
	printf("Please enter 1 to add Patient Details\n2 to display all Patient Details\n3 to display Patient details matching the PPS number or name entered by user\n-1 to exit the program: ");
	scanf("%d", &choice);
	while (choice != -1)
	{
		if (choice == 1)
		{
			if (headPtr == NULL)
				AddPatientAtStart(&headPtr);
			else
			{
				AddPatientAtEnd(headPtr);
			}//else
		}
		else if (choice == 2)
		{
			DisplayAllPatients(headPtr);
		}// choice 2 if
		else if (choice == 3)
		{
			printf("Please enter 1 to get patient details by entering its pps number\n\t\tor\nenter 2 to get patient details by entering its Name:\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				int pps;
				printf("Please enter the pps number of the patient to get its record: ");
				scanf("%d", &pps);
				DisplayPatientDetailsByPps(headPtr, pps);
			}// if by pps
			else if (choice == 2)
			{
				char name[20];
				printf("Please enter the last name of the patient to get its record: ");
				scanf("%s", &name);
				DisplayPatientDetailsByName(headPtr, name);
			}// if by pps
		}
		printf("Please enter 1 to add Patient Details\n2 to display all Patient Details\n3 to display Patient details matching the PPS number or name entered by user\n-1 to exit the program: ");
		scanf("%d", &choice);
	}//while
}

