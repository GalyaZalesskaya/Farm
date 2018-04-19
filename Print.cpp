#include "Print.h"
#include <SFML/Graphics.hpp>


Print::Print()
{
}

int Print::Begin_game()
{
	Shop my_shop;
	
		sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 3. kychka-pc.ru"); //��������� ��� �������� ������ ����

		sf::Image landimage; //������� ������ Image (�����������)
		landimage.loadFromFile("images/farm.png");//��������� � ���� ����
		//landimage.createMaskFromColor(sf::Color(255, 255, 255));

		sf::Texture landtexture;//������� ������ Texture (��������)
		landtexture.loadFromImage(landimage);//�������� � ���� ������ Image (�����������)

		sf::Sprite landsprite[16];//������� ������ Sprite(������)
		for (int i = 0; i < 16; i++)
		{
			landsprite[i].setTexture(landtexture);//������� � ���� ������ Texture (��������)
			landsprite[i].setTextureRect(sf::IntRect(440, 231, 80, 42));
			landsprite[i].setScale(0.67, 0.72);
		}
		sf::Sprite ordinaryland;
		ordinaryland.setTexture(landtexture);
		ordinaryland.setTextureRect(sf::IntRect(440, 231, 80, 42));
		ordinaryland.setScale(0.67,0.72);

		sf::Sprite groundsprite;
		groundsprite.setTexture(landtexture);
		groundsprite.setTextureRect(sf::IntRect(440, 283, 80, 42));
		groundsprite.setScale(0.67, 0.72);

		sf::Image bagimage;
		bagimage.loadFromFile("images/bag.png");
		sf::Texture bagtexture;
		bagtexture.loadFromImage(bagimage);
		sf::Sprite bagsprite;
		bagsprite.setTexture(bagtexture);
		bagsprite.setScale(0.1, 0.1);
		bagsprite.setPosition(10,10);

		sf::Image shopimage;
		shopimage.loadFromFile("images/Cart.png");
		sf::Texture shoptexture;
		shoptexture.loadFromImage(shopimage);
		sf::Sprite shopsprite;
		shopsprite.setTexture(shoptexture);
		shopsprite.setScale(0.33, 0.33);
		shopsprite.setPosition(90, 10);

		sf::Image menu;
		menu.loadFromFile("images/main_menu.png");
		//menu.createMaskFromColor(sf::Color(255,255,255));
		sf::Texture menutexture;
		menutexture.loadFromImage(menu);
		sf::Sprite menusprite;
		menusprite.setTexture(menutexture);
		menusprite.setPosition(50,50);
		menusprite.setScale(0.7,0.7);

		sf::Sprite partmenu[3];
		for (int i = 0; i < 3; i++)
		{
			partmenu[i].setTexture(landtexture);
			partmenu[i].setPosition(110 + 90 * i, 150);
		}




		int startX = 150, startY = 150;
		
		for (int i = 0; i < 4; i++)//10
			for (int j = 0; j < 4; j++)//12
				landsprite[i * 4 + j].setPosition(startX + 27.5 * (i % 2) + j * 55, startY + i * 14);//������ ��������� ���������� ��������� �������

		sf::Clock clock;

		bool flag_menu = 0;


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

			int mass[2], i0;
			int x1, x2, y1, y2;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				mass[0] = -1;
				mass[1] = -1;
				i0 = 0;

				for (int i = 0; i < 16; i++)
				{
					if (landsprite[i].getGlobalBounds().contains(pos.x, pos.y))
					{
						mass[i0] = i;
						i0++;
					}
					else
					{
						landsprite[i].setColor(sf::Color::White);//� ���� ��� ������� ����
					}
				}

				if (mass[1] >= 0)
				{
					x1 = landsprite[mass[0]].getPosition().x + 27.5;
					y1 = landsprite[mass[0]].getPosition().y + 14;
					x2 = landsprite[mass[1]].getPosition().x + 27.5;
					y2 = landsprite[mass[1]].getPosition().y + 14;
					if (pow(pow(x1 - pos.x, 2) + pow(y1 - pos.y, 2), 0.5) < pow(pow(x2 - pos.x, 2) + pow(y2 - pos.y, 2), 0.5))
					{
						landsprite[mass[0]].setColor(sf::Color::Red);
						landsprite[mass[1]].setColor(sf::Color::White);
						if (event.type == sf::Event::MouseButtonPressed)//���� ������ ������� ����
							if (event.key.code == sf::Mouse::Left)//� ������ �����
							{
								groundsprite.setPosition(landsprite[mass[0]].getPosition());
								landsprite[mass[0]] = groundsprite;
							}

					}
					else
					{
						landsprite[mass[0]].setColor(sf::Color::White);
						landsprite[mass[1]].setColor(sf::Color::Red);
						if (event.type == sf::Event::MouseButtonPressed)//���� ������ ������� ����
							if (event.key.code == sf::Mouse::Left)//� ������ �����
							{
								groundsprite.setPosition(landsprite[mass[1]].getPosition());
								landsprite[mass[1]] = groundsprite;
							}
					}
				}
				else
				{
					landsprite[mass[0]].setColor(sf::Color::Red);
					landsprite[mass[1]].setColor(sf::Color::White);
					if (event.type == sf::Event::MouseButtonPressed)//���� ������ ������� ����
						if (event.key.code == sf::Mouse::Left)//� ������ �����
						{
							groundsprite.setPosition(landsprite[mass[0]].getPosition());
							landsprite[mass[0]] = groundsprite;
						}
				}

				if (event.type == sf::Event::MouseButtonPressed)//���� ������ ������� ����
					if (event.key.code == sf::Mouse::Left)//� ������ �����
						if (shopsprite.getGlobalBounds().contains(pos.x, pos.y))
						{
							flag_menu = 1;
							std::cout << flag_menu;
						}
				if (flag_menu == 1)
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						flag_menu = 0;
			}
			
			window.clear(sf::Color(95,194,49));

			for (int i = 0; i < 16; i++)
				window.draw(landsprite[i]);
			window.draw(bagsprite);
			window.draw(shopsprite);

			if (flag_menu == 1)
			{
				window.draw(menusprite);

				partmenu[0].setTextureRect(sf::IntRect(my_shop.products[0]->Get_address().first, my_shop.products[0]->Get_address().second, my_shop.products[0]->Get_size().first, my_shop.products[0]->Get_size().second));
				partmenu[1].setTextureRect(sf::IntRect(my_shop.products[1]->Get_address().first, my_shop.products[1]->Get_address().second, my_shop.products[1]->Get_size().first, my_shop.products[1]->Get_size().second));
				partmenu[2].setTextureRect(sf::IntRect(my_shop.products[2]->Get_address().first, my_shop.products[2]->Get_address().second, my_shop.products[2]->Get_size().first, my_shop.products[2]->Get_size().second));

				
				window.draw(partmenu[0]);
				window.draw(partmenu[1]);
				window.draw(partmenu[2]);

			}
			


			window.display();
		}
		return 0;
	
}


Print::~Print()
{
}
