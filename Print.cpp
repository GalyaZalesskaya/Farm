#include "Print.h"
#include <SFML/Graphics.hpp>


Print::Print()
{
}

int Print::Begin_game()
{

	
		sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 3. kychka-pc.ru"); //увеличили дл€ удобства размер окна

		sf::Image landimage; //создаем объект Image (изображение)
		landimage.loadFromFile("images/farm.png");//загружаем в него файл
		landimage.createMaskFromColor(sf::Color(255, 255, 255));
		/*		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 25; j++)
				for (int k = 0; k < 25; k++)
					landimage.createMaskFromColor(sf::Color(255-i, 255-j, 255-k));
					*/
		sf::Texture landtexture;//создаем объект Texture (текстура)
		landtexture.loadFromImage(landimage);//передаем в него объект Image (изображени€)

		sf::Sprite landsprite[16];//создаем объект Sprite(спрайт)
		for (int i = 0; i < 16; i++)
		{
			landsprite[i].setTexture(landtexture);//передаЄм в него объект Texture (текстуры)
			landsprite[i].setTextureRect(sf::IntRect(440, 231, 80, 42));
		}
		int startX = 20, startY = 20;
		
		for (int i = 0; i < 4; i++)//10
			for (int j = 0; j < 4; j++)//12
					landsprite[i * 4 + j].setPosition(startX +40*(i%2)+ j * 80, startY + i * 21);//задаем начальные координаты по€влени€ спрайта				
			
			
	
		bool isMove = false;//переменна€ дл€ щелчка мыши по спрайту
		float dX = 0;//корректировка нажати€ по х
		float dY = 0;//по у

		sf::Clock clock;



		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее врем€ в микросекундах
			clock.restart(); //перезагружает врем€
			time = time / 800;

			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//забираем коорд курсора
			sf::Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
			//std::cout << pixelPos.x << "\n";//смотрим на координату ’ позиции курсора в консоли (она не будет больше ширины окна)
			//std::cout << pos.x << "\n";//смотрим на ’,котора€ преобразовалась в мировые координаты

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
							landsprite[i].setColor(sf::Color::Red);//и даем ему прежний цвет
							d = pow((pow((startX + 40 * ((i % 4) % 2) + (i / 4) * 80 + 40) - pos.x, 2) + pow((startY + (i % 4) * 21 + 21) - pos.y, 2)), 1 / 2);
							landsprite[i0].setColor(sf::Color::White);//и даем ему прежний цвет
							i0 = i;
						}
						else
						{
							landsprite[i].setColor(sf::Color::White);//и даем ему прежний цвет
						}
					}
					else
					{
						landsprite[i].setColor(sf::Color::White);//и даем ему прежний цвет
					}
				}
				/*
				if (event.type == sf::Event::MouseButtonPressed)//если нажата клавиша мыши
					if (event.key.code == sf::Mouse::Left)//а именно лева€
						if (herosprite.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
						{
							std::cout << "isClicked!\n";//выводим в консоль сообщение об этом
							dX = pos.x - herosprite.getPosition().x;//делаем разность между позицией курсора и спрайта.дл€ корректировки нажати€
							dY = pos.y - herosprite.getPosition().y;//тоже самое по игреку
							isMove = true;//можем двигать спрайт							
						}

				if (event.type == sf::Event::MouseButtonReleased)//если отпустили клавишу
					if (event.key.code == sf::Mouse::Left) //а именно левую
						isMove = false; //то не можем двигать спрайт
				herosprite.setColor(sf::Color::White);//и даем ему прежний цвет

			}

			if (isMove) {//если можем двигать
				herosprite.setColor(sf::Color::Green);//красим спрайт в зеленый 
				herosprite.setPosition(pos.x - dX, pos.y - dY);//можно и так написать,если у вас нету х и у*/
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
