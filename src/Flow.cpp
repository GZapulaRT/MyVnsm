#include "Flow.h"
#include "System.h"

using namespace std;

template<>
Flow<System>::Flow(System* const& o, System* const& d)
{
	//! Constructor. Receives to systems to connect.
	/*
		Input: Origin System pointer, Destiny System pointer. Both can receive NULL.

		The constructor receives two System pointer variables, the first being the origin System, which
		will net in the energy/mass loss on the flow, and the second being the destiny, netting in the
		gain of energy/mass.
	*/
	this->origin = o;
	this->destiny = d;
}

template<>
Flow<System>::~Flow()
{
	//! Destructor. TBI.
}

template<>
System* Flow<System>::getSysOrigin()
{
	//! Function to return the Flow's respective Giver System pointer.
	/*
		Input: None.
		Output: Origin System pointer.
	*/
	return origin;
}

template<>
System* Flow<System>::getSysDestiny()
{
	//! Function to return the Flow's respective Receiver System pointer.
	/*
		Input: None.
		Output: Destiny System pointer.
	*/
	return destiny;
}

template<>
float Flow<System>::getChange()
{
	//! Function to return the Flow's total change.
	/*
		Input: None.
		Output: Flow's exchange value between systems, as a floating point value.

		This function calculates the exchange sequentially on each depending system, according to the
		function of the same index. Each function must be inputted by the user, with the defineFunc method.
	*/
	float acc = 0;

	// Check if func and dep are the same size (later)
	for(int i = 0; i < func.size(); i++)
	{
		acc += func[i](dep[i]->getValue());
	}

	return acc;
}

template<> 
void Flow<System>::defineFunc(System* const& sys, float (*func)(float))
{
	//! Function to define a new system dependency for the flow, with a function pointer set for the calculation.
	/*
		Input: System pointer of the depending system; and a function or function pointer.
		Output: None.

		This function defines each System object that influences the flow value of the Flow object that the 
		method is used.
	*/	
	this->func.push_back(func);
	dep.push_back(sys);
}