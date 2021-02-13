/*
https://programmers.co.kr/learn/courses/30/lessons/12921
1���� �Է¹��� ���� n ���̿� �ִ� �Ҽ��� ������ ��ȯ�ϴ� �Լ�, solution�� ����� ������.

�Ҽ��� 1�� �ڱ� �ڽ����θ� ���������� ���� �ǹ��մϴ�.
(1�� �Ҽ��� �ƴմϴ�.)

n	result
10	4
5	3

*/
#include <iostream>

#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<bool>prime(n,true);

    prime[0] = prime[1] = false;


    
    for(int i = 2; i<= int(sqrt(n)); i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j<=n; j+=i)
            {
                prime[j] = false;
            }
        }
    }

    for(bool x : prime)
    {
        if(x)
        {
            answer++;
        }
    }   


    return answer;
}

int main()
{
    int n;
    cin>> n;

    n = solution(n);

    cout << n;
}