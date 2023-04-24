#include "comm.h"

using namespace std;

int Partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] > pivot) right--;
        nums[left] = nums[right];
        while (left < right && nums[left] < pivot) left++;
        nums[right] = nums[left];
    }

    nums[left] = pivot;

    return left;
}

void QuickSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int pos = Partition(nums, left, right);
        QuickSort(nums, left, pos - 1);
        QuickSort(nums, pos + 1, right);
    }
}

int FindKthNumber(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int pos = Partition(nums, left, right);
        if(pos == k - 1)
        {
            return nums[pos];
        }
        else if(pos > k - 1)
        {
            right = pos;
        }
        else
        {
            left++;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums{5, 10, 1, 3, 8, 9, 2};
//    QuickSort(nums, 0, nums.size() - 1);
//    PrintVector(nums);

    cout << FindKthNumber(nums, 2);
    return 0;
}