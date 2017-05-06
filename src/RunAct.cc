//
// Created by student on 06.05.17.
//

#include <G4Run.hh>
#include <RunAct.hh>
#include <Run.hh>

void RunAct::EndOfRunAction(const G4Run* aRun){

    G4int result;

    std::cout<<"Result for this thread = "<<result<<std::cout;

    G4int* res= static_cast<G4int*>(Run->result);


    //std::cout<<"Result for this thread = "<< <<std::cout;

}
G4Run* RunAct::GenerateRun(){
    return new Run;

}