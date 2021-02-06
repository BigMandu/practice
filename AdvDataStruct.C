#pragma warning(disable: 4996)

#include <stdio.h>

//8.5

#if 1

#include <stdio.h>
int N;
int a[30000 + 10];
int tmp[30000 + 10];

void Msort(int s, int e)
{
	int m,i,j,k; //피봇, 레프트, 타겟
	if (s >= e) return; //스타트가 엔드보다 크거나 같을때

	m = (s + e) / 2;

	Msort(s, m); //왼쪽영역
	Msort(m + 1, e);//오른쪽 영역

	i = s; j = m + 1; //왼쪽 오른쪽 루프 돌꺼 시작점
	k = s;//k 임시버퍼 시작점

	//왼족영역 오른쪽 영역 비교후, 작은값을 임시배열에 저장함.
	while (i <= m && j <= e)
	{
		if (a[i] < a[j])
		{
			tmp[k++] = a[i++]; //왼쪽이 더작으면 
		}
		else
			tmp[k++] = a[j++];
	}


	//왼쪽, 오른쪽 영역중 남은 영역을 임시배열에 저장.'
	while (i <= m) tmp[k++] = a[i++];
	while (j <= e) tmp[k++] = a[j++];

	//임시배열을 원본배열에 복사후 끝.
	for (i = s; i <= e; i++)
	{
		a[i] = tmp[i];
	}


}


void Qsort(int s, int e)
{
	int p, l, t, temp; //피봇, 레프트, 타겟
	if (s >= e) return; //스타트가 엔드보다 크거나 같을때
	p = e; //피봇(기준)은 엔드,끝요소
	t = s; // 타겟(교환위치)은 시작위치
	for (l = s; l < e; l++) //비교대상
	{
		if (a[l] < a[p]) //비교 Left 와 Pivot을 비교.
		{
			temp = a[l]; //교환은 target과 left를 한다.
			a[l] = a[t];
			a[t] = temp;
			t++; //교환후 target하나 증가.
		}
	}
	//마지막에 데이터가 양분화가됨.
	//이때 target과 pivot데이터를 교환해야함
	temp = a[p];
	a[p] = a[t];
	a[t] = temp;
	Qsort(s, t - 1); //왼쪽영역 정렬
	Qsort(t + 1, e); //오른쪽영역 정렬
}


int main()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	//Qsort(0, N - 1); //스타트, 엔드
	Msort(0, N - 1);
	
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	

	return 0;
}

#endif//퀵소트와 머지소트

#if 0

#include <stdio.h>

int a[50001];
int N;

int Bin_search(int s, int e, int data)
{
	int m;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (a[m] == data) return m + 1;
		else if (a[m] > data) e = m - 1;
		else s = m + 1;
	}
	return 0;
}

int main()
{
	int i, T, data;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &data);
		printf("%d\n", Bin_search(0, N - 1, data));
	}
	return 0;
}

#endif //이진탐색

#if 0
int N,M;
int num[200000];
int snum[200000];

int slower(int s, int e, int data)
{
	int m, tmp = -1;

	while (s <= e)
	{
		m = (s + e) / 2;

		if (num[m] == data)
		{
			tmp = m;
			e = m - 1;
		}
		else if (num[m] > data)
		{
			e = m - 1;
		}
		else s = m + 1;
	}
	return tmp;
}
int supper(int s, int e, int data)
{
	int m, tmp = -1;

	while (s <= e)
	{
		m = (s + e) / 2;

		if (num[m] == data)
		{
			tmp = m;
			s = m + 1;
		}
		else if (num[m] > data)
		{
			e = m - 1;
		}
		else s = m + 1;
	}
	return tmp;
}

int main()
{
	int i, lower, upper;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d", &snum[i]);
	}


	for (i = 0; i < M; i++)
	{
		lower = slower(0, N - 1, snum[i]);
		if (lower != -1)
		{
			upper = supper(0, N - 1, snum[i]);
			printf("%d ", upper - lower + 1);
		}
		else printf("0 ");
	}

}

#endif //이진탐색 lower upper bound구성

#if 0

int N;
int num[200000];

int ln, hn;

int slower(int s, int e, int lwn)
{
	int m, tmp = -1;

	while (s <= e)
	{
		m = (s + e) / 2;

		if (num[m] >= lwn)
		{
			tmp = m;
			e = m - 1;
		}
		//else if (num[m] < lwn)
		//{
		//	e = m - 1;
		//}
		else s = m + 1;
	}
	return tmp;
}

int supper(int s, int e, int hin)
{
	int m, tmp = -1;

	while (s <= e)
	{
		m = (s + e) / 2;

		if (num[m] <= hin)
		{
			tmp = m;
			s = m + 1;
		}
	//	else if (num[m] > hin)
	//	{
	//		e = m - 1;
	//	}
		else e = m - 1;
	}
	return tmp;
}

int main()
{
	int i, lower, upper;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}


	scanf("%d %d", &ln, &hn);

	lower = slower(0, N - 1, ln);
	if (lower != -1)
	{
		upper = supper(0, N - 1, hn);
		printf("%d ", upper - lower + 1);
	}
	else printf("0 ");

}

#endif //이진탐색 범위내 개수구하기

#if 0
/*
1. 개구리가 뛴 거리가 이전에 뛴 거리 이상 뛰지만 그 2배보다 멀리 뛰지는 않는다.
2. 개구리는 오른쪽으로만 뛴다.
3. 개구리는 두 번만 뛴다.
4. 위 세 가지 조건을 만족한다면 어느 곳에서든 시작할 수 있다.
*/

#include <stdio.h>
int N;

int le[1010];

void sort()
{
	int i, j,tmp;

	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			if (le[i] > le[j])
			{
				tmp = le[i];
				le[i] = le[j];
				le[j] = tmp;
			}
		}
	}
}

int search()
{
	int i, j, k;
	int len = 0;
	int cnt = 0;
	
		for (i = 0; i < N-2; i++) //출발우치
		{
			for (j = i+1; j < N-1; j++) //첫점프
			{
				len = le[j] - le[i];
				for (k = j+1; k < N; k++) //두번째점프
				{
					//if (len == 0) le[j] - le[i];


					//if (le[k] - a[j] < len) continue;
					//else if (le[k] - le[j]>len * 2) break; //아래보다 좀더 효율적인 분기문

					if (le[j] < le[k] && ((len <= le[k] - le[j]) && (le[k] - le[j] <= len * 2)))
					{
						//len = le[j] - le[i];
						cnt++;
					}
				}
			}
		}
	return cnt;
}

