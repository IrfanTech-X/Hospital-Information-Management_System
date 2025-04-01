#include <iostream>
#include <string>
using namespace std;

int patientCount = 0;
int doctorCount = 0;
int appointmentCount=0;

struct PatientInfo
{
    string name;
    int id;
    int age;
    string disease;
    string contact;
} patient[250];

struct DoctorInfo
{
    string name;
    string degree;
    string specialty;
    int id;
    string contact;
} doctor[20];

struct AppointmentInfo {
    int appointmentId;
    int patientId;
    int doctorId;
    string date;
    string time;
} appointment[100];


void Main_Menu()
{

    cout<<"*=*=*GREEN UNIVERSITY HOSPITAL*=*=*"<<endl;
    cout<<"\n"<<endl;

    cout << "=== Hospital Information Management System ===" <<endl;
    cout<<"__________________________________________________"<<endl;
    cout<<"\n"<<endl;

    cout<<"1. Hospital's Information."<<endl;
    cout<<"2. Patient Management."<<endl;
    cout<<"3. Doctor Management."<<endl;
    cout<<"4. Appointment Management"<<endl;
    cout<<"5. Medical Reports"<<endl;
    cout<<"6. Billing Management"<<endl;

    cout<<"7. Exit"<<endl;

}



void Hospital_Information()
{
    cout<<"\n"<<endl;
    cout<<"GREEN UNIVERSITY HOSPITAL"<<endl;
    cout<<"Purbachal American City, Kanchan, Rupgonj."<<endl;
    cout<<"\n"<<endl;

    cout<<"### More than 25+ Specialized Doctor Available 24/7 For Service"<<endl;
    cout<<"### More than 10+ ICU Available"<<endl;
    cout<<"### More than 100+ Wards Available"<<endl;
    cout<<"### More than 120+ Nurses and Ward Boy's are ready 24/7 For Service"<<endl;
    cout<<"### Has More than 24+ Ambulances for Emergency Support"<<endl;
    cout<<"### A Huge Medical Store Where almost every medicine are available  "<<endl;
    cout<<"### A clean big Cafeteria for Food  Services and Many More!!!!! "<<endl;
    cout<<"\n"<<endl;


    cout<<"Contact Number : 01354356520 \nContact Email : Guh@gmail.com"<<endl;
    cout<<"\n"<<endl;


}
void Patient_Management()
{
    int option;
    cout << "Patient Management: " << endl;
    cout << "1. Add New Patient" << endl;
    cout << "2. Update Patient Information" << endl;
    cout << "3. View Patient Information" << endl;
    cout << "4. Delete Patient Record" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        if (patientCount >= 120)
        {
            cout << "Patient list is full!" << endl;
            break;
        }
        else
        {
            cout << "Enter Patient's Name: ";
            cin.ignore();
            getline(cin, patient[patientCount].name);
            cout << "Enter Patient Age: ";
            cin >> patient[patientCount].age;
            cin.ignore(); // Clear the newline character from the buffer
            cout << "Enter Name of Disease: ";
            getline(cin, patient[patientCount].disease);
            cout << "Enter Contact Number/Email: ";
            getline(cin, patient[patientCount].contact);
            patient[patientCount].id = 1000 + patientCount; // Assign a unique ID
            cout << "Patient " << patient[patientCount].name << " added successfully with ID: " << patient[patientCount].id << endl;
            patientCount++;
            break;
        }
    }
    case 2:
    {
        int patientId;
        cout << "Enter Patient ID to update: ";
        cin >> patientId;
        bool found = false;
        for (int i = 0; i < patientCount; i++)
        {
            if (patient[i].id == patientId)
            {
                found = true;
                cout << "Updating information for Patient ID: " << patientId << endl;
                cout << "Enter Patient's Name: ";
                cin.ignore();
                getline(cin, patient[i].name);
                cout << "Enter Patient Age: ";
                cin >> patient[i].age;
                cin.ignore();
                cout << "Enter Name of Disease: ";
                getline(cin, patient[i].disease);
                cout << "Enter Contact Number: ";
                getline(cin, patient[i].contact);
                cout << "Patient information updated successfully!" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Patient ID not found." << endl;
        }
        break;
    }
    case 3:
    {
        int patientId;
        cout << "Enter Patient ID to view: ";
        cin >> patientId;
        bool found = false;
        for (int i = 0; i < patientCount; i++)
        {
            if (patient[i].id == patientId)
            {
                found = true;
                cout << "Displaying information for Patient ID: " << patientId << endl;
                cout << "Name: " << patient[i].name << endl;
                cout << "Age: " << patient[i].age << endl;
                cout << "Disease: " << patient[i].disease << endl;
                cout << "Contact: " << patient[i].contact << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Patient ID not found." << endl;
        }
        break;
    }
    case 4:
    {
        int patientId;
        cout << "Enter Patient ID to delete: ";
        cin >> patientId;
        bool found = false;
        for (int i = 0; i < patientCount; i++)
        {
            if (patient[i].id == patientId)
            {
                found = true;
                for (int j = i; j < patientCount - 1; j++)
                {
                    patient[j] = patient[j + 1];
                }
                patientCount--;
                cout << "Patient record deleted successfully!" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Patient ID not found." << endl;
        }
        break;
    }
    default:
        cout << "Invalid option. Please try again." << endl;
    }
    cout << "\n" << endl;
}

void Doctor_Management()
{
 int option;
    cout << "Doctor Management: " << endl;
    cout << "1. Add New Doctor" << endl;
    cout << "2. Update Doctor Information" << endl;
    cout << "3. View Doctor Information" << endl;
    cout << "4. Delete Doctor Record" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            if (doctorCount >= 20) {
                cout << "Doctor list is full!" << endl;
                break;
            }

            cout << "Enter Doctor's Name: ";
            cin.ignore();
            getline(cin, doctor[doctorCount].name);
            cout << "Enter Doctor's Degree: ";
            getline(cin, doctor[doctorCount].degree);
            cout << "Enter Doctor's Specialty: ";
            getline(cin, doctor[doctorCount].specialty);
            cout << "Enter Contact Number: ";
            getline(cin, doctor[doctorCount].contact);
            doctor[doctorCount].id = 2000 + doctorCount; // Assign a unique ID
            cout << "Doctor " << doctor[doctorCount].name << " added successfully with ID: " << doctor[doctorCount].id << endl;
            doctorCount++;
            break;
        }
        case 2: {
            int doctorId;
            cout << "Enter Doctor ID to update: ";
            cin >> doctorId;
            bool found = false;
            for (int i = 0; i < doctorCount; i++) {
                if (doctor[i].id == doctorId) {
                    found = true;
                    cout << "Updating information for Doctor ID: " << doctorId << endl;
                    cout << "Enter Doctor's Name: ";
                    cin.ignore();
                    getline(cin, doctor[i].name);
                    cout << "Enter Doctor's Degree: ";
                    getline(cin, doctor[i].degree);
                    cout << "Enter Doctor's Specialty: ";
                    getline(cin, doctor[i].specialty);
                    cout << "Enter Contact Number: ";
                    getline(cin, doctor[i].contact);
                    cout << "Doctor information updated successfully!" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Doctor ID not found." << endl;
            }
            break;
        }
        case 3: {
            int doctorId;
            cout << "Enter Doctor ID to view: ";
            cin >> doctorId;
            bool found = false;
            for (int i = 0; i < doctorCount; i++) {
                if (doctor[i].id == doctorId) {
                    found = true;
                    cout << "Displaying information for Doctor ID: " << doctorId << endl;
                    cout << "Name: " << doctor[i].name << endl;
                    cout << "Degree: " << doctor[i].degree << endl;
                    cout << "Specialty: " << doctor[i].specialty << endl;
                    cout << "Contact: " << doctor[i].contact << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Doctor ID not found." << endl;
            }
            break;
        }
        case 4: {
            int doctorId;
            cout << "Enter Doctor ID to delete: ";
            cin >> doctorId;
            bool found = false;
            for (int i = 0; i < doctorCount; i++) {
                if (doctor[i].id == doctorId) {
                    found = true;
                    for (int j = i; j < doctorCount - 1; j++) {
                        doctor[j] = doctor[j + 1];
                    }
                    doctorCount--;
                    cout << "Doctor record deleted successfully!" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Doctor ID not found." << endl;
            }
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
    }
    cout << "\n" << endl;
}
void Appointment_Management()
{
 int option;
    cout << "Appointment Management: " << endl;
    cout << "1. Add New Appointment" << endl;
    cout << "2. Update Appointment Information" << endl;
    cout << "3. View Appointment Information" << endl;
    cout << "4. Cancel Appointment" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            if (appointmentCount >= 100) {
                cout << "Appointment list is full!" << endl;
                break;
            }else{
            cout << "Enter Patient ID: ";
            cin >> appointment[appointmentCount].patientId;
            cout << "Enter Doctor ID: ";
            cin >> appointment[appointmentCount].doctorId;
            cout << "Enter Appointment Date (DD/MM/YYYY): ";
            cin.ignore();
            getline(cin, appointment[appointmentCount].date);
            cout << "Enter Appointment Time (HH:MM): ";
            getline(cin, appointment[appointmentCount].time);
            appointment[appointmentCount].appointmentId = 3000 + appointmentCount; // Assign a unique ID
            cout << "Appointment added successfully with ID: " << appointment[appointmentCount].appointmentId << endl;
            appointmentCount++;
            break;
            }
        }
        case 2: {
            int appointmentId;
            cout << "Enter Appointment ID to update: ";
            cin >> appointmentId;
            bool found = false;
            for (int i = 0; i < appointmentCount; i++) {
                if (appointment[i].appointmentId == appointmentId) {
                    found = true;
                    cout << "Updating information for Appointment ID: " << appointmentId << endl;
                    cout << "Enter Patient ID: ";
                    cin >> appointment[i].patientId;
                    cout << "Enter Doctor ID: ";
                    cin >> appointment[i].doctorId;
                    cout << "Enter Appointment Date (DD/MM/YYYY): ";
                    cin.ignore();
                    getline(cin, appointment[i].date);
                    cout << "Enter Appointment Time (HH:MM): ";
                    getline(cin, appointment[i].time);
                    cout << "Appointment information updated successfully!" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Appointment ID not found." << endl;
            }
            break;
        }
        case 3: {
            int appointmentId;
            cout << "Enter Appointment ID to view: ";
            cin >> appointmentId;
            bool found = false;
            for (int i = 0; i < appointmentCount; i++) {
                if (appointment[i].appointmentId == appointmentId) {
                    found = true;
                    cout << "Displaying information for Appointment ID: " << appointmentId << endl;
                    cout << "Patient ID: " << appointment[i].patientId << endl;
                    cout << "Doctor ID: " << appointment[i].doctorId << endl;
                    cout << "Date: " << appointment[i].date << endl;
                    cout << "Time: " << appointment[i].time << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Appointment ID not found." << endl;
            }
            break;
        }
        case 4: {
            int appointmentId;
            cout << "Enter Appointment ID to delete: ";
            cin >> appointmentId;
            bool found = false;
            for (int i = 0; i < appointmentCount; i++) {
                if (appointment[i].appointmentId == appointmentId) {
                    found = true;
                    for (int j = i; j < appointmentCount - 1; j++) {
                        appointment[j] = appointment[j + 1];
                    }
                    appointmentCount--;
                    cout << "Appointment deleted successfully!" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Appointment ID not found." << endl;
            }
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
    }
    cout << "\n" << endl;

}

void Billing_Management()
{
    cout<<"\n"<<endl;
    cout<<"This Section is UNDER DEVELOPMENT!!!"<<endl;
    cout<<"\n"<<endl;
}
void Report()
{
    cout<<"\n"<<endl;
    cout<<"This Section is UNDER DEVELOPMENT!!!"<<endl;
    cout<<"\n"<<endl;

}

int main()
{
    int choice;

    while(true)
    {

        Main_Menu();

        cout<<"Enter your choice : "<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
            Hospital_Information();
            break;
        case 2:
            Patient_Management();
            break;
        case 3:
            Doctor_Management();
            break;
        case 4:
            Appointment_Management();
            break;
        case 5:
            Report();
            break;
        case 6:
            Billing_Management();
            break;
        case 7:
            cout<<"\n"<<endl;
            cout << "Exiting the system. Goodbye!" << endl;

            return 0;
        default:
            cout << "Invalid choice. Please try again." <<endl;
            cout<<"\n"<<endl;

        }

    }



    return 0;
}
