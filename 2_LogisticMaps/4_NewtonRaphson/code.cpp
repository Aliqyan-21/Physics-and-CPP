// Newton Raphson of Function of One Variable

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	string buf;
	const double rho = 15.0;
	const double eps = 1.0e-6;
	const int NMAX = 1000;
	double x0, x1, err, g, gp;
	int i;

	// Input

	printf("Enter x0: ");
	scanf("%lf", &x0);
	getline(cin, buf);

	printf("Iter x error/n");
	printf("-----------------------------------/n");
	printf("0 %lf %lf/n", x0, err);

	// Calculate

	cout.precision(17);
	for (int i = 1; i <= NMAX; i++)
	{
		// Value of function g(x)
		g = x0 * tan(x0) - sqrt(rho * rho - x0 * x0);

		// Value of the derivative g'(x)
		gp = x0/sqrt(rho*rho - x0*x0) + x0/(cos(x0)*cos(x0))+tan(x0);
		x1 = x0 - g/gp;
		err = abs(x1-x0);

		if(err<eps) break;
		x0 = x1;
	}	
}