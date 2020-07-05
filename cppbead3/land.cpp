#ifndef LAND_CPP
#define LAND_CPP

#include "land.h"

using namespace std;


///Puszta
void puszta::rainy(){
    water=water+5;
}
void puszta::sunny(){
    if(water<3){
        water=0;
    }
    else{water=water-3;}
}
void puszta::cloudy(){
    if(water<1){
        water=0;
    }
    else{water=water-1;}
}
void puszta::evaporation(int &humid){
    humid=humid+3;
}

///Zöld
void zold::rainy(){
    water=water+10;
}
void zold::sunny(){
    if(water<6){
        water=0;
    }
    else{water=water-6;}
}
void zold::cloudy(){
    if(water<2){
        water=0;
    }
    else{water=water-2;}
}
void zold::evaporation(int &humid){
    humid=humid+7;
}

//Tavas
void tavas::rainy(){
    water=water+15;
}
void tavas::sunny(){
    if(water<10){
        water=0;
    }
    else{water=water-10;}
}
void tavas::cloudy(){
    if(water<3){
        water=0;
    }
    else{water=water-3;}
}
void tavas::evaporation(int &humid){
    humid=humid+10;
}

///Általános

tuple<bool,char,int,string> Lands::vibecheck(){
    bool returnbool=false;
    char returnchar;
    int returnwater=water;
    string returnowner=owner;
    ///tavas
    if(type=='t'){
        if(water<51){
            returnbool=true;
            returnchar='z';
        }
    }

    ///zöld
    if(type=='z'){
        if(water<16){
            returnbool=true;
            returnchar='p';
        }
        else if(water>50){
            returnbool=true;
            returnchar='t';
        }
    }

    ///puszta
    if(type=='p'){
        if(water>15){
            returnbool=true;
            returnchar='z';
        }
    }

    return make_tuple(returnbool,returnchar,returnwater,returnowner);
}

#endif
