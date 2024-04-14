//�������� ������ ���������-����������, ��������������, 
//���������������� ��������� � ����������� ������� ����� � �������.
//�������� ������ ������������� ��������, ��������, ������ �
//����������� ������� ����� � �������.�������� ���������, �������
//������� ������� ������� �� ���� �������, ���������� ����� �����������
//������������������.������� ��������� ��������, ���������������
//�������� ����������� �� ������������������.������ �� ���� ����������
//�������� �� ����� � � ����.������ ������ ��������� ������ ��������� �
//��������� �������� ���� �����.��� ���� ������� ������ ���� ��������� �
//���������� private ��� protected.

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

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
			std::cout << "������������ ����! ���������� ��� ���." << std::endl;
	}

	return val;
}

class Trans_Company
{
protected:
	std::string m_name;
	std::string m_country;
public:
	 Trans_Company(std::string name, std::string country);
	 Trans_Company();
	 ~Trans_Company() {};
	 void setTransportCompany(std::string name, std::string country) { m_country = country; m_name = name; };
	 void PrintCompany(Trans_Company& company)
	 {
		 std::cout << company.m_name << " " << company.m_country << "\n";
	 }
};

class Avia_Company
{
protected:
	std::string m_name;
	std::string m_country;

public:
	 Avia_Company(std::string name, std::string country);
	 Avia_Company();
	 ~Avia_Company() {};
	 void setAviaCompany(std::string name, std::string country) { m_country = country; m_name = name; };
	 void PrintCompany(const Avia_Company& company)
	 {
		 std::cout << company.m_name << " " << company.m_country << "\n";
	 }

};

class Railway_Company
{
protected:
	std::string m_name;  
	std::string m_country;

public:
	 Railway_Company(std::string name, std::string country);
	 Railway_Company();
	 void setRailwayCompany(std::string name, std::string country) { m_country = country; m_name = name; };
	 ~Railway_Company() {};
	 void PrintCompany(const Railway_Company& company)
	 {
		 std::cout << company.m_name << " " << company.m_country << "\n";
	 }

};

class Transport: public Trans_Company//�������� ����� Trans_Company
{
private:

	int m_capacity, m_throughput_in_month, m_range;//����������� � ���������� ��������� ������� � �����
	std::string m_transportName;

public:
	Transport(int capacity, int throughput, int range, std::string transportName);
	Transport() { m_capacity = 80; m_throughput_in_month = 15; m_range = 500; m_transportName = "�������"; }
	~Transport() {};
	int getCapacity() { return m_capacity; };
	int getThroughput() { return m_capacity; };
	int getRange() { return m_capacity; };
	void setCompanyTransport(std::string transportName, int throughput, int capacity, int range) { m_transportName = transportName; m_throughput_in_month = throughput; m_capacity = capacity; m_range = range; }
	void Print(const Transport& trans)
	{
		std::cout << "�����������: " << trans.m_capacity << "\n���������� ������ � �����: " << m_throughput_in_month << "\n������������ ��������� �����: " << m_range << "\n�������� ����������: " << m_transportName << std::endl;
	}
};

class Plane : public Avia_Company
{
private:

	int m_capacity, m_throughput_in_month, m_range;
	std::string m_transportName;

public:
	Plane(int capacity, int throughput, int range, std::string trasportName);
	Plane() { m_capacity = 200; m_throughput_in_month = 10; m_range = 5000; m_transportName = "�������"; }
	~Plane() {};
	int getCapacity() { return m_capacity; };
	int getThroughput() { return m_capacity; };
	int getRange() { return m_capacity; };
	void setCompanyTransport(std::string transportName, int throughput, int capacity, int range) { m_transportName = transportName; m_throughput_in_month = throughput; m_capacity = capacity; m_range = range; }
	void Print(const Plane& trans)
	{
		std::cout << "�����������: " << trans.m_capacity << "\n���������� ������ � �����: " << m_throughput_in_month << "\n������������ ��������� �����: " << m_range << "\n�������� ����������: " << m_transportName << std::endl;
	}
};

