#include "Ganho.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include <assert.h>

float funcG(float a)
{
	return 0.05*a*(1-a/200)+5;
}

void testGanho()
{
	System sys2(0);
	Flow<System> f(NULL, &sys2);
	f.defineFunc(&sys2, funcG);

	Model<System, Flow<System>> sim;

	sim.addSystem(&sys2);
	sim.addFlow(&f);

	sim.runModel(100);
}