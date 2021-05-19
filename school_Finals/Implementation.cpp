//DONE BY THE CORNDOGIRLS:  ERIN CORDERO, MICIELLA DECANO, DANA HUANG
#include <iostream>
#include "Data.h"
#include <string>
#include <vector>
using namespace std;

namespace ns {

    //ALL CONSTRUCTORS:
    Movies::Movies() {
        head = nullptr;
        ListNode* newNode, * nodePtr;
        getVideoContent.open("movies.txt");
        string tempNum1, trash; //store ints from txt file
        int tempNum2, tempNum3; //turn string from txt file into int (e.g. copies, movie id)

        if (!getVideoContent)
            cout << "File cannot be opened.";
        else {
            while (!getVideoContent.eof()) {

                newNode = new ListNode;

                getline(getVideoContent, tempNum1);
                if (tempNum1 == "")
                    break;
                tempNum1.erase(0, 10);
                tempNum2 = stoi(tempNum1);
                if (tempNum2 >= 100 && tempNum2 < 200) {
                    genAction = tempNum2;
                }
                else if (tempNum2 >= 200 && tempNum2 < 300) {
                    genComedy = tempNum2;
                }
                else if (tempNum2 >= 300 && tempNum2 < 400) {
                    genHorror = tempNum2;
                }
                else if (tempNum2 >= 400 && tempNum2 < 500) {
                    genRomance = tempNum2;
                }
                else if (tempNum2 >= 500 && tempNum2 < 600) {
                    newNode->movieID = tempNum2;
                    genSciFi = tempNum2;
                }
                else {
                    genOthers = tempNum2;
                }
                newNode->movieID = tempNum2;
                // getline(getVideoContent, trash); //cin.ignore()
                getline(getVideoContent, newNode->movieTitle);
                newNode->movieTitle.erase(0, 13);
                getline(getVideoContent, newNode->movieGenre);
                newNode->movieGenre.erase(0, 13);
                getline(getVideoContent, newNode->movieProduction);
                newNode->movieProduction.erase(0, 18);
                getline(getVideoContent, tempNum1);
                tempNum1.erase(0, 14);
                tempNum2 = stoi(tempNum1);
                newNode->movieCopies = tempNum2;
                getline(getVideoContent, newNode->imageFilename);
                newNode->imageFilename.erase(0, 13);
                getline(getVideoContent, trash);
                newNode->next = nullptr;

                if (!head) {
                    head = newNode;
                }
                else {
                    nodePtr = head;
                    while (nodePtr->next) {
                        nodePtr = nodePtr->next;
                    }
                    nodePtr->next = newNode;
                }
            } //END OF READING FILE
        }
        getVideoContent.close();
        getVideoContent.open("rentedMovieFile.txt");
        if (!getVideoContent)
            cout << "File Cannot Be Opened...";
        else {
            while (!getVideoContent.eof()) {
                getline(getVideoContent, tempNum1);
                if (tempNum1 == "")
                    break;
                tempNum1.erase(0, 13);
                tempNum2 = stoi(tempNum1);
                getline(getVideoContent, tempNum1);
                tempNum1.erase(0, 10);
                tempNum3 = stoi(tempNum1);
                getline(getVideoContent, trash);
                rentedMovies.emplace_back(tempNum2, tempNum3);
            }
        }
    }


    //END OF CONSTRUCTORS
    //MOVIE-RELATED FUNCTIONS:

    void Movies::NewMovie(int ID, string title, string genre, string production, int copies, string fileName) {
        ListNode* newNode, * nodePtr;

        newNode = new ListNode;
        newNode->movieID = ID;
        newNode->movieTitle = title;
        newNode->movieGenre = genre;
        newNode->movieProduction = production;
        newNode->movieCopies = copies;
        newNode->imageFilename = fileName;
        newNode->next = nullptr;

        if (!head)
            head = newNode;
        else {
            nodePtr = head;
            while (nodePtr->next)
                nodePtr = nodePtr->next;
            nodePtr->next = newNode;
        }
        cout << endl << "Movie has been successfully added!" << endl;

    }

