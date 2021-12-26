#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/bank
*/

class Persona
{
public:
    int cash;
    int time;
    Persona(int cash, int time)
    {
        this->cash = cash;
        this->time = time;
    }
    friend bool operator>(const Persona &p1, const Persona &p2);
};

bool operator<(const Persona &p1, const Persona &p2)
{
    return p1.cash >= p2.cash;
}

int main()
{
    int N, T;
    int total = 0;
    int i = 0;
    cin >> N >> T;

    vector<Persona> persons;
    for (int i = 0; i < N; i++)
    {
        int c, t;
        cin >> c >> t;
        Persona p(c, t);
        persons.push_back(p);
    }

   
    sort(persons.begin(), persons.end());

    vector<int> vec(T);
    while (i < persons.size())
    {
        int j = persons[i].time;
        while (j >= 0)
        {
            if (vec[j] == 0)
            { 
                vec[j] = persons[i].cash;
                break;
            }
            j--;
        }
        i++;
    }

    for (int i = 0; i < vec.size(); i++)
        total += vec[i];

    cout << total;
    return 0;
}