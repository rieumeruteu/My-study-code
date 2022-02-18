
#include <iostream>
#include "TestHead.h"

void Println::Menu(void)
{
	std::cout << "----Menu----" << std::endl;
	std::cout << "1.계좌개설" << std::endl;
	std::cout << "2. 입금" << std::endl;
	std::cout << "3.출금" << std::endl;
	std::cout << "4.계좌정보 전체 출력" << std::endl;
	std::cout << "5.프로그램 종료" << std::endl;
}

double Println::InputMoney(double storage, int ID)
{
	double add = 0;
	
	std::cout << "[입    금]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> ID;
	std::cout << "입금액: ";
	std::cin >> add;
	storage += add;
	return storage;
}

double Println::OutputMoney(double storage,int ID)
{
	double Min = 0;
	std::cout << "[출    금]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> ID;
	std::cout << "출금액: ";
	std::cin >> Min;
	storage -= Min;
	return storage;
}

void Println::TotalAccount(double storage,int ID,char name)
{
	
	std::cout << "계좌ID: ";
	std::cout << ID<<std::endl;
	std::cout << "이름: ";
	std::cout << name << std::endl;
	std::cout << "현재 금액: ";
	std::cout << storage << std::endl;
}

void Println::End(void)
{
	std::cout << "종료합니다.";
}

int Println::Storage_ID(int ID)
{
	int ID_bank[100];
	int Count = 1;
	for (int i = 0; i < Count; i++)
	{
		if (ID_bank[i] == NULL)
			ID_bank[i] = ID;
		else
			++Count;
	}
	

}

double Println::Storage_Money(double Money)
{

}

char Println::Storage_Name(char** name)
{

}


void Println::MakingAccount(void)
{
	int ID = 0;
	char name;
	std::cout << "계좌ID: ";
	std::cin >> ID;
	std::cout << "이름: ";
	std::cin >> name;

	Storage_ID(ID);

}
