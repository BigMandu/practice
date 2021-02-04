/*
    https://programmers.co.kr/learn/courses/30/lessons/12906

    arr = [1, 1, 3, 3, 0, 1, 1] �̸� [1, 3, 0, 1] �� return �մϴ�.
    arr = [4, 4, 4, 3, 3] �̸�       [4, 3] �� return �մϴ�.


*/


#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.

    for(int i = 0; i<arr.size(); i++)
    {
        if(i+1 < arr.size())
        {
            if(arr[i] != arr[i+1])
            {
                answer.push_back(arr[i]);
            }
        }
        else
        {
            if(answer.empty() || answer.back() != arr[i])
            {
                answer.push_back(arr[i]);
            }
        }
    }

    return answer;
}

int main()
{
    vector<int>invec;

    for(int i=0;i<100;i++)
    {
        int input;
        scanf("%d",&input);
        if(input < 0) break;
        invec.push_back(input);
    }

    invec = solution(invec);
    for(int i=0;i<invec.size(); i++)
    {
        printf("%d",invec[i]);
    }
}