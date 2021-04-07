//
// Created by Александр on 18.09.2020.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <regex>
#include <typeinfo>

using namespace std;

class Config {
private:
    map<string, map<string, string>> myData;

public:
    Config(string fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            throw "Can't open the file";
        }

        string raw;
        string sect;
        while (getline(file, raw, ';')) {
            if ((raw[0] == '[') && (raw[raw.length() - 1] == ']')) {
                sect = raw.substr(1, raw.length() - 2);
                regex regex("[A-Za-z0-9_]");
                if (!regex_match(sect, regex)) {
                    throw sect + ": Incorrect name of a section";
                }

            } else {
                if ((raw.length() > 0) && (raw.find('=') != string::npos)) {
                    raw.erase(raw.find('='), 1);
                    if(raw.find('=') != string::npos){
                        throw "There is more than one = sign";
                    }
                        string str1 = raw.substr(0, raw.find('='));
                    string str2 = raw.substr(raw.find('=') + 1, raw.length() - raw.find('=') - 1);
                    regex regex1("[A-Za-z0-9_]");
                    if (!regex_match(str1, regex1)) {
                        throw str1 + ": Incorrect type of a name";
                    }
                    regex regex2("[A-Za-z0-9_.]");
                    if (!regex_match(str2, regex1)) {
                        throw str2 + ": Incorrect type of a value";
                    }
                    map<string, string> tmp;
                    tmp.insert(make_pair(str1, str2));
                    myData.insert(std::make_pair(sect, tmp));
                } else {
                    if (raw.length() > 1) {
                        throw raw + " -- dude, what are those???";
                    }
                }
            }
        }
    }

string GetStringValue(string Section, string Name){

        if (!myData.contains(Section))
            throw "No such Section";
        if (!myData[Section].contains(Name))
            throw "No such name in Section";
        return myData[Section][Name];
    }

int GetIntValue(string Section, string Name)
    {

        string str = GetStringValue(Section, Name);
        int res = 0;
        if (!Int32.TryParse(str, out res)){
            throw Section + " " + Name + " is not a integer number";
        }
        return res;

    }

double GetDoubleValue(string Section, string Name)
    {
        string str = GetStringValue(Section, Name);
        double res = 0;
        if (!Double.TryParse(str, out res))
        throw Section + " " + Name + " is not a double number";
        return res;
    }

vector<string> GetSections(){
        vector<string> res(myData.size());
        int i = 0;
        foreach (string key in myData.Keys)
        {
            res[i++] = key;
        }
        return res;
    }

vector<string> GetNames(string Section){
        if (!myData.contains(Section))
            throw "No such Section");

        vector<string> res(myData[Section].size());
        int i = 0;
        foreach (string key in myData[Section].Keys)
        {
            res[i++] = key;
        }

        return res;
    }
};

