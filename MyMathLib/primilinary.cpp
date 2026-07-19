#include "preliminary.h"


namespace Rmath
{
	

	/*******Point******************************************************************/
	Point::Point()
	{
		x = 0;
		y = 0;
	}
	Point::Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int& Point::GetX()
	{
		// TODO: 在此处插入 return 语句
		return x;
	}

	int& Point::GetY()
	{
		// TODO: 在此处插入 return 语句
		return y;
	}

	void Point::Zero()
	{
		x = 0;
		y = 0;
	}

	void Point::SetPos(const int& xa, const int& ya)
	{
		x = xa;
		y = ya;
	}

	Point::Point(Point& po)
	{
		this->x = po.x;
		this->y = po.y;
	}

	Point::Point(const int& xp, const int& yp)
	{
		x = xp;
		y = yp;
	}

	void Point::SetPointValue(int& x_t, int& y_t)
	{
		x_t = x;
		y_t = y;
	}



	Point& Point::GetPointPos()
	{
		return *this;
	}
	Point& Point::MoveX(int stepx)
	{
		x += stepx;
		return *this;
	}

	Point& Point::MoveY(int stepy)
	{
		y += stepy;
		return *this;
	}

	/*******Point******************************************************************/


	/*******Circle***begin***************************************************************/
	Circle::Circle()
	{
		x = 0;
		y = 0;
		radius = 0;
	}


	Circle::Circle(const int& x_t, const int& y_t, const unsigned int r)
	{
		x = x_t;
		y = y_t;
		radius = r;
	}

	Circle::Circle(const Circle& c)
	{
		this->x = c.x;
		this->y = c.y;
		this->radius = c.radius;
	}




	Circle& Circle::Copy()
	{
		return *this;
	}


	bool Circle::IsOnCircle(const int& x_t, const int& y_t)
	{
		if (x == x_t && y == y_t)
			return true;
		return false;
	}

	bool  Circle::operator==(Circle& c)
	{
		// TODO: 在此处插入 return 语句
		if (c.x == this->x && c.y == this->y && c.radius == this->radius)
			return true;
		return false;
	}

	void Circle::SetRadius(unsigned int r)
	{
		radius = r;
	}

	unsigned int& Circle::GetRadius()
	{
		return this->radius;
	}

	unsigned int Circle::SidesLeghth()
	{
		// TODO: 在此处插入 return 语句
		return static_cast<unsigned int>(radius * 2 * Pi_0);
	}

	unsigned int Circle::Area()
	{
		// TODO: 在此处插入 return 语句
		return static_cast<unsigned int>(Pi_14 * radius * radius);
	}

	unsigned int Circle::Diameter()
	{
		return (radius * 2);
	}

	/*******Circle***end***************************************************************/

	/*******Pixel******************************************************************/
	Pixel::Pixel(Pixel& p)
	{
		this->s_x = p.s_x;
		this->s_y = p.s_y;
		this->rgb = p.rgb;
	}

	Pixel::Pixel(const unsigned int& x, const unsigned int& y,
		const unsigned int& red, const unsigned int& green, const unsigned int& blue)
	{
		this->s_x = x;
		this->s_y = y;
		this->rgb.rgbRed = red;
		this->rgb.rgbGreen = green;
		this->rgb.rgbBlue = blue;
	}

	Pixel::~Pixel()
	{
	}

	unsigned int& Pixel::GetSX()
	{
		// TODO: 在此处插入 return 语句
		return this->s_x;
	}

	unsigned int& Pixel::GetSY()
	{
		// TODO: 在此处插入 return 语句
		return s_y;
	}

	RGBQUAD& Pixel::GetRGB()
	{
		// TODO: 在此处插入 return 语句
		return rgb;
	}


	/*******Pixel******************************************************************/

	/*******Square******************************************************************/

	template<class T>
	inline Square<T>::Square()
	{
		side = 0;
	}

	template<class T>
	inline Square<T>::Square(T& side)
	{
		this->side = side;
	}

	template<class T>
	inline T& Square<T>::GetSquare()
	{
		// TODO: 在此处插入 return 语句
		return side * side;
	}

	template<class T>
	inline T& Square<T>::SidesLeghth()
	{
		// TODO: 在此处插入 return 语句
		return 4 * side;
	}

	template<class T>
	inline T& Square<T>::Area()
	{
		// TODO: 在此处插入 return 语句
		return side * side;
	}
	/*******Square******************************************************************/



