#pragma once/*
int Add(int n1, int n2);
int Min(int n1, int n2);*/
namespace Test1
{
	int Add(int n1, int n2);
}

namespace Test2
{
	int Min(int n1, int n2);
}



namespace Println
{
	void Menu(void);
	double InputMoney(double storage, int ID);
	double OutputMoney(double storage, int ID);
	void MakingAccount(void);
	void TotalAccount(double storage, int ID, char name);
	void End(void);
	char Storage_Name(char** name);
	int Storage_ID(int ID);
	double Storage_Money(double Money);
}