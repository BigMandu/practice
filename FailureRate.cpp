/*
https://programmers.co.kr/learn/courses/30/lessons/42889


������ ����
- ���������� ����������, ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��

( 1<= N <=50  // 1 <= �迭length <=200000
    1 <= �迭��� <=N+1 �� �ڿ����� ��� (N+1�� ��� N��° �������� ���� Ŭ������ �������.)
)

N - ��ü �������� ��
�迭 - ������ �̿��ϴ� ����ڰ� ���� �����ִ� ���������� ��ȣ��.

�������� ���� ������������ ������ ������ ���������� ��ȣ�� ���� �迭�� return.

- �������� ���� stage�� �ִٸ�, ���� ��ȣ�� stage�� ���� ������ �Ѵ�.
- ���������� ������ ������ ���� ���, �������� 0���� ����.

N	stages	                    result
5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
4	[4,4,4,4,4]	                [4,1,2,3]

*/
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool custom(pair<double,int> cur, pair<double,int> nex)
{
    if(cur.first == nex.first)
    {
        return cur.second  < nex.second;
    }
    else return cur.first > nex.first;
}

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<pair<double,int>> save;

    save.resize(N+1);

    for(int x : stages) //�÷��̾� ����ֱ�
    {
        if(x == N+1) continue;

        save[x].first += 1;
    }

    for(int i = 0; i<save.size(); i++) //�����÷��̾� ����ֱ�
    {
        if(i != 0 && save[i].second == 0)
        {
            if(i == 1)
            {
                save[i].second = stages.size();
            }
            else
            {
                save[i].second = save[i-1].second - save[i-1].first;
            }
        }
    }

    for(int i = 0; i<save.size(); i++) //������ ���
    {
        if(save[i].first != 0)
        {
            save[i].first = save[i].first / save[i].second;
        }
        save[i].second = i;
    }

    sort(save.begin(), save.end(),custom); //����

    for(int i = 0; i<save.size(); i++) //�������� �ֱ�
    {
        if(save[i].second == 0) continue;
        answer.push_back(save[i].second);
    }

    return answer;
}

int main()
{
    int N;
    vector<int>vec;

    N = 4;
    vec = {4,4,4,4,4};

    vec = solution(N,vec);

    for(int x : vec)
    {
        cout << x;
    }
}