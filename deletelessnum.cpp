/*
https://programmers.co.kr/learn/courses/30/lessons/12935

가장 작은 수를 제거한 배열을 리턴.
리턴하려는 배열이 빈 배열인 경우엔 배열에 -1을 채워 리턴.
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