    void Movies::displayAllMovies()
    {
        ListNode* nodePtr;
        if (head == nullptr)
            cout << "The movies are sold out, no movies in list." << endl;
        else {
            cout << "The movies in the list are: " << endl;
            nodePtr = head;
            while (nodePtr != nullptr) {
                for (int i = 0; i < 15; i++)
                    cout << "=*=";
                cout << endl;
                cout << "Movie ID        : " << nodePtr->movieID << endl;
                cout << "Movie Title     : " << nodePtr->movieTitle << endl;
                cout << "Movie Genre     : " << nodePtr->movieGenre << endl;
                cout << "Movie Production: " << nodePtr->movieProduction << endl;
                nodePtr = nodePtr->next;

                for (int i = 0; i < 15; i++)
                    cout << "=*=";
                cout << endl;
            }
        }
    }

    void Movies::showMovieDetails(int movieCode) {
        ListNode* nodePtr;
        int found = 0;
        nodePtr = head;
        while (nodePtr != nullptr) {
            if (nodePtr->movieID == movieCode) {
                cout << "Movie Found!" << endl << endl;
                cout << "Movie ID: " << nodePtr->movieID << endl;
                cout << "Movie Title: " << nodePtr->movieTitle << endl;
                cout << "Movie Genre: " << nodePtr->movieGenre << endl;
                cout << "Production: " << nodePtr->movieProduction << endl;
                cout << "Number of Copies: " << nodePtr->movieCopies << endl;
                string str = nodePtr->imageFilename;
                vector<char> picturePath(str.begin(), str.end());
                picturePath.push_back('\0');
                system(&picturePath[0]);
                found++;
                break;
            }
            else
                nodePtr = nodePtr->next;
        }
        if (found == 0)
            cout << "Movie not found..." << endl;
    }


    void Movies::checkMovieAvailability(int id) {
        ListNode* nodePtr;
        int found = 0;

        nodePtr = head;
        while (nodePtr != nullptr) {
            if (nodePtr->movieID == id) {
                cout << "Movie Found!" << endl;
                cout << "Movie ID: " << nodePtr->movieID << endl;
                cout << "Movie Title: " << nodePtr->movieTitle << endl;
                cout << "Movie Genre: " << nodePtr->movieGenre << endl;
                cout << "Production: " << nodePtr->movieProduction << endl;
                cout << "Number of Copies: " << nodePtr->movieCopies << endl;
                if (nodePtr->movieCopies > 0)
                    cout << "Availability: Movie is Available for Renting" << endl << endl;
                else
                    cout << "Availability: There are no Available Copies for Renting" << endl << endl;
                found++;
                break;
            }
            else
                nodePtr = nodePtr->next;
        }
        if (found == 0)
            cout << "Movie Not Found" << endl;
    }

    int Movies::idGen() {
        int c;
        system("cls");
        cout << "Enter the Movie's Genre" << endl;
        cout << "[1] Action" << endl;
        cout << "[2] Comedy" << endl;
        cout << "[3] Horror" << endl;
        cout << "[4] Romance" << endl;
        cout << "[5] Sci-Fi" << endl;
        cout << "[6] Others" << endl << endl;
        cout << "Input: ";
        cin >> c;
        switch (c) {
        case 1:
            ++genAction;
            return genAction;
        case 2:
            ++genComedy;
            return genComedy;
        case 3:
            ++genHorror;
            return genHorror;
        case 4:
            ++genRomance;
            return genRomance;
        case 5:
            ++genSciFi;
            return genSciFi;
        case 6:
            ++genOthers;
            return genOthers;
        default:
            cout << "Invalid Input" << endl;
            return 0;
        }
    }
    //END OF MOVIE-RELATED FUNCTIONS

