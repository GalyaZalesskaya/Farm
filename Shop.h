#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
class Shop
{
public:
	std::vector<Product*> products;
	Shop();
	~Shop();
};

