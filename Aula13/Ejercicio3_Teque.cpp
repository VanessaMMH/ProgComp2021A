#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct teque
{
};

int main()
{
  int t;
  cin >> t;
  deque<int> fq;
  deque<int> bq;
  for (int tc = 0; tc < t; tc++)
  {
    string op;
    int num;
    cin >> op >> num;
    if (op == "push_front")
    {
      if (fq.size() > bq.size())
      {
        int x = fq.back();
        fq.pop_back();
        bq.push_front(x);
      }

      fq.push_front(num);
    }
    else if (op == "push_back")
    {
      if (bq.size() > fq.size())
      {
        int x = bq.front();
        bq.pop_front();
        fq.push_back(x);
      }
      bq.push_back(num);
    }
    else if (op == "push_middle")
    {
      int idx = (fq.size() + bq.size()) / 2;
      if (fq.size() > bq.size())
        bq.push_front(num);
      else if (bq.size() > fq.size())
      {
        int x = bq.front();
        bq.pop_front();
        fq.push_back(x);
        bq.push_front(num);
      }
      else
        fq.push_back(num);
    }
    else
    {
      if (num < fq.size())
        cout << fq[num] << endl;
      else
      {
        num -= fq.size();
        cout << bq[num] << endl;
      }
    }
  }
}