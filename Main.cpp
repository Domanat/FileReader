#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

void mergeSort(vector<uint32_t> &arr, int start, int mid, int end)
{
	int lsize = mid - start + 1;
	int rsize = end - mid;

	vector<uint32_t> left(lsize);
	vector<uint32_t> right(rsize);

	for (int i = 0; i < lsize; i++)
		left[i] = arr[start + i];

	for (int j = 0; j < rsize; j++)
		right[j] = arr[mid + j + 1];

	int leftCounter = 0;
	int rightCounter = 0;
	int sourceCounter = start;

	while (leftCounter < lsize && rightCounter < rsize)
	{
		if (left[leftCounter] < right[rightCounter])
		{
			arr[sourceCounter] = left[leftCounter];
			leftCounter++;
		}
		else
		{
			arr[sourceCounter] = right[rightCounter];
			rightCounter++;
		}

		sourceCounter++;
	}

	while (leftCounter < lsize)
	{
		arr[sourceCounter] = left[leftCounter];
		sourceCounter++;
		leftCounter++;
	}

	while (rightCounter < rsize)
	{
		arr[sourceCounter] = right[rightCounter];
		sourceCounter++;
		rightCounter++;
	}
}

void mergeSort(vector<uint32_t> &arr, int start, int end)
{
	if (end > start)
	{
		int mid = (start + end) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		mergeSort(arr, start, mid, end);
	}
}

int main(int argc, char *argv[])
{
	ifstream file("text.txt");
	string line;
	uint32_t number;
	vector<uint32_t> nums;
	

	if (file.is_open())
	{
		while (file >> hex >> number)
		{
			//cout << number << "   ";
			nums.push_back(number);
		}

		file.close();

		
	}
	else
		cout << "Cant open the file" << endl;



	mergeSort(nums, 0, nums.size() - 1);

	for (uint32_t var : nums)
		cout << var << "  ";
	cout << endl;

	return 0;
}