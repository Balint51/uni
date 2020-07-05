#include "WholeNum.h"

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//Gets a whole num, looks it up than deletes it

    void WholeNum::rem(int i){
        vector<int>::iterator it;

        it= find(vec.begin(), vec.end(), i);
        if(it!=vec.end()){
            int index= distance(vec.begin(), it);
            vec.erase(vec.begin()+index);
            Sum = Sum-i;
        }
        else{throw NOTELEMENT;}


    }

    //adds a new element to the vector

    void WholeNum::add(int i){
        vector<int>::iterator it;
        it= find(vec.begin(), vec.end(), i);
        if(it == vec.end()){
        vec.push_back(i);
        Sum = Sum+i;
        }
        else{throw ALREADYELEMENT;}
    }

    //returns the first element of the vector when called

    int WholeNum::get(){
        if(vec.size()==0){
            throw EMPTYVEC;
        }
        return vec[0];
    }

    //writes out the elements of the halmaz to the console

    void WholeNum::wrElem(){
        if (vec.size()==0)
        {
            throw EMPTYVEC;
        }
        else{
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<", ";
        }
        }
    }

    //returns the Sum value inside the object

    int WholeNum::getSum(){
        return Sum;
    }

