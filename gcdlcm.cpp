/*
https://programmers.co.kr/learn/courses/30/lessons/12940


배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다

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
    //p<q 의 처리를 하지 않은 이유
    // p<q인 입력이 들어오는 경우, p%q = p임. 따라서 다음 재귀호출은 q,p가 되기때문이다.
}

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int gcm = 0;
    
    gcm = Getgcd(n,m);
    
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