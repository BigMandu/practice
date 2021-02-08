/*
https://programmers.co.kr/learn/courses/30/lessons/12915



각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 
예를 들어 strings가 [sun, bed, car]이고 n이 1이면 

각 단어의 인덱스 1의 문자 u, e, a로 strings를 정렬합니다.

strings	            n	return
[sun, bed, car]	    1	[car, bed, sun]
[abce, abcd, cdx]	2	[abcd, abce, cdx]

인덱스 1의 문자가 같은 문자열이 여럿 일 경우, 
사전순으로 앞선 문자열이 앞쪽에 위치합니다.

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