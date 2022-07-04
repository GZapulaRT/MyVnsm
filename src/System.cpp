#include "System.h"

using namespace std;

System::System(float value)
{
	//! Constructor. The method receives a float to set as initial value.

	/*
		Input: The initial value of mass/energy for the system, as a floating point value.
	*/
	this->value = value;
}

System::~System()
{
	//! Destructor. TBI.
}

float System::getValue()
{
	//! Function to return the present energy/mass value of the system.

	/*
		Input: None.
		Output: Energy/mass value of the system as a floating point value.
	*/
	return this->value;
}

void System::changeValue(float value)
{
	//! Function to change the energy/mass value of a system.

	/*
		Input: Value to be added to the system. In case the value must be subtracted, input a negative value.
		Output: None.
	*/
	this->value += value;
}