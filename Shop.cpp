#include "Shop.h"


Shop::Shop()
{
	Product* Tulip = new Product("�������", 100, 120, 350, 9, 55, 44);
	Product* Rose = new Product("����", 180, 200, 350, 53, 55, 37);
	Product* Iris = new Product("����", 170, 210, 346, 90, 55, 59);
	Product* Cabbage = new Product("�������", 90, 140, 360, 162, 55, 33);
	Product* Pepper = new Product("�����", 70, 160, 362, 200, 55, 39);
	Product* Greenery = new Product("������", 90, 130, 360, 246, 55, 26);
	Product* Carrot = new Product("�������", 100, 160, 360, 280, 55, 31);
	Product* Corn = new Product("��������", 140, 200, 360, 320, 55, 48);
	Product* Pumpkin = new Product("�����", 150, 210, 360, 376, 55, 33);
	Product* Tomato = new Product("�������", 140, 180, 361, 411, 55, 42);
	Product* Oak = new Product("���", 60, 50, 134, 2, 55, 71);
	Product* Pear = new Product("�����", 70, 80, 143, 74, 55, 72);
	Product* Apple = new Product("������", 60, 90, 134, 147, 55, 72);
	Product* Cherry = new Product("�����", 80, 120, 128, 221, 55, 64);


	products = {Tulip,Rose,Iris,Cabbage,Pepper,Greenery,Carrot,Corn,Pumpkin,Tomato,Oak,Pear,Apple,Cherry};
}


Shop::~Shop()
{
}
