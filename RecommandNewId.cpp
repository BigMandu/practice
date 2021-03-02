/*
https://programmers.co.kr/learn/courses/30/lessons/72410

�ϰ��ܰ��� ó������
1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
     ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.


���ѻ���
new_id�� ���� 1 �̻� 1,000 ������ ���ڿ��Դϴ�.
new_id�� ���ĺ� �빮��, ���ĺ� �ҹ���, ����, Ư�����ڷ� �����Ǿ� �ֽ��ϴ�.
new_id�� ��Ÿ�� �� �ִ� Ư�����ڴ� -_.~!@#$%^&*()=+[{]}:?,<>/ �� �����˴ϴ�.

����� ���ѻ���
���̵��� ���̴� 3�� �̻� 15�� ���Ͽ��� �մϴ�.
���̵�� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.) ���ڸ� ����� �� �ֽ��ϴ�.
��, ��ħǥ(.)�� ó���� ���� ����� �� ������ ���� �������� ����� �� �����ϴ�.


�����
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