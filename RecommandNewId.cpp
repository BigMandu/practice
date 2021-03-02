/*
https://programmers.co.kr/learn/courses/30/lessons/72410

일곱단계의 처리과정
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.


제한사항
new_id는 길이 1 이상 1,000 이하인 문자열입니다.
new_id는 알파벳 대문자, 알파벳 소문자, 숫자, 특수문자로 구성되어 있습니다.
new_id에 나타날 수 있는 특수문자는 -_.~!@#$%^&*()=+[{]}:?,<>/ 로 한정됩니다.

결과의 제한사항
아이디의 길이는 3자 이상 15자 이하여야 합니다.
아이디는 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 문자만 사용할 수 있습니다.
단, 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없습니다.


입출력
new_id	                        result
"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
"z-+.^."	                    "z--"
"=.="	                        "aaa"
"123_.def"	                    "123_.def"
"abcdefghijklmn.p"	            "abcdefghijklmn"

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void FirstStep(string& id)
{
    std::transform(id.begin(), id.end(),id.begin(), ::tolower);
}

void SecondStep(string& id)
{
    for(int i = 0; i<id.size(); ++i)
    {
       if(isalpha(id[i]) || isdigit(id[i])|| id[i] == '-' || id[i] == '_' || id[i] == '.')
       {
           continue;
       }
       else
       {
           id.erase(i, 1);
           --i;
       }
    }
}

void ThirdStep(string& id)
{
    for(int i = 0; i<id.size(); ++i)
    {
        if(i+1 > id.size()) break;
        if(id[i] == '.' && id[i+1] == '.')
        {
            id.erase(i,1);
            --i;
        }
    }
}

void FourthStep(string& id)
{
    if(!id.empty())
    {
        if(id[0] == '.')
        {
            id.erase(0,1);
        }
        int ind = id.size()-1;
        if(id[ind] == '.')
        {
            id.erase(ind,1);
        }
    }
}

void FifthStep(string& id)
{
    if(id.empty())
    {
        id.push_back('a');
    }
}

void SixthStep(string& id)
{
    if(id.size() >= 15)
    {
        int len = id.size() - 15;
        id.erase(15, len);

        FourthStep(id);
    }

}

void SeventhStep(string& id)
{
    if(id.size() < 3)
    {
        char ch = id.back();
        while(id.size() < 3)
        {
            id.push_back(ch);
        }
    }
}

string solution(string new_id) 
{
    string answer = new_id;
    
    FirstStep(answer);
    SecondStep(answer);
    ThirdStep(answer);
    FourthStep(answer);
    FifthStep(answer);
    SixthStep(answer);
    SeventhStep(answer);
    return answer;
}

int main()
{
    string id = "abcdefghijklmn.p";

    id = solution(id);
    cout << id;
}

/*
new_id	                        result
"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
"z-+.^."	                    "z--"
"=.="	                        "aaa"
"123_.def"	                    "123_.def"
"abcdefghijklmn.p"	            "abcdefghijklmn"
*/