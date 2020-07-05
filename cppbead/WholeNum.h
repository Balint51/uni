#pragma once

#include <vector>
using namespace std;

class WholeNum {
private:
    vector <int> vec;
    int Sum=0;

public:

    enum NumberErrors{NOTELEMENT,ALREADYELEMENT,EMPTYVEC};

    void add(int i);
    void rem(int i);
    int get();
    void wrElem();
    int getSum();
};