int main(void)
{
	// 여기서부터 작성
	int i;

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &le[i]);
	}

	sort();
	printf("%d",search());



	return 0;
}


#endif //도약 3중루프


#if 0
#include <stdio.h>

int N;

int le[10010];


int lower(int s, int e, int data)
{
	int m, tmp = -1;

	while (s <= e)
	{
		m = (s + e) / 2;

		if (le[m] >= data)
		{
			tmp = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	return tmp;
}
int upper(int s, int e, int data)
{
	int m, tmp = -1;

	while (s <= e)
	{
		m = (s + e) / 2;

		if (le[m] <= data)
		{
			tmp = m;
			s = m + 1;
		}
		else s = m - 1;
	}
	return tmp;
}



void sort()
{
	int i, j,tmp;

	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			if (le[i] > le[j])
			{
				tmp = le[i];
				le[i] = le[j];
				le[j] = tmp;
			}
		}
	}
}

int search()
{
	int i, j, start, end;

	int low,upp;
	int len = 0;
	int cnt = 0;

	for (i = 0; i < N - 2; i++) //출발우치
	{
		for (j = i + 1; j < N - 1; j++) //첫점프
		{
			len = le[j] - le[i];
			start = le[j] + len;
			end = le[j] + len*2;

			// jump1 ~ jump2 범위 이내의 양끝 경계 위치를 이용
			//lower만 잘 체크하면됨

			//start 이상중에서 가장 작은 값의 위치 탐색
			low = lower(0, N - 1, start);
			

			//예외조건체크 : 실패일 경우(-1맅)나, 2배를 초과시, 아니라면 jump2이하중에서 가장 큰 값의 위치 탐색
			if (low == -1 || le[low]>end) continue;
			
			upp = upper(0, N - 1, end);

			cnt += upp - low + 1;
			
		}
	}
	return cnt;
}

int main(void)
{
	// 여기서부터 작성
	int i;

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &le[i]);
	}

	sort();

	printf("%d", search());



	return 0;
}

#endif //도약 이진탐색 lower upper bound구성


#if 0

int N;
int M,cnt;

int map[110][110];

int visit[110];

void ff(int c)
{
	int i;
	for (i = 1; i <= N; i++) //열
	{
		if (map[c][i] == 1 && visit[i] == 0)
		{
			cnt++;
			visit[i] = 1;
			ff(i);
		}
	}
}

int main(void)
{
	// 여기서부터 작성
	int i, s, e;;

	scanf("%d", &N);

	scanf("%d", &M);

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &s, &e);
		map[s][e] = map[e][s] = 1;
	}
	visit[1] = 1;
	ff(1); //1번 컴터퓨터시작
	printf("%d", cnt);
	


	return 0;
}

#endif //바이러스 인접행렬 (Flood fill이나 BFS로 찾는방법)

//8.6

#if 0

#include <stdio.h>
#define MAX    10
#define HASH_KEY 5 
#define STEP     1 

int Hash_table[MAX] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //초기값 -1로
int test[MAX] = { 1, 5, 3, 4, 9, 10, 11, 6, 2, 7 }; //테스트값
int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}
void Print_All_Data(void)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (Hash_table[i] > 0) printf("[%d] data=%d\n", i, Hash_table[i]);
	}
}

int Insert_Data(int  data) {
	int i, key;
	key = Get_Hash_Key(data);
	//여기에 함수를 완성한다.
	
	

	for (i = 0; i < MAX; i++)
	{
		if (Hash_table[key] == data)return -1;

		if (Hash_table[key] <= 0)
		{
			Hash_table[key] = data;
			return key;
		}
		else key = (key+STEP)%MAX;
	}

	return -1;
}

int Delete_Data(int data) {
	int i, key;
	key = Get_Hash_Key(data);
	//여기에 함수를 완성한다.

	for (i = 0; i < MAX; i++)
	{
		if (Hash_table[key] == -1) return -1;

		if (Hash_table[key] == data)
		{
			Hash_table[key] = 0;
			return key;
		}
		else key = (key + STEP) % MAX;
	}
	return -1;

}

void main(void)
{
	int i, r;
	for (i = 0; i < MAX; i++) Insert_Data(test[i]);
	Print_All_Data();
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[11] Delete Result=%d\n", r = Delete_Data(11));
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	Print_All_Data();
}

#endif //해쉬테이블 open address


#if 0
#define MAX 200000

typedef struct
{
	int x, nid;
}COW;

COW cow[50001], tmp[50001];
int chk[MAX];
int hash_table[MAX];


int id_cnt;
int N;


int Get_newid(int id)
{
	int i;
	int key = id%MAX;
	for (i = 0; i < MAX; i++)
	{
		if (hash_table[key] == 0)
		{
			hash_table[key] = id;
			id_cnt++;
			return key;
			//chk[key]++;
		}
		else if (hash_table[key] == id)
		{
			return key;
		}
		key = (key + 1) % MAX;
	}
	return -1;
}

void sort(int s, int e)
{
	int i, j, k, m;
	if (s >= e) return;
	m = (s + e) / 2;

	sort(s, m); //왼쪽영역
	sort(m + 1, e);

	i = s;
	j = m + 1;
	k = s;
	while (i<=m && j<=e)
	{
		if (cow[i].x < cow[j].x)
		{
			tmp[k++] = cow[i++];
		}
		else tmp[k++] = cow[j++];
	}
	while (i <= m) tmp[k++] = cow[i++];
	while (j <= e) tmp[k++] = cow[j++];

	for (i = s; i <= e; i++)
	{
		cow[i] = tmp[i];
	}
}

int solve()
{
	//모든 품종이 포함되는 x좌표의 최소 범위를 탐색
	int min = 0x7fffffff;
	int s, e, cnt = 0, dis;

	for (s = 0, e = 0; s < N; s++)
	{
		if (chk[cow[s].nid]++ == 0)
		{
			//chk[cow[s].nid]++;
			cnt++;
		}
		while (cnt == id_cnt)
		{
			dis = cow[s].x - cow[e].x;
			if (min > dis) min = dis;

			if (--chk[cow[e].nid] == 0)
			{
				//--chk[cow[e].nid];
				cnt--;
			}
			e++;
			
		}
	}
	return min;
}
int main(void)
{
	// 여기서부터 작성
	int i, id;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &cow[i].x, &id);
		cow[i].nid = Get_newid(id);
	}
	sort(0,N-1);

	printf("%d", solve());

	return 0;
}


#endif //암소라인업

#if 0
#define MAX_HEAP    (30000)

