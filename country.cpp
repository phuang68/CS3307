/*  Author:Pu Huang
    Student Number: 250986943
    Short Description: this is a class c++file that declares the country class that has the country's name, two-letter country code,
    and six statistical counts (new confirmed cases, new deaths, new recovered cases, total confirmed cases, total deaths, and 
    total recovered cases), gettter and setter methods, constructors and destructor.
    Date: 2020-09-30
*/
#include <iostream>
#include <string>
#include <vector>
#include "country.h"

using namespace std;

    // Country onstructor with parameterscountry's name, two-letter country code,country's name, two-letter country code,and six statistical counts (new confirmed cases, new deaths, new recovered cases, total confirmed cases, total deaths, and total recovered cases)
    Country::Country(string name, string code, int newC, int newD, int newRe, int totalC, int totalD, int totalRe){
        cntryName = name;
        cntryCode = code;
        newConfirmed = newC;
        newDeath = newD;
        newRecovered = newRe;
        totalConfirmed = totalC;
        totalDeath = totalD;
        totalRecovered = totalRe;
    }

    //Copy constructor
    Country::Country(const Country &c){
        cntryName = c.cntryName;
        cntryCode = c.cntryCode;
        newConfirmed = c.newConfirmed;
        newDeath = c.newDeath;
        newRecovered = c.newRecovered;
        totalConfirmed = c.totalConfirmed;
        totalDeath = c.totalDeath;
        totalRecovered = c.totalRecovered;
    }
    //Destructor
    Country::~Country(){

    };

    /* Function name：getCntryName
       Description：return the country name of the contry object
       Parameter descriptions：null
       Return description：return the country name of string type
    */
    string Country::getCntryName(){
        return this->cntryName;
    }
    /* Function name：setCntryName
       Description: set the country name of the contry object
       Parameter descriptions：the country name of string type
       Return description：null
    */
    void Country::setCntryName(string cntryName)
    {
        this->cntryName = cntryName;
    }

    /* Function name：getCntryCode
       Description：return the country code of the contry object
       Parameter descriptions：null
       Return description：return the country code of string type
    */
    string Country::getCntryCode()
    {
        return this->cntryCode;
    }
    /* Function name：setCntryCode
       Description: set the string of country code of the contry object
       Parameter descriptions：the country code of string type
       Return description：null
    */
    void Country::setCntryCode(string cntryCode)
    {
        this->cntryCode = cntryCode;
    }

    /* Function name：getNewConfirmed
       Description：return the number of new confirmed cases of the contry object
       Parameter descriptions：null
       Return description：return the number of new confirmed case of int type
    */
    int Country::getNewConfirmed()
    {
        return this->newConfirmed;
    }
    /* Function name：setNewConfirmed
       Description: set the number of new confirmed cases of the contry object
       Parameter descriptions：the number of new confirmed cases of int type
       Return description：null
    */
    void Country::setNewConfirmed(int newConfirmed)
    {
        this->newConfirmed = newConfirmed;
    }

    /* Function name：getNewDeath
       Description：return the number of new death cases of the contry object
       Parameter descriptions：null
       Return description：return the number of new death cases of int type
    */
    int Country::getNewDeath()
    {
        return this->newDeath;
    }
    /* Function name：setNewDeath
       Description: set the number of new death cases of the contry object
       Parameter descriptions：the number of new death cases of int type
       Return description：null
    */
    void Country::setNewDeath(int newDeath)
    {
        this->newDeath = newDeath;
    }

    /* Function name：getNewRecovered
       Description：return the number of new recovered cases of the contry object
       Parameter descriptions：null
       Return description：return the number of new recovered cases of int type
    */
    int Country::getNewRecovered()
    {
        return this->newRecovered;
    }
    /* Function name：setNewRecovered
       Description: set the number of new recovered cases of the contry object
       Parameter descriptions：the number of new recovered cases of int type
       Return description：null
    */
    void Country::setNewRecovered(int newRecovered)
    {
        this->newRecovered = newRecovered;
    }

    /* Function name：getTotalConfirmed
       Description：return the number of total confirmed cases of the contry object
       Parameter descriptions：null
       Return description：return the number of total confirmed case of int type
    */
    int Country::getTotalConfirmed()
    {
        return this->totalConfirmed;
    }
    /* Function name：setTotalConfirmed
       Description: set the number of total confirmed cases of the contry object
       Parameter descriptions：the number of total confirmed cases of int type
       Return description：null
    */
    void Country::setTotalConfirmed(int totalConfirmed)
    {
        this->totalConfirmed = totalConfirmed;
    }

    /* Function name：getTotalDeath
       Description：return the number of total death cases of the contry object
       Parameter descriptions：null
       Return description：return the number of total death cases of int type
    */
    int Country::getTotalDeath()
    {
        return this->totalDeath;
    }

    /* Function name：setTotalDeath
       Description: set the number of total death cases of the contry object
       Parameter descriptions：the number of total death case of int type
       Return description：null
    */
    void Country::setTotalDeath(int totalDeath)
    {
        this->totalDeath = totalDeath;
    }

    /* Function name：getTotalRecovered
       Description：return the number of total recovered cases of the contry object
       Parameter descriptions：null
       Return description：return the number of total recoverd case of int type
    */
    int Country::getTotalRecovered()
    {
        return this->totalRecovered;
    }

    /* Function name：setTotalRecovered
       Description: set the number of total recovered cases of the contry object
       Parameter descriptions：the number of total recoverd case of int type
       Return description：null
    */
    void Country::setTotalRecovered(int totalRecovered)
    {
        this->totalRecovered = totalRecovered;
    }

    