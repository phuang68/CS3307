/*  Author:Pu Huang
    Student Number: 250986943
    Short Description: this is a c++ file that contains the functions used to compose a graph and sorting assistant functions.
    Date: 2020-09-30
*/
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include "country.h"
#include "support_func.h"

using namespace std;

/*Function name：parseString
 description：Take in a line of string and parse the string into a vector by double quote
 parameter descriptions： string
 return description：a vector of string
*/
vector<string> parseString(string str)
{
    vector<string> tokens;
    stringstream ss(str);
    string intermediate;

    while (getline(ss, intermediate, '"')) // parse each line by "
    {
        if (intermediate.length() > 1) // filter all the empty strings and strings with only a comma
            tokens.push_back(intermediate); // only push the strings with valid data
    }

    return tokens;
}

/*Function name：parseNumber
 description：Take in a line of string that contains the number of covid cases info and parse the string into a vector of numbers 
              so that they can be used to initialize a country object.
 parameter descriptions： string
 return description：a vector of int
*/
vector<int> parseNumber(string str)
{
    vector<int> int_tokens;
    stringstream ss(str); // the input string looks like ",12,123,5"
    string intermediate;
    int temp_int;

    while (getline(ss, intermediate, ',')) // parse each line by comma
    {
        if (intermediate.length() > 0) // filter the strings that are empty 
        {
            temp_int = stoi(intermediate); // transform the string to a number because the valid strings are numbers
            int_tokens.push_back(temp_int);
        }
    }

    return int_tokens;
}

/*Function name：inputNumber
 description：used to verify if the user's input is a positive number
 parameter descriptions： 
 return description：a positive number
*/
int inputNumber()
{
    {
        string str;
        regex regex_pattern("(\\+|-)?[[:digit:]]+");// define the regular expression pattern that only digits match
        do
        {
            cout << "Please input a valid option number: ";
            cin >> str;
        } while (!regex_match(str, regex_pattern));// as long as user's input isn't a positive number, it will keep asking the user for a valid input

        return stoi(str);
    }
}

// Sorting assistant functions
/*Function name：nc_less_than
 description：used for sorting countries by new confirmed cases
 parameter descriptions： 2 country objects
 return description：return true if the the first country has a lower number of new confirmed cases
*/
bool nc_less_than(Country &c1, Country &c2)
{
    return c1.getNewConfirmed() < c2.getNewConfirmed();
}

/*Function name：nd_less_than
 description：used for sorting countries by new death cases
 parameter descriptions： 2 country objects
 return description：return true if the the first country has a lower number of new death cases
*/
bool nd_less_than(Country &c1, Country &c2)
{
    return c1.getNewDeath() < c2.getNewDeath();
}

/*Function name：nr_less_than
 description：used for sorting countries by new recovered cases
 parameter descriptions： 2 country objects
 return description：return true if the the first country has a lower number of new recovered cases
*/
bool nr_less_than(Country &c1, Country &c2)
{
    return c1.getNewRecovered() < c2.getNewRecovered();
}

/*Function name：tc_less_than
 description：used for sorting countries by total confirmed cases
 parameter descriptions： 2 country objects
 return description：return true if the the first country has a lower number of total confirmed cases
*/
bool tc_less_than(Country &c1, Country &c2)
{
    return c1.getTotalConfirmed() < c2.getTotalConfirmed();
}

/*Function name：td_less_than
 description：used for sorting countries by total death cases
 parameter descriptions： 2 country objects
 return description：return true if the the first country has a lower number of  total death cases
*/
bool td_less_than(Country &c1, Country &c2)
{
    return c1.getTotalDeath() < c2.getTotalDeath();
}

/*Function name：tr_less_than
 description：used for sorting countries by total recovered cases
 parameter descriptions： 2 country objects
 return description：return true if the the first country has a lower number of total recovered cases
*/
bool tr_less_than(Country &c1, Country &c2)
{
    return c1.getTotalRecovered() < c2.getTotalRecovered();
}