int N;
int heap[MAX_HEAP + 1];
int lastnode = 0;

int Heap_Push(int d)
{
	/*
	lastnode가 가리키는곳이 배열끝요소면 꽉참 -full 체크

	lastnode가 가리키는곳에 data를 삽입후, lastnode 1증가
	자식노드는 lastnode
	부모노드는 자식노드의 /2

	밑에서부터 최상단root까지 탐색/ 부모노드가 최상단 노드이면 중단. - loop
	자식노드가 더 크면(자식노드의 우선순위가 높으면 swap) (맥시멈 트리라)
	swap후 자식노드는 부모노드로, 부모노드는 자식노드/2
	*/
	int tmp ,p,c;

	if (lastnode == MAX_HEAP) return 0; //lastnode가 가리키는곳이 배열끝요소면 꽉참 -풀체크

	heap[++lastnode] = d; //lastnode가 가리키는곳에 data를 삽입후, lastnode 1증가

	c = lastnode; //자식노드는 lastnode
	p = c / 2; //부모노드는 자식노드의 /2
	while (p > 0) // 밑에서부터 최상단root까지 탐색/ 부모노드가 최상단 노드이면 중단.
	{
		if (heap[c] > heap[p]) //자식노드가 더 크면 swap (맥시멈 트리라)
		{
			tmp = heap[p];
			heap[p] = heap[c];
			heap[c] = tmp;

			c = p; p = c / 2; //자식노드는 부모노드로, 부모노드는 자식노드/2
		}
		else break;
	}
	return 1;
}

int Heap_Pop(int *data)
{
	/*
	last노드가 0을 가리키면 없는거임. 0리턴 - empty 체크

	최상단부터 pop을함.
	노드의 최하단에 있는 data를 root노드로,
	부모노드는 root를, 좌측자식노드는 2를, 우측 자식노드는 3을 대입.

	좌측 자식노드와 lastnode를 비교하면서 해당 자식노드가 lastnode일때까지 타고내려감. - loop

	경쟁상대 탐색

	좌측 자식노드가 lastnode이면 , 해당 부모노드의 경쟁상대는 좌측 자식노드.
	자식노드가 두개면, 좌측과 우측을 비교해, 우선순위가 높은 놈을 부모노드의 경쟁상대로, ? : 연산자 써도됨.
	
	자식노드의 우선순위가 높으면 부모노드와 swap
	swap후 부모노드는 자식노드로, 좌측노드는 부모노드*2, 우측노드는 좌측노드+1에.

	*/
	int p, c;
	int le, ri, tmp;
	
	if (lastnode == 0) return 0; //last노드가 0을 가리키면 없는거임. 0리턴

	*data = heap[1]; //최상단부터 pop을함.
	heap[1] = heap[lastnode--]; //노드의 최하단에 있는 data를 root노드로,
	p = 1, le = 2; ri = 3; //부모노드는 root를, 좌측자식노드는 2를, 우측 자식노드는 3을 대입.
	while (le <= lastnode) //좌측 자식노드와 lastnode를 비교하면서 해당 자식노드가 lastnode일때까지 타고내려감.
	{
		//경쟁상대 탐색
		if (le == lastnode) c = le; //좌측 자식노드가 lastnode이면 , 해당 부모노드의 경쟁상대는 좌측 자식노드.
		else if (heap[le] > heap[ri]) c = le; //자식노드가 두개면, 좌측과 우측을 비교해, 우선순위가 높은 놈을 부모노드의 경쟁상대로,
		else c = ri; //위와 합쳐 ? : 연산자 써도됨.
		if (heap[c] > heap[p]) //자식노드의 우선순위가 높으면 부모노드와 swap
		{
			tmp = heap[p];
			heap[p] = heap[c];
			heap[c] = tmp;

			p = c; le = p * 2; ri = le + 1;// 부모노드는 자식노드로, 좌측노드는 부모노드*2, 우측노드는 좌측노드+1에.
		}
		else break;
	}
	return 1;
}


int main(void)
{
	int i, d;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &d);
		Heap_Push(d);
	}

	for (i = N; i >= 1; i--)
	{
		Heap_Pop(&d);
		heap[i] = d;
	}

	for (i = 1; i <= N; i++)
	{
		printf("%d ", heap[i]);
	}

	return 0;
}

#endif //맥시멈 트리

#if 0

#define MAX 5050


int N;
int Heap[MAX];
int lastnode;


int push(int d)
{
	int c,p,tmp;
	
	if (lastnode == MAX) return 0;
	Heap[++lastnode] = d;
	c = lastnode;
	p = c / 2;

	while (p > 0)
	{
		if (Heap[p] > Heap[c])
		{
			tmp = Heap[p];
			Heap[p] = Heap[c];
			Heap[c] = tmp;
			c = p; p = c / 2;
		}
		else break;
	}
	return 1;
}

int pop(int *d)
{
	int p, c, left, right,tmp;

	if (lastnode == 0) return 0;
	*d = Heap[1];
	Heap[1] = Heap[lastnode--];

	p = 1; left = 2; right = 3;

	while (left <= lastnode)
	{
		if (left == lastnode) c = left;
		else c = (Heap[left] > Heap[right]) ? right : left;

		if (Heap[c] < Heap[p])
		{
			tmp = Heap[c];
			Heap[c] = Heap[p];
			Heap[p] = tmp;
			p = c; left = p * 2; right = left + 1;
		}
		else break;
	}
	return 1;
}

int main(void)
{
	int i,j;
	int data,data1;
	int sum=0, cnt=0, tot=0;
	// 여기서부터 작성
	//미니멈 트리로 오름차순으로 정렬후 계산하면 될듯.

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &data);
		push(data);
	}

	/*
	for (j = 0; j < N-1; j++)
	{
		/*
		while(cnt<N)
		{
		for (i = 0; i < 2; i++)
		{
			pop(&data);
			sum += data;
			tot += sum;
			//cnt++;
		}//

		pop(&data);
		pop(&data1);
		sum = data + data1;
		tot = tot + sum;
		push(sum);
	}
	printf("%d", tot);

	*/

	//for (i = 0; i <= N; i++)
	//{
	//	pop(&Heap[i]);
	//	//push(data);
	//}
	for (i = 0; i < N; i++)
	{
		Heap[i] = pop(&data);
		printf("%d", Heap[i]);
	}
	return 0;
}

#endif //최소비용으로 재포장

#if 0

int N;
int WP, RP;
int map[110][110];

int sum[110][110];

