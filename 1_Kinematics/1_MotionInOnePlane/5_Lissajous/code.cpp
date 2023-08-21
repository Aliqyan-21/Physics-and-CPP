// **** Lissajous Curves (Special Case) ****
// **** x(t) = cos(o1*t), y(t) = sin(o2*t)

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

#define PI 3.141592

int main()
{
	string buf;
	float x0, y0, R, x, y,  vx, vy, t, t0, tf, dt;
	float o1, o2 , T1, T2;

	printf("# Enter omega1 and omega2: ");
	scanf("%f %f", &o1, &o2);
	getline(cin, buf);

	printf("# Enter tf and dt: ");
	scanf("%f %f", &tf, &dt);
	getline(cin, buf);

	printf("o1 = %f \t o2 = %f\n", o1, o2);
	printf("t0 = %f \t tf  = %f \t dt = %f\n", 0.0, tf, dt);

	if(o1 <= 0.0)
	{
		cerr << "Illegal value of o1 <= 0\n";
		exit(1);
	}
	if(o2 <= 0.0)
	{
		cerr << "Illegal value of o2 <= 0\n";
		exit(1);
	}

	T1 = (2 * PI) / o1;
	T2 = (2 * PI) / o2;

	printf("T1 = %f \t T2 = %f\n", T1, T2);

	ofstream myfile("Lissajous.dat");
	myfile.precision(7);

	t = t0;

	while (t <= tf)
	{
		x = cos(o1 * t);
		y = sin(o2 * t);

		vx = -o1 * sin(o1 * t);
		vy = o2 * cos(o2 * t);

		myfile << t << " " << x << " " << y << " " << vx << " " << vy << endl;

		t = t + dt;
  	}
}