class Train: public Railway_Company
{
private:
	int m_capacity, m_throughput_in_month, m_range;
	std::string m_transportName;

public:
	Train(int capacity, int throughput, int range, std::string trasportName);
	Train() { m_capacity = 1000; m_throughput_in_month = 8; m_range = 2000; m_transportName = "�����"; }
	~Train() {};
	int getCapacity() { return m_capacity; };
	int getThroughput() { return m_capacity; };
	int getRange() { return m_capacity; };
	void setCompanyTransport(std::string transportName, int throughput, int capacity, int range) { m_transportName = transportName; m_throughput_in_month = throughput; m_capacity = capacity; m_range = range; }
	void Print(const Train& trans)
	{
		std::cout << "�����������: " << trans.m_capacity << "\n���������� ������ � �����: " << m_throughput_in_month << "\n������������ ��������� �����: " << m_range << "\n�������� ����������: " << m_transportName << std::endl;
	}

};
int calculation(std::vector<int>& people, std::vector<int>& range, Transport& trans, Train& train, Plane& plane)
{
	int TransCapacity = trans.getCapacity(); int TrainCapacity = train.getCapacity();
	int TransThroughput = trans.getThroughput(); int TrainThroughput = train.getThroughput();
	int TransRange = trans.getRange(); int TrainRange = train.getRange();
	int PlaneCapacity = plane.getCapacity(); int PlaneThroughput = plane.getThroughput();
	int PlaneRange = plane.getRange(); 
	int trips = 0;
	std::ofstream out;
	out.open("Results.txt");
	for (int i = 0; i<people.size(); i++) //� ���������� ���������� �������� �����������
	{
		
		
		if (TrainThroughput == 0)
		{
			i = people.size();
		}
		if (range[i] <= TransRange && range[i]!=0)
		{
			if (people[i] <= TransCapacity && people[i]!=0)
			{
				TransThroughput--;
				trips++;
				range[i] = 0; 
				people[i] = 0;
			}
		}
	
	}
	std::cout << "���������� ������ ����������� ��������: " << trips << std::endl;
	if (out.is_open()) 
	{
		out << "���������� ������ ����������� ��������: " << trips <<std::endl;
	}
	trips = 0;
	for (int i = 0;  i < people.size(); i++) //� ���������� ���������� �������� �����������
	{
		if (TrainThroughput == 0)
		{
			i = people.size();
		}
		if (range[i] <= TrainRange && range[i] != 0)
		{
			if (people[i] <= TrainCapacity && people[i] != 0)
			{
				TrainThroughput--;
				trips++;
				range[i] = 0;
				people[i] = 0;
			}
		}
	}
	std::cout << "���������� ������ �/� ��������: " << trips << std::endl;
	if (out.is_open())
	{
		out << "���������� ������ �/� ��������: " << trips << std::endl;
	}
	trips = 0;
	for (int i = 0;  i < people.size(); i++) //� ���������� ���������� �������� �����������
	{
		if (TrainThroughput == 0)
		{
			i = people.size();
		}
		if (range[i] <= PlaneRange && range[i] != 0)
		{
			if (people[i] <= PlaneCapacity && people[i] != 0)
			{
				PlaneThroughput--;
				trips++;
				range[i] = 0;
				people[i] = 0;
			}
		}
	}
	std::cout << "���������� ������ ������������: " << trips << std::endl;
	if (out.is_open())
	{
		out << "���������� ������ ������������: " << trips << std::endl;
	}
	return 0;
}

