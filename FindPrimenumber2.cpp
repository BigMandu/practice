/*
https://programmers.co.kr/learn/courses/30/lessons/42839

숫자가 적힌 문자열 numbers가 주어질때,
해당 숫자들로 만들 수 있는 소수가 몇개인지 return.

numbers	    return
"17"	    3
"011"	    2

입출력 설명
1. [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

2. [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.
    (11과 011은 같은 숫자로 취급합니다.)
*/

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) 
{
    int answer = 0;

    vector<int> vec;

    for(char& ch : numbers)
    {
        vec.push_back(ch - '0');
    }

    sort(vec.begin(), vec.end());

    do{
        for(int i : vec)
        {
            cout << i;
        }
        cout << '\n';

    }while(next_permutation(vec.begin(), vec.end()));

    return answer;
}

int main()
{
    string input;
    int sol = 0;
    input = "17";

    sol = solution(input);

    cout << sol;
}