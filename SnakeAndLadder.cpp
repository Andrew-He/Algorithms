// find the shortest path in a directed graph 
/*
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

If the player reaches a cell which is base of a ladder, the player has to climb up that ladder and if reaches a cell is mouth of the snake, has to go down to the tail of snake without a dice throw.

snakesladders

For example consider the board shown on right side (taken from here), the minimum number of dice throws required to reach cell 30 from cell 1 is 3. Following are steps.

a) First throw two on dice to reach cell number 3 and then ladder to reach 22
b) Then throw 6 to reach 28.
c) Finally through 2 to reach 30.

There can be other solutions as well like (2, 2, 6), (2, 4, 4), (2, 3, 5).. etc.

*/ 

#include <iostream>
#include <queue>

using namespace std; 

struct queueEntry
{	
	int v; 
	int dist; 
};

int getMinDiceThrows(int move[], int N) {
	bool *visited = new bool[N];
	for(int i = 0; i < N; i++) visited[i] = false; 

	queue<queueEntry> q ;
	visited[0] = true; 
	queueEntry s = {0, 0}; 
	q.push(s); 

	queueEntry qe; 
	while (!q.empty())
	{
		qe = q.front(); 
		int v = qe.v; 

		if (v == N-1) break; 
		q.pop(); 
		for(int j = v+1; j <= (v+6) && j < N; ++j)
		{
			if (!visited[j])
			{
				queueEntry a;
				a.dist = (qe.dist + 1); 
				visited[j] = true; 

				if (move[j] != -1)
					a.v = move[j]; 
				else 
					a.v = j; 
					q.push(a);
			}
		}

	}
	return qe.dist;
}

int main()
{	
	int N = 30; 
	int moves[N]; 
	for(int i = 0; i < N; i++)
		moves[i] = -1; 

	moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Min dice throw required is " << getMinDiceThrows(moves, N); 
    return 0;
}











