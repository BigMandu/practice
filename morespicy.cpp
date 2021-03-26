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
#include<algorithm>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;

    make_heap(scoville.begin(), scoville.end());
    partial_sort(scoville.begin(), scoville.end(), scoville.end(),greater<int>());
    
    while(scoville.back() < K && scoville.size() > 1)
    {
        int min = scoville.back();
        scoville.pop_back();

        int secmin = scoville.back();
        scoville.pop_back();
        
        scoville.push_back(min + secmin*2);
        ++answer;

        make_heap(scoville.begin(), scoville.end());
        partial_sort(scoville.begin(), scoville.end(), scoville.end(),greater<int>());

    }

    if(scoville.back() < K)
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