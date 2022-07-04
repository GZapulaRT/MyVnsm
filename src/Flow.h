#ifndef FLOW_H
#define FLOW_H

#include<vector>
#include<string>

template<class T> class Flow{
	T* origin; //! System pointer to Giver System.
	T* destiny; //! System pointer to Receiver System.
	std::vector<float (*)(float)> func; //! Vector with function pointers for each System that influences it.
	std::vector<T*> dep; //! Vector with each system dependency.

public:
	Flow(T* const&, T* const&);
	~Flow();

	T* getSysOrigin();
	T* getSysDestiny();

	float getChange();
	void defineFunc(T* const&, float(*)(float));
};

#endif