int dr[] = { 0, 1, 0, -1 }; //우,하,좌,상
int dc[] = { 1, 0, -1, 0 };

typedef struct
{
	int c, r;
}QUE;

QUE que[110 * 110 * 10];

void enqu(int r, int c)
{
	que[WP].c = c;
	que[WP].r = r;
	WP++;
}

int search()
{
	int i;
	int nr, nc;
	QUE q;
	
	enqu(0, 0);
	sum[0][0] = 0;
	while (RP < WP)
	{
		q = que[RP++];

		for (i = 0; i < 4; i++)
		{
			nr = q.r + dr[i];
			nc = q.c + dc[i];
			if (nr > N || nr<0 || nc>N || nc < 0) continue;
			//이전의 해보다 현재 해가 더 작으면 큐에 저장후 기록
			if (sum[q.r][q.c] + map[nr][nc] < sum[nr][nc])
			{
				enqu(nr, nc);
				sum[nr][nc] = map[nr][nc] + sum[q.r][q.c];
				
			}	
		}
	}
	return sum[N-1][N-1];
}

int main(void)
{
	// 여기서부터 작성
	int i,j;

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
			sum[i][j] = 0x7fffffff;
		}
	}

	
	printf("%d", search());
	return 0;
}


#endif //자외선 피하기 BFS 메모이제이션 책 170page 필기 참고

// 8.7

#if 0
#define MAX 110

int N;

int map[110][110];
int visit[110][110]; //방문표시

int dr[] = { 0, 1, 0, -1 }; //우,하,좌,상
int dc[] = { 1, 0, -1, 0 };

int lastnode = 0;

typedef struct
{
	int c, r, sum;
}QUE;

QUE Heap[110 * 110];

void push(int r, int c, int sum)
{
	QUE tmp;
	int ci, pa;

	Heap[++lastnode].r = r;
	Heap[lastnode].c = c;
	Heap[lastnode].sum = sum;

	ci = lastnode;
	pa = c / 2;

	while (pa > 0)
	{
		if (Heap[pa].sum > Heap[ci].sum)
		{
			tmp = Heap[pa];
			Heap[pa] = Heap[ci];
			Heap[ci] = tmp;
			ci = pa; pa = ci / 2;
		}
		else break;
	}
}

void pop(QUE *d)
{
	int p, c, left, right;
	QUE tmp;

	*d = Heap[1];
	Heap[1] = Heap[lastnode--];

	p = 1; left = 2; right = 3;

	while (left <= lastnode)
	{
		if (left == lastnode) c = left;
		else c = (Heap[left].sum > Heap[right].sum) ? right : left;

		if (Heap[c].sum < Heap[p].sum)
		{
			tmp = Heap[c];
			Heap[c] = Heap[p];
			Heap[p] = tmp;
			p = c; left = p * 2; right = left + 1;
		}
		else break;
	}
}

int search()
{
	int i;
	int nr, nc;
	QUE q;

	//last 노드가 있을동안 반복 , 방문안한 자리를 큐에 저장하고 방문표시
	//push
	push(1, 1, map[1][1]);
	visit[1][1] = 1;

	while (lastnode>0)
	{
		//pop
		pop(&q);

		if (q.r == N && q.c == N) return q.sum;

		for (i = 0; i < 4; i++)
		{
			nr = q.r + dr[i];
			nc = q.c + dc[i];

			if (nr > N || nr<1 || nc>N || nc < 1) continue;

			if (visit[nr][nc] == 1) continue;

			visit[nr][nc] = 1;
			push(nr, nc, q.sum + map[nr][nc]);
		}
	}
	return q.sum;
}

int main(void)
{
	// 여기서부터 작성
	int i, j;
	int result;
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	result = search();
	printf("%d", result);
	return 0;
}


#endif //자외선 피하기 우선순위 큐로 구성하기.



/***********************************************************/
// [2-3-2.1~4] Segment Tree
/***********************************************************/

#if 00

/***********************************************************/
// [2-3-2.1] Segment Tree 자료 확인
/***********************************************************/
#if 01

#define NUM_DATA	(5)
#define MAX_DATA	(NUM_DATA)
#define MAX_TREE	(MAX_DATA*3) //세배정도 잡아야 한다.
#define LAST_NODE	(MAX_DATA*3-1)

int tree[MAX_TREE];

int exam[NUM_DATA + 1] = { 0, 1, 2, 3, 4, 5 }; // 0번 index 공간 무시

#define PRINT_TREE {int j;printf("( ");	for(j=1;j<=LAST_NODE;j++){printf("%3d ",tree[j]);}printf(")\n");}


// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다
void Update_New_Data(int node, int s, int e, int idx, int data);
void Update_Add(int node, int s, int e, int us, int ue, int add);
int Query(int node, int s, int e, int qs, int qe);
#endif
/***********************************************************/
// [2-3-2.2] 새로운 데이터의 추가 및 데이터 업데이트 함수
/***********************************************************/
#if 0
/*
node = 노드번호, 
*/

void Update_New_Data(int node, int s, int e, int idx, int data)
{
	int m;

	m = (s + e) / 2;

	if (s == e)
	{
		tree[node] = data;
		return;
	}

	if (idx <= m)
	{
		Update_New_Data(node * 2, s, m, idx, data);
	}
	else
	{
		Update_New_Data(node * 2 + 1, m + 1, e, idx, data);
	}
	

	tree[node] = tree[node * 2] + tree[node * 2 + 1];

}
#endif

#if 0
void main(void)
{
	int i;

	printf("Update_New_Data() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
		printf("[%d] data : %d ", i, exam[i]);
		PRINT_TREE;
	}
}
#endif


/***********************************************************/
// [2-3-2.3] 구간 정보 요청
/***********************************************************/
#if 0
int Query(int node, int s, int e, int qs, int qe)
{
	int m = (s + e) / 2;
	int l, r;
	if (qs <= s && qe >= e)
	{

		return tree[node];
	}

	if (e < qs || qs < s)
	{
		return 0;
	}
	l = Query(node * 2, s, m, qs, qe);
	r = Query(node * 2+1, m+1, e, qs, qe);


	return l + r;
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Query() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
	}

	printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));
}
#endif


/*************************************************************/
// [2-3-2.4] 특정 구간 데이터 변경 함수 - 데이터 증가/감소
/*************************************************************/
#if 0
void Update_Add(int node, int s, int e, int us, int ue, int add)
{
	int m;
	m = (s + e) / 2;

	if (us<e || ue >s)
	{
		return;
	}


	if (s == e)
	{
		tree[node] += add;
		return;
	}
	Update_Add(node * 2, s, m, us, ue, add);
	Update_Add(node * 2+1, m+1, e, us, ue, add);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Update_Add() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
	}

	printf("[Before Range Update] ");
	PRINT_TREE;
	printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));

	Update_Add(1, 1, NUM_DATA, 2, 4, 2);

	printf("\n[After Range Update] ");
	PRINT_TREE;
	printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));
}
#endif
#endif



