#include<iostream>
#include<string>
using namespace std;

struct train {
	string depart_station;
	string arrival_station;
	int  ID;
};
struct seat {
	int seat_ID;
	bool seat_status;
};
struct car {
	int car_ID;
	int num_seats;
	seat s[30];
};
void seat_status(car crr[])
{
	int j;
	cout << "enter the num of car" << endl;
	cin >> j;
	while (j>10 || j<1)
	{
		cout << "check the number you entered" << endl;
		cout << "enter the correct number" << endl;
		cin >> j;
	}

	cout << "\n\n";
	cout << "                  car  " << j << endl;
	for (int i = 0; i<30; i += 3)
	{
		cout << "\n\n" << "      " << crr[j - 1].s[i].seat_ID << "                  " << crr[j - 1].s[i + 1].seat_ID << "                              " << crr[j - 1].s[i + 2].seat_ID << endl;
		if (crr[j - 1].s[i].seat_status)
		{
			cout << "  not reserved      ";
		}
		else
		{
			cout << "    reserved         ";
		}
		if (crr[j - 1].s[i + 1].seat_status)
		{
			cout << "  not reserved      ";
		}
		else
		{
			cout << "    reserved        ";
		}
		if (crr[j - 1].s[i + 2].seat_status)
		{
			cout << "            not reserved      ";
		}
		else
		{
			cout << "           reserverd        ";
		}
	}
	cout << "\n\n\n";
	cout << endl;
}
void seats_show(car crr[], seat s[], int j, int c)
{
	if (c>10)
	{
		c = 1;
	}
	cout << "\n\n";
	cout << "                  car  " << c << endl;
	for (int i = 0; i<30; i += 3)
	{
		cout << "\n\n" << "      " << crr[j].s[i].seat_ID << "                  " << crr[j].s[i + 1].seat_ID << "                             " << crr[j].s[i + 2].seat_ID << endl;
		if (crr[j].s[i].seat_status)
		{
			cout << "  not reserved      ";
		}
		else
		{
			cout << "   reserved         ";
		}
		if (crr[j].s[i + 1].seat_status)
		{
			cout << "  not reversed      ";
		}
		else
		{
			cout << "   reserved        ";
		}
		if (crr[j].s[i + 2].seat_status)
		{
			cout << "            not reserved      ";
		}
		else
		{
			cout << "           reserved          ";
		}
		cout << "\n";
	}

	j++;
	cout << "\n\n\n";
	int x;
	cout << "if you want to see another car press 1" << endl;
	cout << "if you want to choose the place of your seats press 2" << endl;
	cin >> x;
	if (x == 1)
	{
		c++;
		if (j>9)
		{
			j = 1;
		}
		seats_show(crr, s, j, c);

	}
	else if (x == 2)
	{
		return;
	}
}



