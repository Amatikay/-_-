#include "include/Curve.h"
#include <iostream>
#include <numbers>



int main() {
	
	std::unique_ptr<std::vector<std::unique_ptr<ICurve>>> curves = create_first_vector();
	print_curve_details(curves, std::numbers::pi_v<double> / 4);
  return 0;
}
