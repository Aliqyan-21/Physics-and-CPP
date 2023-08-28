// Bifurcation Diagram Of The Logistic Map

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	string buf;
	const double rmin = 2.5;
	const double rmax = 4.0;
	const double NTRANS = 500;
	const double NSTEPS = 100;
	const double RSTEPS = 2000;

	int i;
	double r, dr, x0, x1;

	// Initialize

	dr = (rmax - rmin) / RSTEPS; // Increment in r

	ofstream myfile("bif.dat");
	myfile.precision(17);

	// Calculate

	r = rmin;
	while(r <= rmax)
	{
		x0 = 0.5;
		// Transient steps skip
		for (int i = 1; i <= NTRANS; i++)
		{
			x1 = r * x0 * (1.0 - x0);
			x0 = x1;
		}
		// NSTEPS calculate
		for (int i = 1; i <= NSTEPS; i++)
		{
			x1 = r * x0 * (1.0 - x0);
			myfile << r << " " << x1 << endl;
			x0 = x1;
		}
		r += dr;
	}
	myfile.close();
}