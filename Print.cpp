#include "Print.h"
#include <SFML/Graphics.hpp>


Print::Print()
{
}

int Print::Begin_game()
{
	Shop my_shop;
	Bag bag;

	sf::RenderWindow window(sf::VideoMode(626, 626), "Lesson 3. kychka-pc.ru"); //óâåëè÷èëè äëÿ óäîáñòâà ðàçìåð îêíà

	sf::Image fonimage;
	fonimage.loadFromFile("images/fon.png");
	sf::Texture fontexture;
	fontexture.loadFromImage(fonimage);
	sf::Sprite fonsprite;
	fonsprite.setTexture(fontexture);
	fonsprite.setPosition(0, 0);

	sf::Image landimage;
	landimage.loadFromFile("images/farm.png");
	sf::Texture landtexture;
	landtexture.loadFromImage(landimage);
	sf::Sprite landsprite[16];
	for (int i = 0; i < 16; i++)
	{
		landsprite[i].setTexture(landtexture);
		landsprite[i].setTextureRect(sf::IntRect(440, 231, 80, 42));
		landsprite[i].setScale(0.67, 0.72);
	}

	sf::Sprite ordinaryland;
	ordinaryland.setTexture(landtexture);
	ordinaryland.setTextureRect(sf::IntRect(440, 231, 80, 42));
	ordinaryland.setScale(0.67, 0.72);

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
	bagsprite.setPosition(25, 530);

	sf::Image shopimage;
	shopimage.loadFromFile("images/Cart.png");
	sf::Texture shoptexture;
	shoptexture.loadFromImage(shopimage);
	sf::Sprite shopsprite;
	shopsprite.setTexture(shoptexture);
	shopsprite.setScale(0.33, 0.33);
	shopsprite.setPosition(110, 530);

	sf::Image menu;
	menu.loadFromFile("images/shop_menu.png");
	sf::Texture menutexture;
	menutexture.loadFromImage(menu);
	sf::Sprite menusprite;
	menusprite.setTexture(menutexture);
	menusprite.setPosition(75, 230);
	menusprite.setScale(0.75, 0.75);

	sf::Image mybagimage;
	mybagimage.loadFromFile("images/my_bag.png");
	sf::Texture mybagtexture;
	mybagtexture.loadFromImage(mybagimage);
	sf::Sprite mybagsprite;
	mybagsprite.setTexture(mybagtexture);
	mybagsprite.setPosition(75, 230);
	mybagsprite.setScale(0.75, 0.75);

	sf::Sprite partmenu[4];
	for (int i = 0; i < 4; i++)
	{
		partmenu[i].setTexture(landtexture);
		partmenu[i].setPosition(110 + 90 * i, 150);
	}

	sf::Image fieldimage;
	fieldimage.loadFromFile("images/field.png");
	sf::Texture fieldtexture;
	fieldtexture.loadFromImage(fieldimage);
	sf::Sprite fieldsprite;
	fieldsprite.setTexture(fieldtexture);
	fieldsprite.setPosition(8, 520);

	sf::Texture pointexture;
	pointexture.loadFromFile("images/point.png");
	sf::Sprite rightpoint, leftpoint;
	rightpoint.setTexture(pointexture);
	leftpoint.setTexture(pointexture);
	leftpoint.setTextureRect(sf::IntRect(0, 0, 50, 50));
	rightpoint.setTextureRect(sf::IntRect(69, 0, 50, 50));
	leftpoint.setScale(0.85, 0.85);
	rightpoint.setScale(0.85, 0.85);

	leftpoint.setPosition(menusprite.getPosition().x + 6, menusprite.getPosition().y + 105);
	rightpoint.setPosition(menusprite.getGlobalBounds().left + menusprite.getGlobalBounds().width - 6 - rightpoint.getGlobalBounds().width, menusprite.getPosition().y + 105);
	int startX = 200, startY = 300;

	for (int i = 0; i < 4; i++)//10
		for (int j = 0; j < 4; j++)//12
			landsprite[i * 4 + j].setPosition(startX + 27.5 * (i % 2) + j * 55, startY + i * 14);//çàäàåì íà÷àëüíûå êîîðäèíàòû ïîÿâëåíèÿ ñïðàéòà

	sf::Texture moneytexture;
	moneytexture.loadFromFile("images/money.png");
	sf::Sprite moneysprite;
	moneysprite.setTexture(moneytexture);
	moneysprite.setScale(0.05, 0.05);




	sf::Clock clock;
	bool flag_menu = 0, flag_bag = 0;
	int pos1, pos2;
	int current_num = 0, shop_size = my_shop.products.size(), bag_size = 0;
	sf::Font font;//øðèôò 
	font.loadFromFile("CyrilicOld.ttf");//ïåðåäàåì íàøåìó øðèôòó ôàéë øðèôòà
	sf::Text text("", font, 15);//ñîçäàåì îáúåêò òåêñò. çàêèäûâàåì â îáúåêò òåêñò ñòðîêó, øðèôò, ðàçìåð øðèôòà(â ïèêñåëÿõ);//ñàì îáúåêò òåêñò (íå ñòðîêà)
	text.setColor(sf::Color::White);//ïîêðàñèëè òåêñò â êðàñíûé. åñëè óáðàòü ýòó ñòðîêó, òî ïî óìîë÷àíèþ îí áåëûé



	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //äàòü ïðîøåäøåå âðåìÿ â ìèêðîñåêóíäàõ
		clock.restart(); //ïåðåçàãðóæàåò âðåìÿ
		time = time / 800;

		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//çàáèðàåì êîîðä êóðñîðà
		sf::Vector2f pos = window.mapPixelToCoords(pixelPos);//ïåðåâîäèì èõ â èãðîâûå (óõîäèì îò êîîðä îêíà)

		sf::Event event;

		int mass[2], i0;
		int x1, x2, y1, y2;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}
			mass[0] = -1;
			mass[1] = -1;
			i0 = 0;
			if ((flag_menu != 1) || (flag_bag != 1) )
			{
				for (int i = 0; i < 16; i++)
				{
					if (landsprite[i].getGlobalBounds().contains(pos.x, pos.y))
					{
						mass[i0] = i;
						i0++;
					}
					else
					{
						landsprite[i].setColor(sf::Color::White);//è äàåì åìó ïðåæíèé öâåò
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
						landsprite[mass[0]].setColor(sf::Color::Green);
						landsprite[mass[1]].setColor(sf::Color::White);
						if (event.type == sf::Event::MouseButtonPressed)//åñëè íàæàòà êëàâèøà ìûøè
							if (event.key.code == sf::Mouse::Left)//à èìåííî ëåâàÿ
							{
								groundsprite.setPosition(landsprite[mass[0]].getPosition());
								landsprite[mass[0]] = groundsprite;
							}

					}
					else
					{
						landsprite[mass[0]].setColor(sf::Color::White);
						landsprite[mass[1]].setColor(sf::Color::Green);
						if (event.type == sf::Event::MouseButtonPressed)//åñëè íàæàòà êëàâèøà ìûøè
							if (event.key.code == sf::Mouse::Left)//à èìåííî ëåâàÿ
							{
								groundsprite.setPosition(landsprite[mass[1]].getPosition());
								landsprite[mass[1]] = groundsprite;
							}
					}
				}
				else
				{
					landsprite[mass[0]].setColor(sf::Color::Green);
					landsprite[mass[1]].setColor(sf::Color::White);
					if (event.type == sf::Event::MouseButtonPressed)//åñëè íàæàòà êëàâèøà ìûøè
						if (event.key.code == sf::Mouse::Left)//à èìåííî ëåâàÿ
						{
							groundsprite.setPosition(landsprite[mass[0]].getPosition());
							landsprite[mass[0]] = groundsprite;
						}
				}

			}
			if ((flag_bag!=1) && (flag_menu!=1))
				if (event.type == sf::Event::MouseButtonPressed)
					if (event.key.code == sf::Mouse::Left)
					{
						if (shopsprite.getGlobalBounds().contains(pos.x, pos.y))
						{
							flag_menu = 1;
							current_num = 0;
						}
						if (bagsprite.getGlobalBounds().contains(pos.x, pos.y))
						{
							flag_bag = 1;
							current_num = 0;
						}
					}
			

			if (flag_menu == 1)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					flag_menu = 0;

				for (int j = 0; j < 4; j++)
				{
					if (partmenu[j].getGlobalBounds().contains(pos.x, pos.y))
					{
						partmenu[j].setColor(sf::Color::Magenta);
						if ((event.type == sf::Event::MouseButtonPressed) && (event.key.code == sf::Mouse::Left))
						{
							Product* new_product = new Product(my_shop.products[current_num + j]);
							bag.Buy_product(new_product);
							//bag.Buy_product(my_shop.products[current_num + j]);

						}
						std::cout << bag.my_products.size() << std::endl;
					}
					else
						partmenu[j].setColor(sf::Color::White);
				}

				if (current_num < shop_size - 4)
				{
					if (rightpoint.getGlobalBounds().contains(pos.x, pos.y))
					{
						rightpoint.setColor(sf::Color::Green);
						if ((event.type == sf::Event::MouseButtonPressed) && (event.key.code == sf::Mouse::Left))
							current_num++;
					}
					else
						rightpoint.setColor(sf::Color::White);
				}
				else
					rightpoint.setColor(sf::Color(170, 170, 170));

				if (current_num != 0)
				{

					if (leftpoint.getGlobalBounds().contains(pos.x, pos.y))
					{
						leftpoint.setColor(sf::Color::Green);
						if ((event.type == sf::Event::MouseButtonPressed) && (event.key.code == sf::Mouse::Left))
							current_num--;
					}
					else
						leftpoint.setColor(sf::Color::White);
				}
				else
					leftpoint.setColor(sf::Color(170, 170, 170));
			}
			//BAG
			if (flag_bag == 1)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					flag_bag = 0;

				for (int j = 0; j < 4; j++)
				{
					if (partmenu[j].getGlobalBounds().contains(pos.x, pos.y))
						partmenu[j].setColor(sf::Color::Magenta);
					else
						partmenu[j].setColor(sf::Color::White);
				}


				if (current_num != 0)
				{
					if (leftpoint.getGlobalBounds().contains(pos.x, pos.y))
					{
						leftpoint.setColor(sf::Color::Green);
						if ((event.type == sf::Event::MouseButtonPressed) && (event.key.code == sf::Mouse::Left))
							current_num--;
					}
					else
						leftpoint.setColor(sf::Color::White);
				}
				else
					leftpoint.setColor(sf::Color(170, 170, 170));

				std::cout << bag.my_products.size();

				if ((current_num < bag.my_products.size() - 4) && (bag.my_products.size()>4))
				{

					if (rightpoint.getGlobalBounds().contains(pos.x, pos.y))
					{
						rightpoint.setColor(sf::Color::Green);
						if ((event.type == sf::Event::MouseButtonPressed) && (event.key.code == sf::Mouse::Left))
							current_num++;
					}
					else
						rightpoint.setColor(sf::Color::White);
				}
				else
					rightpoint.setColor(sf::Color(170, 170, 170));

			}
		}

		window.clear(sf::Color(95, 194, 49));
		window.draw(fonsprite);

		for (int i = 0; i < 16; i++)
			window.draw(landsprite[i]);
		window.draw(fieldsprite);
		window.draw(bagsprite);
		window.draw(shopsprite);


		if (flag_menu == 1)
		{
			window.draw(menusprite);
			
			for (int j = 0; j < 4; j++)
			{
				partmenu[j].setTextureRect(sf::IntRect(my_shop.products[current_num + j]->Get_address().first, my_shop.products[current_num + j]->Get_address().second, my_shop.products[current_num + j]->Get_size().first, my_shop.products[current_num + j]->Get_size().second));
				pos1 = menusprite.getPosition().x + 65 + 55 * j + 30 * j;
				pos2 = menusprite.getPosition().y + 80 + (85 - my_shop.products[current_num + j]->Get_size().second);
				partmenu[j].setPosition(pos1, pos2);
				text.setString(my_shop.products[current_num + j]->Get_name());//çàäàåò ñòðîêó òåêñòó
				text.setPosition(pos1 - 5, pos2 + 10 + my_shop.products[current_num + j]->Get_size().second);//çàäàåì ïîçèöèþ òåêñòà, öåíòð êàìåðû
				window.draw(text);//ðèñóþ ýòîò òåêñò
				moneysprite.setPosition(pos1 - 10, pos2 + 22 + my_shop.products[current_num + j]->Get_size().second + 5);
				text.setString(std::to_string(my_shop.products[current_num + j]->Get_price_for_seed()));
				text.setPosition(pos1 + 10, pos2 + 22 + my_shop.products[current_num + j]->Get_size().second + 5);
				window.draw(text);//рисую этот текст
				window.draw(moneysprite);
				window.draw(partmenu[j]);
			}
			window.draw(leftpoint);
			window.draw(rightpoint);
		}
		if (bag.my_products.size() < 4)
			bag_size = bag.my_products.size();
		else
			bag_size = 4;

		if (flag_bag == 1)
		{
			window.draw(mybagsprite);
			
			for (int j = 0; j < bag_size; j++)
			{
				partmenu[j].setTextureRect(sf::IntRect(bag.my_products[current_num + j]->Get_address().first, bag.my_products[current_num + j]->Get_address().second, bag.my_products[current_num + j]->Get_size().first, bag.my_products[current_num + j]->Get_size().second));
				pos1 = mybagsprite.getPosition().x + 65 + 55 * j + 30 * j;
				pos2 = mybagsprite.getPosition().y + 80 + (85 - bag.my_products[current_num + j]->Get_size().second);
				partmenu[j].setPosition(pos1, pos2);
				text.setString(bag.my_products[current_num + j]->Get_name());//çàäàåò ñòðîêó òåêñòó
				text.setPosition(pos1 - 5, pos2 + 10 + bag.my_products[current_num + j]->Get_size().second);//çàäàåì ïîçèöèþ òåêñòà, öåíòð êàìåðû
				window.draw(text);//ðèñóþ ýòîò òåêñò
				moneysprite.setPosition(pos1 - 10, pos2 + 22 + bag.my_products[current_num + j]->Get_size().second + 5);
				text.setString(std::to_string(bag.my_products[current_num + j]->Get_price_for_fetus()));
				text.setPosition(pos1 + 10, pos2 + 22 + bag.my_products[current_num + j]->Get_size().second + 5);
				window.draw(text);//рисую этот текст
				window.draw(moneysprite);
				window.draw(partmenu[j]);
			}
			window.draw(leftpoint);
			window.draw(rightpoint);
		}
	
		window.display();
	}

}


Print::~Print()
{
}
