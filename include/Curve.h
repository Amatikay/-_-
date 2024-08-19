#ifndef CURVE_H
#define CURVE_H

#include <vector>
#include <cmath>

struct Point {
    double x = {};
    double y = {};
    double z = {};
};

class ICurve {
public:
	virtual Point getPoint(const double& t) = 0;
	virtual Point getDerivative (const double& t) = 0;
	virtual ~ICurve () = default;
};

class Circle : public ICurve {
public:
	Circle() {};
	Circle(const double& p_radius) : radius(p_radius){};
	Point getPoint(const double& t) override;
	Point getDerivative(const double& t) override;
private:
	double radius = {};
};

class Ellipse : public ICurve {
public:
	Ellipse(const double& p_radi_a, const double& p_radi_b): 
											 radi_a(p_radi_a), radi_b(p_radi_b){};	
	Ellipse() {};
	Point getPoint (const double& t) override;
	Point getDerivative(const double& t) override;
private:
	double radi_a = {};
	double radi_b = {};
};

class Helix : public ICurve {
public:
	Helix(const double& p_radius, const double& p_step): 
											 radius(p_radius), step(p_step){};	
	Helix() {};
	Point getPoint (const double& t) override;
	Point getDerivative(const double& t) override;
private:
	double radius = {};
	double step = {};
};


#endif