int HeadFunction_3()
{
	int choise;
	Transport vehicle;
	Plane plane;
	Train train;
	std::vector<int> people, range_for_dilivery;

	do
	{
		std::cout << "~~~~~~~~~~~~~~����~~~~~~~~~~~~~~\n" << "1. �������� ������� ��������\n2. �������� ��������\n3. �������� ������� ��������� ��������\n4. �������� ��������� ��������\n";
		std::cout<<"5. ������ ����������\n6. ������� ����������\n7. ������\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		choise=checkInput<int>();
		switch (choise)
		{
		case 1:
		{
			std::cout << "������������ ��������\n";
			vehicle.PrintCompany(vehicle);
			std::cout << "�/� ��������\n";
			train.PrintCompany(train);
			std::cout << "������������\n";
			plane.PrintCompany(plane);
			break;
		}
		case 2:
		{
			std::string newCompanyName, newCompanyCountry;
			do
			{
				std::cout << "------���� ��������������------\n" << "1. �������� ������������ ��������\n2. �������� �/� ��������\n3. �������� ������������\n4. �����\n" << "-------------------------------\n";
				choise = checkInput<int>();
				switch (choise)
				{
				case 1:
					std::cout << "������� ����� �������� � ������\n";
					newCompanyName = checkInput<std::string>();
					newCompanyCountry = checkInput<std::string>();
					vehicle.setTransportCompany(newCompanyName, newCompanyCountry);
					break;

				case 2:
					std::cout << "������� ����� �������� � ������\n";
					newCompanyName = checkInput<std::string>();
					newCompanyCountry = checkInput<std::string>();
					train.setRailwayCompany(newCompanyName, newCompanyCountry);
					break;

				case 3:
					std::cout << "������� ����� �������� � ������\n";
					newCompanyName = checkInput<std::string>();
					newCompanyCountry = checkInput<std::string>();
					plane.setAviaCompany(newCompanyName, newCompanyCountry);
					break;

				default:
					break;
				}
			} while (choise != 4);
			break;
		}
		case 3:
		{
			std::cout << "��������� ����������� ��������\n";
			vehicle.Print(vehicle);
			std::cout << "��������� ������������\n";
			plane.Print(plane);
			std::cout << "��������� �/� ��������\n";
			train.Print(train);
			break;
		}
		case 4:
		{
			std::string newTransportName;
			int newRange, newCapacity, newThoughputInMonth;
			do
			{
				std::cout<< "------���� ��������������------\n" <<"1. �������� ��������� ������������ ��������\n2. �������� ��������� ������������\n3. �������� ��������� �/� ��������\n"<< "-------------------------------\n";
				choise = checkInput<int>();
				switch (choise)
				{
				case 1:
					std::cout << "������� ����� ��������, ���-�� ������, �����������, ���������\n";
					newTransportName = checkInput<std::string>();
					newThoughputInMonth = checkInput<int>();
					newCapacity = checkInput<int>();
					newRange = checkInput<int>();
					vehicle.setCompanyTransport(newTransportName, newThoughputInMonth, newCapacity, newRange);
					break;
				case 2:
					std::cout << "������� ����� ��������, ���-�� ������, �����������, ���������\n";
					newTransportName = checkInput<std::string>();
					newThoughputInMonth = checkInput<int>();
					newCapacity = checkInput<int>();
					newRange = checkInput<int>();
					plane.setCompanyTransport(newTransportName, newThoughputInMonth, newCapacity, newRange);
					break;
				case 3:
					std::cout << "������� ����� ��������, ���-�� ������, �����������, ���������\n";
					newTransportName = checkInput<std::string>();
					newThoughputInMonth = checkInput<int>();
					newCapacity = checkInput<int>();
					newRange = checkInput<int>();
					train.setCompanyTransport(newTransportName, newThoughputInMonth, newCapacity, newRange);
					break;
				default:
					break;
				}
			} while (choise != 4);
			break;
		}
		case 5:
		{
			int quantity, range;
			std::cout << "������� ���������� ����������� ����� � ����������"<<std::endl;
			quantity = checkInput<int>();
			range = checkInput<int>();
			people.push_back(quantity);
			range_for_dilivery.push_back(range);
			break;
		}
		case 6:
		{
			for (int i = 0; i < people.size(); i++)
			{
				std::cout << "���-�� �����   ��������� ���������\n";
				std::cout << people[i] << "        " << range_for_dilivery[i] << std::endl;
			}
			break;
		}
		case 7:
			calculation(people, range_for_dilivery, vehicle, train, plane);
			break;

		default:
			break;

		}

	} while (choise != 8);

	return 0;
}

Train::Train(int capacity, int throughput, int range, std::string transportName)
{
	m_capacity = capacity;
	m_throughput_in_month = throughput;
	m_transportName = transportName;
	m_range = range;
}

Plane::Plane(int capacity, int throughput, int range, std::string transportName)
{
	m_capacity = capacity;
	m_throughput_in_month = throughput;
	m_transportName = transportName;
	m_range = range;
}

Transport::Transport(int capacity, int throughput, int range, std::string transportName)
{
	m_capacity = capacity;
	m_throughput_in_month = throughput;
	m_transportName = transportName;
	m_range = range;
}

Railway_Company::Railway_Company(std::string name, std::string country)
{
	m_name = name;
	m_country = country;
}

Railway_Company::Railway_Company() { m_country = "�����"; m_name = "KrichevRail"; };

Avia_Company::Avia_Company(std::string name, std::string country)
{
	m_name = name;
	m_country = country;
}

Avia_Company::Avia_Company() { m_country = "�����"; m_name = "���� Airlines"; };

Trans_Company::Trans_Company(std::string name, std::string country)
{
	m_name = name;
	m_country = country;
}

Trans_Company::Trans_Company() { m_country = "������"; m_name = "TransTrap";};
