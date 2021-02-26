/*
https://programmers.co.kr/learn/courses/30/lessons/17681


�Է�����
�Է����� ������ �� �� ũ�� n �� 2���� ���� �迭 arr1, arr2�� ���´�.

1 ? n ? 16
arr1, arr2�� ���� n�� ���� �迭�� �־�����.
���� �迭�� �� ���� x�� �������� ��ȯ���� ���� ���̴� n �����̴�. ��, 0 ? x ? 2n - 1�� �����Ѵ�.


��� ����
������ ��������� �ص��Ͽ� '#', �������� ������ ���ڿ� �迭�� ����϶�.



�Ű�����	��
n	        5
arr1	    [9, 20, 28, 18, 11]
arr2	    [30, 1, 21, 17, 28]
���	    ["#####","# # #", "### #", "# ##", "#####"]


�Ű�����	��
n	        6
arr1	    [46, 33, 33 ,22, 31, 50]
arr2	    [27 ,56, 19, 14, 14, 10]
���	    ["######", "### #", "## ##", " #### ", " #####", "### # "]
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string binToStr(int n, int x)
{
    string str;

    while(str.size() != n)
    {
        str = ((x % 2 == 0)? ' ' : '#') +str;
        x/=2;
    }
    
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<int> tmpstore;
    vector<string> answer;

    for(int i =0; i<n; i++)
    {
        int num = (arr1[i] | arr2[i]);

        tmpstore.push_back(num);
    }

    for(int bit : tmpstore)
    {
        answer.push_back(binToStr(n, bit));
    }

    return answer;
}


int main()
{
    int n;
    vector<int>arr1;
    vector<int>arr2;
    vector<string>str;

    n = 6;
    arr1 = {46, 33, 33 ,22, 31, 50};
    arr2 = {27 ,56, 19, 14, 14, 10};

    str = solution(n,arr1,arr2);

    for(string s : str)
    {
        cout<<s<<endl;
    }
}