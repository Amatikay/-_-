#include "../include/Curve.h"
#include <random>
#include <memory>
#include <vector>
#include <stdexcept>
	

Circle::Circle(const double& p_radius) : radius(p_radius){
		if (p_radius < 0) {
			throw std::invalid_argument("Отрицательный радиус");
		}
};

Point Circle::getPoint(const double& t){
	return {radius * cos(t), radius * sin(t)};	
};

Point Circle::getDerivative(const double& t){
	return {-1 * radius * sin(t), radius * cos(t)};
};

Ellipse::Ellipse(const double& p_radi_a, const double& p_radi_b): 
								 radi_a(p_radi_a), radi_b(p_radi_b){
	if (p_radi_a < 0 || p_radi_b < 0){
		throw std::invalid_argument("Отрицательный радиус");
	}
};

Point Ellipse::getPoint(const double& t){
	return {radi_a * cos(t), radi_b * sin(t)};	
};

Point Ellipse::getDerivative(const double& t){
	return {-1 * radi_a * sin(t), radi_b * cos(t)};
};

Helix::Helix(const double& p_radius, const double& p_step): 
						 radius(p_radius), step(p_step){
	if (p_radius < 0){
		throw std::invalid_argument("Отрицательный радиус");
	}
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
	  std::uniform_real_distribution<> rdistr(-100,100);
	  std::uniform_int_distribution<>  curvedistr(1,3);
	  
	  bool isCircle  = false;
	  bool isEllipse = false;
	  bool isHelix   = false;
	  
	 	int vector_size = idistr(gen);
		auto curves = std::make_unique<std::vector<std::unique_ptr<ICurve>>>();
		/*
		* Если передан отрацательный аргумент - пусть вызывается 
		* Конструктор по умолчанию.
		*/
			for (int i = 0; i < vector_size; ++i){
				int curve_number = curvedistr(gen);
				switch(curve_number){
					case 1:
						try{
							curves->push_back(std::make_unique<Circle>(rdistr(gen)));
							isCircle  = true;
						}
						catch (std::invalid_argument& error ) {
							std::cerr << error.what() << std::endl;
							curves->push_back(std::make_unique<Circle>());
							isCircle  = true;
						}
						break;
					case 2:
						try{
							curves->push_back(std::make_unique<Ellipse>(rdistr(gen), rdistr(gen)));
							isEllipse  = true;
						}
						catch (std::invalid_argument& error ) {
							std::cerr << error.what() << std::endl;
							curves->push_back(std::make_unique<Ellipse>(rdistr(gen), rdistr(gen)));
							isEllipse  = true;
							
						}
						break;
					case 3:
						try{
							curves->push_back(std::make_unique<Helix>(rdistr(gen), idistr(gen)));
							isHelix  = true;
						}
						catch (std::invalid_argument& error ) {
							std::cerr << error.what() << std::endl;
							curves->push_back(std::make_unique<Helix>(rdistr(gen), idistr(gen)));
							isHelix  = true;
						}
						break;
				}
		/*
		* Добавить, если не хватает какого то из элементов
		*/
		if (!isCircle) {
			curves->push_back(std::make_unique<Circle>(rdistr(gen)));
			isCircle = true;
		}
		if (!isEllipse) {
			curves->push_back(std::make_unique<Ellipse>(rdistr(gen), rdistr(gen)));
			isEllipse = true;
		}
		if (!isHelix) {
			curves->push_back(std::make_unique<Helix>(rdistr(gen), idistr(gen)));
			isHelix = true;
		}
	}
	
	return curves;
};


