//
// Created by student on 06.05.17.
//

#ifndef M_DGW_4_STEPACT_HH
#define M_DGW_4_STEPACT_HH

#include <G4UserSteppingAction.hh>
#include "EventAct.hh"

class StepAct: public G4UserSteppingAction{
public:
    StepAct(EventAct* act):Act(act){}
    ~StepAct(){}
    void UserSteppingAction(const G4Step*);
private:
    EventAct* Act;


};

#endif //M_DGW_4_STEPACT_HH
