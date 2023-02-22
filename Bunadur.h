#pragma once
#include <iostream>
#include <string>

//bæta við cout stuðning sem aukakröfu t.d.

class Bunadur {
    protected:
        int audkenni;
        int verdmaeti;
        char stadsetning[3];
    public:
        Bunadur();
        Bunadur(int audkenni, int verdmaeti, int stadsetning);
        int get_audkenni();
        void set_audkenni(int nytt_audkenni);
        int get_verdmaeti();
        void set_verdmaeti(int nytt_verdmaeti);
        int get_stadsetning();
        void set_stadsetning(int ny_stadsetning);
        int get_hus();
        void set_hus(int nytt_hus);
        int get_haed();
        void set_haed(int ny_haed);
        int get_herbergi();
        void set_herbergi(int nytt_herbergi);
        virtual void prenta();
        virtual std::string getType();
        //virtual ~Bunadur();
};