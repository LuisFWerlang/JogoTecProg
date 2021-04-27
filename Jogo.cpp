#include "Jogo.h"

Jogo::Jogo():
	window(sf::VideoMode(400, 400), "Jogo", sf::Style::Default)
{
    jogador1 - new Jogador();
    jogador1->setWindow(&window);
    fase1 = new Fase(jogador1, &window);
    LEs = fase1->getListaEntidades();
    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        jogador1->move();
        window.clear();
        for (int i = 0; i < LEs->LEs.getLen(); i++) {
            Entidade* temp = LEs->LEs.getItem(i);
            temp->draw();
        }
        jogador1->draw();
        window.display();
    }
}