/***********************************************************/
// [2-3-2.5~9] Segment Tree with Lazy Propagation
/***********************************************************/

#if 00

/***********************************************************/
// [2-3-2.5] Segment Tree with Lazy Propagation 자료 확인
/***********************************************************/
#if 01
#include <stdio.h>

#define NUM_DATA	(5)
#define MAX_DATA	(NUM_DATA)
#define MAX_TREE	(MAX_DATA*2)
#define LAST_NODE	(MAX_DATA*2-1)

int tree[MAX_TREE];
int lazy[MAX_TREE];

int exam[NUM_DATA + 1] = { 0, 1, 2, 3, 4, 5 }; // 0번 index 공간 무시

#define PRINT_TREE {int j;printf("( ");	for(j=1;j<=LAST_NODE;j++){printf("%3d ",tree[j]);}printf(")\n");}


// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다
void Propagate(int n, int s, int e);
void Update_New_Data_Lazy(int node, int s, int e, int idx, int data);
void Update_Add_Lazy(int node, int s, int e, int us, int ue, int add);
int Query_Lazy(int node, int s, int e, int qs, int qe);
#endif


/***********************************************************/
// [2-3-2.6] Propagate 함수
/***********************************************************/
#if 01

void Propagate(int node, int s, int e)
{
	if (lazy[node] != 0) //lazy값이 있으면, 갱신되지 않은 이전값
	{
		if (s != e) //leaf노드가 아니면(부모노드면)
		{
			lazy[node * 2] += lazy[node];
			/*if (node * 2 + 1 <= LAST_NODE) 오른쪽 노드여부를 체크하는건데 필요없음.*/ lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += (e - s + 1)*lazy[node];
		lazy[node] = 0;
	}
}
#endif

/***********************************************************/
// [2-3-2.7] 새로운 data 추가/Update
/***********************************************************/

#if 01
void Update_New_Data_Lazy(int node, int s, int e, int idx, int data)
{
	int m;

	Propagate(node, s, e);

	if (s == e)
	{
		tree[node] = data;
		return;
	}

	m = (s + e) / 2;
	if (idx <= m) Update_New_Data_Lazy(node * 2, s, m, idx, data);
	else Update_New_Data_Lazy(node * 2 + 1, m + 1, e, idx, data);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Update_New_Data() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data_Lazy(1, 1, NUM_DATA, i, exam[i]);
		printf("[%d] data : %d ", i, exam[i]);
		PRINT_TREE;
	}
}
#endif


/***********************************************************/
// [2-3-2.8] 구간 정보 요청
/***********************************************************/
#if 01
int Query_Lazy(int node, int s, int e, int qs, int qe)
{
	int m, l, r;

	Propagate(node, s, e); //propagate함수를 불러, 해당노드에 lazy값 여부 확인해줌.

	if (qs <= s && e <= qe) return tree[node];
	else if (qs>e || s>qe) return 0;

	m = (s + e) / 2;
	l = Query_Lazy(node * 2, s, m, qs, qe);
	r = Query_Lazy(node * 2 + 1, m + 1, e, qs, qe);

	return l + r;
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Query() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data_Lazy(1, 1, NUM_DATA, i, exam[i]);
	}

	printf("Query[1~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 3, 5));
}
#endif


/*************************************************************/
// [2-3-2.9] 특정 구간 데이터 변경 함수 - 데이터 증가/감소
/*************************************************************/
#if 01
void Update_Add_Lazy(int node, int s, int e, int us, int ue, int add)
{
	int m;

	Propagate(node, s, e);

	if (us <= s && e <= ue)
	{
		lazy[node] += add;
		Propagate(node, s, e);//현재노드만 갱신
		return;
	}
	else if (us>e || s>ue) return;

	m = (s + e) / 2;
	Update_Add_Lazy(node * 2, s, m, us, ue, add);
	Update_Add_Lazy(node * 2 + 1, m + 1, e, us, ue, add);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Update_Add() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data_Lazy(1, 1, NUM_DATA, i, exam[i]);
	}

	printf("[Before Range Update] ");
	PRINT_TREE;
	printf("Query[1~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 3, 5));

	Update_Add_Lazy(1, 1, NUM_DATA, 2, 4, 2);

	printf("\n[After Range Update] ");
	PRINT_TREE;
	printf("Query[1~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query_Lazy(1, 1, NUM_DATA, 3, 5));
}
#endif
#endif



#if 00

#include <stdio.h>


int tree[50000 * 3];

int N,Q;

int Query(int node, int s, int e, int qs, int qe)
{
	int m, l, r;
	m = (s + e) / 2;
	if (qs <= s && e <= qe)
	{
		return tree[node];
	}
	if (s>qe || e<qs) return 0;

	l = Query(node * 2, s, m, qs, qe);
	r = Query(node * 2 + 1, m + 1, e, qs, qe);

	return l + r;
}

void update(int node, int s, int e, int idx, int data)
{
	int m;
	m = (s + e) / 2;

	if (s == e)
	{
		tree[node] += data;
		return;
	}

	if (idx <= m){
		update(node * 2, s, m, idx, data);
	}
	else{
		update(node * 2 + 1, m + 1, e, idx, data);
	}
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main(void)
{
	// 여기서부터작성
	int i,data;
	int qs, qe, idx, add;
	scanf("%d %d", &N, &Q);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &data);
		update(1, 1, N, i, data);
	}

	for (i = 1; i <= Q; i++)
	{
		scanf("%d %d %d %d", &qs, &qe, &idx, &add);

		printf("%d\n", Query(1, 1, N, qs, qe));
		update(1, 1, N, idx, add);
	}
	
	return 0;
}


#endif //구간합구하기

#if 00

#include <stdio.h>


int tree[50000 * 3];

int N, Q;

int Query(int node, int s, int e, int qs, int qe)
{
	int m, l, r, result;
	
	m = (s + e) / 2;
	if (qs <= s && e <= qe)
	{
		return tree[node];
	}
	if (s>qe || e<qs) return 0;

	l = Query(node * 2, s, m, qs, qe);
	r = Query(node * 2 + 1, m + 1, e, qs, qe);

	result = (l > r) ? l : r;
	return result;
}

