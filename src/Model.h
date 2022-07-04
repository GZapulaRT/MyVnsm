#ifndef SIMULATION_H
#define SIMULATION_H

#include<vector>
#include<string>

template <class S, class T>
class Model{
	std::vector<S*> sys; //! Vector of systems included in the simulation.
	std::vector<T*> flow; //! Vector of flows included in the simulation.

public:
	Model();
	~Model();

	void simDescription();

	void addSystem(S*);
	S* removeSystem(int);

	void addFlow(T*);
	T* removeFlow(int);

	void runModel(int);
};

#endif