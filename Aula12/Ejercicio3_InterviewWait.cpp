#include <bits/stdc++.h>
using namespace std;

/*
Interview Wait
Estás sentado en una fila de sillas, esperando una entrevista.
Al elegir el próximo entrevistado, el entrevistador siempre elegirá entre
ya sea en el lado izquierdo o en el lado derecho de la fila de sillas.
Además, el entrevistador sabe exactamente cuánto tiempo durará cada entrevista.
tomar, y siendo vago, siempre elegirá el bando con el menor tiempo de entrevista.
(Puede asumir que todos los tiempos son distintos).
Se le indica con un tiempo de entrevista de -1, lo que significa que el entrevistador
siempre te elige a ti por encima de la persona del lado opuesto. Cuanto tiempo sera
tomar antes de que el entrevistador llegue a usted?
Input:
[4, -1, 5, 2, 3]
Output: 9

*/

int interviewWait(vector<int>&v){
    deque <int> dq;
    for(auto d:v){
        dq.push_back(d);
    }
    int temp=0;
    while(dq.front()!=-1 && dq.back()!=-1){
        if (dq.front()<dq.back())
        {
            temp+=dq.front();
            dq.pop_front();
        }
        else
        {
            temp+=dq.back();
            dq.pop_back();

        }
        
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    vector <int> v={4, -1, 5, 2, 3};
    cout << interviewWait(v);
    
    return 0;
}