void update(int node, int s, int e, int idx, int data)
{
	int m;
	m = (s + e) / 2;

	if (s == e)
	{
		tree[node] = data;
		return;
	}

	if (idx <= m){
		update(node * 2, s, m, idx, data);
	}
	else{
		update(node * 2 + 1, m + 1, e, idx, data);
	}


	tree[node] = (tree[node * 2] < tree[node * 2 + 1]) ? tree[node * 2 + 1] : tree[node * 2];
}
int main(void)
{
	// 여기서부터작성
	int i, data;
	int qs, qe;
	scanf("%d %d", &N, &Q);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &data);
		update(1, 1, N, i, data);
	}

	for (i = 1; i <= Q; i++)
	{
		scanf("%d %d", &qs, &qe);

		printf("%d\n", Query(1,1,N,qs, qe));
	}

	return 0;
}



#endif //구간 최대값 구하기

#if 00


int N;//스위치개수
int M;//일
int tree[262144];

int cnt;
int Query(int node, int s, int e, int qs, int qe)
{
	int m, l, r;

	m = (s + e) / 2;
	if (qs <= s && e <= qe)
	{
		return tree[node];
	}
	if (s>qe || e<qs) return 0;

	l = Query(node * 2, s, m, qs, qe);
	r = Query(node * 2 + 1, m + 1, e, qs, qe);

	return l + r;
}

void update(int node, int s, int e, int us, int ue)
{
	int m;
	m = (s + e) / 2;

	if (us>e || ue<s) return;

	if (s == e)
	{
		if (tree[node] == 1)
		{
			tree[node] = 0;
		}
		else
		{
			tree[node] = 1;
		}
		return;
	}

	update(node * 2, s, m, us, ue);
	update(node * 2 + 1, m + 1, e, us, ue);


	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

typedef struct
{
	int O, S, T;
}swit;

swit swi[1010];

void input_data(void){
	int i;
	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &swi[i].O, &swi[i].S, &swi[i].T);
	}

}

void solve(void){
	int i;

	for (i = 0; i < M; i++)
	{
		if (swi[i].O == 0) //S,T까지 반전
		{
			update(1, 1, N, swi[i].S, swi[i].T);
		}
		else if (swi[i].O == 1)//S,T중 켜진 스위치 개수.
		{
			printf("%d\n",Query(1, 1, N, swi[i].S, swi[i].T));
		}
	}

}

int main(void){
	input_data();
	solve();
	return 0;
}
#endif //스위치 구하기

// 8.8

#if 00


int T;
int N, M;//갖고있는 개수, 보려고하는 영화개수;
int tree[200010*3];
int cdp[100010];

int Query(int node, int s, int e, int qs, int qe)
{
	int m, l, r;

	m = (s + e) / 2;
	if (qs <= s && e <= qe)
	{
		return tree[node];
	}
	if (s>qe || e<qs) return 0;

	l = Query(node * 2, s, m, qs, qe);
	r = Query(node * 2 + 1, m + 1, e, qs, qe);

	return l + r;
}


void update(int node, int s, int e, int idx, int data)
{
	int m;
	m = (s + e) / 2;

	if (s == e)
	{
		tree[node] = data;
		return;
	}

	if (idx <= m){
		update(node * 2, s, m, idx, data);
	}
	else{
		update(node * 2 + 1, m + 1, e, idx, data);
	}


	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

	


int main(void)
{
	// 여기서부터작성
	int i;
	int movie;
//	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (T; T > 0; T--)
	{
		scanf("%d %d", &N, &M);
		for (i = 1; i <= 200010 * 3; i++)	tree[i] = 0; //재사용 할꺼니 초기화 해줘야함
		for (i = 1; i <= 100010; i++) cdp[i] = 0; //얘도
		for (i = 1; i <= N; i++)
		{
			cdp[i] = M + i; //cd 위치 기록. cd[i[= cd번호, M+i = 트리노드 번호.
			update(1, 1, N + M, M + i, 1); //data는 1 = cd있다.,(cd여부만 확인)
		}

		for (i = 0; i < M; i++)
		{
			scanf("%d", &movie);
			printf("%d ", Query(1, 1, N + M, 1, cdp[movie] - 1)); //개수구하는거
			//본 cd를 제일 위로 올리기
			update(1, 1, N + M, cdp[movie], 0); //이전 위치 cd를 빼고(0으로)
			update(1, 1, N + M, M-i, 1);//새로운 위치에 뺀 cd넣음.
			cdp[movie] = M - i; //맨위로 올린후 위치변경 해줘야함.
		}
		printf("\n");
		
	}

	return 0;
}

#endif // 영화 블루레이 수집 다시해보기

#if 00

#include <stdlib.h>
int N,cnt;

typedef struct stk
{
	int id;
	struct stk*prev;
}STACK;

STACK * sp;

int push(int d)
{
	STACK *s = calloc(1, sizeof(STACK));
	//if (s == NULL) return -1;

	s->id = d;
	s->prev = sp;
	sp = s;
	cnt++;

	return 1;
}

int pop(STACK *d)
{
	STACK *p = sp;
	if (sp == NULL) return 0;
	*d = *sp;
	sp = sp->prev;
	free(p);
	cnt--;
	return 1;
	/*
	while (sp->prev != NULL)
	{
		if (sp->prev->id == d->id)
		{
			*d = *sp;
			p = sp->prev;
			sp->prev = sp->prev->prev;
			free(p);
			cnt--;
			return 1;
		}
		sp = sp->prev;
	}
	return -1;
	*/
}
int main()
{
	int i,cmd,data;
	STACK tmp;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			scanf("%d", &data);
			push(data);
		}
		else if (cmd == 0)
		{
			if (pop(&tmp) == 1) printf("%d\n",tmp.id);
			else printf("E\n");
		}
		else
		{
			printf("%d\n", cnt);
		}
	}
	return 0;
}

#endif //스택 링크드리스트로 구현


#if 00

#include <stdio.h>

#include <malloc.h>

struct st
{
	int id;
	struct st * rp;
	struct st * wp;
};

struct st HEAD = { 0, NULL, NULL };
struct st TAIL = { 0, NULL, NULL };


struct st * QUEUE(int d)
{
	// 코드설계
	struct st * s = calloc(1, sizeof(struct st));

	s->id = d;

	s->rp = &TAIL;
	s->wp = TAIL.wp;

	
	TAIL.wp = s;
	s->wp->rp = s;
	//TAIL.wp->rp = s;

	return s;
}

