/*  Author:Pu Huang
    Student Number: 250986943
    Short Description: this is a c++ file that takes in a processed csv file which contains covid stats, 
    and users can select desired options and order to decide the graph display which shows top/bottom 10
    records of the selected stat. In the graph, it shows the country code and their corresponding cases 
    represented by #, the users' choice and the approximate number of each #
    Date: 2020-09-30
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include "country.h"
#include "support_func.h"

using namespace std;


int main()
{ 
    vector<Country> countryVec; // Used to store all the country objects in the file
    // Read file
    string line; // Used to read a line of the csv file
    fstream covidFile; // Used to open the input csv file
    char file[256]; // Take in the file that the user typed 
    int data_choice; // Take in a number that's listed in the selected covid data option below
    string data_name; // Used to indicate the name of the data option
    int character_proximity; // Store the number of how many cases a # symbol represent
    int sort_choice; // Take in a number that's listed in the selected order option below

    cout << "Provide the csv file name: ";
    cin.getline(file, 256); // Take in user's input and send it to the variable file
    covidFile.open(file); 
    if(!covidFile.is_open()){ // Check if the user input is valid, if not terminate the program
        cerr << "The input file " << file << " doesn't exist and the program is terminated" << '\n';
        return 0;
    }

    cout << "---------------------------------------------------------------------------" << '\n';
    cout << "What data would you like to sort in the file and get the top/bottom 10 records? " << '\n';
    cout << "1) New confirmed case" << '\n';
    cout << "2) New death case" << '\n';
    cout << "3) New recovered case" << '\n';
    cout << "4) Total confirmed case" << '\n';
    cout << "5) Total death case" << '\n';
    cout << "6) Total recovered case" << '\n';
    cout << "---------------------------------------------------------------------------" << '\n';
    do{
        data_choice = inputNumber(); // Use inputeNumber function to ensure user's input is a positive number
    } while (data_choice > 6 || data_choice <= 0); // Checked the input number falls into the numbers provided above

    cout << "---------------------------------------------------------------------------" << '\n';
    cout << "In what order would you like the records sorted?" << '\n';
    cout << "1) Ascending order" << '\n';
    cout << "2) Descending order" << '\n';
    cout << "---------------------------------------------------------------------------" << '\n';
    do{
        sort_choice = inputNumber(); // Use inputeNumber function to ensure user's input is a positive number
    } while (sort_choice > 2 || sort_choice <= 0); // Checked the input number falls into the numbers provided above

    if(covidFile.is_open()){
        getline(covidFile, line); // Remove the first line which doesn't contain desired data
        while(getline(covidFile, line)){
            // declare the variables used to store corresponding data from the file to make a country object
            string cntryName;
            string cntryCode;
            string cntryNew;
            string cntryTotl;
            int newConfirmed;
            int newDeath;
            int newRecovered;
            int totalConfirmed;
            int totalDeath;
            int totalRecovered;

            // Parse file and create country object and put them in a country vector
            vector<string> countryData = parseString(line);
            
            cntryName = countryData.at(0); // The first string has the name of the country
            cntryCode = countryData.at(1); // The second string has the country code
            cntryNew = countryData.at(3); // The 4th string has all the new case numbers
            cntryTotl = countryData.at(5); // The 6th string has all the total case numbers

            vector<int> newCaseData = parseNumber(cntryNew);// Parse the 4th string and put each new case info in the integer vector
            vector<int> totlCaseData = parseNumber(cntryTotl); // Parse the 6th string and put each new case info in the integer vector
            newConfirmed = newCaseData.at(0); // The first integer in new case vector is the number of new confirmed cases
            newDeath = newCaseData.at(1);     // The second integer in new case vector is the number of new death cases
            newRecovered = newCaseData.at(2); // The third integer in new case vector is the number of new recovered cases
            totalConfirmed = totlCaseData.at(0);// The first integer in total case vector is the number of total confirmed cases
            totalDeath = totlCaseData.at(1);// The second integer in total case vector is the number of total death cases
            totalRecovered = totlCaseData.at(2); // The third integer in total case vector is the number of total recovered cases

            Country country(cntryName, cntryCode, newConfirmed, newDeath, newRecovered, totalConfirmed, totalDeath, totalRecovered); // Create a country with the processd variables declared above
            countryVec.push_back(country); // Put the country object in the counrty vector
        }
    }
    
    vector<int> dataVec;// Used to store all the numbers of covid case info
    switch (data_choice) // Sort the country vector based on user's selection
    {
    case 1: // if user's choice is new confirmed cases
        sort(countryVec.begin(), countryVec.end(), nc_less_than);
        data_name = "New Confirmed Cases";
        for (auto i : countryVec) // copy the numbers of new confirmed cases from the class objects to the integer vector
            dataVec.push_back(i.getNewConfirmed());
        break;
    case 2: // if user's choice is new death cases
        sort(countryVec.begin(), countryVec.end(), nd_less_than);
        data_name = "New Death Cases";
        for (auto i : countryVec) // copy the numbers of new death cases from the class objects to the integer vector
            dataVec.push_back(i.getNewDeath());
        break;
    case 3: // if user's choice is new recovered cases
        sort(countryVec.begin(), countryVec.end(), nr_less_than);
        data_name = "New Recovered Cases";
        for (auto i : countryVec) // copy the numbers of new recovered cases from the class objects to the integer vector
            dataVec.push_back(i.getNewRecovered());
        break;
    case 4: // if user's choice is total confirmed cases
        sort(countryVec.begin(), countryVec.end(), tc_less_than);
        data_name = "Total Confirmed Cases";
        for (auto i : countryVec) // copy the numbers of  total confirmed cases from the class objects to the integer vector
            dataVec.push_back(i.getTotalConfirmed());
        break;
    case 5: // if user's choice is total death cases
        sort(countryVec.begin(), countryVec.end(), td_less_than);
        data_name = "Total Death Cases";
        for (auto i : countryVec) // copy the numbers of total death cases from the class objects to the integer vector
            dataVec.push_back(i.getTotalDeath());
        break;
    case 6: // if user's choice is total recovered cases
        sort(countryVec.begin(), countryVec.end(), tr_less_than);
        data_name = "Total Recovered Cases";
        for (auto i : countryVec) // copy the numbers of total recovered cases from the class objects to the integer vector
            dataVec.push_back(i.getTotalRecovered());
        break;
    }

    character_proximity = calculate_proximity(dataVec, sort_choice);// With the above process, use the function calculate_proximity to determine how many cases a character represents in the output graph

    if(sort_choice == 2) // if the user wants the grpah displays desired covid info in descending order
        reverse(countryVec.begin(), countryVec.end()); // We reverse the sorted country vector to make it in descending order
    
    // Output a graph that shows desired outcome of top/bottom 10 countries
    produceGraph(countryVec,data_choice, character_proximity, data_name);
    return 0;
}