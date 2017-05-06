//
// Created by student on 06.05.17.
//

#include <G4Event.hh>
#include <EventAct.hh>
#include <Run.hh>
#include <G4RunManager.hh>

void EventAct::EndOfEventAction(const G4Event* anEvent){

    Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());

    run->SetNewEvent();

}

void BeginOfEventAction(const G4Event* anEvent){
    bool flag;

    flag=0;

    std::cout<<"Begin of an Event. Flag = "<<flag<<std::cout;
}