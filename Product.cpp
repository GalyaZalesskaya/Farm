#include "Product.h"


Product::Product(Product* some_product)
{
	name = some_product->Get_name();
	price_for_fetus = some_product->Get_price_for_fetus();
	price_for_seed = some_product->Get_price_for_seed();
	address = some_product->Get_address();
	size = some_product->Get_size();
}


Product::~Product()
{
}
