#include  <SFML\Graphics.hpp>
#include <iostream>
#include "Particle.cpp"
#include "Strength.cpp"

#define SCREEN_HIGHT 960
#define SCREEN_WIDTH 1200

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), "title");
    window.setFramerateLimit(60);
    
    //CRICLE declaration
    Grav_Strength grav_strength;
    Particle mass1(150, 400, 60, 0, 0, 50, 0, 0);//posx, posy, radius, velx, vely, accx, accy
    Particle mass2(600, 500, 60, 0.6, 2, 60, 89, -50);//posx, posy, radius, velx, vely, accx, accy
    sf::Event event;
    
    sf::Clock clock;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }

        }
        
        grav_strength.distance(mass1, mass2);
        grav_strength.force(mass1, mass2);
        grav_strength.force_mass1_x(mass1);
        float dt = clock.restart().asSeconds();

        //std::cout << grav_strength.get_force_mass1_x()<< std::endl;
        //render
        window.clear();//clear old frames

        //draw 
        mass1.render(window);
        mass2.render(window);
        
        //line
        sf::Vertex line[] = { sf::Vertex(sf::Vector2f(mass1.get_pos().x + mass1.get_radius(), mass1.get_pos().y + mass1.get_radius())), sf::Vertex(sf::Vector2f(mass2.get_pos().x + mass1.get_radius(), mass2.get_pos().y + mass1.get_radius())) };
        window.draw(line, 2, sf::Lines);

        mass1.velocity(dt);
        mass2.velocity(dt);
        mass1.acceleration(dt);
        mass2.acceleration(dt);
        //mass1.force(grav_strength);
        //mass2.force(grav_strength);
        mass1.collision();
        mass2.collision();

        window.display();


    }

    return 0;
}