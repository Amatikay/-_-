#include "../include/Curve.h"
#include <random>
#include <memory>
#include <vector>



Point Circle::getPoint(const double& t){
	return {radius * cos(t), radius * sin(t)};	
};

Point Circle::getDerivative(const double& t){
	return {-1 * radius * sin(t), radius * cos(t)};
};

Point Ellipse::getPoint(const double& t){
	return {radi_a * cos(t), radi_b * sin(t)};	
};

Point Ellipse::getDerivative(const double& t){
	return {-1 * radi_a * sin(t), radi_b * cos(t)};
};

Point Helix::getPoint(const double& t){
	return {radius * cos(t), radius * sin(t), step * t};	
};

Point Helix::getDerivative(const double& t){
	return {-1 * radius * sin(t), radius * cos(t), step};
};

std::unique_ptr<std::vector<std::unique_ptr<ICurve>>> create_first_vector (){
		std::random_device rd; 
	  std::mt19937 gen(rd()); 
	  /*
	  * Пусть генератор случаных целых чисел генерирует число от 3 до 100.
	  * Минимальное значение выбрано таким потому, что по заданию
	  * в векторе должен быть каждый дочерний объект интерфейса кривой.
	 	* Количество кривых так же будет случаным. Для количества кривых
	  * будет использоваться это генератор. Данное упрощение не противоречит условию. 
	  */
	  std::uniform_int_distribution<>  idistr(3,100); 
	  std::uniform_real_distribution<> rdistr(0,20);
	  std::uniform_int_distribution<>  curvedistr(1,3);
	  
	  bool isCircle  = false;
	  bool isEllipse = false;
	  bool isHelix   = false;
	  
	 	int vector_size = idistr(gen);
		auto curves = std::make_unique<std::vector<std::unique_ptr<ICurve>>>();

		/*
		* Каждая итерация начинается с пустого вектора
		* Пока вектор не будет заполнен всеми типами 
		* Начинать заново
		*/
		
	  while ((isCircle && isEllipse && isHelix) == false ){  // Пока в векторе не будут все кривые
			curves->clear();
			for (int i = 0; i < vector_size; ++i){
				int curve_number = curvedistr(gen);
				switch(curve_number){
					case 1:
						curves->push_back(std::make_unique<Circle>(rdistr(gen)));
						isCircle  = true;
						break;
					case 2:
						curves->push_back(std::make_unique<Ellipse>(rdistr(gen), (rdistr(gen))));
						isEllipse = true;
						break;
					case 3:
						curves->push_back(std::make_unique<Helix>(rdistr(gen), (rdistr(gen))));
						isHelix   = true;
						break;
				}
			}
			
		}
		return curves;
};


