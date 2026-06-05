#include <iostream>
using namespace std;
int main()
{
    char passengerNames[500] = "\0";
    char passengerIDs[500] = "\0";
    int passengerAges[10];
    char passengerContacts[500] = "\0";
    int passengerCount = 0;


    char flightNames[200] = "PK101\0PK202\0Pk303\0\0";
    char flightDest[200] = "Lahore\0Karachi\0Hyderabad\0\0";
    int flightSeats[3] = { 50, 40, 30 };
    char trainNames[200] = "TR0095\0TR0180\0TR0001\0\0";
    char trainRoutes[200] = "LHR-KHI\0LHR-KHI\0PSH-KHI\0\0";

    int trainSeats[3] = { 100, 80, 60 };
    int choice;
    do {
        cout << "\n MAIN MENU\n";
        cout << "1. Display Flights & Trains\n";
        cout << "2. Add Passenger Record\n";
        cout << "3. Book Ticket\n";
        cout << "4. Search Passenger\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n--- Flights ---\n";
            int i = 0, index = 0;
            while (!(flightNames[i] == '\0' && flightNames[i + 1] == '\0'))
            {
                cout << "Flight: ";
                while (flightNames[i] != '\0')
                {
                    cout << flightNames[i++];
                }
                cout << " Destination: ";

                int j = 0;
                while (flightDest[j] != '\0')
                {
                    cout << flightDest[j++];
                }
                cout << " Seats: " << flightSeats[index] << endl;

                i++;
                while (flightDest[j] != '\0')
                    j++;
                index++;
            }
            cout << "\n Trains \n";
            i = 0; index = 0;
            while (!(trainNames[i] == '\0' && trainNames[i + 1] == '\0'))
            {
                cout << "Train: ";
                while (trainNames[i] != '\0')
                {
                    cout << trainNames[i++];
                }
                cout << " Route: ";

                int j = 0;
                while (trainRoutes[j] != '\0')
                {
                    cout << trainRoutes[j++];
                }
                cout << "  Seats: " << trainSeats[index] << endl;

                i++;
                while (trainRoutes[j] != '\0') j++;
                j++;
                index++;
            }
        }
        else if (choice == 2)
        {
            if (passengerCount >= 10)
            {
                cout << "Passenger limit reached!\n";
            }
            else
            {
                char name[30], id[20], contact[20];
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Age: ";
                cin >> passengerAges[passengerCount];
                cout << "Enter Contact: ";
                cin >> contact;

                int i = 0, j = 0;

                while (!(passengerNames[i] == '\0' && passengerNames[i + 1] == '\0'))
                    i++;
                while (name[j] != '\0') passengerNames[i++] = name[j++];
                passengerNames[i++] = '\0';
                passengerNames[i] = '\0';

                i = 0; j = 0;
                while (!(passengerIDs[i] == '\0' && passengerIDs[i + 1] == '\0'))
                    i++;
                while (id[j] != '\0') passengerIDs[i++] = id[j++];
                passengerIDs[i++] = '\0';
                passengerIDs[i] = '\0';

                i = 0; j = 0;
                while (!(passengerContacts[i] == '\0' && passengerContacts[i + 1] == '\0'))
                    i++;
                while (contact[j] != '\0') passengerContacts[i++] = contact[j++];
                passengerContacts[i++] = '\0';
                passengerContacts[i] = '\0';

                passengerCount++;
                cout << "Passenger Added Successfully!\n";
            }
        }
        else if (choice == 3)
        {
            int type;
            cout << "1. Air\n2. Rail\nSelect: ";
            cin >> type;

            if (type == 1)
            {
                int f;
                cout << "Select Flight (0-2): ";
                cin >> f;
                if (flightSeats[f] > 0)
                {
                    flightSeats[f]--;
                    cout << "Flight Ticket Booked!\n";
                }
                else
                {
                    cout << "No seats available!\n";
                }
            }
            else if (type == 2)
            {
                int t;
                cout << "Select Train (0-2): ";
                cin >> t;
                if (trainSeats[t] > 0)
                {
                    trainSeats[t]--;
                    cout << "Train Ticket Booked!\n";
                }
                else
                {
                    cout << "No seats available!\n";
                }
            }
        }
        else if (choice == 4)
        {
            char searchID[20];
            cout << "Enter ID to search: ";
            cin >> searchID;

            int i = 0, found = 0;
            while (!(passengerIDs[i] == '\0' && passengerIDs[i + 1] == '\0'))
            {
                int j = 0;
                while (passengerIDs[i + j] == searchID[j] && passengerIDs[i + j] != '\0' && searchID[j] != '\0')
                    j++;

                if (passengerIDs[i + j] == '\0' && searchID[j] == '\0')
                {
                    found = 1;
                    break;
                }
                while (passengerIDs[i] != '\0'); 
                i++;
            }

            if (found)
                cout << "Passenger Found!\n";
            else
                cout << "Passenger Not Found!\n";
        }

    } while (choice != 5);

    cout << "THANKYOU FOR USING PAKISTAN AIRLINE AND RAILWAY MANAGEMENT\n";
    return 0;
}