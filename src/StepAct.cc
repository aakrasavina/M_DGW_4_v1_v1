//
// Created by student on 06.05.17.
//

#include <G4Step.hh>
#include <StepAct.hh>

void StepAct::UserSteppingAction(const G4Step* step){
    G4String vname = step->GetTrack()->GetVolume()->GetLogicalVolume()->GetName();

    if(vname=="Log_Tubs")
        Act->SetFlag();
    ;}