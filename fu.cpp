int m[10][10] =  
{   0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
    0,    1,    0,    0,    0,    0,    1,    1,    1,    1,
    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,
    0,    0,    0,    1,    1,    0,    1,    1,    1,    1,
    0,    1,    1,    1,    0,    0,    1,    0,    0,    1,
    1,    1,    1,    1,    0,    1,    1,    0,    0,    1,
    1,    1,    0,    1,    0,    0,    0,    0,    0,    1,
    1,    1,    0,    0,    1,    1,    1,    1,    0,    1,
    0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
    0,    1,    1,    1,    1,    1,    1,    1,    0,    0
};

bool maze_problem(int dim, int maze[dim][dim], int x, int y){
	if (x == dim - 1 && y == dim - 1)  // recursive terminal condition
	{
		return true; 
	}
	// check if valid move 
	if(x >= 0 && x < dim && y >= 0 && y < dim && maze[x][y] == 1)	
	{
	
		if (maze_problem(dim, maze, x + 1, y)) // move x direction  
			return true; 
		if (maze_problem(dim, maze, x, y + 1)) // move y direction if move x does not work 
			return true; 
		// if move x and y does not work then backtrack 
		return false; 
	}
	
	return false; 
}


int main(){

	max_problem(10, m, 0, 0); 


}