// **** Motion In A Plane ****

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	int NSTEPS, i;
	double r, x0, x1;

	string buf;

	// Input

	printf("Enter NSTEPS, r, x0: ");
	scanf("%d %lf %lf", &NSTEPS, &r, &x0);
	getline(cin, buf);


	printf("# NSTEPS = %d\n", NSTEPS);
	printf("# r = %lf\n", r);
	printf("# x0 = %lf\n", x0);

	// Initialize

	ofstream myfile("trj.dat");
	myfile.precision(17);

	// Calculate

	myfile << 0 << " " << x0 << " " << 0 << endl;

	for (i = 1; i <= NSTEPS; i++)
	{
		x1 = r * x0 * (1.0 - x0);
		myfile << 2*i-3 << " " << x0 << " " << x1 << endl;
		myfile << 2*i-2 << " " << x1 << " " << x1 << endl;
		x0 = x1;
	}
	myfile.close();
}