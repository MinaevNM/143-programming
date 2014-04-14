#include <iostream>
#include "bus.h"

using namespace std;

void main()
{
	Bus b;
	bool run = true;
	int x, y, d, n;
	bool flag;
	char s[100];
	while (run)
	{
		switch (getchar())
		{
		case 's':
			cin >> x >> y >> d;
			b = Bus(x, y, d, 0, 0);
			break;
		case 'u':
			cin >> x >> y >> d;
			flag = true;
			while (flag)
			{
			    try
		     	{
			        b.update(x, y, d);
					flag = false;
		    	}
			    catch (OffTheField otf)
			    {
					cout << "Wrong position input. Current position: "
						<< otf.x << " " << otf.y << endl;
					cout << "Input new position ";
					cin >> x >> y;
			    }
			    catch (WrongDirection wd)
			    {
					cout << "Wrong direction input. Current direction: "
						<< wd.dir << endl;
					cout << "Input new direction ";
					cin >> d;
				}
			}
			break;
		case 'l':
			b.rotateLeft();
			break;
		case 'r':
			b.rotateRight();
			break;
		case 'f':
			cin >> x;
			b.moveForward(x);
			break;
		case 'w':
			b.print();
			break;
		case 'i':
			cin >> n;
			b.busEnter(n);
			break;
		case 'o':
			cin >> n;
			b.busLeave(n);
			break;
		case 'm':
			cout << "Money: " << b.get_money() << endl;
			break;
		case 'e':
			cin >> s;
			if (!strcmp(s, "xit"))
				run = false;
			break;
		}
	}
}