	/******Coordinates***********************************************************/
	


	Coordinates::Coordinates(double& lat, double& lng)
	{
		this->lat = lat;
		this->lng = lng;
	}

	double& Coordinates::GetLat()
	{
		// TODO: 在此处插入 return 语句
		return this->lat;
	}

	double& Coordinates::GetLng()
	{
		// TODO: 在此处插入 return 语句
		return this->lng;
	}

	void Coordinates::SetCoordinates(double& lat, double& lng)
	{
		this->lat = lat;
		this->lng = lng;
	}

	char Coordinates::EastOrWestLng()
	{
		// TODO: 在此处插入 return 语句
		if (lng >= 0)
			return 'E';
		else
			return 'W';
		return 0;
	}

	char Coordinates::NorthOrSouthLat()
	{
		if (lat >= 0)
			return 'N';
		else
			return 'S';
		return 0;
	}

	char Coordinates::NorthernOrSourthHemisphere()
	{
		if (lat < 0)
			return 'S';
		else
			return 'N';
		return 0;
	}

	char Coordinates::EasternOrWesternHemisohere()
	{
		if (lng > -20 && lng <= 160)
			return 'E';
		else
			return 'W';
		return 0;
	}

	int Coordinates::TimeZone()
	{
		if ((int)lng % 15 > 0)
			return lng / 15 + 1;
		else
			return lng / 15;
		return 0;
	}

	int Coordinates::TimeZone(double lng)
	{
		if ((int)lng % 15 > 0)
			return lng / 15 + 1;
		else
			return lng / 15;
		return 0;
	}

	double Coordinates::TimeZoneCenterline()
	{
		// TODO: 在此处插入 return 语句
		int n = 0;
		if ((int)lng % 15 > 0)
			n = lng / 15 + 1;
		else
			n = lng / 15;
		return static_cast<double>(n * 15);
	}

	double Coordinates::TimeZoneCenterline(int n)
	{
		// TODO: 在此处插入 return 语句
		return static_cast<double>(n * 15);
	}

	double Coordinates::LeftLngOfTimeZone()
	{
		int n = 0;
		if ((int)lng % 15 > 0)
			n = lng / 15 + 1;
		else
			n = lng / 15;
		return n * 15 - 7.5;
	}

	double Coordinates::RightLngOfTimeZone()
	{
		int n = 0;
		if ((int)lng % 15 > 0)
			n = lng / 15 + 1;
		else
			n = lng / 15;
		return n * 15 + 7.5;
	}


	double Coordinates::LeftLngOfTimeZone(double lng)
	{
		int n = 0;
		if ((int)lng % 15 > 0)
			n = lng / 15 + 1;
		else
			n = lng / 15;
		return n * 15 - 7.5;
	}

	double Coordinates::RightLngOfTimeZone(double lng)
	{
		int n = 0;
		if ((int)lng % 15 > 0)
			n = lng / 15 + 1;
		else
			n = lng / 15;
		return n * 15 + 7.5;
	}
	/******Coordinates***********************************************************/

	/******mMatrix***********************************************************/
	// Study.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
	// 2025年《C++程序设计》
	// 加分题
	// Author：柴锦
	// 
	mMatrix::mMatrix(unsigned char rows, unsigned char column)
	{
		this->rows = rows;
		this->column = column;
		pBuf = new unsigned char[rows * column];
	}
	mMatrix::mMatrix(unsigned char rows, unsigned char column, vector<unsigned char> data)
	{
		this->rows = rows;
		this->column = column;
		pBuf = new unsigned char[rows * column];
		for (int i = 0;i < data.size();i++)
		{
			pBuf[i] = data[i];
		}
	}

	mMatrix::mMatrix()
	{
		rows = 3;
		column = 3;
		pBuf = new unsigned char[rows * column];
	}

	mMatrix::~mMatrix()
	{
		if (pBuf)
			delete pBuf;
	}

	void inline mMatrix::initBuffer(unsigned char rows, unsigned char column)
	{
		this->rows = rows;
		this->column = column;
		pBuf = new unsigned char[rows * column];
	}

