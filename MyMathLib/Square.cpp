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
	// TODO: �ڴ˴����� return ���
	return side * side;
}

template<class T>
inline T& Square<T>::SidesLeghth()
{
	// TODO: �ڴ˴����� return ���
	return 4 * side;
}

template<class T>
inline T& Square<T>::Area()
{
	// TODO: �ڴ˴����� return ���
	return side * side;
}
