#include "Complexo.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include <assert.h>

float func1(float a)
{
	return 0.1*a;
}

float func2(float a)
{
	return 0.3*a;
}

float func3(float a)
{
	return 0.15*a;
}

void testComplexo()
{
	System Q1(150), Q2(100), Q3(200), Q4(400), Q5(250);
	Flow<System> f(&Q1, &Q2);
	Flow<System> g(&Q1, &Q3);
	Flow<System> r(&Q2, &Q5);
	Flow<System> t(&Q2, &Q3);
	Flow<System> u(&Q3, &Q4);
	Flow<System> v(&Q4, &Q1);

	f.defineFunc(&Q1, func1);
	g.defineFunc(&Q1, func3);
	r.defineFunc(&Q2, func2);
	t.defineFunc(&Q2, func2);
	u.defineFunc(&Q3, func1);
	v.defineFunc(&Q4, func3);

	Model<System, Flow<System>> sim;

	sim.addSystem(&Q1);
	sim.addSystem(&Q2);
	sim.addSystem(&Q3);
	sim.addSystem(&Q4);
	sim.addSystem(&Q5);
	sim.addFlow(&f);
	sim.addFlow(&g);
	sim.addFlow(&r);
	sim.addFlow(&t);
	sim.addFlow(&u);
	sim.addFlow(&v);

	sim.runModel(15);
}