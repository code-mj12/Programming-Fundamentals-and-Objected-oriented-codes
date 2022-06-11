#include"Shape.h"
class Square
{
private:
	int side;
public:
	Square ();
	Square (int s);
	float getarea ();
    float getparameter();
	void Display();
	int getSide() const;
};