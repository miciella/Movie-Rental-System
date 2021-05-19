//DONE BY THE CORNDOGIRLS:  ERIN CORDERO, MICIELLA DECANO, DANA HUANG
#include <iostream>
#include "Data.h"
using namespace std;
using namespace ns;

int menu();
string genSelect(int id);

int main() {
    Movies list;
    customerClass cust;
    string title, genre, production, filename;
    string cusName, cusAdd;
    int ch, copies, id;

    do {
        ch = menu();
        system("cls");
        switch (ch) {
        case 1:
            id = list.idGen();
            cout << " << Insert a New Movie >> " << endl << endl;
            cout << "Movie ID" << endl;
            cout << id << endl;
            cout << "Movie Title  : ";
            cin.ignore();
            getline(cin, title);
            cout << "Movie Genre  : ";
            genre = genSelect(id);
            cout << genre << endl;
            cout << "Production Company : ";
            getline(cin, production);
            cout << "Number of Copies: ";
            cin >> copies;
            cout << "File Name of Movie Poster: ";
            cin.ignore();
            getline(cin, filename);
            list.NewMovie(id, title, genre, production, copies, filename);

            system("pause");
            break;

        case 2:
            cout << " << Rent a Movie >> " << endl << endl;
            list.rentVid();
            system("pause");
            break;


        case 3:
            cout << " << Return a Movie >> " << endl << endl;
            list.returnMovie();
            system("pause");
            break;

        case 4:
            int id;
            cout << " << Show Movie Details >> " << endl << endl;
            cout << "Enter Movie ID: ";
            cin >> id;
            list.showMovieDetails(id);
            system("pause");
            break;

        case 5:
            cout << " << Print Movie List >> " << endl;
            list.displayAllMovies();
            system("pause");
            break;

        case 6:
            cout << "<< Check Video Availability >> " << endl;
            cout << "Enter Video ID: ";
            cin >> id;
            list.checkMovieAvailability(id);
            system("pause");
            break;

        case 7:
            int choice;

            system("cls");
            cout << " << Customer Maintenance >>" << endl;
            cout << "[1] Add New Customer" << endl;
            cout << "[2] Show Customer Details" << endl;
            cout << "[3] Print All Customer Details" << endl;
            cout << "[4] List of Videos Rented by a Customer" << endl;
            cout << "Enter Choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "<< Add New Customer>> " << endl;
                cust.addCustomer();
                system("pause");
                break;
            case 2:
                cout << "<< Show Customer Details >>" << endl;

                cust.showCustomerDetails();
                system("pause");
                break;
            case 3:
                cout << "Print All Customer Details" << endl;
                cust.displayAllCustomers();
                system("pause");
                break;
            case 4:
                cout << "<< List of Movies Rented by a Customer >> " << endl;
                list.rentedList();
                system("pause");
                break;
            default:
                cout << "Invalid Input..." << endl;
            }

            break;

        case 8:
            cout << "You have exited the program" << endl;
            cout << "Thank you for using!" << endl;
            list.~Movies();
            exit(0);

        default:
            cout << "Invalid Input!" << endl << endl;
            break;
        }
    } while (ch != 8);
}

int menu()
{
    int ch;
    system("cls");
    cout << " << Movie Rental System >> " << endl << endl;
    cout << "[1] Insert a New Movie" << endl;
    cout << "[2] Rent a Movie" << endl;
    cout << "[3] Return a Movie" << endl;
    cout << "[4] Show Movie Details" << endl;
    cout << "[5] Print Movie List" << endl;
    cout << "[6] Check Video Availability" << endl;
    cout << "[7] Customer Maintenance" << endl;
    cout << "[8] Exit Program" << endl;
    cout << "Enter Choice: ";
    cin >> ch;
    return(ch);
}

string genSelect(int id) {
    if (id >= 100 && id < 200)
        return("Action");
    else if (id >= 200 && id < 300)
        return("Comedy");
    else if (id >= 300 && id < 400)
        return("Horror");
    else if (id >= 400 && id < 500)
        return("Romance");
    else if (id >= 500 && id < 600)
        return("Sci-Fi");
    else
        return("Others");
}
