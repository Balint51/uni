

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE
#include <iostream>
#include "enors.h"
int main()
{
    HalEnor t("inp.txt");
    int HalNum=0;
    bool MindHarcsa=false;
    string MindNev;

    for( t.first(); !t.end(); t.next() ){
        bool alwaysFish=true;
        for(int i=0; i<t.current().HarcsaBools.size();i++)
        {
            if(t.current().HarcsaBools[i]==false){
                alwaysFish=false;
            }
            else{
                HalNum++;
            }
        }
        if(alwaysFish==true){
            MindHarcsa=true;
            MindNev=t.current().Name;
        }
    }
    cout<<HalNum<<" db sorban volt harcsa"<<endl;
    if(MindHarcsa==false){
        cout<<"Nem volt aki mindig fogott volna harcsat"<<endl;
    }
    else{
        cout<<MindNev<<" minden versenyen fogott harcsa(ka)t"<<endl;
    }
/*
                if(_cur.HalVec[i].type=="Harcsa"){
                    HarcsaNum++;
                    Harcsafound=true;
                }
                i++;
            }
            if(Harcsafound==false){
                MindigHarcsa=false;
            }
*/
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "enors.h"
#include "catch.hpp"

TEST_CASE("1"){
    ///Ha az egyik verseny�n nem fog a hal�sz halat, akkor nem fogott mindegyiken
    HalEnor test("testtxt1.txt");
    int HalNum=0;
    bool MindHarcsa=false;
    string MindNev;
    for(test.first();!test.end();test.next()){
        bool alwaysFish=true;
        for(int i=0; i<test.current().HarcsaBools.size();i++)
        {
            if(test.current().HarcsaBools[i]==false){
                alwaysFish=false;
            }
            else{
                HalNum++;
            }
        }
        if(alwaysFish==true){
            MindHarcsa=true;
            MindNev=test.current().Name;
        }
    }

    CHECK(HalNum==2);
    CHECK(MindHarcsa==false);
}

TEST_CASE("2"){
    ///Ha mindenhol fog, akkor rendesen �rz�keli
    HalEnor test("testtxt2.txt");
    int HalNum=0;
    bool MindHarcsa=false;
    string MindNev;
    for(test.first();!test.end();test.next()){
        bool alwaysFish=true;
        for(int i=0; i<test.current().HarcsaBools.size();i++)
        {
            if(test.current().HarcsaBools[i]==false){
                alwaysFish=false;
            }
            else{
                HalNum++;
            }
        }
        if(alwaysFish==true){
            MindHarcsa=true;
            MindNev=test.current().Name;
        }
    }

    CHECK(HalNum==3);
    CHECK(MindHarcsa==true);
}

TEST_CASE("3"){
    ///Ha egy versenyen t�bb Harcs�t is fog, azokat csak 1-nek sz�m�tja
    HalEnor test("testtxt3.txt");
    int HalNum=0;
    bool MindHarcsa=false;
    string MindNev;
    for(test.first();!test.end();test.next()){
        bool alwaysFish=true;
        for(int i=0; i<test.current().HarcsaBools.size();i++)
        {
            if(test.current().HarcsaBools[i]==false){
                alwaysFish=false;
            }
            else{
                HalNum++;
            }
        }
        if(alwaysFish==true){
            MindHarcsa=true;
            MindNev=test.current().Name;
        }
    }

    CHECK(HalNum==1);
}

#endif
