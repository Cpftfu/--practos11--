#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>

using namespace std;

class MergeSort
{
public:
    void Sort(vector<int>& arr)
    {
        if (arr.size() <= 1) {
            return;
        }

        int middle = arr.size() / 2;

        vector<int> left(arr.begin(), arr.begin() + middle);
        vector<int> right(arr.begin() + middle, arr.end());

        Sort(left);
        Sort(right);
        Merge(arr, left, right);
    }

private:
    void Merge(vector<int>& arr, vector<int>& left, vector<int>& right)
    {
        int leftIdx = 0, rightIdx = 0, idx = 0;

        while (leftIdx < left.size() && rightIdx < right.size())
        {
            if (left[leftIdx] < right[rightIdx])
            {
                arr[idx++] = left[leftIdx++];
            }
            else
            {
                arr[idx++] = right[rightIdx++];
            }
        }

        while (leftIdx < left.size())
        {
            arr[idx++] = left[leftIdx++];
        }

        while (rightIdx < right.size())
        {
            arr[idx++] = right[rightIdx++];
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    vector<int> numbers(10);

    cout << "Приветик!\nВведи 10 целых чисел пожалуйста: " << endl;

    for (int i = 0; i < 10; ++i)
    {
        cin >> numbers[i];
    }

    MergeSort mergeSort;
    auto sortFunction = [&](std::vector<int>& arr)
        {
            mergeSort.Sort(arr);
        };

    thread mergeSortThread(sortFunction, ref(numbers));
    mergeSortThread.join();

    cout << "Отсортированный массив:" << endl;
    for (const int& num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}