/*Function name：calculate_proximity
 description：depending on the sorting method, it calculates the how many cases each # represents, which is used in producing the graph
 parameter descriptions： integer vector of country data that the user chose for sorting, the sorting method the user chose
 return description：return an integer number for how many cases each # represents in the output graph
*/
int calculate_proximity(vector<int> countryData, int sort){
    int proximity;
    if (sort == 1) // if the sorting order is ascending, the value is 1
    {
        proximity = countryData[9] / 70; // the highest number should be the tenth in the integer vector, 70 represents 70 # symbols, it calculate the number for each hash 
        if(proximity < 1) // there is a chance that the highest number is lower than 70, which causes the number for each hash less than 0
        proximity = countryData[9]/ 7; // So we recalculate again, but this time we use 7, which guarentte the number for each hash is higher than 0
    }
    else// the sorting order is descending, the value is 2
    {
        reverse(countryData.begin(), countryData.end()); // it will give us a list of data in descending order
        proximity = countryData[0] / 70; // the highest number should be the first in the reversed integer vector, 70 represents 70 # symbols, it calculate the number for each hash
    }
    return proximity;
}

/*Function name：produce_hash_bar
 description：Takes in the number of how many cases a # represent and the number of cases, it outputs a bar of # symbols after the calculation
 parameter descriptions： the approxiamte integer that a # represents, the number of cases
 return description：return a bar of # symbols
*/
void produce_hash_bar(int hash_proximity, int cases){
    if(cases != 0) // the number of the cases should be more than 1, or else it couldn't do the following calculation
    {
        int num_of_hash = cases / hash_proximity;// calculate the result of how many # should it produces
        if(num_of_hash > 1) // if the result shows there more than 1 #
        {
            for (int i = 0; i < num_of_hash; i++) // produces the # symbols
            {
                cout << '#'; 
            }
        }
    }
    cout << '\n';// the # is finished producing
}

/*Function name：produceGraph
  Description：It produces a user desired graph depending on their selection on the covid stats and the sorting order. 
               The graph outputs either top 10 or bottom 10 records of the stats that has the country code, and display
               a bar of # to represent the relative amount for each country. At the bottom of the graph, it shows the 
               user's choice and the approximate number of each #.
  Parameter descriptions：a list of vector type of sorted countries, choice of covid stat of integer type, approximate number
               of #, the name of the covid stat
  Return description：outputs a graph described in the description
*/
void produceGraph(vector<Country> countryList, int data, int hash_proximity, string data_name)
{
    int cases;
    cout << "---------------------------------------------------------------------------" << '\n';
    for (int i = 0; i < 10; i++) // only output 10 records
    {
        switch (data)
        {
        case 1: // if user's choice is to see top/bottom 10 countries with new confirmed cases
            cases = countryList[i].getNewConfirmed();
            cout << countryList[i].getCntryCode() << " | ";
            produce_hash_bar(hash_proximity,cases);
            break;
        case 2: // if user's choice is to see top/bottom 10 countries with new death cases
            cases = countryList[i].getNewDeath();
            cout << countryList[i].getCntryCode() << " | ";
            produce_hash_bar(hash_proximity, cases);
            break;
        case 3: // if user's choice is to see top/bottom 10 countries with new recovered cases
            cases = countryList[i].getNewRecovered();
            cout << countryList[i].getCntryCode() << " | ";
            produce_hash_bar(hash_proximity, cases);
            break;
        case 4: // if user's choice is to see top/bottom 10 countries with total confirmed cases
            cases = countryList[i].getTotalConfirmed();
            cout << countryList[i].getCntryCode() << " | ";
            produce_hash_bar(hash_proximity, cases);
            break;
        case 5: // if user's choice is to see top/bottom 10 countries with total death cases
            cases = countryList[i].getTotalDeath();
            cout << countryList[i].getCntryCode() << " | ";
            produce_hash_bar(hash_proximity, cases);
            break;
        case 6: // if user's choice is to see top/bottom 10 countries with total recovered cases
            cases = countryList[i].getTotalRecovered();
            cout << countryList[i].getCntryCode() << " | ";
            produce_hash_bar(hash_proximity, cases);
            break;
        }
    }
    cout << "---------------------------------------------------------------------------" << '\n';
    cout << data_name << "; " << "Each # is approx. " << hash_proximity << " cases" << '\n'; // display the user's choice, and how many cases does 1 # symbol represents in the graph
}