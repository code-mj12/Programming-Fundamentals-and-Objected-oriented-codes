
int **MatrixMul(int **MatrixA, int rowsA,int colsA ,int **MatrixB, int rowsB, int colsB ) {
	int **m3=new int *[rowsA];
	int i=0;
	while( i < rowsA){
		m3[i]=new int[colsA];
		i++;
		}
		int j,k;
	for(i = 0; i < rowsA; ++i){
        for(j = 0; j < colsA; ++j){
            k = 0;
			while(k < colsA)
            {
                m3[i][j] = m3[i][j] + MatrixA[i][k] * MatrixB[k][j];
				++k;
			}}}
            return m3;
		}
		
		
int **MatrixAdd (int **MatrixA, int rowsA,int colsA ,int **MatrixB, int rowsB, int colsB ) {
	int **m3=new int *[rowsA];
	int i=0;
	while( i < rowsA){
		m3[i]=new int[colsA];
		i++;
		}
		i=0;
	while( i < rowsA){
		for(int j=0; j < colsA; ++j){
			m3[i][j]=MatrixA[i][j]+MatrixB[i][j];
		}
		++i;
	}
			
	return m3;
	}	
	
int **MatrixSub (int **MatrixA, int rowsA,int colsA ,int **MatrixB, int rowsB, int colsB ) {
	int **m3=new int *[rowsA];
	int i=0;
	while( i < rowsA){
		m3[i]=new int[colsA];
		i++;}
		
	for(i=0; i < rowsA; ++i)
		for(int j=0; j < colsA; ++j)
			m3[i][j]=MatrixA[i][j]-MatrixB[i][j];
			
	return m3;
	}
	
int **MatrixTranspose(int **Matrix , int rows , int cols)
{
	int **result=new int*[cols];
	int i=0;
	while(i<rows)
	{
		result[i]=new int[rows];
		++i;	
	}
	for(i=0 ;i<rows; ++i)
	{
		int j=0;
		while( j<cols )
		{
			result[j][i]= Matrix[i][j];
			j++;		
		}	
	}
	return result;
}

int** MatrixRotate(int **Matrix, int rows , int cols) 
{
	int temp=0;
	int **result=new int*[cols];
	int i=0;
	while(i<rows)
	{
		result[i]=new int[rows];
		++i;	
	}
	int v= cols;
	int u=0;
	i=0;
	for ( ;i < rows;) 
   	{
   		u=0;
        	v -= 1;
        	for(int j=0 ; j<cols ;++j)
        	{
        		result[u][v]=Matrix[i][j];
        		++u;
        	}
			i++;	
        }
       return result;
}

	
int MatrixDet(int **Matrix, int rows , int cols)
{
	int deti=0;
    if(cols == 1 )
    {
		int a = Matrix[0][0];
	return a;
    }
    if(rows == 2 && cols == 2)
    {
		int a1 = Matrix[0][0] * Matrix[1][1] - Matrix[1][0] * Matrix[0][1];
	 return a1;
    }
	if(cols==3 && rows == 3)
	{
		int i=0;
		while(i<3)
		{
			deti = deti + (Matrix[0][i] * (Matrix[1][(i+1)%3] * Matrix[2][(i+2)%3] - Matrix[1][(i+2)%3] * Matrix[2][(i+1)%3]));
			++i;
		
		}
		return deti*1;
	}
	return Matrix[0][0];
}
	
float **MatrixInverse(int **Matrix , int rows, int cols ) {
	//cout<<5555;
	if (rows == 1){
		//cout<<5555;
		float **m3 = new float*[1];
		m3[0] = new float;
		m3[0][0] = 1.00 / (**Matrix); 
		//cout<<**m3<<endl;
		return m3;
		}
	else{
		//cout<<"check2";
		float **m3 =new float*[rows];
		int i=0;
		for(i = 0; i< rows; i++){
			m3[i]= new float[rows];}
		//cout<<"check1";
		float det = 1.00 / (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
		//cout<<"check2";
		m3[0][0]=Matrix[1][1]*det;	m3[1][1]=Matrix[0][0]*det;	m3[0][1]=-Matrix[0][1]*det;		m3[1][0]=-Matrix[1][0]*det; 	
			return m3;
		}
	
	}
	
/*int main(){
	
	int ** m1 = new int*[2];// 2x2 matrix
	m1[0] = new int[2];
	m1[1] = new int[2];

	m1[0][0] = 4;	
	m1[0][1] = 7;	
	m1[1][0] = 2;	
	m1[1][1] = 6;
	cout<<**MatrixInverse(m1,2,2);
	return 0;
	}*/
			

	
	
