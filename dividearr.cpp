/*
    https://programmers.co.kr/learn/courses/30/lessons/12910

    array�� �� element �� divisor�� ������ �������� ���� 
    ������������ ������ �迭�� ��ȯ�϶�.

    divisor�� ������ �������� element�� �ϳ��� ���ٸ� -1�� return�϶�.

    arr	            divisor	return
    [5, 9, 7, 10]	5	    [5, 10]
    [2, 36, 1, 3]	1	    [1, 2, 3, 36]
    [3,2,6]	        10	    [-1]

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]%divisor == 0)
        {
            answer.push_back(arr[i]);
        }
    }

    if(answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        
    }

    return answer;
}