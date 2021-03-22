/*
https://programmers.co.kr/learn/courses/30/lessons/42839

���ڰ� ���� ���ڿ� numbers�� �־�����,
�ش� ���ڵ�� ���� �� �ִ� �Ҽ��� ����� return.

numbers	    return
"17"	    3
"011"	    2

����� ����
1. [1, 7]���δ� �Ҽ� [7, 17, 71]�� ���� �� �ֽ��ϴ�.

2. [0, 1, 1]���δ� �Ҽ� [11, 101]�� ���� �� �ֽ��ϴ�.
    (11�� 011�� ���� ���ڷ� ����մϴ�.)
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