/*
https://programmers.co.kr/learn/courses/30/lessons/12935

���� ���� ���� ������ �迭�� ����.
�����Ϸ��� �迭�� �� �迭�� ��쿣 �迭�� -1�� ä�� ����.
arr	        return
[4,3,2,1]	[4,3,2]
[10]	    [-1]
*/
#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int minvalue = 0x77777f;
    int minele = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        if(minvalue > arr[i])
        {
            minvalue = arr[i];
            minele  = i;
        }
    }

    for(int i = 0; i <arr.size(); i++)
    {
        if(arr.size() == 1)
        {
            answer.push_back(-1);
            break;
        }
        if(minele != i)
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

int main()
{
    vector<int> arr =  { 4,3,2,1};//{10};

    arr = solution(arr);

    for(int x : arr)
    {
        cout << x;
    }
}