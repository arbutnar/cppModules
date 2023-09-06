#include "Fixed.hpp"
#include "Point.hpp"

Fixed myabs( Fixed val ) {
	if (val < Fixed(0))
		return val * Fixed(-1);
	return val;
}

Fixed	areas( Point const a, Point const b, Point const c ) {

	Fixed xa, ya, xb, yb, xc, yc;

	xa = a.getX();
	ya = a.getY();
	xb = b.getX();
	yb = b.getY();
	xc = c.getX();
	yc = c.getY();

	return myabs((xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb)) / Fixed(2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed area1, area2, area3, fullArea;

	area1 = areas(point, b, c);
	area2 = areas(a, point, c);
	area3 = areas(a, b, point);
	fullArea = areas(a, b, c);

	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0) || fullArea == Fixed(0))
		return false;
	if (fullArea == (area1 + area2 + area3))
		return true;
	return false;
}
