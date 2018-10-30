
class Matrix {
public:
	Matrix(int row = 1, int column = 1);
	Matrix(const Matrix& matrix);
	~Matrix();

	int GetRow() const;
	int GetColumn() const;

	Matrix& operator +=(const double scalar);
	Matrix& operator +=(const Matrix & matrix);
	Matrix& operator -=(const double scalar);
	Matrix& operator -=(const Matrix & matrix);
	Matrix& operator *=(const double scalar);
	Matrix& operator *=(const Matrix& matrix);
	friend Matrix operator +(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator +(const Matrix& matrix, const double scalar);
	friend Matrix operator +(const double scalar, const Matrix& matrix);
	friend Matrix operator -(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator -(const Matrix& matrix, const double scalar);
	friend Matrix operator -(const double scalar, const Matrix& matrix);
	friend Matrix operator *(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator *(const Matrix& matrix, const double scalar);
	friend Matrix operator *(const double scalar, const Matrix& matrix);

private:
	int m_row, m_column;
	double **m_data;
	void AllocMatrix();
	
};