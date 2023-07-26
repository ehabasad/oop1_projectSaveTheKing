#include "StaticObjects.h"

void StaticObjects::setStay(bool a)
{
	m_found = a;
}

bool StaticObjects::getStay() const 
{
	return m_found;
}

