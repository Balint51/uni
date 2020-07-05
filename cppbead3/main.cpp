#include "land.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;



void initialize(const string &str, vector <Lands*> &foldek,int &humid,int &numberofLand){
    ifstream f(str.c_str());//régebbi c++ compilerekkel nem működik
    if(f.fail()) { cout << "There are no files with that filename. Try entering a different one and try again."<<endl; exit(1);}

    f >> numberofLand;
    for(int i=0;i<numberofLand;i++){
        string owner;
        char tipus;
        int wadda;
        foldek.resize(numberofLand);

        f>>owner>>tipus>>wadda;

            /*if(tipus=='t'){
                foldek.push_back(new tavas(tipus, owner, wadda));
                break;
            }
            if(tipus=='z'){
                foldek.push_back(new zold(tipus, owner, wadda));
                break;
            }
            if(tipus=='p'){
                foldek.push_back(new puszta(tipus, owner, wadda));
                break;
            }*/

            if(tipus=='t'){
                foldek[i] = new tavas(tipus, owner, wadda);
            }else if(tipus=='z'){
                foldek[i] = new zold(tipus, owner, wadda);
            }else if(tipus=='p'){
                foldek[i] = new puszta(tipus, owner, wadda);
            }
   }
    f>>humid;
}

int simulation(vector <Lands*> &foldek,int &humid,int &numberofLand,int &simulationtimes){
    //ez a random-szám generáláshoz kell majd
    srand (time(NULL));

    int n; //ez az aktuális nap/kör száma lesz

    //megnézi a páratartalmat és csinálja az esőt
    for(n=0;n<simulationtimes;n++)
    {
        //esik eső karikára
        if(humid>70){
            humid=30;
            for(int i=0;i<numberofLand;i++){
                foldek[i]->rainy();
            }
        }
        //napos idő, és mivel else if, ezért nem cseszi el mint korábban
        else if(humid<40){
            for(int i=0;i<numberofLand;i++){

                foldek[i]->sunny();
            }
        }
        //felhőnézés
        else if(humid>40 && humid<70){
            int random= rand()% 100;
            //this sounds like rainy() with extra steps
            if(random<(humid-40)*3.3){
                for(int i=0;i<numberofLand;i++){
                    foldek[i]->rainy();
                }
            }
            //itt szerencsénk van és a ritka felhőzést látjuk
            else{
                for(int i=0;i<numberofLand;i++){
                    foldek[i]->cloudy();
                }
            }
        }


///////////////////////////////////////////////////////////////
        //páratartalom állítása, mivel a humid-ra direktben hivatkozunk,
        //ezért gond nélkül lehet így módosítgatni
        //egy virtual evaporation függvénnyel végezzük, ezért ha jön új fajta föld, akkor ott csak át kell írni bizonyos részeit

        for(int i=0;i<numberofLand;i++){
            foldek[i]->evaporation(humid);
        }
        if(humid>100){
            humid=100;
        }
////////////////////////////////////////////////////////////////////
        //itt nézem meg h mikor változnak a területek
        for(int i=0;i<numberofLand;i++){
            bool needchange = get<0>(foldek[i]->vibecheck());
            char tipus = get<1>(foldek[i]->vibecheck());
            int viz = get<2>(foldek[i]->vibecheck());
            string tulaj = get<3>(foldek[i]->vibecheck());

            if(get<0>(foldek[i]->vibecheck())==true){

                if(tipus=='t'){
                    foldek[i] = new tavas(tipus, tulaj, viz);
                }
                else if(tipus=='z'){
                    foldek[i] = new zold(tipus, tulaj, viz);
                }
                else if(tipus=='p'){
                    foldek[i] = new puszta(tipus, tulaj, viz);
                }
            }
        }

///////////////////////////////////////////////////////////////////////////////////////


        //Aznapi állapot kiírása
        cout<<n+1<<". ciklus:"<<endl;
        for(int i=0;i<numberofLand;i++){
            cout<<foldek[i]->getowner()<<"  "<<foldek[i]->gettype()<<"  "<<foldek[i]->getwater()<<endl;
        }
        cout<<humid<<endl;
    }
    //állapot vége

    //itt van a maxkeresés, elég egyszerű, mert csak végiglépkedünk a vektorunkon
    int maxindex=0;
    int maxwater=0;
    for(int i=0;i<numberofLand;i++){
        if(foldek[i]->getwater()>maxwater)
        {
            maxwater=foldek[i]->getwater();
            maxindex=i;
        }
    }
    return maxindex;
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    int humid;
    int numberofLand;
    int simulationtimes=10;
    vector <Lands*> foldek;
    initialize("input.txt",foldek,humid,numberofLand);
    int ind=simulation(foldek,humid,numberofLand,simulationtimes);
    cout<<"A legvizesebb terulet tulaja: "<<foldek[ind]->getowner()<< " ahol "<<foldek[ind]->getwater()<< " km3 viz van"<<" A telek pedig "<<foldek[ind]->gettype()<<" Típusu"<<endl;
    return 0;
}

#else
//Innen jön a kötelező tesztelés
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("input")
{
    int humid;
    int numberofLand;
    int simulationtimes=10;
    vector <Lands*> foldek;
    initialize("input.txt",foldek,humid,numberofLand);
    CHECK(foldek[0]->getwater()==86);
    CHECK(foldek[0]->getowner()=="Bean");
    CHECK(foldek[1]->getwater()==26);
    CHECK(foldek[2]->getwater()==12);
    CHECK(foldek[3]->getwater()==35);
}

TEST_CASE("1 nagyon tavas, 3 nagyon puszta"){
    int humid;
    int numberofLand;
    int simulationtimes=10;
    vector <Lands*> foldek;
    initialize("input2.txt",foldek,humid,numberofLand);
    CHECK(simulation(foldek,humid,numberofLand,simulationtimes)==0);

}

TEST_CASE("eláradás nézése"){
    int humid;
    int numberofLand;
    int simulationtimes=10;
    vector <Lands*> foldek;
    initialize("input3.txt",foldek,humid,numberofLand);
    int ind=simulation(foldek,humid,numberofLand,simulationtimes);
    CHECK(foldek[0]->gettype()!='p');
    CHECK(foldek[0]->getwater()>10);
}

#endif
