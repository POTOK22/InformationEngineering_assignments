#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1080, 600), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::CircleShape mycircle(50.0);
    mycircle.setPosition(100.0, 100.0);
    mycircle.setFillColor(sf::Color(150, 220, 90));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::RectangleShape myrectangle(sf::Vector2f(100.0, 50.0));
    myrectangle.setPosition(sf::Vector2f(400.0, 500.0));
    myrectangle.setFillColor(sf::Color::Red);
    myrectangle.setOutlineColor(sf::Color::White);
    myrectangle.setOutlineThickness(2.0);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::ConvexShape mytriangle;
    mytriangle.setPointCount(3);
    mytriangle.setPoint(0, sf::Vector2f(100.0f, 100.0f));
    mytriangle.setPoint(1, sf::Vector2f(200.0f, 100.0f));
    mytriangle.setPoint(2, sf::Vector2f(150.0f, 50.0f));
    mytriangle.setFillColor(sf::Color::Green);
    mytriangle.setOutlineColor(sf::Color::White);
    mytriangle.setOutlineThickness(2.0f);
    mytriangle.setPosition(400.0, 250.0);

    // run the program as long as the window is open
    sf::Clock clock;
    int rectangle_velocity_x=1650;
    int rectangle_velocity_y=1750;
    int rectangle_angular_velocity=120;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        //time description in microseconds
        sf::Time elapsed = clock.restart();
        float time = elapsed.asMicroseconds();
        std::cout<<time<<std::endl;

        //describing a time change in seconds
        sf::Time delta = clock.restart();
        float dt = delta.asSeconds();

        //methods to move and rotate a rectangle (delta x = velocity*delta t)
        rectangle.move(rectangle_velocity_x*dt, rectangle_velocity_y*dt);
        rectangle.rotate(rectangle_angular_velocity*dt);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
        std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;

        //top
        if(rectangle_bounds.top<=0){
            rectangle_velocity_y=abs(rectangle_velocity_y);
            rectangle.setFillColor(sf::Color(rand() %256, rand() %256, rand() %256));
        }
        //bottom
        if(rectangle_bounds.top+rectangle_bounds.height>=window.getSize().y){
            rectangle_velocity_y=abs(rectangle_velocity_x)*(-1);
            rectangle.setFillColor(sf::Color(rand() %256, rand() %256, rand() %256));
        }
        //left
        if(rectangle_bounds.left<=0){
            rectangle_velocity_x=abs(rectangle_velocity_x);
            rectangle.setFillColor(sf::Color(rand() %256, rand() %256, rand() %256));
        }
        //right
        if(rectangle_bounds.left+rectangle_bounds.width>=window.getSize().x){
            rectangle_velocity_x=abs(rectangle_velocity_y)*(-1);
            rectangle.setFillColor(sf::Color(rand() %256, rand() %256, rand() %256));
        }


        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(mycircle);
        window.draw(rectangle);
        window.draw(myrectangle);
        window.draw(triangle);
        window.draw(mytriangle);

        // end the current frame
        window.display();
    }

    return 0;
}
