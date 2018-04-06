#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
class Farm
{
public:
	std::vector<Product*> my_farm;
	void Change_farm(){};
	void Add_product(Product* new_product){};
	void Delet_product(Product* old_product){};
	Farm();
	~Farm();
};

