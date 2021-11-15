#include <iostream>
#include <vector>
#include <list>

using namespace std;

void print_space(int n)
{
  if(n < 100)
    cout<<" ";
  if(n < 10)
    cout<<" ";
  cout<<n;
}

int main()
{
  int n, k, m;
  while (cin >> n >> k >> m)
  {
    if (n == k && k == m && m == 0)
      break;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      nums[i] = i + 1;

    int it_k = 0;
    int it_m = n - 1;

    string sep = ",";
    string temp = "";
    while (!nums.empty())
    {
      it_k = (it_k + k - 1) % nums.size();
      int m_c = m;
      while (m_c - 1 > 0)
      {
        if(it_m == 0)
          it_m = nums.size() - 1;
        else
          it_m--;
        m_c--;
      }

      cout<<temp;
      temp = sep;
      if (it_k == it_m)
      {
        print_space(nums[it_k]);
        nums.erase(nums.begin() + it_k);
        if (it_k == nums.size())
          it_k = 0;
        if (it_m == 0)
          it_m = nums.size() - 1;
        else
          it_m--;
      }
      else
      {
        print_space(nums[it_k]);
        print_space(nums[it_m]);
        if (it_k > it_m)
        {
          int old_size = nums.size();
          nums.erase(nums.begin() + it_k);
          if (it_k == old_size - 1)
            it_k = 0;
          nums.erase(nums.begin() + it_m);
          if(it_k > 0)
            it_k--;

          if (it_m == 0)
            it_m = nums.size() - 1;
          else
            it_m--;
        }
        else
        {
          nums.erase(nums.begin() + it_m);
          it_m--;

          nums.erase(nums.begin() + it_k);
          if(it_k == nums.size())
            it_k = 0;
          
          if (it_m == 0)
            it_m = nums.size() - 1;
          else
            it_m--;
        }
      }
    }
    cout<<endl;
  }

  return 0;
}