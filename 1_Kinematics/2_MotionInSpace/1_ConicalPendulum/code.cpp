// **** Conical Pendulum ****

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

#define PI 3.141592
#define g 9.81

int main()
{
	string buf;
	float l, r, x, y, z, vx, vy, vz, t, tf, dt;
	float theta, cos_theta, sin_theta, omega;

	printf("# Enter l and omega: ");
	scanf("%f %f", &l, &omega);
	getline(cin, buf);

	printf("# Enter tf and dt: ");
	scanf("%f %f", &tf, &dt);
	getline(cin, buf);

	printf("l = %f \t omega = %f\n", l, omega);
	printf("# T = %f \t omega_min = %f\n", 2.0 * PI / omega, sqrt(g/l));
	printf("t0 = %f \t tf  = %f \t dt = %f\n", 0.0, tf, dt);

	cos_theta = g / (omega * omega * l);

	if(cos_theta >= 1.0)
	{
		cerr << "cos(theta) >= 1\n";
		exit(1);
	}

	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	z = -g / (omega * omega); // remain const throughout motion
	vz = 0.0;

	r = g / (omega * omega) * sin_theta / cos_theta;

	ofstream myfile("ConicalPendulum.dat");
	myfile.precision(7);

	t = 0.0;

	while (t <= tf)
	{
		x = r * cos(omega * t);
		y = r * sin(omega * t);

		vx = -omega * r * sin(omega * t);
		vy = omega * r * cos(omega * t);

		myfile << t << " " << x << " " << y << " " << z << " " << vx << " " << vy << " " << vz << endl;

		t = t + dt;
  	}
}