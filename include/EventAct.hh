//
// Created by student on 06.05.17.
//

#ifndef M_DGW_4_EVENTACT_HH
#define M_DGW_4_EVENTACT_HH

#include <G4UserEventAction.hh>
#include "G4Run.hh"

class EventAct: public G4UserEventAction{
public:
    EventAct():flag(0){}
    ~EventAct(){}
    void SetFlag(){flag=1;}
    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);
private:
    bool flag;
};


#endif //M_DGW_4_EVENTACT_HH
