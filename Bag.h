#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
class Bag
{
public:
	std::vector<Product*> my_products;
	int budget;
	void Buy_product(Product* new_product){ my_products.push_back(new_product); };
	void Use_product(Product* product){};
	void Increase_budget(){};
	void Decrease_budget(){};
	Bag();
	~Bag();
};