void reserve(car r[], seat s[], train p)
{
	int j = 0;//ÈÓÊÎÏãå áãÇ ÈÇÌí ÇÚÑÖ ÇáßÑÇÓí ÚáÔÇä íŞÉáí ÑŞã ÇáÚÑÈíÉ
	int tickets_num, c;        //c is 1 when user want to choose the place of seats;
	cout << "how many tickets do you want to reserve??" << endl;
	cin >> tickets_num;
	cout << "if you want to choose the place of your seats press 1 ." << endl;
	cout << "if you don't want to choose press 2 ." << endl;
	cin >> c;
	if (c == 1)
	{
		seats_show(r, s, j, c);
		int arr[1000], f, d, j = 0;
		for (int i = 0; i<(2 * tickets_num) - 1; i += 2)


		{
			if (j<(2 * tickets_num) - 1)
			{
				cout << "enter the number of car" << endl;
				cin >> f;

				while (f<1 || f>10)
				{
					cout << "check the number that you enterd" << endl;
					cout << "enter the correct number" << endl;
					cin >> f;
				}

				arr[i] = f;
				j++;

				cout << "enter the num of seats that you want to reserve" << endl;
				cin >> d;
				while (d<1 || d>30)
				{
					cout << "check the number that you enterd" << endl;
					cout << "enter the correct number" << endl;
					cin >> d;

				}
				arr[i + 1] = d;
				if (r[f - 1].s[d - 1].seat_status)
				{
					r[f - 1].s[d - 1].seat_status = false;
				}
				else
				{
					cout << "this seat is already reserved" << endl;
					j--;
					i -= 2;
				}


			}
		}
		for (int i = 0; i<2 * tickets_num - 1; i += 2)
		{
			cout << "\n depart station is :" << p.depart_station << endl;
			cout << "\n Arrival station is :" << p.arrival_station << endl;
			cout << "train          " << "car         " << "seat" << endl;
			cout << "  " << p.ID << "            " << arr[i] << "           " << arr[i + 1] << endl;
		}
	}
	if (c == 2)
	{

		int v = 0;

		cout << "depart station is  :" << p.depart_station << endl;
		cout << "arrival station is  :" << p.arrival_station << endl;

		cout << "train          " << "car          " << "seat" << endl;
		for (int i = 0; i<10; i++)
		{
			for (int j = 0; j<30; j++)
			{
				if (v<tickets_num)

				{
					if (r[i].s[j].seat_status == true)
					{
						r[i].s[j].seat_status = false;
						cout << "  " << p.ID << "            " << r[i].car_ID << "           " << r[i].s[j].seat_ID << endl;
						v++;
					}
				}
			}
		}
	}
	cout << "\n\n\n";
	return;

}
void cancel_reservation(car r[], seat s[])
{
	int d, f, tickets_num, i = 0;
	cout << "how many tickets do you want to cancel " << endl;
	cin >> tickets_num;
	while (i<tickets_num)
	{
		cout << "enter the num or ID of car  to cancel the reservation" << endl;
		cin >> f;
		cout << "enter the num of seat" << endl;
		cin >> d;
		if (r[f - 1].s[d - 1].seat_status)
		{
			cout << "Check the number you entered" << endl;
			cout << "this seat is already not reserved" << endl;

		}
		else
		{
			r[f - 1].s[d - 1].seat_status = true;
			i++;
			cout << "Cancel reservation is done " << endl;

		}

	}

}
void car_search(car r[], seat s[])
{
	int d, j = 0;
	cout << "enter the ID or the num of car" << endl;
	cin >> d;
	for (int i = 0; i<30; i++)
	{
		if (r[d - 1].s[i].seat_status)
		{
			j++;
		}
	}
	if (j>0)
	{
		cout << "\nthere are " << j << "  available seat" << endl;

	}
	else
	{
		cout << "this car doesn't have available seat " << endl;
	}
	cout << "\n\n\n\n";
}
void seat_search(car r[], seat s[])
{
	int d, f;
	cout << "To check whether a seat is available or not ." << endl;
	cout << "enter the num of car" << endl;
	cin >> d;
	cout << "enter the num of seat" << endl;
	cin >> f;
	if (r[d - 1].s[f - 1].seat_status)
	{
		cout << "This seat is available" << endl;
	}
	else
	{
		cout << "this seat isn't available" << endl;
	}
}
void available_seat_num(car r[], seat s[])
{
	int d, j = 0;
	cout << "enter the ID or the num of car" << endl;
	cin >> d;
	cout << "the available seat is : ";
	for (int i = 0; i<30; i++)
	{

		if (r[d - 1].s[i].seat_status)
		{
			cout << r[d - 1].s[i].seat_ID << " , ";
		}
	}
	cout << endl;
	cout << "\n\n\n\n";
}


int main()
{
	car crr[10];
	seat s[30];
	train p;
	p.arrival_station = "Assiut";
	p.depart_station = "Cairo";
	p.ID = 120;

	for (int i = 0; i<10; i++)
	{
		crr[i].car_ID = i + 1;
		crr[i].num_seats = 30;

		for (int j = 0; j<30; j++)
		{
			crr[i].s[j].seat_ID = j + 1;
			crr[i].s[j].seat_status = true;
		}
	}
	int n;
	while (true)//the num of operation that user want to do
	{
		cout << "if you want to :" << endl;
		cout << " 1) Reserve a ticket press 1 ." << endl;
		cout << " 2) Cancel the reservation press 2 ." << endl;
		cout << " 3) Check whether a specific car has available seat or not press 3 ." << endl;
		cout << " 4) Check whether a seat is available or not press 4 . " << endl;
		cout << " 5) Get the number of the available seats in a specific car . " << endl;
		cout << " 6) show all the seats status of a specific car press 6 . " << endl;
		cout << " 7) exit press 7 . " << endl;
		cin >> n;
		switch (n) {
		case 1:reserve(crr, s, p);
			break;
		case 2:cancel_reservation(crr, s);
			break;
		case 3:car_search(crr, s);
			break;
		case 4:seat_search(crr, s);
			break;
		case 5:available_seat_num(crr, s);
			break;
		case 6:	seat_status(crr);
			break;
		case 7:return(0);
		default:cout << "Check the number that you entered...........please try again ." << endl;
		}
	}
}