    void Movies::rentVid() {
        customerClass holder;
        int movieID;
        int cusFound = 0;
        int movFound = 0;
        char ans;
        ListNode* h;
        // h = head;

        unsigned int id, y = 0;
        std::cout << "Customer ID: ";
        std::cin >> id;
        for (auto i = holder.customerVectors.begin(); i != holder.customerVectors.end(); ++i) {

            if (id == holder.customerVectors[y].customerID) {
                std::cout << holder.customerVectors[y].customerName << std::endl;
                std::cout << holder.customerVectors[y].customerAddress << std::endl;
                cusFound = 1;
                break;
            }
            y++;
        }

        if (!cusFound)
            std::cout << "\nCustomer not found\n";
        else {
            do {
                cout << "Enter Movie ID: ";
                cin >> movieID;
                h = head;
                while (h != nullptr) { //traverse linked list to return the movie
                    if (movieID == h->movieID) {
                        if (h->movieCopies > 0) {
                            cout << "\nMovie rented successfully! " << endl << endl;
                            h->movieCopies--;
                            cout << "Movie Title: " << h->movieTitle << endl;
                            cout << "Current Number of Copies: " << h->movieCopies << endl;
                            rentedMovies.emplace_back(id, h->movieID);
                            movFound++;
                            break;
                        }
                        else {
                            cout << "There are no available copies for this movie..." << endl;
                            movFound = 2;
                            break;
                        }
                    }
                    else {
                        h = h->next;
                    }
                   
                }//end of while 
                if (movFound == 0)
                    cout << "Movie not found..." << endl;
                cout << "Add another entry? [Y/N]: ";
                cin >> ans;
            } while (ans == 'y' || ans == 'Y');
        }
    }//end of rent

    void Movies::returnMovie() {
        customerClass holder;
        int movieID;
        int cusFound = 0;

        char ans;
        ListNode* h;
        unsigned int id, y = 0;
        std::cout << "Customer ID: ";
        std::cin >> id;
        for (auto i = holder.customerVectors.begin(); i != holder.customerVectors.end(); ++i) {
            if (id == holder.customerVectors[y].customerID) {
                std::cout << holder.customerVectors[y].customerName << std::endl;
                std::cout << holder.customerVectors[y].customerAddress << std::endl;
                cusFound = 1;
                break;
            }
            y++;
        }

        if (!cusFound)
            std::cout << "\nCustomer not found\n";
        else {
            do {
                int movFound = 0;
                cout << "Enter Movie ID: ";
                cin >> movieID;

                for (int z = 0; z < rentedMovies.size(); z++) {
                    if (id == rentedMovies[z].customID) {
                        if (movieID == rentedMovies[z].movieID) {
                            h = head;
                            while (h != nullptr) {
                                if (rentedMovies[z].movieID == h->movieID) {
                                    cout << "Movie returned successfully! " << endl << endl;
                                    h->movieCopies++;
                                    cout << "Movie Title: " << h->movieTitle << endl;
                                    cout << "Number of Copies: " << h->movieCopies << endl;
                                    rentedMovies.erase(rentedMovies.begin() + z);
                                    movFound++;
                                    break;
                                }
                                else {
                                    h = h->next;
                                }
                            }
                        }
                    }
                }
                if (movFound == 0)
                    cout << "Movie not found..." << endl;

                cout << "Return another movie? [Y/N]: ";
                cin >> ans;
            } while (ans == 'y' || ans == 'Y');
        }//end of else (if-else); else:customer found.
    }
    //END OF RETURN MOVIE

    //CONSTRUCTOR OF CUSTOMER CLASS
    customerClass::customerClass() {

        ifstream infile("customers.txt");
        string address, name, trash, tempNum1;
        int tempNum2;
        while (!infile.eof()) {
            getline(infile, tempNum1);
            if (tempNum1 == "")
                break;
            tempNum1.erase(0, 13);
            tempNum2 = stoi(tempNum1);
            latestID = tempNum2;
            getline(infile, name);
            name.erase(0, 6);
            getline(infile, address);
            address.erase(0, 9);
            getline(infile, trash); 

            customerVectors.emplace_back(latestID, name, address);
        }
    }

    void customerClass::addCustomer() {
        string name, address;
        latestID++; //get latest ID of auto-generated customers
        cout << "Customer ID: " << latestID << endl;
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Customer's Address: ";
        getline(cin, address);
        customerVectors.emplace_back(latestID, name, address); //add input to the vector

        editCustomerContent.open("customers.txt");

        int traverseVector = 0;
        for (auto i = customerVectors.begin(); i != customerVectors.end(); ++i) {
            editCustomerContent << "Customer ID: " << customerVectors[traverseVector].customerID << '\n';
            editCustomerContent << "Name: " << customerVectors[traverseVector].customerName << '\n';
            editCustomerContent << "Address: " << customerVectors[traverseVector].customerAddress << "\n";
            editCustomerContent << "===============================================" << endl;
            traverseVector++;
        }
        editCustomerContent.close();

        customerClass();

    }

