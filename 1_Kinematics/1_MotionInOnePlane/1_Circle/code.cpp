// **** Motion In A Plane ****

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

#define PI 3.141592

int main() {
	string buf;

	/*
	The center of the circle (x0 , y0 ), the
	radius R of the circle and the angle θ are stored in the double variables
	x0, y0, R, theta. The times at which we calculate the particle’s position
	and velocity are defined by the parameters t0 , tf , δt and are stored in the
	double variables t0, tf, dt. The current position (x(t), y(t)) is calculated
	and stored in the double variables x, y and the velocity (vx (t), vy (t)) in
	the double variables vx, vy. The declarations of the variables are put in
	the beginning of the program.
	*/
	float x0, y0, R, x, y, vx, vy, t, t0, tf, dt;
	float theta, omega;

	printf("# Enter Omega: ");
	scanf("%f", &omega);
	getline(cin, buf);

	printf("# Enter center of circle (x0, y0) and radius R: ");
	scanf("%f %f %f", &x0, &y0, &R);
	getline(cin, buf);

	printf("# Enter time t0, tf, dt: ");
	scanf("%f %f %f", &t0, &tf, &dt);
	getline(cin, buf);

	printf("omega = %f\n", omega);
	printf("x0 = %f \t y0 = %f \t R = %f\n", x0, y0, R);
	printf("t0 = %f \t tf  = %f \t dt = %f\n", t0, tf, dt);

	if (R <= 0)
	{
		cerr << "Illegal value of R\n";
		exit(1);
  	}

  	if (omega <= 0)
  	{
    	cerr << "Illegal value of omega\n";
		exit(1);
	}

  printf("# T = %f\n", 2.0 * PI / omega);

  ofstream myfile("Circle.dat");
  myfile.precision(7);

  t = t0;

  while(t <= tf)
  {
	theta = omega * (t - t0);
	x = x0 + R * cos(theta);
	y = y0 + R * sin(theta);

	vx = -omega * R * sin(theta);
	vx = omega * R * cos(theta);

	myfile << t << " " << x << " " << y << " " << vx << " " << vy << endl;

	t = t + dt;
  }
}