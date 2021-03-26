/*
https://programmers.co.kr/learn/courses/30/lessons/42626

���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)


��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return�϶�.


-���ѻ���
scoville�� ���̴� 2 �̻� 1,000,000 �����Դϴ�.
K�� 0 �̻� 1,000,000,000 �����Դϴ�.
scoville�� ���Ҵ� ���� 0 �̻� 1,000,000 �����Դϴ�.
��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�.

- ���� ����
������ ���ں� ������ ���� �迭 scoville
���ϴ� ���ں� ���� K

scoville	            K	return
[1, 2, 3, 9, 10, 12]	7	2


[1, 1, 1]               4   2
[10, 10, 10, 10, 10]    100 4  <-
[0, 2, 3, 9, 10, 12]    7   2
[0, 0, 3, 9, 10, 12]    7   3
[0, 0, 0, 0]            7   -1  <-
[0, 0, 3, 9, 10, 12]    7000 -1  <-
[0, 0, 3, 9, 10, 12]    0   0
[0, 0, 3, 9, 10, 12]    1   2
[0, 0]                  0   0
[0, 0]                  1   -1  <-
[1, 0]                  1   1
*/

#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;

    for(int i : scoville)
    {
        pq.push(i);
    }
    
    
    while(pq.top() < K && pq.size() > 1)
    {
        int min = pq.top();
        pq.pop();

        int secmin = pq.top();
        pq.pop();
        
        pq.push(min + secmin*2);
        ++answer;
    }

    if(pq.top() < K)
        answer = -1;

    return answer;
}

int main()
{
    vector<int> input;
    int K;

    input = {1, 2, 3, 9, 10, 12};
    K = 7;

    K = solution(input,K);

    cout << K;
}