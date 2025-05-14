#include <iostream>
#include <string>
#include <vector>
using namespace std;


class sillyvector
{
private:
	int* data{ nullptr };
	size_t arrSize{ 0 };
	size_t arrCapacity{ 0 };

	
public:

	void push_back(int val)
	{
		int pushed_size = arrSize + 1;

		if (pushed_size > arrCapacity) {
			int* newarr = new int[pushed_size];

			if (data != nullptr){
				for (int i = 0; i < arrSize; i++)
				{
					newarr[i] = data[i];
				}

				delete[] data;
			}
			newarr[arrSize] = val;
			arrSize = pushed_size;
			data = newarr;
		}
		else 
		{
			data[arrSize] = val;
			arrSize = pushed_size;
		}
	}

	int at(int index) {
		if (data != nullptr){
			return *(data + index);
		}
		return -1;
	}


	size_t size() 
	{
		return arrSize;
	}

	void pop_back() 
	{
		cout << "last item before pop_back:\t" << data[arrSize - 1] << '\n';

		int* newarr = new int[arrSize - 1];
		for (int i = 0; i < arrSize - 1; i++)
		{
			newarr[i] = data[i];
		}

		delete[] data;
		data = newarr;
		arrSize = arrSize - 1;
		cout << "last item after pop_back:\t" << data[arrSize - 1] << '\n';
	}


	void resize(int newSize, int wanted_item = 0)
	{
		if (newSize >= 0)
		{
			if (newSize < arrSize)
			{

				int* newarr = new int[arrSize];
				for (int i = 0; i < arrSize; i++)
				{
					newarr[i] = data[i];
				}
				delete[] data;
				data = newarr;
				arrSize = newSize;
			}
			else if (newSize == arrSize)
			{
				cout << "u r silly, it's the same size:*";
			}
			else if (newSize > arrSize)
			{
				int* newarr = new int[newSize];
				for (int i = 0; i < newSize; i++)
				{
					newarr[i] = data[i];

					if (i > arrSize - 1)
					{
						newarr[i] = wanted_item;
					}

				}
				delete[] data;
				data = newarr;
				arrSize = newSize;
			}
		}
		else
		{
			cout << "u r silly, our size can't be negative";
		}
	}
};

void main()
{
	/*srand(time(0));

	int size = 5;
	int *arr = new int[size];

	for(int i = 0; i < size; i++) 
	{
		arr[i] = rand();

		cout << arr[i] << '\n';
	}
	delete[] arr;*/

	/*sillyvector smartVec;
	std::vector<int> values = {0,213,124,134,2,34,23,423,4,23,4,23,432,};
	for (int i = 0; i < values.size(); ++i) {
		smartVec.push_back(values[i]);
		if (values[i] != smartVec.at(i)) {
			cout << "mismatch " << values[i] << smartVec.at(i) << "\n";
		}
	}*/



	/*std::vector<int> vec;
	vec.push_back(2);*/

	sillyvector sv;

	sv.push_back(2);
	sv.push_back(1);
	sv.push_back(5);
	
	for (int i = 0; i < 3; i++)
	{
		cout << sv.at(i) << '\n';
	}

	//POP_BACK
	cout << "POP_BACK";
	cout << "\narray size before pop_back:\t" << sv.size() << '\n';

	sv.pop_back();

	cout << "\narray size after pop_back:\t" << sv.size() << '\n';


	//RESIZE<
	cout << "_______________________________________________________________\n";
	cout << "RESIZE<";

	cout << "\narray size before resize (new size < arr size):\t" << sv.size() << '\n';

	sv.resize(1);

	cout << "\narray size after resize (new size < arr size):\t" << sv.size() << '\n';
	for (int i = 0; i < sv.size(); i++)
	{
		cout << sv.at(i) << '\n';
	}


	//RESIZE==
	cout << "_______________________________________________________________\n";
	cout << "RESIZE==";

	cout << "\narray size before resize (new size == arr size):\t" << sv.size() << '\n';

	sv.resize(1);

	cout << "\narray size after resize (new size == arr size):\t" << sv.size() << '\n';

	for (int i = 0; i < sv.size(); i++)
	{
		cout << sv.at(i) << '\n';
	}


	//RESIZE>
	cout << "_______________________________________________________________\n";
	cout << "RESIZE>";

	cout << "\narray size before resize (new size > arr size):\t" << sv.size() << '\n';

	sv.resize(3);

	cout << "\narray size after resize (new size > arr size):\t" << sv.size() << '\n';

	for (int i = 0; i < sv.size(); i++)
	{
		cout << sv.at(i) << '\n';
	}
	
	//RESIZE negative
	cout << "_______________________________________________________________\n";
	cout << "RESIZE negative";

	cout << "\narray size before resize (new size > arr size):\t" << sv.size() << '\n';

	sv.resize(-1);

	cout << "\narray size after resize (new size > arr size):\t" << sv.size() << '\n';

	for (int i = 0; i < sv.size(); i++)
	{
		cout << sv.at(i) << '\n';
	}

	//RESIZE wanted item
	cout << "_______________________________________________________________\n";
	cout << "RESIZE wanted item";

	cout << "\narray size before resize (new size > arr size):\t" << sv.size() << '\n';

	sv.resize(5, 7);

	cout << "\narray size after resize (new size > arr size):\t" << sv.size() << '\n';

	for (int i = 0; i < sv.size(); i++)
	{
		cout << sv.at(i) << '\n';
	}
}