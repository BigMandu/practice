/*
https://programmers.co.kr/learn/courses/30/lessons/12934?language=cpp

*/
#include <iostream>

#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    double sqrtn = sqrt(n);

    if(sqrtn - (int)sqrtn)
    {
        answer = -1;
    }
    else
    {
        answer = pow(sqrtn+1, 2);
    }

    return answer;
}

int main()
{
    long long input = 121;

    input = solution(input);

    cout<<input;
}