/*
https://programmers.co.kr/learn/courses/30/lessons/12940


�迭�� �� �տ� �ִ�����, �״��� �ּҰ������ �־� ��ȯ�ϸ� �˴ϴ�

n	m	return
3	12	[3, 12]
2	5	[1, 10]

*/

#include <iostream>

#include <string>
#include <vector>

#include <math.h>

using namespace std;

int Getgcd(int p, int q)
{
    if(q == 0) return p;
    return Getgcd(q, p%q);
    //p<q �� ó���� ���� ���� ����
    // p<q�� �Է��� ������ ���, p%q = p��. ���� ���� ���ȣ���� q,p�� �Ǳ⶧���̴�.
}

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int gcd = 0;
    int lcm = 0;

    gcd = Getgcd(n,m);
    
    lcm = n*m / gcd;

    answer.push_back(gcd);
    answer.push_back(lcm);
    

    return answer;
}

int main()
{
    vector<int> sol;
    int n, m;

    while(n > 0)
    {
        cout << "input n : ( n<0 break) ";
        cin >> n;
        cout << "input m : ";
        cin >> m;


        sol = solution(n,m);

        for(int x : sol)
        {
            cout << x << " ";
        }
    }
}