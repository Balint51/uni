#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

enum Status {abnorm, norm};

struct Hal{
    string type;
    double weight;
};

struct VersenyFogas{
    string Name;
    string contestName;
    vector <Hal> HalVec;
    vector <bool> HarcsaBools;
};

class HalEnor
{
public:

    enum Errors {FILEERROR};

    HalEnor(const string &str);

    void first(){read();next();}
    VersenyFogas current(){return _cur;}
    void next();
    bool end() {return _end;}
    void CheckLine();

private:


    string MindHNev;
    string _dx;

    std::ifstream _x;
    Status _sx;
    VersenyFogas _cur;
    bool _end;
    void read();

};
