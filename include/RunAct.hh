//
// Created by student on 06.05.17.
//

#ifndef M_DGW_4_RUNACT_HH
#define M_DGW_4_RUNACT_HH

#include <G4UserRunAction.hh>
#include "Run.hh"

class RunAct: public G4UserRunAction{
public:
    RunAct(){}
    ~RunAct(){}

    void EndOfRunAction(const G4Run* aRun);
    G4Run* GenerateRun();


};

#endif //M_DGW_4_RUNACT_HH