int DEQUEUE(int *p)
{
	// 코드설계
	struct st * s;
	s = HEAD.rp;
	if (HEAD.rp == &TAIL)  return -1;
	//if (HEAD.rp == NULL)  return -1;
	*p = s->id;
	HEAD.rp = s->rp;
	s->rp->wp = s->wp;

	free(s);
	return 0;
}


/********************************************************************************/

/* 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지   */

/********************************************************************************/

int main(void)
{
	int i;
	int d;

	struct st * r, *t;
	int p[1];
	int oper[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0 };
	int que[] = { 1, 3, 5, 7, 9, 1, 3, 5, 7, 9, 0, 2, 4, 6, 2, 4, 8, 10, 6, 8, 10, 0 };
	int ans[] = { 1, 3, 5, 7, 9, 0, 0, 0, 0, 0, -1, 2, 4, 6, 0, 0, 8, 10, 0, 0, 0, -1 };

	HEAD.rp = &TAIL;
	TAIL.wp = &HEAD;

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("\nTEST VECTOR [%d]\n", i);

		if (oper[i] == 1)
		{
			r = QUEUE(que[i]);

			t = HEAD.rp;

			while (t->rp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->rp;
			}

			printf("\n");

			t = TAIL.wp;

			while (t->wp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->wp;
			}

			printf("\n");

			if (r == NULL)
			{
				printf(">>>>틀림: 리턴된구조체의주소가NULL 포인터임\n");
				return 0;
			}

			if (r->id != ans[i])
			{
				printf(">>>>틀림: 리턴된구조체주소의id 예상값=> %d, 실제리턴된구조체의id 값=> %d\n", ans[i], r->id);
				return 0;
			}

			if (TAIL.wp != r)
			{
				printf(">>>>틀림: TAIL측wp 링크오류(TAIL의wp가리턴된자료주소가아님)\n");
				return 0;
			}

			if (r->rp != &TAIL)
			{
				printf(">>>>틀림: 리턴된자료의rp가TAIL의주소가아님)\n");
				return 0;
			}

			t = &HEAD;

			for (;;)
			{
				if (t->rp == &TAIL) break;
				else t = t->rp;
			}

			if ((t != r) || (t->id != r->id))
			{
				printf(">>>>틀림: HEAD측으로부터찾은TAIL 바로앞에있어야하는구조체주소와리턴된구조체주소가다름\n");
				return 0;
			}

			printf("OK\n");
		}


		else
		{
			d = DEQUEUE(p);

			t = HEAD.rp;

			while (t->rp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->rp;
			}

			printf("\n");

			t = TAIL.wp;

			while (t->wp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->wp;
			}

			printf("\n");

			if (d != ans[i])
			{
				printf(">>>>틀림: 예상리턴값= %d, 실제리턴값= %d\n", ans[i], d);
				return 0;
			}

			if (d != -1)
			{
				if (*p != que[i])
				{
					printf(">>>>틀림: 큐에서꺼내서p 주소에들어있는데이터의예상값=> %d, 실제p 주소에들어있는값=> %d\n", que[i], *p);
					return 0;
				}

				t = &HEAD;

				for (;;)
				{
					if (t->rp == &TAIL) break;
					else t = t->rp;
				}

				t = &TAIL;

				for (;;)
				{
					if (t->wp == &HEAD) break;
					else t = t->wp;
				}
			}

			printf("OK\n");
		}
	}

	return 1;
}
#endif //큐 링크드리스트로 구현

#if 00
//'9' - '0' = 9;

#include<stdlib.h>

typedef struct _node 
{
	struct _node *next[10];
	int end;
}NODE;

NODE Head;

