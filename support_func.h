/*  Author:Pu Huang
    Student Number: 250986943
    Short Description: this is a header file that lists supporting functions for outputing a graph
    Date: 2020-09-30
*/
#include <string>
#include <vector>

class Country;
std::vector<std::string> parseString(std::string str);
std::vector<int> parseNumber(std::string str);
int inputNumber();
bool nc_less_than(Country &c1, Country &c2);
bool nd_less_than(Country &c1, Country &c2);
bool nr_less_than(Country &c1, Country &c2);
bool tc_less_than(Country &c1, Country &c2);
bool td_less_than(Country &c1, Country &c2);
bool tr_less_than(Country &c1, Country &c2);
int calculate_proximity(std::vector<int> countryData, int sort);
void produce_hash_bar(int hash_proximity, int cases);
void produceGraph(std::vector<Country> countryList, int data, int hash_proximity, std::string data_name);
