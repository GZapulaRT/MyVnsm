#include "Troca.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include <assert.h>

float func4(float a)
{
	return 0.1*a;
}

float func5(float a)
{
	return 0.3*a;
}

void testTroca()
{
	System s1(100), s2(150);
	Flow<System> f(&s1, &s2);
	f.defineFunc(&s1, func4);
	Flow<System> g(&s2, &s1);
	g.defineFunc(&s2, func5);

	Model<System, Flow<System>> sim;

	sim.addSystem(&s1);
	sim.addSystem(&s2);
	sim.addFlow(&f);
	sim.addFlow(&g);

	sim.runModel(15);
}