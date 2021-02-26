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

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int max = 0;
    int cnt = 0;

    int tmp = 0;

    for(int i = 0; i<d.size(); i++)
    {
        tmp = d[i];
        cnt = 1;
        for(int j = i+1; j<d.size(); j++)
        {
            if(tmp+d[j] > budget) break;
            else
            {
                tmp+=d[j];
                cnt++;
            }
        }
        max = (cnt > max)? cnt : max;
    }
    
    answer = max;

    return answer;
}

int main()
{
    vector<int>vec;
    int budget;

    vec = {2,2,3,3};
    budget = 10;

    budget = solution(vec,budget);
    cout << budget;
}