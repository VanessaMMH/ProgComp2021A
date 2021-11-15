#include <vector>
#include <iostream>

using namespace std;

void heapify_max(vector<int> &arr, int i)
{
  int n = arr.size();
  int largest = i;   
  int l = 2 * i + 1; 
  int r = 2 * i + 2; 

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
    swap(arr[i], arr[largest]);

    heapify_max(arr, largest);
  }
}

void heapify_min(vector<int> &arr, int i)
{
  int n = arr.size();
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] < arr[smallest])
    smallest = l;

  if (r < n && arr[r] < arr[smallest])
    smallest = r;

  if (smallest != i)
  {
    swap(arr[i], arr[smallest]);

    heapify_min(arr, smallest);
  }
}

void pop_top(vector<int> &arr, bool is_min_heap)
{
  if (arr.empty())
    return;

  arr[0] = arr[arr.size() - 1];
  arr.pop_back();

  is_min_heap ? heapify_min(arr, 0) : heapify_max(arr, 0);
}

int findKthLargest(vector<int> &nums, int k)
{
  int n = nums.size();
  bool is_min_heap;

  int pops = -1;
  if (k < n / 2)
  {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify_max(nums, i);

    pops = k - 1;
    is_min_heap = false;
  }
  else
  {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify_min(nums, i);

    pops = n - k;
    is_min_heap = true;
  }

  for (int i = 0; i < pops; i++)
    pop_top(nums, is_min_heap);

  for (auto &&i : nums)
    cout << i << endl;
  return nums[0];
}

int main()
{
  vector<int> nums = {3,2,3,1,2,4,5,5,6};

  int k = 4;

  cout << "ans: " << findKthLargest(nums, k) << endl;
}