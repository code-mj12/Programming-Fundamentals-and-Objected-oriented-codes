#include"Shape.h"
class Rectangle
{
private:
	int length;
	int width;
public:
	Rectangle();
	Rectangle(int l, int w);
	float getarea ();
    float getperimeter();
	void Display();
	int getLength() const;
	int getWidth() const;
};