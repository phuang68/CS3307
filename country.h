/*  Author:Pu Huang
    Student Number: 250986943
    Short Description: this is a header file that declares the country class that has the country's name, two-letter country code,
    and six statistical counts (new confirmed cases, new deaths, new recovered cases, total confirmed cases, total deaths, and total recovered cases). 
    Date: 2020-09-30
*/
#include <string>
#ifndef COUNTRY_H // include guard
#define COUNTRY_H
#endif

class Country{
    private: // Data members
        std::string cntryName;
        std::string cntryCode;
        int newConfirmed;
        int newDeath;
        int newRecovered;
        int totalConfirmed;
        int totalDeath;
        int totalRecovered;
    public:
        // Constructor 
        Country(std::string name, std::string code, int newC, int newD, int newRe, int totalC, int totalD, int totalRe);
        // Copy constructor
        Country(const Country &c);
        // Getters and setters for all the data members below
        std::string getCntryName();
        void setCntryName(std::string cntryName);

        std::string getCntryCode();
        void setCntryCode(std::string cntryCode);

        int getNewConfirmed();
        void setNewConfirmed(int newConfirmed);

        int getNewDeath();
        void setNewDeath(int newDeath);


        int getNewRecovered();
        void setNewRecovered(int newRecovered);


        int getTotalConfirmed();
        void setTotalConfirmed(int totalConfirmed);


        int getTotalDeath();
        void setTotalDeath(int totalDeath);


        int getTotalRecovered();
        void setTotalRecovered(int totalRecovered);

        //Destructor
        ~Country();
};