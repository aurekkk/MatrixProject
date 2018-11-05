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
	Matrix& operator =(const Matrix& matrix);
	Matrix& operator +();
	Matrix& operator -();
	friend Matrix operator +(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator +(const Matrix& matrix, const double scalar);
	friend Matrix operator +(const double scalar, const Matrix& matrix);
	friend Matrix operator -(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator -(const Matrix& matrix, const double scalar);
	friend Matrix operator -(const double scalar, const Matrix& matrix);
	friend Matrix operator *(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator *(const Matrix& matrix, const double scalar);
	friend Matrix operator *(const double scalar, const Matrix& matrix);
	friend Matrix operator /(const Matrix& matrix, const double scalar);
	friend Matrix operator /(const double scalar, const Matrix& matrix);
	friend Matrix operator ^(const Matrix& matrix, const int n);
	double* operator[](int row);
	friend bool operator ==(const Matrix& matrix1, const Matrix& matrix2);
	friend bool operator !=(const Matrix& matrix1, const Matrix& matrix2);
	friend std::istream & operator >>(std::istream& in, const Matrix& matrix);
	friend std::ostream & operator <<(std::ostream& out, const Matrix& matrix);

private:
	int m_row, m_column;
	double **m_data;

};