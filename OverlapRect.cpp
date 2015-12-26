#include <iostream>

typedef struct _Point
{
	int x, y; 
} Point;

bool isOverLap(Point l1, Point r1, Point l2, Point r2 )
{
	if (l1.x > r2.x || l2.x > r1.x)
		return false;
	if (l1.y < r2.y || l2.y > l2.y)
		return false; 
	return true; 
}

int main(){}


