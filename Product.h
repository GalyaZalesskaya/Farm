#pragma once
#include <iostream>
#include <string>

class Product
{
	int price_for_seed;
	int price_for_fetus;
	int number_of_stages = 3;
	int current_stage = 1;
	int lifespan = 5;
	std::string name;
	std::pair<int,int> address1;
	std::pair<int, int> address2;
	std::pair<int, int> curr_address1;
	std::pair<int, int> curr_address2;
	std::pair<int, int> xy;
	
public:
	Product(std::string name_, int seed_price, int fetus_price, int x1,int y1,int x2,int y2, int num_stage) :name(name_), price_for_seed(seed_price), price_for_fetus(fetus_price), address1(x1,y1),address2(x2,y2), number_of_stages(num_stage){};
	int Get_seed(){ return price_for_seed; };
	int Get_fetus(){ return price_for_fetus; };
	std::string Get_name(){ return name; };
	//std::string Get_address(){ return address; };
	int Get_num_stages(){ return number_of_stages; };
	std::pair<int, int> Get_xy(){ return xy; };
	void Set_xy(int x, int y){ xy.first = x; xy.second = y; };
	//void Set_current_address(){};//need to create address according to the stage of product to have access to image



	~Product();
};

