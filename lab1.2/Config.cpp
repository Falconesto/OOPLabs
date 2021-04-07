//
// Created by Александр on 18.09.2020.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Config {
private:
    map<string, map<string, string>> myData;

public:
    Config(string fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            throw (string) "Can't open the file";
        }

        string raw;
        string sect;
        while (getline(file, raw)) {
            string::size_type n = raw.find(';');
            if (n != std::string::npos) {
                raw = raw.substr(0, n);
            }
            if ((raw[0] == '[') && (raw[raw.length() - 1] == ']')) {
                sect = raw.substr(1, raw.length() - 2);
                regex regex("[A-Za-z0-9_]+");
                if (!regex_match(sect, regex)) {
                    throw sect + ": Incorrect name of a section";
                }

            } else {
                if ((raw.length() > 0) && (raw.find('=') != string::npos)) {
                    string str1 = raw.substr(0, raw.find('=')-1);
                    string str2 = raw.substr(raw.find('=') + 2, raw.length() - raw.find('=') - 1);
                    raw.erase(raw.find('='), 1);
                    if (raw.find('=') != string::npos) {
                        throw (string) "There is more than one = sign";
                    }
                    regex regex1("[A-Za-z0-9_]+");
                    if (!regex_match(str1, regex1)) {
                        throw str1 + ": Incorrect type of a name";
                    }
                    regex regex2("[A-Za-z0-9_.]+");
                    regex regex2_2("-?[0-9.]+");
                    if (!regex_match(str2, regex2)&&!regex_match(str2, regex2_2)) {
                        throw str2 + ": Incorrect type of a value";
                    }
                    if(myData.find(sect)==myData.end()) {
                        map<string, string> tmp;
                        tmp.insert(make_pair(str1, str2));
                        myData.insert(std::make_pair(sect, tmp));
                    }else{
                        myData[sect][str1]=str2;
                    }
                } else {
                    if (raw.length() > 1) {
                        throw raw + " -- dude, what are those???";
                    }
                }
            }
        }
    }

    string GetMinorStringValue(string Section, string Name) {

        if (myData.find(Section) == myData.end())
            throw (string) "No such Section";
        if (myData[Section].find(Name) == myData[Section].end())
            throw (string) "No such name in Section";
        return myData[Section][Name];
    }

    string GetStringValue(string Section, string Name) {
        string str = GetMinorStringValue(Section, Name);
        regex regex1("[A-Za-z0-9_.]+");
        if (!regex_match(str, regex1)) {
            throw Section + " - " + Name + ": is not a string";
        }
        return str;

    }

    int GetIntValue(string Section, string Name) {
        string str = GetMinorStringValue(Section, Name);
        regex regex1("-?[0-9]+");
        if (!regex_match(str, regex1)) {
            throw Section + " - " + Name + ": is not a integer number";
        }
        return stoi(str);

    }

    double GetDoubleValue(string Section, string Name) {
        string str = GetMinorStringValue(Section, Name);
        regex regex1("-?[0-9.]+");
        double res = stod(str);
        if (!regex_match(str, regex1)) {
            throw Section + " - " + Name + ": is not a double number";
        }
        return stod(str);
    }
};

