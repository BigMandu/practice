/*
    https://programmers.co.kr/learn/courses/30/lessons/62048

    W, H의 넓이를 가진 종이를 대각선 꼭지점 2개를 잇는 방향으로 잘라 놓았습니다. 
    그러므로 현재 직사각형 종이는 크기가 같은 직각삼각형 2개로 나누어진 상태입니다. 
    이 종이에서 원래 종이의 가로, 세로 방향과 평행하게 1cm × 1cm로 잘라 사용할 수 있는 만큼만 사용하기로 하였습니다.
    가로의 길이 W와 세로의 길이 H가 주어질 때, 사용할 수 있는 정사각형의 개수를 구하는 solution 함수를 완성해 주세요.

    W, H : 1억 이하의 자연수

    W	H	result
    8	12	80

    가로가 8, 세로가 12인 직사각형을 대각선 방향으로 자르면 총 16개 정사각형을 사용할 수 없게 된다. 
    원래 직사각형에서는 96개의 정사각형을 만들 수 있었으므로, 96 - 16 = 80 을 반환합니다.


    수학이 약해서 찾아보니..
    초등학교5학년이 푸는 문제다..

    직각삼각형에 한변의 길이가 x인 정사각형의 모양을 붙여라!...    
    가로+세로-가로세로의 최대공약수.. 가 정답이다.

    초등학교 수학경시대회 은상이었는데.. 계속했으면 어땟을까하는 생각이 든다.
    중학교2학년 이후로 공부를 안했는데도 54545등급. 아마 계속했으면 2-3등급은 나오지 않았을까..
*/
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int w,int h) 
{
    long long answer = 1;

    long long square = (long long)w*h;
    int triangle = w+h-__gcd(w,h);

    answer = square - triangle;    
    return answer;
}

int main()
{
    long long ans = 0;
    int w;
    int h;

    w = 8;
    h = 12;

    ans = solution(w,h);

    cout<<ans;
}