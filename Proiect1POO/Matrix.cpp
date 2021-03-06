#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.hpp"    

Matrix::Matrix(int row, int column)
	: m_row(row)
	, m_column(column)
{
	m_data = new double*[m_row];
	for (int i = 0; i < m_row; i++) {
		m_data[i] = new double[m_column];
	}
	for (int i = 0; i < m_row; i++)
		for (int j = 0;j < m_column;j++)
		{
			if (i == j) m_data[i][j] = 1;
			else m_data[i][j] = 0;
		}
	
}

Matrix::Matrix(const Matrix & matrix)
	: m_row(matrix.m_row)
	, m_column(matrix.m_column)
{
	m_data = new double*[m_row];
	for (int i = 0; i < m_row; i++) {
		m_data[i] = new double[m_column];
	}

	for (int i = 0;i < m_row;i++) {
		for (int j = 0;j < m_column;j++) {
			m_data[i][j] = matrix.m_data[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0;i < m_row;i++)
		delete[] m_data[i];
	delete[] m_data;
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
			m_data[i][j] *= matrix.m_data[i][j];
		}
	return *this;
}

Matrix & Matrix::operator=(const Matrix & matrix)
{
	if (matrix != *this) {
		m_row = matrix.m_row;
		m_column = matrix.m_column;
		for (int i = 0; i < m_row; i++) {
			for (int j = 0; j < m_column; j++) {
				m_data[i][j] = matrix.m_data[i][j];
			}
		}
		return *this;


	}
	else {
		for (int i = 0; i < m_row; i++) {
			for (int j = 0; j < m_column; j++) {
				m_data[i][j] = matrix.m_data[i][j];
			}
		}
		return *this;
	}
}

Matrix & Matrix::operator+()
{
	return *this;
}







Matrix & Matrix::operator -()
{
	Matrix result(*this);

	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			m_data[j][i] = result.m_data[i][j];
		}

	return *this;
}

/*{
	Matrix result(*this);

	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_column; j++)
		{
			result.m_data[j][i] =m_data[i][j];
		}

	return result;
}*/
double * Matrix::operator[](int row)
{
	return m_data[row];
}

Matrix operator +(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1 != matrix2) throw std::runtime_error("cannot add matrix");

	Matrix result(matrix1);

	result += matrix2;

	return result;
}


Matrix operator +(const Matrix& matrix, const double scalar)
{
	Matrix result(matrix); // constructor de copiere

	result += scalar;

	return result;
}

Matrix operator +(const double scalar, const Matrix& matrix)
{
	Matrix result(matrix); // constructor de copiere

	result += scalar;

	return result;
}

Matrix operator -(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1 != matrix2) throw std::runtime_error("cannot decrease matrix");

	Matrix result(matrix1);
	result -= matrix2;

	return result;
}
Matrix operator -(const Matrix& matrix, const double scalar)
{
	Matrix result(matrix); // constructor de copiere

	result -= scalar;

	return result;
}

Matrix operator -(const double scalar, const Matrix& matrix)
{
	Matrix result(matrix); // constructor de copiere

	result -= scalar;

	return result;
}

Matrix operator *(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1 != matrix2) throw std::runtime_error("cannot multiply matrix");
	Matrix result(matrix1);
	/*for (int i = 0; i < result.m_row; i++)
		for (int j = 0;j < result.m_column;j++)
		{
			result.m_data[i][j] = 0;
			for (int k = 0; k < result.m_column; k++)
			{
				result.m_data[i][j] = result.m_data[i][j] + matrix1.m_data[i][k] * matrix2.m_data[k][j];
			}
		}
	*/
	result *= matrix2;
	return result;
}

Matrix operator *(const Matrix& matrix, const double scalar)
{
	Matrix result(matrix);
	result *= scalar;
	return result;
}

Matrix operator *(const double scalar, const Matrix& matrix)
{
	Matrix result(matrix);
	result *= scalar;
	return result;
}

Matrix operator /(const Matrix& matrix, const double scalar)
{
	if (scalar == 0) throw std::runtime_error("cannot divide by 0");
	Matrix result(matrix);
	for (int i = 0; i < result.m_row; i++)
		for (int j = 0; j <result.m_column ; j++)
		{
			result.m_data[i][j] = result.m_data[i][j] / scalar;
		}
	return result;
}

Matrix operator /(const double scalar, const Matrix& matrix)
{
	if (scalar == 0) throw std::runtime_error("cannot divide by 0");
	Matrix result(matrix);
	for (int i = 0; i < result.m_row; i++)
		for (int j = 0; j < result.m_column; j++)
		{
			result.m_data[i][j] = result.m_data[i][j] / scalar;
		}
	return result;
}

Matrix operator ^(const Matrix& matrix, const int n)
{
	if (matrix.m_row != matrix.m_column) throw std::runtime_error("cannot raise matrix");

	Matrix result(matrix);
	for (int i = 1; i < n; i++)
	{
		result *= matrix;
	}

	return result;

}

bool operator ==(const Matrix& matrix1, const Matrix& matrix2)
{
	return matrix1.m_row == matrix2.m_row && matrix1.m_column == matrix2.m_column;
}

bool operator !=(const Matrix& matrix1, const Matrix& matrix2)
{
	return !(matrix1 == matrix2);
}

std::istream & operator>>(std::istream & in, const Matrix & matrix)
{
	for (int i = 0; i < matrix.m_row; i++)
		for (int j = 0; j < matrix.m_column; j++)
		{
			in >> matrix.m_data[i][j];
		}
	return in;
}

std::ostream & operator<<(std::ostream & out, const Matrix & matrix)
{
	for (int i = 0; i < matrix.m_row; i++)
	{
		for (int j = 0; j < matrix.m_column; j++)
			out << matrix.m_data[i][j] << " ";
		out << std::endl;
	}

	return out;
}


