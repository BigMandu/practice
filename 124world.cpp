/*
https://programmers.co.kr/learn/courses/30/lessons/12899

124 나라에는 자연수만 존재합니다.
124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.

예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.

10진법	124 나라	10진법	124 나라
1	    1	        6	    14
2	    2	        7	    21
3	    4	        8	    22
4	    11      	9	    24
5	    12      	10  	41

자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하라.
(n은 500,000,000이하의 자연수)

3 나눗셈, 나머지 연산? 
1 = 1
2 = 2
3 = 4
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

string solution(int n) 
{
    string answer = "";
    int div = 0;
    while(n != 0)
    {
        if(n%3 == 0)
        {
            answer = '4' + answer;
            --n;
        }
        else
        {
            div = n%3;
            answer = char(div+'0') + answer;
        }
        n/=3;
    }


    return answer;
}

int main()
{
    int input;
    string sol = "";
    cout<<"input : ";
    cin>>input;
    sol = solution(input);

    cout << sol;
}