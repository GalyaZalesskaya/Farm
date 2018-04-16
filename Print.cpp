#include "Print.h"
#include <SFML/Graphics.hpp>


Print::Print()
{
}

int Print::Begin_game()
{

	
		sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 3. kychka-pc.ru"); //��������� ��� �������� ������ ����

		sf::Image landimage; //������� ������ Image (�����������)
		landimage.loadFromFile("images/farm.png");//��������� � ���� ����
		landimage.createMaskFromColor(sf::Color(255, 255, 255));
		/*		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 25; j++)
				for (int k = 0; k < 25; k++)
					landimage.createMaskFromColor(sf::Color(255-i, 255-j, 255-k));
					*/


		


		sf::Texture landtexture;//������� ������ Texture (��������)
		landtexture.loadFromImage(landimage);//�������� � ���� ������ Image (�����������)

		sf::Sprite landsprite[2];//������� ������ Sprite(������)
		landsprite[0].setTexture(landtexture);//������� � ���� ������ Texture (��������)
		landsprite[0].setTextureRect(sf::IntRect(440, 231, 80, 42));
		landsprite[1].setTexture(landtexture);//������� � ���� ������ Texture (��������)
		landsprite[1].setTextureRect(sf::IntRect(440, 231, 80, 42));


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color(95,194,49));

			for (int i = 0; i < 8; i++)//10
				for (int j = 0; j < 10; j++)//12
				{
					landsprite[0].setPosition(20+i * 80,20+j * 42);//������ ��������� ���������� ��������� �������
					window.draw(landsprite[0]);//������� ������ �� �����
					landsprite[1].setPosition( 20+40 + i * 80, 20+ 21 + j * 42);//������ ��������� ���������� ��������� �������
					window.draw(landsprite[1]);//������� ������ �� �����

				}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				landsprite[1].setColor(sf::Color::Red);
			}
	
			window.display();
		}
		return 0;
	
}


Print::~Print()
{
}
