#include "TestBench.h"
#include "RaiseMathLib.h"


//海伦公式
int heronformula()
{
	double a, b, c, s, p;//a,b,c为三角形的三条边，p为半周长，s为面积

	cin >> a >> b >> c;

	p = (a + b + c) / 2;

	s = sqrt(p * (p - a) * (p - b) * (p - c));

	cout.setf(ios::fixed);

	cout.precision(3);

	cout << s << endl;

	return 0;
}

void PrintPos(Point& p)
{
	cout << "X:" << p.GetX() << endl;
	cout << "Y:" << p.GetY() << endl;
}

void print_Circle(Circle& c)//Circle
{
	cout << "X:" << c.GetX() << endl;
	cout << "Y:" << c.GetY() << endl;
	cout << "Radius:" << c.GetRadius() << endl;
}
void PrintSRectData(ScreenRectangle& sR)
{
	cout << "lefttop_x:" << sR.GetLeftTop().s_x << " lefttop_y:" << sR.GetLeftTop().s_y << endl;
	cout << "leftbottom_x:" << sR.GetLeftBottom().s_x << " leftbottom_y:" << sR.GetLeftBottom().s_y << endl;
	cout << "righttop_x:" << sR.GetRightTop().s_x << " righttop_y:" << sR.GetRightTop().s_y << endl;
	cout << "rightbottom_x:" << sR.GetRightBootom().s_x << " rightbottom_y:" << sR.GetRightBootom().s_y << endl;
	cout << "center_x:" << sR.GetMidPos().s_x << " center.s_y:" << sR.GetMidPos().s_y << endl;
	cout << "sRct_width:" << sR.GetWidth() << " sRct_height:" << sR.GetHeight() << endl;
}
void Print_Matrix(mMatrix& mat)
{
	cout << "This Matrix Data is as Follows:" << endl;
	auto data = mat.GetData();
	auto rows = mat.GetRows();
	auto cols = mat.GetColumns();
	for (int i = 0; i < rows* cols; i++)
	{
		cout << std::setw(3) << std::left << data[i] << " ";
		if (i % mat.GetColumns() + 1 == mat.GetColumns())
			cout << endl;
	}
}
void SetData(mMatrix& mat)
{
	cout << "Please Input Matrix Data:" << "\n";
	int temp = 0;
	for (int i = 0; i < mat.GetRows() * mat.GetColumns(); i++)
	{
		cin >> temp;
		mat.setElement(i, temp);
	}
}
void test_mMatrix()
{
	mMatrix mat(3,3);	//矩阵
	//mat.Generate();
	SetData(mat);
	Print_Matrix(mat);
	auto result = mat.Find1();
	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << " ";
	}
	cout << "Fond Fist Data Rows Nunber is " << mat.Find1_RowNo() << endl;
}


void PrintScreenPos(Pixel& pix)
{
	cout << "s_x:" << pix.GetSX() << "  s_y:" << pix.GetSY() << endl;
}

void PrintRGB(Rmath::RGBQUAD& rgb)
{
	cout << "Red:" << rgb.rgbRed << " Green:" << rgb.rgbGreen << " Blue:" << rgb.rgbBlue << endl;
}

int test_MD5() {
	const char* test_str = "hello world";
	cout << "MD5(\"" << test_str << "\") = " << md5(test_str, strlen(test_str)) << endl;
	return 0;
}

void test_sPos()
{
	std::cout << "Hello World!\n";
	ScreenRectangle srct(20, 30, 40, 40);
	PrintSRectData(srct);
}

void print_complexFreq(complexfreq& s)
{
	cout << "s=" << s.getreal() << " + j" << s.getimag() << endl;
}



