/*
https://programmers.co.kr/learn/courses/30/lessons/12925
 str�� 1234�̸� 1234�� ��ȯ�ϰ�, 
 -1234�̸� -1234�� ��ȯ�ϸ� �˴ϴ�.

str�� ��ȣ(+,-)�� ���ڷθ� �����Ǿ� �ְ�, 
�߸��� ���� �ԷµǴ� ���� �����ϴ�.
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