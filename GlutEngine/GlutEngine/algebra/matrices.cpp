#include "matrices.h"

kmu::SquareMatrix::SquareMatrix(size_t power, float diagonal)
	: oSize(power)
	, oData(nullptr)
{
	if (oSize != 0)
	{
		oData = new float[oSize*oSize];
		memset(oData, 0, bytes());
		for (register size_t i(0); i < oSize; ++i)
				oData[i * oSize + i] = diagonal;
	}
}

kmu::SquareMatrix::SquareMatrix(const SquareMatrix & mtx)
{
	oSize = mtx.oSize;
	oData = new float[oSize*oSize];
	memcpy(oData, mtx.oData, bytes());
}

kmu::SquareMatrix::~SquareMatrix()
{
	if (oSize != 0)
	{
		delete[] oData;
	}
}

kmu::SquareMatrix kmu::SquareMatrix::mult(const SquareMatrix &mtx1, const SquareMatrix &mtx2)
{
	if ((mtx1.oSize != mtx2.oSize) ||
		(std::fminl(mtx1.oSize, mtx2.oSize) == 0))
		return SquareMatrix(0);

	size_t size = mtx1.oSize;
	SquareMatrix res(size);

	for (register size_t i = 0; i < size; i++)
		for (register size_t j = 0; j < size; j++)
			for (register size_t k = 0; k < size; k++)
				res.oData[i * size + j] += mtx1.oData[i * size + k] * mtx2.oData[k * size + j];

	return res;
}

inline float & kmu::SquareMatrix::element(size_t i, size_t j)
{
	return oData[i * oSize + j];
}

inline float kmu::SquareMatrix::at(size_t i, size_t j)
{
	return oData[i * oSize + j];
}

inline size_t kmu::SquareMatrix::bytes()
{
	return (sizeof(float) * oSize * oSize);
}

inline const float * kmu::SquareMatrix::get()
{
	return oData;
}

const kmu::SquareMatrix & kmu::SquareMatrix::operator=(const SquareMatrix & mtx)
{
	if (oSize > 0)
		delete[] oData;
	oSize = mtx.oSize;
	oData = new float[oSize*oSize];
	memcpy(oData, mtx.oData, bytes());
	return *this;
}

const kmu::SquareMatrix & kmu::SquareMatrix::operator*=(const SquareMatrix & mtx)
{
	if ((oSize != mtx.oSize) ||
		(std::fminl(oSize, mtx.oSize) == 0))
		return *this;

	size_t size = oSize;
	SquareMatrix res(size);

	for (register size_t i = 0; i < size; i++)
		for (register size_t j = 0; j < size; j++)
			for (register size_t k = 0; k < size; k++)
				res.oData[i * size + j] += oData[i * size + k] * mtx.oData[k * size + j];
	*this = res;
	return *this;
}

std::string kmu::SquareMatrix::toString()
{
	std::string buffer("");

	for (register size_t i = 0; i < oSize; i++)
	{
		for (register size_t j = 0; j < oSize; j++)
			buffer += std::to_string(this->at(i, j)) + " ";
		buffer += '\n';
	}
	return buffer;
}


//------------------------------------------------------------------------------------------------------------------------------------------------
kmu::mat4::mat4(float n) : SquareMatrix(4, n)
{
}

kmu::mat4::mat4(const mat4 & mat) : SquareMatrix(mat)
{
}

kmu::mat4::~mat4()
{
}

const kmu::mat4 & kmu::mat4::operator*(const mat4 & right)
{
	for (register size_t i(0); i < 4; i++)
	{
		for (register size_t j(0); j < 4; j++)
		{
			element(i, j) = at(i, 0) * static_cast<SquareMatrix>(right).at(0, j) +
							at(i, 1) * static_cast<SquareMatrix>(right).at(1, j) +
							at(i, 2) * static_cast<SquareMatrix>(right).at(2, j) +
							at(i, 3) * static_cast<SquareMatrix>(right).at(3, j);
		}
	}
	return *this;
}
