#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//�ν��Ͻ��� �������� �����ϴ� ���
	//new �����ڴ� �޸� ũ�⸦ ������ ����
	int* pData = new int;

	//�ʱ갪�� ����ϴ� ���
	int* pNewData = new int(10);

	*pData = 5;
	std::cout << *pData << std::endl;
	std::cout << *pNewData << std::endl;

	delete pData;
	delete pNewData;
	//5
	//10
}