#include "Shop.h"


Shop::Shop()
{
	Product* Tulip = new Product("�������", 100,120,350,9,55,44);
	Product* Rose = new Product("����", 180,200,350,53,55,37);
	Product* Iris = new Product("����",170,210,346,90,55,59);
	products = {Tulip,Rose,Iris};
}


Shop::~Shop()
{
}