	void mMatrix::Generate()
	{
		srand(time_t());

		for (int i = 0; i < rows * column; i++)
		{
			pBuf[i] = rand() % 255;
		}
	}
	uint16_t& mMatrix::GetRows()
	{
		return this->rows;
	}
	uint16_t& mMatrix::GetColumns()
	{
		return this->column;
	}
	std::span<unsigned char> GetData()
	{
		static unsigned char buffer[128];
		return buffer; // 生命周期由调用者负责
	}
	//序数从1开始而不是从0开始
	//没有返回0
	//返回的是第一个满足条件的行号
	int mMatrix::Find1_RowNo()
	{
		//rows * column /rows	每行的个数
		for (int i = 0; i < column; i++)
		{
			if (pBuf[i] == 1)
			{
				return i / column + 1;
			}
			i += column;
		}
		return 0;
	}
	vector<unsigned char> mMatrix::Find1()
	{
		auto tmp = vector<unsigned char>();
		//rows * column /rows	每行的个数
		for (int i = 0; i < column; i++)
		{
			if (pBuf[i] == 1)
			{
				for (int j = i; j < column; j++)
					tmp.push_back(pBuf[j]);
			}
			i += column;
		}
		return tmp;
	}
	bool mMatrix::setElement(int index, int value)
	{
		if (index < 0 || index >= sizeof(this->pBuf))//static_cast<int>(data_.size())
			return false;

		if (value < 0 || value > 255)
			return false;

		this->pBuf[static_cast<size_t>(index)] = static_cast<unsigned char>(value);
		return true;
	}

	
	/******mMatrix***********************************************************/


	/******MD5***********************************************************/
	inline uint32_t rotate_left(uint32_t x, int n) {
		return (x << n) | (x >> (32 - n));
	}

