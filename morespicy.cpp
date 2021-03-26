/*
https://programmers.co.kr/learn/courses/30/lessons/42626

섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)


모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return하라.


-제한사항
scoville의 길이는 2 이상 1,000,000 이하입니다.
K는 0 이상 1,000,000,000 이하입니다.
scoville의 원소는 각각 0 이상 1,000,000 이하입니다.
모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.

- 변수 설명
음식의 스코빌 지수를 담은 배열 scoville
원하는 스코빌 지수 K

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