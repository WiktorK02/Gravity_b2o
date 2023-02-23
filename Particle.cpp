
#include  <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>

#define SCREEN_HIGHT 960
#define SCREEN_WIDTH 1200
#define G_Constant 6.6743 * pow(10, -11)
class Particle
{
public:
    Particle(float posx, float posy, float radius, float velx, float vely, float mass, float accx, float accy);

    sf::Vector2f get_pos() {
        return pos;
    }
    float get_radius() {
        return radius;
    }
    float get_mass() {
        return mass;
    }
    void velocity(float dt) {
        pos.x += vel.x * dt;
        pos.y += vel.y * dt;
    }
    void acceleration(float dt) {
        vel.x += acc.x * dt;
        vel.y += acc.y * dt;
    }
    //void force(Grav_Strength &grav_strength) {
      //   acc.x += grav_strength.get_force_mass1_y();
        // acc.y += grav_strength.get_force_mass1_y();
    //}
    void collision() {
        if (pos.x <= 0) {
            vel.x = -vel.x;
            pos.x = 0;
        }
        if (pos.y <= 0) {
            vel.y = -vel.y;
            pos.y = 0;
        }
        if ((pos.x + radius * 2) >= SCREEN_WIDTH) {
            pos.x = SCREEN_WIDTH - radius * 2;
            vel.x = -vel.x;
        }
        if ((pos.y + radius * 2) >= SCREEN_HIGHT) {
            pos.y = SCREEN_HIGHT - radius * 2;
            vel.y = -vel.y;
        }
    }
    void render(sf::RenderWindow& window) {
        s.setPosition(pos);
        s.setRadius(this->radius);
        window.draw(s);
    }
    ~Particle();

private:
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;
    sf::Vector2f f;
    sf::CircleShape s;
    int radius;
    float mass;
    //Grav_Strength grav_strength;

};

Particle::Particle(float posx, float posy, float radius, float velx, float vely, float mass, float accx, float accy)
{
    pos.x = posx;
    pos.y = posy;

    vel.x = velx;
    vel.y = vely;

    acc.x = accx;
    acc.y = accy;

    this->mass = mass;
    this->radius = radius;
    
    s.setFillColor(sf::Color::Magenta);

}

Particle::~Particle()
{
}