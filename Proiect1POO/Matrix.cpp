#include "Matrix.hpp"    

Matrix::Matrix(int row, int column)
	: m_row(row)
	, m_column(column)
{
	AllocMatrix();
	for (int i = 0; i < m_row; i++)
		for (int j = 0;j < m_column;j++)
		{
			if (i == j) m_data[i][j] = 1;
			else m_data[i][j] = 0;
		}
}

Matrix::Matrix(const Matrix & matrix)
	: m_row(matrix.m_row)
	, m_column(matrix.m_row)
{
	AllocMatrix();
	for (int i = 0;i < m_row;i++)
		for (int j = 0;j < m_column;j++)
			m_data[i][j] = matrix.m_data[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0;i < m_row;i++)
		delete [] m_data[i];
	delete [] m_data;
}



int Matrix::GetRow() const
{
	return m_row;
}


int Matrix::GetColumn() const
{
	return m_column;
}

Matrix & Matrix::operator+=(const double scalar)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			m_data[i][j] += scalar;
		}
	return *this;
}

Matrix & Matrix::operator+=(const Matrix & matrix)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			m_data[i][j] += matrix.m_data[i][j];
		}
	return *this;
}

Matrix & Matrix::operator-=(const double scalar)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			m_data[i][j] -= scalar;
		}
	return *this;
}

Matrix & Matrix::operator-=(const Matrix & matrix)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			m_data[i][j] -= matrix.m_data[i][j];
		}
	return *this;
}

Matrix & Matrix::operator*=(const double scalar)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			m_data[i][j] *= scalar;
		}
	return *this;
}

Matrix & Matrix::operator*=(const Matrix & matrix)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			m_data[i][j] -= matrix.m_data[i][j];
		}
	return *this;
}

Matrix operator +(const Matrix& matrix1, const Matrix& matrix2)
{
	//exemplu throw
	if (matrix1.m_row == matrix2.m_row && matrix1.m_column == matrix2.m_column)
	{
		Matrix result(matrix1);
		result += matrix2;
	}
	else throw std::runtime_error("cannot add matrix");
	return result;
}

Matrix operator +(const Matrix& matrix, const double scalar)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0;j < m_column;j++)
		{
			matrix.m_data[i][j] += scalar;
		}

	return *this;
}

Matrix operator +(const double scalar, const Matrix& matrix)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0;j < m_column;j++)
		{
			matrix.m_data[i][j] += scalar;
		}

	return *this;
}

Matrix operator -(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.m_column == matrix2.m_column && matrix1.m_row == matrix2.m_row)
	{
		Matrix result(matrix1);
		result += matrix2;
	}
		return result;
}

Matrix operator -(const Matrix& matrix, const double scalar)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0;j < m_column;j++)
		{
			matrix.m_data[i][j] -= scalar;
		}

	return *this;
}

Matrix operator -(const double scalar, const Matrix& matrix)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0;j < m_column;j++)
		{
			matrix.m_data[i][j] -= scalar;
		}

	return *this;
}

Matrix operator *(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.m_row == matrix2.m_row && matrix1.m_column == matrix2.m_column)
	Matrix m(matrix1);
	for (int i = 0; i < m_row; i++)
		for (int j = 0;j < m_column;j++)
		{
			m.m_data[i][j] = 0;
				for (int k = 0; k < m_column; k++)
				{
					m.m_data[i][j] = m.m_data[i][j] + matrix1.m_data[i][k] * matrix2.m_data[k][j];
				}
		}
	return m;
}

Matrix operator *(const Matrix& matrix, const double scalar)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			matrix.m_data[i][j] *= scalar;
		}
	return *this;
}

Matrix operator *(const double scalar, const Matrix& matrix)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			matrix.m_data[i][j] *= scalar;
		}
	return *this;
}

void Matrix::AllocMatrix()
{
	M = new double*[m_row];
	for (int i = 0;i < m_row;i++)
			m_data[i] = new double[m_column];
}




