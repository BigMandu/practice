/*
https://programmers.co.kr/learn/courses/30/lessons/12921
1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.

소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
(1은 소수가 아닙니다.)

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