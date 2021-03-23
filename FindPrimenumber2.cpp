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
#include <math.h>
#include <set>

using namespace std;

bool IsPrime(int numb)
{
    if(numb<2) return false;
    
    for(int i = 2; i<=sqrt(numb); ++i)
    {
        if(numb%i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) 
{
    int answer = 0;
    set<int> primeset; //set���� �ߺ�����
    vector<char> vec;

    for(char& ch : numbers)
    {
        vec.push_back(ch);
    }

    sort(vec.begin(), vec.end());

    do{
        string str = "";

        for(char ch : vec)
        {
            str += ch;
            //cout<<ch;
            int number = stoi(str);
        
            if(IsPrime(number)) //�׳� ���ڸ� �� �����־� �Ҽ� �Ǻ����״�. 
            //������ 1�ڸ� ���� ���� ������ �Ǻ��ؼ� �־������ 
            //����� �ڵ带 �ι��� ���ϱ� �׳� �� ��������.
            {
                primeset.insert(number);
            }
        }
        
    }while(next_permutation(vec.begin(), vec.end()));

    answer = primeset.size();
    return answer;
}

int main()
{
    string input;
    int sol = 0;
    input = "011";

    sol = solution(input);

    cout << sol;
}