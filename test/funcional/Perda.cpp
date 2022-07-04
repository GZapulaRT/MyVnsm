#include "Perda.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include <assert.h>

float funcP(float a)
{
	return 0.25*a;
}

void testPerda()
{
	System sys1(30);
	Flow<System> f(&sys1, NULL);
	f.defineFunc(&sys1, funcP);

	Model<System, Flow<System>> sim;

	sim.addSystem(&sys1);
	sim.addFlow(&f);

	sim.runModel(50);
}