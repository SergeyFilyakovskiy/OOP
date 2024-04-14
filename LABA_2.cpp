//Создать класс, описывающий вектор на плоскости, задаваемый
//парой координат.Реализовать метод, вычисляющий длину вектора,
//перегрузить операторы « + »(сложение двух векторов), «* »(умножения
//вектора на число), « == »(сравнение векторов), « > »(сравнение векторов по
//длине).Создать методы доступа к полям класса.Реализовать конструкторы
//(по умолчанию, с параметрами, копирования), деструктор.Реализовать
//friend - функции для операторов ввода / вывода в поток для созданного класса

#include <iostream>
#include <sstream>
#include <cmath>

template<typename T>
T checkInput()
{
	T val;
	while (true)
	{
		std::string input;
		std::cin >> input;

		std::stringstream ss(input);
		if (ss >> val && ss.eof())
			break;
		else
			std::cout << "Некорректный ввод! Попробуйте еще раз." << std::endl;
	}

	return val;
}

class Vector
{
private:
	float m_firstX, m_secondX, m_firstY, m_secondY;//переменные члены класса

public:

	Vector() { m_firstX = 0; m_firstY = 0; m_secondX = 0; m_secondY = 0; }; //Конструктор по умолчанию
	
	Vector(float firstX, float firstY, float secondX, float secondY)//Конструктор с параметрами
	{
		m_firstX = firstX;
		m_firstY = firstY;
		m_secondX = secondX;
		m_secondY = secondY;
	}
	Vector(const Vector& other)//конструтор копирования
	{
		m_firstX = other.m_firstX; m_firstY = other.m_firstY; m_secondX = other.m_secondX; m_secondY = other.m_secondY;
	}
	~Vector() {} //деструктор

	//перегрузки 
	friend std::ostream& operator<< (std::ostream& out, const Vector& vector);
	friend std::istream& operator>> (std::istream& in, Vector& vector);
	friend Vector operator+(const Vector& first, const Vector& second);
	friend Vector operator*(const Vector& vector, int multiplier);
	friend int operator==(const Vector& first, const Vector& second);
	friend int operator<(Vector& first, Vector& second);
	void setVaules(float fX, float fY, float sX, float sY)
	{
		m_firstX = fX; m_firstY = fY;
		m_secondX = sX; m_secondY = sY;
	}
	//методы 
	float vectorLength();

};

int HeadFunction_2 ()
{
	Vector firstVector, secondVector;
	int choise;
	do 
	{
		std::cout << "======================Меню======================\n";
		std::cout << "1.Ввести 2 вектора\n2.Вычислить длину вектора\n3.Сложение двух векторов\n4.Умножение вектора на чилсо\n5.Сравнение векторов\n6.Сравнение векторов по длине\n7. Вывод значений векторов\n";
		std::cout << "================================================\n";
	    choise= checkInput<int>();

		switch (choise)
		{
		case 1:
			do
			{
				std::cout << "1.Ввести первый вектор\n2.Ввести второй вектор\n3.Выход из ввода";
				choise = checkInput<int>();
				switch (choise)
				{
				case 1:
				{
					std::cout << "Введите вектор:\n";
					float fX, fY, sX, sY;
					fX = checkInput<float>();
					fY = checkInput<float>();
					sX = checkInput<float>();
					sY = checkInput<float>();
					firstVector.setVaules(fX, fY, sX, sY);
					break;
				}
				case 2:
				{
					std::cout << "Введите вектор:\n";

					float fX, fY, sX, sY;
					fX = checkInput<float>();
					fY = checkInput<float>();
					sX = checkInput<float>();
					sY = checkInput<float>();
					secondVector.setVaules(fX, fY, sX, sY);
					break;
				}
				case 3:
					break;
				}
			} while (choise != 3);
			break;

		case 2:
		{
			do
			{
				std::cout << "1.Найти длину первого вектора\n2.Найти длину второго вектора\n3.Выход\n";
				choise = checkInput<int>();
				switch (choise)
				{
				case 1:
				{
					std::cout << firstVector.vectorLength() << std::endl;
					break;
				}
				case 2:
					std::cout << secondVector.vectorLength() << std::endl;
					break;
				case 3:
					break;
				}
			} while (choise != 3);
			break;
		}
		case 3:
		{
			Vector Result = firstVector + secondVector;
			std::cout << Result;
			break;
		}
		case 4:
			{
				do
				{
					std::cout << "1.Умножить первый вектор\n2.Умножить второй вектора\n3.Выход\n";
					choise = checkInput<int>();
					switch (choise)
					{
					case 1:
					{
						std::cout << "Введите множитель\n" << std::endl;
						int multiplier = checkInput<int>();
						firstVector = firstVector * multiplier;
						std::cout << firstVector <<std::endl;
						break;
					}
					case 2:
					{
						std::cout << "Введите множитель\n" << std::endl;
						int multiplier = checkInput<int>();
						Vector secondVector = secondVector * multiplier;
						std::cout << secondVector << std::endl;
						break;
					}
					case 3:
						break;
					}
				} while (choise != 3);
				break;
			}
		case 5:
			if (firstVector == secondVector)
			{
				std::cout << "Вектора равны" << std::endl;
			}
			else std::cout << "Вектора не равны" << std::endl;
			break;

		case 6:
			firstVector < secondVector;
			break;

		case 7:
			std::cout << "Первый вектор: " << firstVector << std::endl;
			std::cout << "Второй вектор: " << secondVector << std::endl;
			break;

		default:
			break;
		}
	} while (choise != 8);
	
	return 0;
}

float Vector::vectorLength() 
{
	float length;
	length = sqrt(pow(m_secondX - m_firstX, 2) + pow(m_secondY - m_firstY, 2));
	return length;
}
Vector operator+(const Vector& first, const Vector& second)
{
	return Vector(first.m_firstX + second.m_firstX, first.m_firstY + second.m_firstY, first.m_secondX+second.m_secondX, first.m_secondY+second.m_secondY);
};
Vector operator*(const Vector& vector, int multiplier)
{
	return Vector(vector.m_firstX * multiplier, vector.m_firstY * multiplier, vector.m_secondX * multiplier, vector.m_secondY * multiplier);
};
int operator==(const Vector& first, const Vector& second) 
{
	int compareResult = (first.m_firstX == second.m_firstX && first.m_firstY == second.m_firstY && first.m_secondX == second.m_secondX && first.m_secondY == second.m_secondY ? 1 : 0);
	return compareResult;
};
std::ostream& operator<< (std::ostream& out, const Vector& vector) 
{
	out << "Вектор(" << vector.m_firstX << "," << vector.m_firstY << ";" << vector.m_secondX << "," << vector.m_secondY << ")\n";
	
	return out;
}
std::istream& operator>> (std::istream& in,Vector& vector)
{
	in >> vector.m_firstX;
	in >> vector.m_firstY;
	in >> vector.m_secondX;
	in >> vector.m_secondY;

	return in;
}
int operator<(Vector& first, Vector& second)
{
	if (first.vectorLength() < second.vectorLength())
	{
		std::cout << "Первый вектор меньше второго" << std::endl;
	}
	else 	if (first.vectorLength() > second.vectorLength())
	{
		std::cout << "Первый вектор больше второго" << std::endl;
	}
	else
	{
		std::cout << "Длины равны" << std::endl;
	}
	return 0;
}