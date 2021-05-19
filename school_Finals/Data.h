//DONE BY THE CORNDOGIRLS:  ERIN CORDERO, MICIELLA DECANO, DANA HUANG
#pragma once
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;
namespace ns {

    class Movies {
    private:
        struct ListNode {
            string movieTitle;
            string movieGenre;
            string movieProduction;
            string imageFilename;
            int movieID;
            int movieCopies;
            struct ListNode* next;
        };
        ListNode* head;
        ofstream editVideoContent;
        ifstream getVideoContent;

        struct rent {
            rent(int cID, int id) : customID(cID), movieID(id) {}
            int movieID;
            int customID;
        };
    public:
        Movies();
        ~Movies();

        int genAction, genComedy, genHorror, genRomance, genSciFi, genOthers;
        void NewMovie(int ID, string title, string genre, string production, int copies, string fileName);
        int idGen();
        void rentVid(); 
        void returnMovie(); 
        void showMovieDetails(int movieCode);
        void displayAllMovies();

        void checkMovieAvailability(int id);
        void rentedList();
        vector <rent> rentedMovies;
    };

    class customerClass {
    private:
        struct customers {
            customers(unsigned int i, std::string n, std::string a) : customerID(i), customerName(n), customerAddress(a) {}
            unsigned int customerID;
            std::string customerAddress;
            std::string customerName;
        };
        int latestID;
        ofstream editCustomerContent;

    public:
        vector<customers> customerVectors;
        customerClass();
        void addCustomer();
        void showCustomerDetails();
        void displayAllCustomers();
    };

}