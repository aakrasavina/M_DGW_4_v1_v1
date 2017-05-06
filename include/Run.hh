//
// Created by student on 06.05.17.
//

#ifndef M_DGW_4_RUN_HH
#define M_DGW_4_RUN_HH

#include <G4Run.hh>

class Run: public G4Run{
public:
    Run():result(0){}
    ~Run(){}

    void SetNewEvent(){result++;}
    int GetResult()const{return result;}
    G4int result;
//private:



};

#endif //M_DGW_4_RUN_HH
