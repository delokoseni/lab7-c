#include "Hours.h"
#include "Jobtitle.h"

int normhcost(Hours hour, Jobtitle jtitle) {
	int x = 0;
	x += hour.normal * jtitle.hourlycost;
	return x;
}