/*
* 1874 스택 수열
* 올데이에서 하는 백준...ㅎㅎ 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100000

int n;
int stack[MAX_NUM];
int idx_top = -1;

int is_full()
{
	return (idx_top >= MAX_NUM);
}

int is_empty()
{
	return (idx_top <= -1);
}

void push(int num)
{
	if(!is_full())
		stack[++idx_top] = num;
}

int pop()
{
	return is_empty() ? 0
					  :	stack[idx_top--];			
}

int top()
{
	return is_empty() ? 0
					  :	stack[idx_top];
}

int size()
{
	return idx_top + 1;
}


int main(void)
{
	scanf("%d", &n);
	int push_num = 1;
	
	char result[MAX_NUM * 2];
	int idx = 0;
	
	while(n--)
	{
		int num;
		scanf("%d", &num);
		
		if (num ==  top())
		{
			pop();
			result[idx++] = '-';
//			printf("-\n");
			continue;
		}
		
		int diff = num - push_num + 1; // 차이 구하고 그 차이만큼 push(+일때) or pop(-일때) 
//		int diff_pop = num - top();
		
		if (diff >= 0)
		{
			int i;
			for (i = 0; i < diff; i++)
			{
				push(push_num++);
				result[idx++] = '+';
			}
			pop();
			result[idx++] = '-';
		}
		else if (diff < 0)
		{
			strcpy(result, "NO\n");
			break;
		}
	}
	
	int i;
	if(result[0] == 'N')
		printf("NO");
	else
	{
		result[idx++] = '\0';     // strlen()할 때 NULL 문자 있어야 실행됨 
		int len = strlen(result); // strlen()을 따로 안 넣어주면 시간복잡도 발생 가능 
		for(i = 0; i < len; i++){
			printf("%c\n", result[i]);
		}
	}
	
	return 0;
}
