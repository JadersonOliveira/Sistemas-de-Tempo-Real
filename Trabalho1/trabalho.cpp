#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    bool comercar = false;
    bool receberTeclado = true;
    bool comecarContarTempo = false;
    bool tentativaErrado = false;
    bool resetar =  false;

    sf::Clock clock;
    sf::Time t1;
    string valor1 = "";
    string valor2 = "";
    string valor3 = "";
    string valor4 = "";

    srand(time(0));
    int cor_sorteada;
    int posicaoX_sorteada;//COLUNAS
    int posicaoY_sorteada; //LINHAS
    int pontuacao = 0;
    int tentativas = 0;
    int soma_tempo = 0;
    int cont = 0;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Trabalho 1 - Sistemas de Tempo Real");
    sf::CircleShape shape(50.f);
    shape.setPosition(posicaoX_sorteada,posicaoY_sorteada);
    shape.setFillColor(sf::Color::Green);


    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(700, 300));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(0, 475);


    //Declare and load a font
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Create a text1
    sf::Text text1("Score: ", font);
    text1.setCharacterSize(20);
    text1.setStyle(sf::Text::Bold);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(20, 480);

    // Create a text2
    sf::Text text2("Tempo de Reacao: ", font);
    text2.setCharacterSize(20);
    text2.setStyle(sf::Text::Bold);
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(20, 510);

    // Create a text3
    sf::Text text3("Tentativas: ", font);
    text3.setCharacterSize(20);
    text3.setStyle(sf::Text::Bold);
    text3.setFillColor(sf::Color::Red);
    text3.setPosition(20, 540);

    // Create a text4
    sf::Text text4("Media de Tempo: ", font);
    text4.setCharacterSize(20);
    text4.setStyle(sf::Text::Bold);
    text4.setFillColor(sf::Color::Red);
    text4.setPosition(20, 570);
    sf::Text text5("Pressione <Enter> para comecar", font);

    // Create a text5
    text5.setCharacterSize(20);
    text5.setStyle(sf::Text::Bold);
    text5.setFillColor(sf::Color::Red);
    text5.setPosition(150, 280);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)&&!comercar)
        {
            comercar = true;
        }
        if(!comercar)
        {
            window.clear();
            window.draw(text5);
            window.display();
        }

        if(comercar)
        {
            if(receberTeclado==1)
            {

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    if(cor_sorteada==0)
                    {
                        pontuacao++;
                        tentativaErrado = false;
                    }
                    else
                    {
                        pontuacao--;
                        tentativaErrado = true;
                    }
                    receberTeclado = false;
                    t1  = clock.getElapsedTime();
                    if(tentativaErrado==false)
                    {
                        if(cont<10)
                        {
                            soma_tempo+= t1.asMilliseconds();
                            cont++;
                        }
                    }
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    if(cor_sorteada==1)
                    {
                        pontuacao++;
                        tentativaErrado = false;
                    }
                    else
                    {
                        pontuacao--;
                        tentativaErrado = true;
                    }
                    receberTeclado = false;
                    t1  = clock.getElapsedTime();
                    if(tentativaErrado==false)
                    {
                        if(cont<10)
                        {
                            soma_tempo+= t1.asMilliseconds();
                            cont++;
                        }
                    }
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    if(cor_sorteada==2)
                    {
                        pontuacao++;
                        tentativaErrado = false;
                    }
                    else
                    {
                        pontuacao--;
                        tentativaErrado = true;
                    }
                    receberTeclado = false;
                    t1  = clock.getElapsedTime();
                    if(tentativaErrado==false)
                    {
                        if(cont<10)
                        {
                            soma_tempo+= t1.asMilliseconds();
                            cont++;
                        }
                    }
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    if(cor_sorteada==3)
                    {
                        pontuacao++;
                        tentativaErrado = false;
                    }
                    else
                    {
                        pontuacao--;
                        tentativaErrado = true;
                    }
                    receberTeclado = false;
                    t1  = clock.getElapsedTime();
                    if(tentativaErrado==false)
                    {
                        if(cont<10)
                        {
                            soma_tempo+= t1.asMilliseconds();
                            cont++;
                        }
                    }
                }

            }
            if(receberTeclado==false)
            {

                text1.setString(valor1);
                text2.setString(valor2);
                text3.setString(valor3);
                text4.setString(valor4);

                window.clear();
                window.draw(rectangle);
                window.draw(text1);
                window.draw(text2);
                window.draw(text3);
                window.draw(text4);
                window.display();

                t1  = clock.getElapsedTime();
                sf::sleep(sf::seconds(1.f));
                receberTeclado = true;
                comecarContarTempo = false;
            }

            if(comecarContarTempo==false)
            {
                if(cont==10)
                {
                    resetar = true;
                }
                if(resetar==false)
                {
                    tentativas++;
                    cor_sorteada =  rand() % 4;
                    posicaoX_sorteada = rand() % 500; //COLUNAS
                    posicaoY_sorteada = rand() % 300; //LINHAS
                    if(cor_sorteada == 0)
                    {
                        shape.setFillColor(sf::Color::Green);
                    }
                    else if(cor_sorteada == 1)
                    {
                        shape.setFillColor(sf::Color::Red);
                    }
                    else if(cor_sorteada == 2)
                    {
                        shape.setFillColor(sf::Color::Yellow);
                    }
                    else
                    {
                        shape.setFillColor(sf::Color::Blue);
                    }
                    shape.setPosition(posicaoX_sorteada, posicaoY_sorteada);
                    valor1 = "Score: " + to_string(pontuacao);
                    if(tentativaErrado)
                    {
                        valor2 = "Tempo de Reacao: ";
                    }
                    else
                    {
                        valor2 = "Tempo de Reacao: " + to_string(t1.asMilliseconds()) + "ms";
                    }
                    valor3 = "Tentativas: " + to_string(tentativas);

                    if(cont==10)
                    {
                        valor4 = "Media de Tempo (10 acertos): " + to_string(soma_tempo/10.0);
                    }
                    else
                    {
                        valor4 = "Media de Tempo: ";
                    }
                    text1.setString(valor1);
                    text2.setString(valor2);
                    text3.setString(valor3);
                    text4.setString(valor4);
                    window.clear();
                    window.draw(shape);
                    window.draw(rectangle);
                    window.draw(text1);
                    window.draw(text2);
                    window.draw(text3);
                    window.draw(text4);
                    window.display();
                    clock.restart();
                    comecarContarTempo = true;

                }
                else
                {
                    valor1 = "Score: " + to_string(pontuacao);
                    valor2 = "Tempo de Reacao:";
                    valor3 = "Tentativas: " + to_string(tentativas);
                    valor4 = "Media de Tempo (10 acertos): " + to_string(soma_tempo/10.0);
                    text1.setString(valor1);
                    text2.setString(valor2);
                    text3.setString(valor3);
                    text4.setString(valor4);
                    text5.setString("Pressione <R> pra reset");
                    text5.setPosition(150, 250);
                    window.clear();
                    window.draw(rectangle);
                    window.draw(text1);
                    window.draw(text2);
                    window.draw(text3);
                    window.draw(text4);
                    window.draw(text5);
                    window.display();
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                    {
                        cont=0;
                        comercar = false;
                        receberTeclado = true;
                        comecarContarTempo = false;
                        tentativaErrado = false;
                        text5.setString("Pressione <Enter> pra comecar");
                        text5.setPosition(150, 280);

                        srand(time(0));
                        pontuacao = 0;
                        tentativas = 0;
                        soma_tempo = 0;
                        cont = 0;
                        resetar = false;
                        t1  = t1 - t1;
                    }


                }

            }
        }

    }
}
