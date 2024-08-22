#include "include/Curve.h"
#include <iostream>
#include <numbers>



int main() {
	
	std::unique_ptr<std::vector<std::unique_ptr<ICurve>>> curves = create_first_vector();
	// print_curve_details(curves, std::numbers::pi_v<double> / 4);
	std::cout << curves->size() << std::endl;
	auto circles = std::make_unique<std::vector<std::unique_ptr<ICurve>>>();
	move_circles_to_second_vector(curves, circles);
	std::cout << curves->size() << std::endl;
  return 0;
}
