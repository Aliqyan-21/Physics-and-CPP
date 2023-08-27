// Motion of a free particle in a one dimensional box

// Use integration with timestep dt: x = x * v*dt

/* The user can set the size of the box L, the initial conditions x0 and v0 at time t0, the final time tf and the time step dt */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	string buf;
	float L, x0, v0, t0, tf, dt, t, x, v;

	printf("# Enter L: ");
	scanf("%f", &L);
	getline(cin, buf);

	printf("# Enter x0 and v0: ");
	scanf("%f %f", &x0, &v0);
	getline(cin, buf);

	printf("# Enter t0, tf, dt: ");
	scanf("%f %f", &t0, &tf, &dt);
	getline(cin, buf);

	printf("L = %f \n", L);
	printf("x0 = %f \t v0 = %f \n", x0, v0);
	printf("t0 = %f \t tf  = %f \t dt = %f\n", t0, tf, dt);

	if(L <= 0.0f)
	{
		cerr << "L <= 0\n";
		exit(1);
	}
	if(x0 < 0.0f)
	{
		cerr << "x0 <= 0\n";
		exit(1);
	}
	if(x0 > L)
	{
		cerr << "x0 >= L\n";
		exit(1);
	}
	if(v0 == 0.0f)
	{
		cerr << "v0 == 0\n";
		exit(1);
	}

	t = t0;
	x = x0;
	v = v0;
	ofstream myfile("OneDimensionalBox.dat");
	myfile.precision(9);

	while (t <= tf)
	{
		myfile << setw(17) << t << " " << setw(17) << x << " " << setw(17) << v << endl;

		x += v * dt;

		if(x<0.0f || x>L) v = -v;

		t = t + dt;
  	}
	myfile.close();
}