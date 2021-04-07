#include "Config.cpp"

int main() {
    try {
        Config conf("1.ini");
        string sect = "First";
        string name = "one";
        int ires = conf.GetIntValue(sect, name);

        sect = "First";
        name = "two";
        double dres = conf.GetDoubleValue(sect, name);

        sect = "First";
        name = "three";
        string sres = conf.GetStringValue(sect, name);

        sect = "Second";
        name = "lol";
        string ssres = conf.GetStringValue(sect, name);
        cout << ires << endl << dres << endl << sres << endl << ssres;
    } catch (string &exception) {
        std::cerr << "Error: " << exception << '\n';
        return 1;
    }
    return 0;
}