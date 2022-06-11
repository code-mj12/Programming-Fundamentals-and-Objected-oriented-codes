#include "pch.h"
#include "Matrix.h"
ostream& operator<<(ostream& input, const Matrix& M1) //Outputs the Matrix
{
	// implement this
}
istream& operator>>(istream& ouput, Matrix& M1) //Inputs the Matrix
{
	// implement this
}




TEST(testMatrix, subscript) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;



	EXPECT_EQ(M1(0,0), 1); EXPECT_EQ(M1(0, 1), 2); EXPECT_EQ(M1(0, 2), 3);
	EXPECT_EQ(M1(1, 0), 1); EXPECT_EQ(M1(1, 1), 1); EXPECT_EQ(M1(1, 2), 1);
	EXPECT_EQ(M1(2, 0), 0); EXPECT_EQ(M1(2, 1), 2); EXPECT_EQ(M1(2, 2), 4);



}


TEST(testMatrix, CopyConstructor) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2(M1);

	EXPECT_EQ(M2(0, 0), 1); EXPECT_EQ(M2(0, 1), 2); EXPECT_EQ(M2(0, 2), 3);
	EXPECT_EQ(M2(1, 0), 1); EXPECT_EQ(M2(1, 1), 1); EXPECT_EQ(M2(1, 2), 1);
	EXPECT_EQ(M2(2, 0), 0); EXPECT_EQ(M2(2, 1), 2); EXPECT_EQ(M2(2, 2), 4);



}


TEST(testMatrix, equal) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2;
	M2 = M1;

	EXPECT_EQ(M2(0, 0), 1); EXPECT_EQ(M2(0, 1), 2); EXPECT_EQ(M2(0, 2), 3);
	EXPECT_EQ(M2(1, 0), 1); EXPECT_EQ(M2(1, 1), 1); EXPECT_EQ(M2(1, 2), 1);
	EXPECT_EQ(M2(2, 0), 0); EXPECT_EQ(M2(2, 1), 2); EXPECT_EQ(M2(2, 2), 4);



}


TEST(testMatrix, equal_equal) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2;
	M2 = M1;

	EXPECT_EQ(M2==M1, 1);


	Matrix M3(2,2);

	EXPECT_EQ(M3 == M1, 0);


}



TEST(testMatrix, plus) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2;
	M2 = M1+M1;

	EXPECT_EQ(M2(0, 0), 2); EXPECT_EQ(M2(0, 1), 4); EXPECT_EQ(M2(0, 2), 6);
	EXPECT_EQ(M2(1, 0), 2); EXPECT_EQ(M2(1, 1), 2); EXPECT_EQ(M2(1, 2), 2);
	EXPECT_EQ(M2(2, 0), 0); EXPECT_EQ(M2(2, 1), 4); EXPECT_EQ(M2(2, 2), 8);


}



TEST(testMatrix, minus) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2;
	M2 = M1 - M1;

	EXPECT_EQ(M2(0, 0), 0); EXPECT_EQ(M2(0, 1), 0); EXPECT_EQ(M2(0, 2), 0);
	EXPECT_EQ(M2(1, 0), 0); EXPECT_EQ(M2(1, 1), 0); EXPECT_EQ(M2(1, 2), 0);
	EXPECT_EQ(M2(2, 0), 0); EXPECT_EQ(M2(2, 1), 0); EXPECT_EQ(M2(2, 2), 0);



}

TEST(testMatrix, mul) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2;
	M2 = M1 * M1;


	EXPECT_EQ(M2(0, 0), 3); EXPECT_EQ(M2(0, 1), 10); EXPECT_EQ(M2(0, 2), 17);
	EXPECT_EQ(M2(1, 0), 2); EXPECT_EQ(M2(1, 1), 5); EXPECT_EQ(M2(1, 2), 8);
	EXPECT_EQ(M2(2, 0), 2); EXPECT_EQ(M2(2, 1), 10); EXPECT_EQ(M2(2, 2), 18);



}

TEST(testMatrix, plus_equal){


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2=M1;
	M2 += M1;


	EXPECT_EQ(M2(0, 0), 2); EXPECT_EQ(M2(0, 1), 4); EXPECT_EQ(M2(0, 2), 6);
	EXPECT_EQ(M2(1, 0), 2); EXPECT_EQ(M2(1, 1), 2); EXPECT_EQ(M2(1, 2), 2);
	EXPECT_EQ(M2(2, 0), 0); EXPECT_EQ(M2(2, 1), 4); EXPECT_EQ(M2(2, 2), 8);



}



TEST(testMatrix, minus_equal) {


	Matrix M1(3, 3);
	M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
	M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
	M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;

	Matrix M2=M1;
	M2 -= M1;

	EXPECT_EQ(M2(0, 0), 0); EXPECT_EQ(M2(0, 1), 0); EXPECT_EQ(M2(0, 2), 0);
	EXPECT_EQ(M2(1, 0), 0); EXPECT_EQ(M2(1, 1), 0); EXPECT_EQ(M2(1, 2), 0);
	EXPECT_EQ(M2(2, 0), 0); EXPECT_EQ(M2(2, 1), 0); EXPECT_EQ(M2(2, 2), 0);



}