    void customerClass::showCustomerDetails() {
        int found = 0;
        unsigned int id, y = 0;
        std::cout << "Customer ID: ";
        std::cin >> id;
        for (auto i = customerVectors.begin(); i != customerVectors.end(); ++i) {

            if (id == customerVectors[y].customerID) {
                std::cout << "Name: "<< customerVectors[y].customerName << std::endl;
                std::cout << "Address: " << customerVectors[y].customerAddress << std::endl << std::endl;
                found = 1;
                break;
            }
            y++;
        }

        if (!found)
            std::cout << "\nCustomer not found\n";

    }

    void customerClass::displayAllCustomers() {
        cout << "List of all Customers" << endl << endl;
        unsigned int x = 0;
        for (auto i = customerVectors.begin(); i != customerVectors.end(); ++i) {
            cout << "Customer ID: " << customerVectors[x].customerID << endl;
            cout << "Name: " << customerVectors[x].customerName << endl;
            cout << "Address: " << customerVectors[x].customerAddress << endl << endl;
            x++;
        }
    }

    void Movies::rentedList() {
        customerClass holder;
        ListNode* h;
        int cusFound = 0;
        int movFound = 0;
        unsigned int id, y = 0;
        std::cout << "Customer ID: ";
        std::cin >> id;

        for (auto i = holder.customerVectors.begin(); i != holder.customerVectors.end(); ++i) {

            if (id == holder.customerVectors[y].customerID) {
                std::cout << holder.customerVectors[y].customerName << std::endl;
                std::cout << holder.customerVectors[y].customerAddress << std::endl;
                cusFound = 1;
                cout << endl << "Movies Rented" << endl;
                cout << "Movie ID" << "-----" << "Movie Title" << endl;

                for (int x = 0; x < rentedMovies.size(); x++) {
                    h = head;
                    while (h != nullptr) {
                        if (rentedMovies[x].customID == id) {
                            if (rentedMovies[x].movieID == h->movieID) {
                                cout << rentedMovies[x].movieID << "          " << h->movieTitle << endl;
                                movFound++;
                            }
                        }

                        h = h->next;
                    }
                }
            }
            y++;
        }
        if (!cusFound)
            std::cout << "\nCustomer not found\n";
        else if (!movFound)
            cout << endl << "It seems that there are no rented videos for this customer ID..." << endl << endl;
        cout << endl;
    }

    //START OF DESTRUCTORS
    Movies::~Movies() {
        editVideoContent.open("movies.txt");

        ListNode* nodePtr, * nextNode;

        nodePtr = head;
        while (nodePtr != nullptr) {
            nextNode = nodePtr->next;
            editVideoContent << "Movie ID: " << nodePtr->movieID << endl;
            editVideoContent << "Movie Title: " << nodePtr->movieTitle << endl;
            editVideoContent << "Movie Genre: " << nodePtr->movieGenre << endl;
            editVideoContent << "Movie Production: " << nodePtr->movieProduction << endl;
            editVideoContent << "Movie Copies: " << nodePtr->movieCopies << endl;
            editVideoContent << "Movie Image: " << nodePtr->imageFilename << endl;
            editVideoContent << "===============================================" << endl;
            nodePtr = nextNode;
        }
        editVideoContent.close();

        int traverseVector = 0;
        editVideoContent.open("rentedMovieFile.txt");
        for (auto i = rentedMovies.begin(); i != rentedMovies.end(); ++i) {
            editVideoContent << "Customer ID: " << rentedMovies[traverseVector].customID << endl;
            editVideoContent << "Movie ID: " << rentedMovies[traverseVector].movieID << endl;
            editVideoContent << "===============================================" << endl;
            traverseVector++;
        }

        editVideoContent.close();

    }


}// end of namespace
