#pragma once
#include <cmath>
#include <iostream>
#include  <SFML\Graphics.hpp>
#define SCREEN_HIGHT 960
#define SCREEN_WIDTH 1200
#define G_Constant 6.6743 * pow(10, -11)

class Grav_Strength
{
public:
	Grav_Strength();
	
	//return distance beetwen two masess
	void distance(Particle& mass1, Particle& mass2) {
		x = mass1.get_pos().x + mass1.get_radius() - mass2.get_pos().x + mass2.get_radius();
		y = mass1.get_pos().y + mass1.get_radius() - mass2.get_pos().y + mass2.get_radius();
		r = sqrt(pow(x, 2) + pow(y, 2));
	}

	void force(Particle &mass1, Particle &mass2) {
		f = (mass1.get_mass() * mass2.get_mass()) / pow(r, 2);
	}

	float get_force_mass1_x() {
		std::cout << x / r << std::endl;
		return 100*(f * x / r);
	}
	float get_force_mass1_y() {
		return 100*(f * y / r);
	}
	float get_force_mass2_x() {
		return 100*(f * y / r);
	}
	float get_force_mass2_y() {
		return 100*(f * x / r);
	}
	~Grav_Strength();

private:
	float x, y, r;
	float f, f_mass1_x, f_mass2_x, f_mass1_y, f_mass2_y;
};

Grav_Strength::Grav_Strength()
{
}

Grav_Strength::~Grav_Strength()
{
}