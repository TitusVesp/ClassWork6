// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h> 
using namespace std;

struct point
{
	int x = 0;
	int y = 0;
};

int main()
{
	srand(time(NULL));
	int rad = 0, dot = 0;
	cout << "Imput R of Circle: " << endl;
	cin >> rad;
	cout << "Imput quantity of dots" << endl;
	cin >> dot;
	point* mas = new point[dot];

	cout << "Your Dots: " << endl;
	for (int i = 0; i < dot; i++)
	{
		mas[i].x = rand() % 20 - 10;
		mas[i].y = rand() % 10;
		cout << "X:" << mas[i].x << " Y : " << mas[i].y << "\t";
		if ((i + 1) % 5 == 0 && i != 0)
			cout << endl;
	}

	cout << endl << endl;
	int xCenter = rand() % 20 - 10, yCenter = rand() % 10;
	cout << "X Center:" << xCenter << " Y Center: " << yCenter << endl << endl;
	point fPoint, sPoint;
	bool flag = false, flagF = true, tempFlag = true;
	for (int i = 0; i <= rad; i++)
	{
		for (int j = 0; j < dot; j++)
		{
			if (flagF)
			{
				if ((xCenter + i) == mas[j].x)
				{
					fPoint.x = mas[j].x;
					fPoint.y = mas[j].y;
					flagF = false;
				}
			}
			else
			{
				if (tempFlag)
				{
					i = 0;
					tempFlag = false;
				}
				if ((xCenter - i) == mas[j].x)
				{
					sPoint.x = mas[j].x;
					sPoint.y = mas[j].y;
					flag = true;
				}
			}
		}
		if (flag) break;
	}

	if (fPoint.y == 0 && sPoint.y == 0) cout << "Any of dots isn't correct!" << endl;
	else
	{
		cout << "First dot:\nX:" << fPoint.x << endl << "Y:" << fPoint.y << endl;
		cout << "Second dot:\nX:" << sPoint.x << endl << "Y:" << sPoint.y << endl;
	}
	delete[] mas;
}

