#ifndef SYSTEM_H
#define SYSTEM_H

#include<string>

class System{
	float value; //! The amount of energy/mass available in the system.

public:
	System(float);
	~System();

	float getValue();
	void changeValue(float);
};

#endif