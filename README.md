# MatrixFunction

The Cramer, Determinant, Coefficient, Multiplication for the matrix.

## Search

### Cramer's rule

In linear algebra, Cramer's rule is an explicit formula for the solution of a system of linear equations with as many equations as unknowns, valid whenever the system has a unique solution. It expresses the solution in terms of the determinants of the (square) coefficient matrix and of matrices obtained from it by replacing one column by the column vector of right-hand-sides of the equations. It is named after Gabriel Cramer (1704–1752), who published the rule for an arbitrary number of unknowns in 1750, although Colin Maclaurin also published special cases of the rule in 1748 (and possibly knew of it as early as 1729).

Cramer's rule implemented in a naïve way is computationally inefficient for systems of more than two or three equations. In the case of n equations in n unknowns, it requires computation of n + 1 determinants, while Gaussian elimination produces the result with the same computational complexity as the computation of a single determinant. Cramer's rule can also be numerically unstable even for 2×2 systems. However, it has recently been shown that Cramer's rule can be implemented in O(n3) time, which is comparable to more common methods of solving systems of linear equations, such as Gaussian elimination (consistently requiring 2.5 times as many arithmetic operations for all matrix sizes), while exhibiting comparable numeric stability in most cases. 

[Read More](https://en.wikipedia.org/wiki/Cramer%27s_rule)

### Determinant

In linear algebra, the determinant is a scalar value that can be computed from the elements of a square matrix and encodes certain properties of the linear transformation described by the matrix. The determinant of a matrix A is denoted det(A), det A, or |A|. Geometrically, it can be viewed as the volume scaling factor of the linear transformation described by the matrix. This is also the signed volume of the n-dimensional parallelepiped spanned by the column or row vectors of the matrix. The determinant is positive or negative according to whether the linear mapping preserves or reverses the orientation of n-space. 

[Read More](https://en.wikipedia.org/wiki/Determinant)

### Coefficient

In mathematics, a coefficient is a multiplicative factor in some term of a polynomial, a series, or any expression; it is usually a number, but may be any expression. In the latter case, the variables appearing in the coefficients are often called parameters, and must be clearly distinguished from the other variables.

[Read More](https://en.wikipedia.org/wiki/Coefficient)

### Matrix multiplication

In mathematics, matrix multiplication or matrix product is a binary operation that produces a matrix from two matrices with entries in a field, or, more generally, in a ring or even a semiring. The matrix product is designed for representing the composition of linear maps that are represented by matrices. Matrix multiplication is thus a basic tool of linear algebra, and as such has numerous applications in many areas of mathematics, as well as in applied mathematics, statistics, physics, economics, and engineering. In more detail, if A is an n × m matrix and B is an m × p matrix, their matrix product AB is an n × p matrix, in which the m entries across a row of A are multiplied with the m entries down a column of B and summed to produce an entry of AB. When two linear maps are represented by matrices, then the matrix product represents the composition of the two maps. 

[Read More](https://en.wikipedia.org/wiki/Matrix_multiplication)
