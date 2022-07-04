#include "Model.h"
#include "Flow.h"
#include "System.h"
#include <iostream>

using namespace std;

template<>
Model<System,Flow<System>>::Model(/*vector<System*> &Systems, vector<Flow<System>*> &Flows*/)
{
	//! Constructor.
	/*
		Input: None.
	*/
//	sis = &Systems;
//	flow = &Flows;
}

template<>
Model<System,Flow<System>>::~Model()
{
	//! Destructor. TBI.

}

template<>
void Model<System,Flow<System>>::simDescription()
{
	//Incluir prints dos sistemas e dos fluxos linearmente
	//! Function to print all the Systems and Flows included in the simulation. TBI.
}

template<>
void Model<System,Flow<System>>::addSystem(System* s)
{
	//! Function to insert a System into the simulation.

	/*
		Input: System pointer to be added in the simulation.
		Output: None.
	*/
	sys.push_back(s);
}

template<>
System* Model<System,Flow<System>>::removeSystem(int i)
{
	//! Function to remove a System from the simulation.

	/*
		Input: Index of the System to be removed.
		Output: System pointer of the system removed.
	*/
	System *s = sys[i];
	sys.erase(sys.begin()+i);
	// Remover os fluxos relacionados ou substituir por "NULL" (ultimo preferencial)
	return s;
}

template<>
void Model<System,Flow<System>>::addFlow(Flow<System>* f)
{
	//! Function to insert a Flow into the simulation.

	/*
		Input: Flow pointer to be added in the simulation.
		Output: None.
	*/
	flow.push_back(f);
}

template<>
Flow<System>* Model<System,Flow<System>>::removeFlow(int i)
{
	//! Function to remove a Flow from the simulation.

	/*
		Input: Index of the Flow to be removed.
		Output: Flow pointer of the flow removed.
	*/
	Flow<System> *f = flow[i];
	flow.erase(flow.begin()+i);
	return f;
}

template<>
void Model<System,Flow<System>>::runModel(int a)
{
	//! Function to run the simulation of the systems and flows included for a time steps.

	/*
		Input: The number of steps of the simulation, as an integer.
		Output: Printing each system with the energy/mass value resultant from each step.
		
		The printing of each system is done sequentially according to the order of insertion on the
		simulation.
	*/
	cout << "Tempo 0:" << endl;
	for(int i = 0; i < sys.size(); i++)
	{
		cout << "System " << i+1 << ": " << sys[i]->getValue() << "\t";
	}
	cout << endl;

	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < flow.size(); j++)
		{
			float change = flow[j]->getChange();
			if(flow[j]->getSysOrigin() != NULL)
			{
				flow[j]->getSysOrigin()->changeValue(-change);
			}
			if(flow[j]->getSysDestiny() != NULL)
			{
				flow[j]->getSysDestiny()->changeValue(change);
			}
		};

		cout << "Tempo " << i+1 << ":" << endl;
		for(int j = 0; j < sys.size(); j++)
		{
			cout << "System " << j+1 << ": " << sys[j]->getValue() << "\t";
		}
		cout << endl;
	}
}
