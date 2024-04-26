#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(800, 800), "Chess App");  // TODO: Refactor into a class later (this is for prototyping only)

void draw_board() {
    float square_size = 100.f;


    for (int i = 0; i < 8*8 ; ++i) {
        sf::RectangleShape square(sf::Vector2f(square_size, square_size));



        int file = i % 8;
        int rank = i / 8;

        if ((file+rank) % 2  == 0)
            square.setFillColor(sf::Color::White);
        else
            square.setFillColor(sf::Color::Black);

        square.setPosition((square_size * file), (square_size * rank));

        window.draw(square);
    }
}

int main() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        draw_board();
        window.display();
    }

    return 0;
}
