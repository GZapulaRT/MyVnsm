#include "Exponencial.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include <assert.h>

float logistico(float a)
{
	return 0.01*a*(1-a/70);
}

void testLogistico()
{
	System p1(100), p2(100);
	Flow<System> f(&p1, &p2);
	f.defineFunc(&p2, logistico);

	Model<System, Flow<System>> sim;

	sim.addSystem(&p1);
	sim.addSystem(&p2);
	sim.addFlow(&f);

	sim.runModel(20);
}