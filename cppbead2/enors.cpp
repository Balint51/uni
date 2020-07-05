
#include "enors.h"

using namespace std;



HalEnor::HalEnor(const string &str){
    _x.open(str.c_str());
    if(_x.fail()) throw FILEERROR;
}
/*
void HalEnor::next(){
    _end = (abnorm==_sx);
    if(!_end){
        _dx=_cur.Name;
        bool MindigHarcsa=true; ///Ez n�zi h minden alkalommal fogott-e harcs�t v nem
        for( ; norm==_sx && _dx==_cur.Name; read()){
            int i=0;
            bool Harcsafound=false;
            while(Harcsafound==false && i<_cur.HalVec.size()){
                if(_cur.HalVec[i].type=="Harcsa"){
                    HarcsaNum++;
                    Harcsafound=true;
                }
                i++;
            }
            if(Harcsafound==false){
                MindigHarcsa=false;
            }
        }
        if(MindigHarcsa==true)
        {
            MindHarcsa=true;
        }
    }
}
*/

void HalEnor::next(){
    _cur.HarcsaBools.clear();
    _end = (abnorm==_sx);
    if(!_end){
        _dx=_cur.Name;
        for( ; norm==_sx && _dx==_cur.Name; read()){
            CheckLine();
        }
    }
}

void HalEnor::CheckLine(){
    bool harcsabool=false;
    for(int i=0;i<_cur.HalVec.size();i++){
        if(_cur.HalVec[i].type=="Harcsa"){
            harcsabool=true;
        }
    }
    _cur.HarcsaBools.push_back(harcsabool);
}

void HalEnor::read(){
    string Line;
    getline(_x, Line, '\n');
    istringstream _s(Line);
    _s >> _cur.Name >> _cur.contestName;
    _cur.HalVec.clear();
    Hal a;
    while( _s >> a.type >> a.weight )
    {
        _cur.HalVec.push_back(a);
    }
    if ( _x.fail() ) _sx = abnorm;
    else _sx= norm;
}
