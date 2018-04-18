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

		sf::Sprite landsprite[16];//������� ������ Sprite(������)
		for (int i = 0; i < 16; i++)
		{
			landsprite[i].setTexture(landtexture);//������� � ���� ������ Texture (��������)
			landsprite[i].setTextureRect(sf::IntRect(440, 231, 80, 42));
		}
		int startX = 20, startY = 20;
		
		for (int i = 0; i < 4; i++)//10
			for (int j = 0; j < 4; j++)//12
					landsprite[i * 4 + j].setPosition(startX +40*(i%2)+ j * 80, startY + i * 21);//������ ��������� ���������� ��������� �������				
			
			
	
		bool isMove = false;//���������� ��� ������ ���� �� �������
		float dX = 0;//������������� ������� �� �
		float dY = 0;//�� �

		sf::Clock clock;



		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
			clock.restart(); //������������� �����
			time = time / 800;

			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//�������� ����� �������
			sf::Vector2f pos = window.mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
			//std::cout << pixelPos.x << "\n";//������� �� ���������� � ������� ������� � ������� (��� �� ����� ������ ������ ����)
			//std::cout << pos.x << "\n";//������� �� �,������� ��������������� � ������� ����������

			sf::Event event;



			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				int i0 = 0;
				float d = FLT_MAX;

				for (int i = 0; i < 16; i++)
				{
					if (landsprite[i].getGlobalBounds().contains(pos.x, pos.y))
					{
						if (pow((pow((startX + 40 * ((i % 4) % 2) + (i / 4) * 80 + 40) - pos.x, 2) + pow((startY + (i % 4) * 21 + 21) - pos.y, 2)), 1 / 2) < d)
						{
							landsprite[i].setColor(sf::Color::Red);//� ���� ��� ������� ����
							d = pow((pow((startX + 40 * ((i % 4) % 2) + (i / 4) * 80 + 40) - pos.x, 2) + pow((startY + (i % 4) * 21 + 21) - pos.y, 2)), 1 / 2);
							landsprite[i0].setColor(sf::Color::White);//� ���� ��� ������� ����
							i0 = i;
						}
						else
						{
							landsprite[i].setColor(sf::Color::White);//� ���� ��� ������� ����
						}
					}
					else
					{
						landsprite[i].setColor(sf::Color::White);//� ���� ��� ������� ����
					}
				}
				/*
				if (event.type == sf::Event::MouseButtonPressed)//���� ������ ������� ����
					if (event.key.code == sf::Mouse::Left)//� ������ �����
						if (herosprite.getGlobalBounds().contains(pos.x, pos.y))//� ��� ���� ���������� ������� �������� � ������
						{
							std::cout << "isClicked!\n";//������� � ������� ��������� �� ����
							dX = pos.x - herosprite.getPosition().x;//������ �������� ����� �������� ������� � �������.��� ������������� �������
							dY = pos.y - herosprite.getPosition().y;//���� ����� �� ������
							isMove = true;//����� ������� ������							
						}

				if (event.type == sf::Event::MouseButtonReleased)//���� ��������� �������
					if (event.key.code == sf::Mouse::Left) //� ������ �����
						isMove = false; //�� �� ����� ������� ������
				herosprite.setColor(sf::Color::White);//� ���� ��� ������� ����

			}

			if (isMove) {//���� ����� �������
				herosprite.setColor(sf::Color::Green);//������ ������ � ������� 
				herosprite.setPosition(pos.x - dX, pos.y - dY);//����� � ��� ��������,���� � ��� ���� � � �*/
			}
			
			window.clear(sf::Color(95,194,49));

			for (int i = 0; i < 16; i++)
				window.draw(landsprite[i]);

					

			window.display();
		}
		return 0;
	
}


Print::~Print()
{
}
