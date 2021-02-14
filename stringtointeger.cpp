/*
https://programmers.co.kr/learn/courses/30/lessons/12925
 str이 1234이면 1234를 반환하고, 
 -1234이면 -1234를 반환하면 됩니다.

str은 부호(+,-)와 숫자로만 구성되어 있고, 
잘못된 값이 입력되는 경우는 없습니다.
*/

#include <iostream>


#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;

    answer = stoi(s);

    return answer;
}

int main()
{
    string str = "-1234";

    int sol = solution(str);

    cout<<sol;
}