#include "ActionInit.hh"
ActionInit::ActionInit()
{ }

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const
{
    SetUserAction(new PrimaryGen());
    SetUserAction(new RunAct());



    EventAct* eventAction= new EventAct;
    SetUserAction(eventAction);

    SetUserAction(new StepAct(eventAction));
}