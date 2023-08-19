// **** Motion of a projectile near Earth's Surface ****
// **** Ignoring Air Resistance ****

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
	float x0, y0, R, x, y,  vx, vy, t, tf, dt;
	float theta, v0x, v0y, v0;

	printf("# Enter v0 and theta(in degrees): ");
	scanf("%f %f", &v0, &theta);
	getline(cin, buf);

	printf("# Enter tf and dt: ");
	scanf("%f %f", &tf, &dt);
	getline(cin, buf);

	printf("v0 = %f \t theta = %f degrees\n", v0, theta);
	printf("t0 = %f \t tf  = %f \t dt = %f\n", 0.0, tf, dt);

	if(v0 <= 0.0)
	{
		cerr << "Illegal value of v0 <= 0\n";
		exit(1);
	}
	if(v0 <= 0.0)
	{
		cerr << "Illegal value of theta <= 0\n";
		exit(1);
	}
	if(v0 >= 90.0)
	{
		cerr << "Illegal value of v0 >= 90\n";
		exit(1);
	}

	theta = (PI/180) * theta; // converting to radians

	v0x = v0 * cos(theta);
	v0y = v0 * sin(theta);

	printf("v0x = %f \t v0y = %f", v0x, v0y);

	ofstream myfile("Projectile.dat");
	myfile.precision(7);

	t = 0.0;

	while (t <= tf)
	{
		x = v0x * t;
		y = v0y * t - (0.5 * g * t * t);

		vx = v0x;
		vy = v0y - g*t;

		myfile << t << " " << x << " " << y << " " << vx << " " << vy << endl;

		t = t + dt;
  	}
}