int search_node(NODE *p, char *tel) 
{
	int i, no;
	for (i = 0; tel[i]; i++) 
	{//문자열
		no = tel[i] - '0';//문자를 정수화
		//일관성 여부 체크
		if (p->end) return 0;
		if (p->next[no] == 0)
		{
			return 1;
		}
		p = p->next[no];
	}
	return 0;//내 문자열이 끝이어도 일관성 없음
}
void insert_node(NODE *p, char *tel) 
{
	NODE *new;
	int i, no;
	for (i = 0; tel[i]; i++) 
	{
		no = tel[i] - '0';
		//신규이면 노드 생성하여 연결

		if (p->next[no] == 0)//NULL)
		{
			new = calloc(1, sizeof(NODE));
			p->next[no] = new;
		}
		p = p->next[no];
	}
	p->end = 1;//문자열이 끝나면 끝처리 표시
}
void delete_node(NODE *p)
{
	int i;
	for (i = 0; i < 10; i++) 
	{
		if (p->next[i]) //있으면 
		{
			delete_node(p->next[i]);  //쭉타고감.
			free(p->next[i]);
			p->next[i] = 0; //head지우려고 추가함.
		}
	}
}
int main(void) 
{
	int ti, T, N;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (ti = 0; ti < T; ti++) 
	{
		int i, flag = 1;
		char tel[11];
		scanf("%d", &N);

		for (i = 0; i < N; i++) 
		{
			scanf("%s", tel);
			if (flag == 0) continue; //일관성이 없어도, T는 돌아야하니 걍 continue
			if (i != 0) flag = search_node(&Head, tel);
			insert_node(&Head, tel);
		}
		delete_node(&Head);
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

#endif //전화번호 목록

#if 00

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
	char ch;
	struct st * next;
	struct st * prev;

}NODE;

NODE Head, Tail;
NODE *cur;

char str[600001];


void insert(char ch)
{
	NODE * q;
	q = calloc(1, sizeof(NODE));

	q->next = cur;
	q->prev = cur->prev;

	q->ch = ch;

	q->next->prev = q;
	q->prev->next = q;
}

void delete()
{
	NODE *d;
	d = cur->prev;

	d->prev->next = d->next;
	d->next->prev = d->prev;
	free(d);
}

void print_node()
{
	NODE * s = &Head;

	while (s->next != &Tail)
	{
		printf("%c", s->next->ch);
		
		s = s->next;
	}
}

int main(void)
{
	// 여기서부터작성
	char cmd,ch;
	int N, i;

	Head.next = &Tail;
	Tail.prev = &Head;
	cur = &Tail;
	scanf("%s", str);
	scanf("%d", &N);


	for(i=0;str[i];i++)
	{
		insert(str[i]);
	}

	for (i = 0; i < N; i++)
	{
		scanf(" %c", &cmd); //%c앞엔 공백해줘야함. 안그럼 엔터까지 %c가 가져옴
		if (cmd == 'L') //왼쪽 한칸 이동
		{
			if (cur->prev == &Head) continue;
			cur = cur->prev;
			
		}
		else if (cmd == 'D') //오른쪽 한칸이동.
		{
			if (cur == &Tail) continue; //cur->next == NULL
			cur = cur->next;

		}
		else if (cmd == 'P')//문자 ch를 커서왼쪽에 추가함
		{
			scanf(" %c", &ch);
			insert(ch);
		}
		else //커서왼쪽 문자 삭제.
		{
			if (cur->prev == &Head) continue;
			delete();
		}
	}
	print_node();

	return 0;
}

#endif //에디터


//8.8

#if 00

int N;
int map[15][15];
int visit[30];

int min = 0x7fffffff;

void search(int n,int sum,int cnt)
{
	int i;
	if (cnt == N)
	{
		if (map[n][1] != 0)
		{
			sum += map[n][1];
			if (min > sum) min = sum;
		}
		return;
	}

	for (i = 2; i <= N; i++)
	{
		if (visit[i] == 1 || map[n][i]==0) continue;
		visit[i] = 1;
		search(i, sum + map[n][i], cnt + 1); //n+1아님.
		visit[i] = 0;
	}

}

int main(void)
{
	// 여기서부터 작성
	int i, j;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	search(1, 0, 1);
	printf("%d", min);

	return 0;
}

#endif //또밀턴 순환회로



#if 00

int M, N;

int map[110][110];
int RP, WP;

int min = 0x7fffffff;

int cost[110];
int path[110]; //경로기록.

int que[110 * 110]; //역의 번호만 넣으면됨. 구조체로 설계할 필요 없음.
//방문배열 요소번호 = 목적지,  요소내용 = 출발지. 스택을 이용, 재귀로 거꾸로뽑음

void print_path(int no)
{
	if (no == 1)
	{
		printf("1 ");
		return;
	}
	print_path(path[no]);

	printf("%d ", no);
}

int search()
{
	//int nr, nc,
	//QUE q;
	int  i, no;
	que[WP++] = 1;
	cost[1] = 0; //map[1][1];

	while (RP < WP)
	{
		no = que[RP++];

		for (i = 2; i <= N; i++)
		{
			if (cost[no] + map[no][i] < cost[i])
			{
				que[WP++] = i;
				cost[i] = cost[no] + map[no][i];

				path[i] = no; //현재역, 가볼 경로기록.
			}
		}
	}
	return cost[M];
}


int main(void)
{
	// 여기서부터 작성
	int i, j;
	scanf("%d %d", &N, &M); //N 지하철역수, M 목적역 번호

	for (i = 1; i <= N; i++)
	{
		cost[i] = 0x7fffffff;
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n",search());
	print_path(M);

	return 0;
}
#endif //자철 bfs


#if 00

int N,M;
int money[10010];


int check(int m)
{
	int i, sum = 0;
	for (i = 0; i < N; i++)
	{
		if (money[i] > m) sum += m; //상한액 초과하면 상한액으로 결정.
		else sum += money[i]; //초과하지 않았으면 그대로.
	}
	return sum;
}

int main(void)
{
	// 여기서부터 작성
	int i, m, s=0, e=0, sol;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &money[i]);
		if (e < money[i]) e = money[i];
	}
	scanf("%d", &M);

	while (s <= e)
	{
		m = (s + e) / 2; //상한가는 중간액으로 정함.
		if (check(m) <= M) //check = 총액을 리턴, 총액이 상한가보다 아래면 늘려봄.
		{
			s = m + 1; //시작을 상한가+1로 다시 정함.
			sol = m; //상한가를 매번 백업하고감.
		}
		else //줄임
		{
			e = m - 1;
		}
	}
	printf("%d", sol);
	


	return 0;
}

#endif //예산


///////////////////////////////////////////////////
///////////////////////////////////////////////////

#if 00
#include <stdio.h>

long N, M;
long tree[1000010];

long search(int m)
{
	int i;
	long sum = 0;
	for (i = 0; i < N; i++)
	{
		if (tree[i] >= m) sum += tree[i] - m;
	}
	return sum;
}


int main(void)
{
	// 여기서부터작성
	int i;
	long m, s = 0, e = 0;
	long bak;

//	freopen("input.txt", "r", stdin);

	scanf("%ld %ld", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%ld", &tree[i]);
		if (e < tree[i]) e = tree[i];
	}
	//정렬?


	while (s <= e)
	{
		m = (s + e) / 2;

		//if (search(m) >= M)
		//{
		//	s = m + 1;
		//	bak = m;
		//}
		//else e = m - 1;
		if (search(m)==M)
		{
			bak = m;
			break;
		}
		else if (search(m)>M)
		{
			s = m + 1;
			bak = m;
		}
		else e = m - 1;
	}
	printf("%ld", bak);
	
	
	return 0;
}


#endif //나무자르기

#if 00


long tree[2000];
long save[2000];

int lastnode = 0;


int N;

void push(int d)
{
	int c, p,tmp;
	tree[++lastnode] = d;
	c = lastnode;
	p = c / 2;

	while (p > 0)
	{
		if (tree[p] > tree[c])
		{
			tmp = tree[p];
			tree[p] = tree[c];
			tree[c] = tmp;
			c = p; p = c / 2;
		}
		else break;
	}
}
void pop(int *d)
{
	int p, c, l, r;
	int tmp;

	*d = tree[1]; //값전달하고,
	tree[1] = tree[lastnode--]; //노드끝에ㅣㅇㅆ는걸 다시 맨위로 올림.


	p = 1; l = 2; r = 3;

	while (l <= lastnode)
	{
		if (lastnode == l) c = l;
		else c = (tree[l] > tree[r]) ? r : l;

		if (tree[p] > tree[c])
		{
			tmp = tree[p];
			tree[p] = tree[c];
			tree[c] = tmp; 
			p = c; l = p * 2; r = p * 2 + 1;
		}
		else break;
	}
}


void solve()
{
	int data = 0;
	int i;

	for (i = 1; i <= 1500; i++)
	{
		pop(&data);
		if (save[i-1] == data) continue;
		save[i] = data;
	
		push(data * 2);
		push(data * 3);
		push(data * 5);
	}
}

int main(void)
{
	// 여기서부터작성
	int input;
	freopen("input.txt", "r", stdin);
	push(1);

	solve();
	scanf("%d", &input);
	printf("%d\n", save[input]);

	while (input)
	{
		if (input == 0) return;
		scanf("%d", &input);
		printf("%d\n", save[input+1]);
	}
}
#endif //못생긴수