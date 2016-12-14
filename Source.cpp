//Program to show working in the bank when customer arrives or exits the bank.
//Author:Nirav Pardiwala
//Date: 11/6/2015 - 11/12/2015
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
const int maxqueue = 6;
int front, rear;
class queue_type		    // declaration of class//
{
public:
	void clear_queue();	//member functions//
	bool empty_queue(); //    of class queue_type//
	bool full_queue();
	void insert_queue(char numb);
	void delete_queue(char& numb);
	int queue[maxqueue + 1];
	int front, rear;
};

// Main Function
int main()
{
	{
		queue_type q1, q2;
		string input_array; // try using tstring array
		char input;
		char one, two, temp;
		int last_counter;
		int o_count = 0;
		int t_count = 0;
		int exit_count = 0;
		int arr_count = 0;
		int counter = 0;
		q1.clear_queue();
		q2.clear_queue();
		cout << "A for Arrival.\n";
		cout << "O for Exit Teller 1.\n";
		cout << "T for Exit Teller 2.\n";
		cout << "-999 to Exit from the program.\n";
		while (input_array != "-999")
		{
			cout << "Please enter your option along with ID :";
			cin >> input_array;
			cout << endl;
// Code For Arrivals
			if (input_array[0] == 'A' || input_array[0] == 'a')
			{
				input = input_array[1];
				arr_count++;
			if (!(q1.full_queue())) //enter in queue 1
			{
				q1.insert_queue(input);
				last_counter = counter;
				counter++;
				cout << input << " entered the main queue in the bank\n";
//Code to assign customers to the tellers
				if ((last_counter == 0) && (counter == 1))
				{
					cout << input << " is assigned to Teller 1 from the main queue.\n";
					q1.delete_queue(one);					
				}
				else if ((last_counter == 1) && (counter == 2))
				{
					cout << input << " is assigned to Teller 2 from the main queue. \n";
					q1.delete_queue(two);
				}
				else{
					cout << input << " is waiting in the main queue.\n";
				}
			}
//Code for the queue outside the bank
			else if (q1.full_queue() && (!(q2.full_queue())))//enter in q2
			{
				q2.insert_queue(input);
				cout << input << " is waiting in the queue outside the bank\n";
			}
//both the queues are full
			else if (q2.full_queue())
			{
				arr_count--;
				cout << "Opss ! both the queues are full, please come after some time.\n";
			}
		}
//Exit Teller 2
			else if(input_array[0] == 'O' || input_array[0] == 'o')
			{
				o_count++;
				cout << one << " left the bank.\n";
				q1.delete_queue(one);
				cout << one <<" is assigned to Teller 1 from the main queue.\n";
				if (!(q2.empty_queue()))
				{
					q2.delete_queue(temp);
					cout << temp << " is moved to the main queue inside the bank.\n";
					q1.insert_queue(temp);
				}
			}
//Exit Teller 1
			else if (input_array[0] == 'T' || input_array[0] == 't')
			{
				t_count++;
				cout << two << " left the bank.\n";
				q1.delete_queue(two);
				cout << two << " is assigned to Teller 2 from the main queue.\n";
				if (!(q2.empty_queue()))
				{
					q2.delete_queue(temp);
					cout << temp << " is moved to the main queue inside the bank.\n";
					q1.insert_queue(temp);
				}
			}
//Exit the Program
			else if (input_array[0] = '-999')
			{
				cout << arr_count << " arrived so far.\n";
				exit_count = o_count + t_count;
				cout << exit_count << " left from the bank so far.\n";
				break;
			}
			else
			{
				cout << "Invalid Input. Please try again.\n";
			}
	}
		system("PAUSE");
		return 0;
	}
}
//Queue Functions.
//----------------------------------------------------------------------
void queue_type::clear_queue()
{
	front = maxqueue;
	rear = maxqueue;
}
//----------------------------------------------------------------------
bool queue_type::empty_queue()
{
	if (rear == front)
		return true;
	else
		return false;
}
//----------------------------------------------------------------------
bool queue_type::full_queue()
{
	int querear;
	if (rear == maxqueue)
		querear = 0;
	else
		querear = rear + 1;
	if (querear == front)
		return true;
	else
		return false;
}
//----------------------------------------------------------------------
void queue_type::insert_queue(char numb)
{
	if (rear == maxqueue)
		rear = 0;
	else
		rear = rear + 1;
	queue[rear] = numb;
	
}
//----------------------------------------------------------------------
void queue_type::delete_queue(char& numb)
{
	if (front == maxqueue)
		front = 0;
	else
		front = front + 1;
	numb = queue[front];
}
//Author:Nirav Pardiwala
//Date: 11/6/2015 - 11/12/2015