	inline uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
		return (x & y) | (~x & z);
	}

	inline uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
		return (x & z) | (y & ~z);
	}

	inline uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
		return x ^ y ^ z;
	}

	inline uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
		return y ^ (x | ~z);
	}

	static const uint32_t T[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
	};

	const int param_indices[4][16] = {
		{0,3,2,1,0,3,2,1,0,3,2,1,0,3,2,1},
		{3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2},
		{2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1},
		{1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0}
	};

	const int m_indices[4][16] = {
		{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
		{1,6,11,0,5,10,15,4,9,14,3,8,13,2,7,12},
		{5,8,11,14,1,4,7,10,13,0,3,6,9,12,15,2},
		{0,3,6,9,12,15,2,5,8,11,14,1,4,7,10,13}
	};

	void FF(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t t) {
		a = b + rotate_left((a + F(b, c, d) + x + t), s);
	}

	void GG(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t t) {
		a = b + rotate_left((a + G(b, c, d) + x + t), s);
	}

	void HH(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t t) {
		a = b + rotate_left((a + H(b, c, d) + x + t), s);
	}

	void II(uint32_t& a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t t) {
		a = b + rotate_left((a + I(b, c, d) + x + t), s);
	}

	vector<uint8_t> pad_data(const uint8_t* input, size_t nBytes) {
		size_t originalLengthBits = nBytes * 8;
		size_t newLength = nBytes + 1;
		while (newLength % 64 != 56) {
			newLength++;
		}
		vector<uint8_t> data(newLength + 8);
		memcpy(data.data(), input, nBytes);
		data[nBytes] = 0x80;
		for (int i = 0; i < 8; ++i) {
			data[newLength + i] = (originalLengthBits >> ((7 - i) * 8)) & 0xFF;
		}
		return data;
	}

	void process_block(const uint8_t* block, uint32_t& a, uint32_t& b, uint32_t& c, uint32_t& d) {
		uint32_t M[16];
		for (int i = 0; i < 16; ++i) {
			M[i] = (block[i * 4] << 24) | (block[i * 4 + 1] << 16) | (block[i * 4 + 2] << 8) | block[i * 4 + 3];
		}

		for (int round = 0; round < 4; ++round) {
			for (int step = 0; step < 16; ++step) {
				int s = param_indices[round][step];
				int m_index = m_indices[round][step];
				uint32_t x = M[m_index];
				switch (round) {
				case 0: FF(a, b, c, d, x, s, T[step]); break;
				case 1: GG(d, a, b, c, x, s, T[16 + step]); break;
				case 2: HH(c, d, a, b, x, s, T[32 + step]); break;
				case 3: II(b, c, d, a, x, s, T[48 + step]); break;
				}
			}
		}
	}

	string md5(const void* input, size_t nBytes) 
	{
		uint32_t a = 0x67452301;
		uint32_t b = 0xEFCDAB89;
		uint32_t c = 0x98BADCFE;
		uint32_t d = 0x10325476;

		vector<uint8_t> data = pad_data(static_cast<const uint8_t*>(input), nBytes);

		for (size_t i = 0; i < data.size(); i += 64) {
			process_block(data.data() + i, a, b, c, d);
		}

		uint8_t digest[16];
		memcpy(digest, &a, 4);
		memcpy(digest + 4, &b, 4);
		memcpy(digest + 8, &c, 4);
		memcpy(digest + 12, &d, 4);

		char hex[33];
		for (int i = 0; i < 16; ++i) {
			sprintf(hex + i * 2, "%02x", digest[i]);
		}
		return string(hex);
	}


	/******MD5***********************************************************/


	/******ScreenRectangle***********************************************************/
	ScreenRectangle::ScreenRectangle()
	{
		this->width = 0;
		this->height = 0;
		this->lefttop.s_x = 0;
		this->lefttop.s_y = 0;
		this->center.s_x = 0;
		this->center.s_y = 0;
		this->rightbottom.s_x = 0;
		this->rightbottom.s_y = 0;
		this->leftbottom.s_x = 0;
		this->leftbottom.s_y = 0;
		this->righttop.s_x = 0;
		this->righttop.s_y = 0;
	}

	ScreenRectangle::ScreenRectangle(ScreenRectangle& sRct)
	{
		this->width = sRct.width;
		this->height = sRct.height;
		this->lefttop = sRct.lefttop;
		this->leftbottom = sRct.leftbottom;
		this->righttop = sRct.righttop;
		this->rightbottom = sRct.rightbottom;
		this->center = sRct.center;
	}

	ScreenRectangle::ScreenRectangle(const unsigned int& s_x, const unsigned int& s_y, const unsigned int& width, const unsigned int& height)
	{
		this->lefttop.s_x = s_x;
		this->lefttop.s_y = s_y;
		this->width = width;
		this->height = height;
		this->leftbottom.s_x = s_x;
		this->leftbottom.s_y = s_y + height;
		this->righttop.s_x = s_x + width;
		this->righttop.s_y = s_y;
		this->rightbottom.s_x = s_x + width;
		this->rightbottom.s_y = s_y + height;
		this->center.s_x = s_x + width / 2;
		this->center.s_y = s_y + height / 2;
	}


	sPos& ScreenRectangle::GetMidPos()
	{
		// TODO: 在此处插入 return 语句
		return this->center;
	}
	sPos& ScreenRectangle::GetLeftTop()
	{
		return this->lefttop;
	}
	sPos& ScreenRectangle::GetLeftBottom()
	{
		return this->leftbottom;
	}
	sPos& ScreenRectangle::GetRightTop()
	{
		return this->righttop;
	}
	sPos& ScreenRectangle::GetRightBootom()
	{
		return this->rightbottom;
	}
	unsigned int& ScreenRectangle::GetWidth()
	{
		return this->width;
	}
	unsigned int& ScreenRectangle::GetHeight()
	{
		return this->height;
	}
	void ScreenRectangle::SetLefttop(const int& lefttop_x, const int& lefttop_y)
	{
		this->lefttop.s_x = lefttop_x;
		this->lefttop.s_y = lefttop_y;
	}

	void ScreenRectangle::SetCenter(const int& mid_x, const int& mid_y, const int& width, const int& height)
	{
		this->center.s_x = mid_x;
		this->center.s_y = mid_y;
		this->height = height;
		this->width = width;
		this->lefttop.s_x = mid_x - width / 2;
		this->lefttop.s_y = mid_y - height / 2;
		this->righttop.s_x = mid_x + width / 2;
		this->righttop.s_y = mid_y - height / 2;
		this->leftbottom.s_x = mid_x - width / 2;
		this->leftbottom.s_y = mid_y + height / 2;
		this->rightbottom.s_x = mid_x + width / 2;
		this->rightbottom.s_y = mid_y + height / 2;
	}

	void ScreenRectangle::SetSRectWidHgt(const int& width, const int& height)
	{
		this->width = width;
		this->height = height;
	}



	void ScreenRectangle::CalcDataByLefttop()
	{
		if (this->width == 0 || this->height == 0)
			return;
		this->center.s_x = this->lefttop.s_x + width / 2;
		this->center.s_y = this->lefttop.s_y + height / 2;
		this->righttop.s_x = this->lefttop.s_x + width;
		this->righttop.s_y = this->lefttop.s_y;
		this->leftbottom.s_x = this->lefttop.s_x;
		this->leftbottom.s_y = this->lefttop.s_y + height;
		this->rightbottom.s_x = this->lefttop.s_x + width;
		this->rightbottom.s_y = this->lefttop.s_y + height;
	}

	void ScreenRectangle::CalcDataByMidPos()
	{
		this->lefttop.s_x = center.s_x - width / 2;
		this->lefttop.s_y = center.s_y - height / 2;
		this->rightbottom.s_x = center.s_x + width / 2;
		this->rightbottom.s_y = center.s_y + height / 2;
		this->leftbottom.s_x = center.s_x - width / 2;
		this->leftbottom.s_y = center.s_y + height / 2;
		this->righttop.s_x = center.s_x + width / 2;
		this->righttop.s_y = center.s_y - height / 2;
	}

	void ScreenRectangle::CalcByLefttopRightbottom(const int& lefttop_x, const int& lefttop_y, const int& rightbottom_x, const int& rightbottom_y)
	{
		this->lefttop.s_x = lefttop_x;
		this->lefttop.s_y = lefttop_y;
		this->rightbottom.s_x = rightbottom_x;
		this->rightbottom.s_y = rightbottom_y;
		this->width = rightbottom_x - lefttop_x;
		this->height = rightbottom_y - lefttop_y;
		this->righttop.s_x = lefttop_x + this->width;
		this->righttop.s_y = lefttop_y;
		this->leftbottom.s_x = lefttop_x;
		this->leftbottom.s_y = rightbottom_y;
		this->center.s_x = lefttop_x + this->width / 2;
		this->center.s_y = lefttop_x + this->height / 2;
	}




	/******ScreenRectangle***********************************************************/

	/******triangle***********************************************************/
	const double EPS = 1e-9;

	inline bool almostEqual(double x, double y)//浮点型要容差
	{
		return std::fabs(x - y) < EPS;
	}
	inline std::array<double, 3> sortSides(double a, double b, double c)
	{
		std::array<double, 3> sides = { a, b, c };
		std::sort(sides.begin(), sides.end());
		return sides;
	}

	triangle::triangle()
	{
		this->a = 3;
		this->b = 4;
		this->c = 5;
	}
	triangle::triangle(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	triangle::triangle(triangle& tria)
	{
		this->a = tria.a;
		this->b = tria.b;
		this->c = tria.c;
	}
	double triangle::area(double base, double height)
	{
		return base * height / 2;
	}
	double triangle::area_heron()
	{
		auto s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
	double triangle::perimeter()
	{
		return a + b + c;
	}
	bool triangle::isTriangle()
	{
		// 边长必须大于 0
		if (a <= 0 || b <= 0 || c <= 0)
			return false;

		// 三角形不等式
		if (a + b <= c || a + c <= b || b + c <= a)
			return false;

		return true;
	}
	double triangle::angleA()
	{
		double angleA_rad = acos((b * b + c * c - a * a) / (2 * b * c));
		return angleA_rad;
	}
	double triangle::angleC()
	{
		double angleC_rad = acos((a * a + b * b - c * c) / (2 * a * b));
		return angleC_rad;
	}
	double triangle::angleB()
	{
		double angleB_rad = acos((a * a + c * c) / (2 * a * c));
		return angleB_rad;
	}
	bool triangle::equalSide()
	{
		if (a == b == c)
			return true;
		return false;
	}
	bool triangle::isosceles()
	{
		return almostEqual(a, b) ||
			almostEqual(b, c) ||
			almostEqual(a, c);
	}


	bool triangle::isSimilar(triangle& other)
	{
		std::array<double, 3> sides1{ this->a, this->b, this->c };
		std::array<double, 3> sides2{ other.a, other.b, other.c };

		std::sort(sides1.begin(), sides1.end());
		std::sort(sides2.begin(), sides2.end());

		double r1 = sides1[0] / sides2[0];
		double r2 = sides1[1] / sides2[1];
		double r3 = sides1[2] / sides2[2];

		return almostEqual(r1, r2) && almostEqual(r2, r3);
	}
	/******triangle***********************************************************/
}/*****namapspace Rmath;**************/