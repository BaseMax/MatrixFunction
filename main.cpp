/**
*
* @Name : MatrixFunction/main.cpp
* @Version : 1.0
* @Programmer : SorenCoder, Max
* @Date : 2019-07-17
* @Released under : https://github.com/BaseMax/MatrixFunction/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/MatrixFunction
*
**/
#include <iostream>
// #include <math.h>
#include <cmath>
/*
 * Reffrences
 * @url:  http://www.cplusplus.com/doc/tutorial/classes/
 * @url: https://en.wikipedia.org/wiki/Determinant
 * @url: https://en.wikipedia.org/wiki/coefficient
 * @url: https://en.wikipedia.org/wiki/Matrix_multiplication
 * @url: https://en.wikipedia.org/wiki/Cramer%27s_rule
 * @url: https://fa.wikipedia.org/wiki/%D9%82%D8%A7%D8%B9%D8%AF%D9%87_%DA%A9%D8%B1%D8%A7%D9%85%D8%B1
*/
const int size = 3;
int length;

class Array {
	private:
		// int size = 3;
		// int length;
	public:
		double arraySum(double* values, const int length) {
			double result = 0;
			for (int i = 0; i < length; ++i) {
				result += values[i];
			}
			return result;
		}

		double* arrayPower(double* values, const int power) {
			double* result = new double[length];
			for (int i = 0; i < length; ++i) {
				result[i] = pow(values[i], power);
			}
			return result;
		}

		double* arrayMultiply(double* firstArray, double* secondArray) {
			double* result = new double[length];
			for (int i = 0; i < length; ++i) {
				result[i] = firstArray[i] * secondArray[i];
			}
			return result;
		}

		void arraySubstituteColumn(double matrix[size][size], int column, double replace[size], double result[size][size]) {
			for (int i = 0; i < size; ++i) {
				for (int j = 0; j < size; ++j) {
					if (j == column)
					{
						result[i][j] = replace[i];
					}
					else
					{
						result[i][j] = matrix[i][j];
					}
				}
			}
		}

		void getCofactor(double matrix[size][size], double output[size][size], const int excludingRow, const int excludingColumn, const int sizeEntions) {
			int i = 0, j = 0;
			for (int row = 0; row < sizeEntions; row++) {
				for (int column = 0; column < sizeEntions; column++) {
					if (row != excludingRow && column != excludingColumn) {
						output[i][j++] = matrix[row][column];
						if (j == sizeEntions - 1) {
							j = 0;
							i++;
						}
					}
				}
			}
		}

		double arrayDeterminant(double matrix[size][size], const int sizeension) {
			double result = 0;
			if (sizeension == 1)
				return matrix[0][0];
			double cofactor[size][size];
			int sign = 1;
			for (int f = 0; f < sizeension; f++) {
				getCofactor(matrix, cofactor, 0, f, sizeension);
				result += sign * matrix[0][f] * arrayDeterminant(cofactor, sizeension - 1);
				sign = -sign;
			}
			return result;
		}
};

int main() {
	Array array;

	std::cout << "Enter Length: " << std::endl;
	std::cin >> length;

	double* x = new double[length];
	double* y = new double[length];

	std::cout << "Enter " << length << " X values (double):" << std::endl;
	for (int i = 0; i < length; i++) {
		std::cin >> x[i];
	}

	std::cout << "Enter " << length << " Y values (double):" << std::endl;
	for (int i = 0; i < length; i++) {
		std::cin >> y[i];
	}

	double* result = new double[3];

	double coefficient[size][size];
	double results[size][1];

	for (int row = 0; row < size; ++row) {
		for (int column = 0; column < size; ++column) {
			coefficient[row][column] = array.arraySum(array.arrayPower(x, row + column), length);
		}
	}

	double* x_y 	= array.arrayMultiply(x, y);
	double* x2 		= array.arrayPower(x, 2);
	double* x2_y 	= array.arrayMultiply(x2, y);

	result[0] = array.arraySum(y, length);
	result[1] = array.arraySum(x_y, length);
	result[2] = array.arraySum(x2_y, length);

	double matrixA[size][size];
	double matrixB[size][size];
	double matrixC[size][size];

	array.arraySubstituteColumn(coefficient, 0, result, matrixA);
	array.arraySubstituteColumn(coefficient, 1, result, matrixB);
	array.arraySubstituteColumn(coefficient, 2, result, matrixC);

	result[0] = array.arrayDeterminant(matrixA, size) / array.arrayDeterminant(coefficient, size);
	result[1] = array.arrayDeterminant(matrixB, size) / array.arrayDeterminant(coefficient, size);
	result[2] = array.arrayDeterminant(matrixC, size) / array.arrayDeterminant(coefficient, size);

	std::cout << "A: " << result[0] << std::endl; // NAN
	std::cout << "B: " << result[1] << std::endl; // NAN
	std::cout << "C: " << result[2] << std::endl; // NAN

	return 0;
}
