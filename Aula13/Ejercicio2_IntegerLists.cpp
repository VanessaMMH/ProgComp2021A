#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        string inst;
        cin >> inst;
        int n;
        cin >> n;
        string num_list;
        cin >> num_list;

        deque<int> numbers;
        stringstream ss(num_list);
        ss.ignore();
        for (int i; ss >> i;)
        {
            numbers.push_back(i);
            if (ss.peek() == ',' || ss.peek() == ']')
                ss.ignore();
        }

        bool revers = false;
        bool err = false;
        for (auto &&i : inst)
        {
            if (i == 'R' && i + 1 == 'R')
            {
                i += 1;
                continue;
            }
            else if (i == 'R')
                revers = !revers;
            else
            {
                if (numbers.empty())
                {
                    err = true;
                    break;
                }
                revers ? numbers.pop_back() : numbers.pop_front();
            }
        }
        if (err)
            cout << "error" << endl;
        else
        {
            cout << "[";
            string sep = ",";
            string temp = "";
            if (revers)
            {
                for (auto it = numbers.rbegin(); it != numbers.rend(); it++)
                {
                    cout << temp << *it;
                    temp = sep;
                }
            }
            else
            {
                for (auto it = numbers.begin(); it != numbers.end(); it++)
                {
                    cout << temp << *it;
                    temp = sep;
                }
            }
            cout<<"]"<<endl;
        }
    }

    return 0;
}