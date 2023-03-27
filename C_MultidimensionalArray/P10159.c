#include <stdio.h>

#define MAX_SIZE 200
#define INT_MAX 1073741823 // 2^30 - 1
#define min(a, b) ((a) < (b) ? (a) : (b))

int dist[MAX_SIZE][MAX_SIZE] = {0};

void print_dist(int n);

int main()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    int num_vertex, edge;
    scanf("%d %d", &num_vertex, &edge);

    for (int i = 0; i < edge; i++)
    {
        int x, y;
        scanf(" %d %d", &x, &y);

        dist[x][y] = 1;
    }

    // printf("입력\n");
    // print_dist(num_vertex);

    // 플로이드-워셜
    for (int k = 1; k <= num_vertex; k++)
    {
        for (int i = 1; i <= num_vertex; i++)
        {
            for (int j = 1; j <= num_vertex; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // printf("플로이드 워셜 후\n");
    // print_dist(num_vertex);

    for (int i = 1; i <= num_vertex; i++)
    {
        for (int j = 1; j <= num_vertex; j++)
        {
            if (dist[i][j] < INT_MAX)
                dist[j][i] = dist[i][j];
        }
    }
    // printf("복사\n");
    // print_dist(num_vertex);

    for (int i = 1; i <= num_vertex; i++)
    {
        int cnt = -1;
        for (int j = 1; j <= num_vertex; j++)
        {
            if (dist[i][j] >= INT_MAX)
                cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}

// void print_dist(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (dist[i][j] < INT_MAX)
//                 printf("%d ", dist[i][j]);
//             else
//                 printf("_ ");
//         }
//         printf("\n");
//     }
// }