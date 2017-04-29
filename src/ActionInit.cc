#include "ActionInit.hh"
ActionInit::ActionInit()
{ }

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const
{
    SetUserAction(new PrimaryGen());
}