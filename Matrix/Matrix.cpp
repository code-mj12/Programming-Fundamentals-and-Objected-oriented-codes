#include "Matrix.h"

ostream& operator<<(ostream& output, const Matrix &a)
{

    for(int i=0 ; i < 2; i++)
    {
        for(int j=0 ; j<2; j++)
        {
            output<<a(i,j)<<" ";
        }
        output<<endl;
    }
    return output;
}
istream& operator>>(istream& input, Matrix &a)
{
    cout<<"Enter Elements in Matrix till completion"<<endl;
    int r =a.getrow();
    int c = a.getcol();
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            input>>a(i,j);
        }
    }
    return input;
}


Matrix::Matrix() {
	// TODO Auto-generated constructor stub
    row =0;
    col =0;
    matrix=NULL;
}

Matrix::Matrix(int r, int c) // a parametrized constructor
{
    row=r;
    col=c;
    matrix = new float *[row];
    for(int i=0; i<row; i++)
    {
        matrix[i] = new float[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 0;        
        }
        
    }
    
}
Matrix::Matrix(const Matrix & M1)// copy constructor
{
    row=M1.row;
    col=M1.col;
    matrix = new float *[row];
    for(int i=0; i<row; i++)
    {
        matrix[i] = new float[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = M1.matrix[i][j];        
        }
        
    }
}
int Matrix::getcol(){
    return col;
}
int Matrix::getrow(){
    return row;
}
float& Matrix::operator()(int &i,int &j)
{
    return matrix[i][j];
}
float & Matrix::operator()(int &i, int &j)const//set value at (i,j)
{
	    return matrix[i][j];
}
Matrix& Matrix::operator=(const Matrix & M1) //assigns (copies) a Matrix. Returns the	same
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = M1.matrix[i][j];
        }
        
    }

    return (*this);
    
}
bool Matrix::operator==(const Matrix & M1) //Compares two matrices
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!(matrix[i][j] == M1.matrix[i][j])){
                return false;
            }
        }
        
    }   
    return true; 
}
Matrix Matrix::operator+(const Matrix & M1) //adds two Matrices and returns the result
{
    Matrix temp(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp.matrix[i][j] = M1.matrix[i][j] + matrix[i][j];   
        }
    }
        return temp;
}

Matrix Matrix::operator-(const Matrix & M1) //subtracts two Matrices and returns the	result
{
    Matrix temp(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp.matrix[i][j] = matrix[i][j] - M1.matrix[i][j];   
        }
    }
        return temp;
}
Matrix Matrix::operator *(const Matrix & M1) //multiplies two Matrices
{
    Matrix temp(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp.matrix[i][j] = matrix[i][j] * M1.matrix[i][j];   
        }
    }
        return temp;
}
Matrix& Matrix::operator++(int i) //add one to every element
{
    for(int i=0;i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            ++matrix[i][j];
        }
    }
    return (*this);
}
void Matrix::operator+=(const Matrix& M1) //adds two Matrices
{
    for(int i=0;i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix[i][j]+=M1.matrix[i][j];
        }
    }
}
void Matrix::operator-=(const Matrix& M1) //subtracts two Matrices
{
    for(int i=0;i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix[i][j]+=M1.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub
for(int i=0; i<row; i++)
    {
        delete []matrix[i];
    }
    delete []matrix;
}
