#include "Terminable.h"
#include "TerminationMan.h"
#include "SceneMan.h"
#include "TerminableReciever.h"
#include "Dumpster.h"

void Terminable::MarkForDestroy()
{
	SceneMan::MarkForDestroy(this);
}

void Terminable::OnDestroy()
{

}

void Terminable::SetTerminableReciever()
{
	tr= SceneMan::ReturnSceneDumpster();
}

void Terminable::SetTerminableReciever(TerminableReciever* trIn)
{
	tr= trIn;
}

TerminableReciever* Terminable::GetTerminableReciever()
{
	return tr;
}