#ifndef LAND_H
#define LAND_H

#include <string>
#include <vector>
#include <tuple>

class Lands{
    protected:
        char type;
        std::string owner;
        int water;
        Lands(char landtype, std::string ownername, int wadda) :type(landtype),owner(ownername), water(wadda){}

    public:
        std::string getowner(){return owner;}
        int getwater(){return water;}
        char gettype(){return type;}
        virtual void rainy()=0;
        virtual void sunny()=0;
        virtual void cloudy()=0;
        virtual void evaporation(int &humid)=0; //Az esőhöz hasonlóan csinálja,
        virtual ~Lands() {}
        ///megnézzük kell-e vmit cserélni
        std::tuple<bool,char,int,std::string>  vibecheck();
};

class puszta : public Lands{
    public:
    puszta(char type, std::string owner, int water) :Lands(type,owner, water){}
    void rainy() override;
    void sunny() override;
    void cloudy() override;
    void evaporation(int &humid) override;
};

class zold : public Lands{
    public:
    zold(char type, std::string owner, int water) :Lands(type, owner, water){}
    void rainy() override;
    void sunny() override;
    void cloudy() override;
    void evaporation(int &humid) override;
};

class tavas : public Lands{
    public:
    tavas(char type, std::string owner, int water) :Lands(type ,owner, water){}
    void rainy() override;
    void sunny() override;
    void cloudy() override;
    void evaporation(int &humid) override;
};

#endif
