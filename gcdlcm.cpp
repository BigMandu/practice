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

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int gcm = 0;
    int maximum = 0;
    for(int i=0; i<=m; i++)
    {
        
        if((int)i/n == i/n && )
        {
            if(maximum < i)
            {
                gcm = i;
            }
        }

    }
    
    answer.push_back(gcm);

    
    

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