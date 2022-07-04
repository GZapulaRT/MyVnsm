#include "Exponencial.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include <assert.h>

float exponencial(float a)
{
	return 0.3*a;
}

void testExponencial()
{
	System pop1(250), pop2(200);
	Flow<System> f(&pop1, &pop2);
	f.defineFunc(&pop1, exponencial);

	Model<System, Flow<System>> sim;

	sim.addSystem(&pop1);
	sim.addSystem(&pop2);
	sim.addFlow(&f);

	sim.runModel(10);
}