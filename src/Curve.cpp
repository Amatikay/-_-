#include "../include/Curve.h"

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
