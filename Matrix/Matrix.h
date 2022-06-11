
#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
using namespace std;
class Matrix {
	int row;
	int col;
	float **matrix;
// think about the private data members... 
// the matrix should store real number
public:
	Matrix();
	Matrix(int, int); // a parametrized constructor
	Matrix(const Matrix &); // copy constructor
	int getcol();
	int getrow();
	float &operator()(int &i, int &j); //set value at (i,j)
	float &operator()(int &i, int &j)const; //set value at (i,j)
	Matrix& operator=(const Matrix &); //assigns (copies) a Matrix. Returns the	same
	bool operator==(const Matrix &); //Compares two matrices
	Matrix operator+(const Matrix &); //adds two Matrices and returns the result
	Matrix operator-(const Matrix &); //subtracts two Matrices and returns the	result
	Matrix operator *(const Matrix &); //multiplies two Matrices
	Matrix& operator++(int); //add one to every element
	void operator+=(const Matrix&); //adds two Matrices
	void operator-=(const Matrix&); //subtracts two Matrices
	virtual ~Matrix();
};

#endif /* MATRIX_H_ */

/*

Matrix::Matrix() {
	// TODO Auto-generated constructor stub

}

Matrix::Matrix(int r, int c) // a parametrized constructor
{

}
Matrix::Matrix(const Matrix & M1)// copy constructor
{

}
float & Matrix::operator()(int i, int j) //set value at (i,j)
{

}
float & Matrix::operator()(int i, int j)const//set value at (i,j)
{
	
}
Matrix& Matrix::operator=(const Matrix & M1) //assigns (copies) a Matrix. Returns the	same
{

}
bool Matrix::operator==(const Matrix & M1) //Compares two matrices
{

}
Matrix Matrix::operator+(const Matrix & M1) //adds two Matrices and returns the result
{

}
Matrix Matrix::operator-(const Matrix & M1) //subtracts two Matrices and returns the	result
{

}
Matrix Matrix::operator *(const Matrix & M1) //multiplies two Matrices
{

}
Matrix& Matrix::operator++(int i) //add one to every element
{

}
void Matrix::operator+=(const Matrix& M1) //adds two Matrices
{

}
void Matrix::operator-=(const Matrix& M1) //subtracts two Matrices
{

}



Matrix::~Matrix() {
	// TODO Auto-generated destructor stub

}

*/