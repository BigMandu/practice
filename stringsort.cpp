/*
https://programmers.co.kr/learn/courses/30/lessons/12915



�� ���ڿ��� �ε��� n��° ���ڸ� �������� �������� �����Ϸ� �մϴ�. 
���� ��� strings�� [sun, bed, car]�̰� n�� 1�̸� 

�� �ܾ��� �ε��� 1�� ���� u, e, a�� strings�� �����մϴ�.

strings	            n	return
[sun, bed, car]	    1	[car, bed, sun]
[abce, abcd, cdx]	2	[abcd, abce, cdx]

�ε��� 1�� ���ڰ� ���� ���ڿ��� ���� �� ���, 
���������� �ռ� ���ڿ��� ���ʿ� ��ġ�մϴ�.

*/


#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end(),[=](string str1, string str2) -> bool
    {
        if(str1[n] == str2[n])
        {
            return str1<str2;
        }
        else
        {
            return str1[n] < str2[n];
        }

    });

    answer = strings;
    

    return answer;
}

int main()
{
    vector<string>instr;
    instr = {"abce", "abcd", "cdx"}; //{"sun", "bed", "car"};
    int inputn = 2;
    // cout << "input string (break -1)"<<endl;
    // for(int i=0;i<20;i++)
    // {
    //     cin>> instr[i];
    //     if(instr[i] == "-1") break;
    // }

    // cout<<"input n : ";
    // cin>> inputn;
    instr = solution(instr,inputn);

    for(string str : instr)
    {
        cout<<str << ' ';
    }

}