/*
https://programmers.co.kr/learn/courses/30/lessons/12982


d	        budget	result
[1,3,2,5,4]	9	    3
[2,2,3,3]	10	    4

budget (예산)내로 최대한 지원해 줄 수 있는 부서의 개수를 리턴.

*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;

    sort(d.begin(),d.end());


    for(int x : d)
    {
        if(sum+x > budget)
        {
            return answer;
        }
        sum+=x;
        answer++;
    }
    return answer;
}

int main()
{
    vector<int>vec;
    int budget;

    vec = {1,3,2,5,4};
    budget = 9;

    budget = solution(vec,budget);
    cout << budget;
}