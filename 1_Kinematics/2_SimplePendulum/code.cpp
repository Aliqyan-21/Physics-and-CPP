// **** Motion In A Plane ****

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

#define PI 3.141592
#define g 9.81

int main() {
	string buf;
	float l, x, y, vx, vy, t, t0, tf, dt;
	float theta, theta0, dtheta_dt, omega;

	printf("# Enter l: ");
	scanf("%f", &l);
	getline(cin, buf);

	printf("# Enter theta0: ");
	scanf("%f", &theta0);
	getline(cin, buf);

	printf("# Enter time t0, tf, dt: ");
	scanf("%f %f %f", &t0, &tf, &dt);
	getline(cin, buf);

	printf("l = %f \t theta0 = %f\n", l, theta0);
	printf("t0 = %f \t tf  = %f \t dt = %f\n", t0, tf, dt);

	omega = sqrt(g / l);

	printf("# Omega = %f", omega);

	printf("T = %f", 2 * PI / omega);

	ofstream myfile("Pendulum.dat");
	myfile.precision(7);

	t = t0;

	while (t <= tf)
	{
		theta = theta0 * cos(omega * (t - t0));
		dtheta_dt = -omega * theta0 * sin(omega * (t - t0));

		x = l * sin(theta);
		y = -l * cos(theta);
		vx = l * dtheta_dt * cos(theta);
		vy = l * dtheta_dt * sin(theta);

		myfile << t << " " << x << " " << y << " " << vx << " " << vy << " " << theta << " " << dtheta_dt << endl; 

		t = t + dt;
  	}
}