

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE
#include "WholeNum.h"
#include <iostream>


legyenek a függvényekhez állapotterek meg feltételek a dokumentációban
using namespace std;

class Menu
{
public:
    WholeNum a;
    void run();
private:
    void menuWrite();
    void add();
    void get();
    void rem();
    void write();
    void sum();
};

void Menu::run()
{
    int n = 0;
    do {
        menuWrite();

        cin>>n;
        switch(n)
        {
        case 1:
            Menu::add();
            break;
        case 2:
            Menu::get();
            break;
        case 3:
            Menu::rem();
            break;
        case 4:
            Menu::write();
            break;
        case 5:
            Menu::sum();
            break;
        }
    } while(n!=0);
}

void Menu::menuWrite(){
    cout<< endl << endl;
    cout<< " 0. - Exit" << endl;
    cout<< " 1. - Add an element" << endl;
    cout<< " 2. - Select an element" <<endl;
    cout<< " 3. - Delete an element" <<endl;
    cout<< " 4. - Write out the stored elements" <<endl;
    cout<< " 5. - Show the Sum of all elements" <<endl;
}

//adott elem betevése

void Menu::add(){
    cout<<"Please Enter a new number"<<endl;
    int f;
    cin>>f;
    while(1==1){
        if(cin.fail()||cin.peek() != '\n'){
            cin.clear();
            cin.ignore ( 100 , '\n' );
            cout<<"Invalid input. Please enter a valid number"<<endl;
            cin>>f;

        }
        else{break;}
    }

    a.add(f);
}

//valamelyik elem kiválasztása – de nem kivétele

void Menu::get(){
    cout<<a.get();
    //a.get();
}

//adott elem kivétele

void Menu::rem(){
    cout<<"Please Enter the element you want to remove:";
    int f;
    cin>>f;
    while(1==1){
        if(cin.fail()||cin.peek() != '\n'){
            cin.clear();
            cin.ignore ( 100 , '\n' );
            cout<<"Invalid input. Please enter a valid number"<<endl;
            cin>>f;

        }
        else{break;}
    }
    a.rem(f);
}

//halmaz kiírását

void Menu::write(){
    a.wrElem();
}

//valamint a halmaz elemeinek összegét visszaadó műveletet

void Menu::sum(){
    cout<<a.getSum();
}

int main()
{
    Menu m;
    m.run();
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "WholeNum.h"
#include <iostream>
#include <vector>

TEST_CASE("check throws"){
    WholeNum test;

    CHECK_THROWS(test.get());

    CHECK_THROWS(test.rem(69));
    CHECK_THROWS(test.rem(666));

    CHECK_THROWS(test.wrElem());

    test.add(69);
    CHECK_THROWS(test.add(69));

}

TEST_CASE("check adding"){
    WholeNum test;
    test.add(69);
    test.add(666);

    CHECK(test.get()==69);
}
TEST_CASE("Selecting element"){
    WholeNum test;
    test.add(69);
    CHECK(test.get()==69);
}
TEST_CASE("sum"){
    WholeNum test;
    test.add(666);
    test.add(42);
    test.add(69);

    CHECK(test.getSum()==777);
}
TEST_CASE("rem"){
    WholeNum test;
    test.add(666);
    test.add(42);
    test.add(69);

    test.rem(666);
    CHECK(test.get()!=666);
}
TEST_CASE("checking sum after removing elements"){
    WholeNum test;
    test.add(666);
    test.add(42);
    test.add(69);

    test.rem(666);
    CHECK(test.getSum()==111);
}

TEST_CASE("Empty vector gives 0 sum"){
    WholeNum test;
    CHECK(test.getSum()==0);
}
TEST_CASE("Selecting doesnt remove"){
    WholeNum test;
    test.add(69);
    test.get();
    CHECK(test.get()==69);
}
#endif
