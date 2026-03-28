#include "Square.h"


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
