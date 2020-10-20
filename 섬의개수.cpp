/** https://www.acmicpc.net/problem/4963
 *  �Է�
 *  ù°�� : 0 < w, h <= 50
 *  ��°��~h : 1 -��, 0 - �ٴ�
 *  �Է� ���� ���� : 0 0
 *  
 *  ���� ���� ����ϸ��. ���� ����Ǿ������� �ϳ��� ������ ������. (8 dir Ž����)
*/

#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int map[MAX][MAX];
bool visit[MAX][MAX];
// ��,��,��,��, ���,����,�»�,����
int dr[] = {-1,1,0,0,-1,1,-1,1}; //�� -> h
int dc[] = {0,0,-1,1,1,1,-1,-1}; //�� -> w
int sol;

void SearchOrNot(int h, int w);
void BeginSearch(int h, int w, int MAX_h, int MAX_w);
void init();

void input()
{
    int h, w;
    while(true)
    {
        cin >> w >> h;
        if(!h && !w) break;

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }
        
        SearchOrNot(h,w);
        cout << "----------" << sol <<endl;
        init();
    }
}

int main()
{
    input();
}

void SearchOrNot(int h, int w)
{
    for(int i = 0; i< h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(map[i][j] && !visit[i][j])
            {
                sol++;
                BeginSearch(i, j, h, w);
            }
        }
    }
}

void BeginSearch(int h, int w, int MAX_h, int MAX_w)
{
    visit[h][w] = true;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(h, w));

    while(!q.empty())
    {
        h = q.front().first;
        w = q.front().second;
        q.pop();

        for(int i = 0; i< 8; i++)
        {
            int nh = h+dr[i];
            int nw = w+dc[i];

            if(nh >= 0 && nh < MAX_h && nw >=0 && nw < MAX_w)
            {
                if(map[nh][nw] && !visit[nh][nw])
                {
                    visit[nh][nw] = true;
                    q.push(pair<int,int>(nh,nw));
                }
            }
        }
    }
}

void init()
{
	fill(map[0], map[0]+MAX*MAX, 0);
	fill(visit[0], visit[0]+MAX*MAX, 0);
    sol = 0;
}