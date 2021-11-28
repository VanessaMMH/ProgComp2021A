#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


//link:  https://www.beecrowd.com.br/judge/en/problems/view/1642

int main()
{
  int m;
  while (1)
  {
    cin >> m;
    if (!m)
      break;
    string s;
    getline(cin, s);
    getline(cin, s);

    auto s_ptr = s.begin();
    auto e_ptr = s.begin();

    int maxSoFar = 0;
    int currentLength = 0;
    unordered_set<char> unique;
    unordered_map<char, int> count;

    while (e_ptr != s.end())
    {
      if(unique.find(*e_ptr) != unique.end())
      {
        ++currentLength;
        count[*e_ptr]++;
        e_ptr++;
      }
      else
      {
        if(unique.size() < m)
        {
          unique.insert(*e_ptr);
          if(count.find(*e_ptr) != count.end())
            count[*e_ptr]++;
          else
            count[*e_ptr] = 1;
          currentLength++;
          e_ptr++;
        }
        else
        {
          while (unique.size() == m)
          {
            count[*s_ptr]--;
            if(count[*s_ptr] == 0)
              unique.erase(*s_ptr);
            currentLength--;
            s_ptr++;
          }
        }
      }
      if(currentLength > maxSoFar)
          maxSoFar = currentLength;
    }
    cout<<maxSoFar<<endl;
    

  }

  return 0;
}