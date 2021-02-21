#include <bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<char> >& a)
{
	int i, j, n = a.size();
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

bool mainDiagDone(vector<vector<char> >& a, char key)
{
	int i, n = a.size();
	for(i = 0; i < n; i++)
	{
		if(a[i][i] != key)
			return false;
	}
	return true;
}

bool secondDiagDone(vector<vector<char> >& a, char key)
{
	int i, n = a.size();
	for(i = 0; i < n; i++)
	{
		if(a[i][n-1-i] != key)
			return false;
	}
	return true;
}

bool rowDone(vector<vector<char> >& a, char key)
{
	int i, j, n = a.size();
	bool flag;
	for(i = 0; i < n; i++)
	{
		flag = true;
		for(j = 0; j < n; j++)
		{
			if(a[i][j] != key)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			break;
	}
	return flag;
}

bool colDone(vector<vector<char> >& a, char key)
{
	int i, j, n = a.size();
	bool flag;
	for(i = 0; i < n; i++)
	{
		flag = true;
		for(j = 0; j < n; j++)
		{
			if(a[j][i] != key)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			break;
	}
	return flag;
}

bool isGameOver(vector<vector<char> >& a, char key)
{
	return (mainDiagDone(a, key) || secondDiagDone(a, key) || rowDone(a, key) || colDone(a, key));
}

bool isGameDrawn(vector<vector<char> >& a)
{
	int i, j, n = a.size();
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(a[i][j] == '-')
				return false;
		}
	}
	return true;
}

int main()
{
	int n = 3;
	vector<vector<char> > board(n, vector<char> (n, '-'));
	int i, j, pos;
	int turn = 0;		//0 indicates player 1's turn, 1 indicates player 2's turn
	cout<<"\n\n\t\t\t\tGet ready, game about to start...\n\n";
	while(1)
	{
		cout<<"\nCurrent status of board:\n";
		displayBoard(board);
		
		while(1)
		{
			cout<<"\nPlayer "<<turn+1<<"'s turn. Choose your square: ";
			cin>>pos;
			
			if(cin.fail())
			{
				cout<<"\nPlease enter an integer value!!\n";
				cin.clear();
				cin.ignore(1,'\n');
				continue;
			}
			
			if(pos < 1 || pos > 9)
			{
				cout<<"\nInvalid square!! Choose a proper square\n";
				continue;
			}		
			
			//Getting the array index
			pos--;
			i = pos/n;
			j = pos%n;
			
			if(board[i][j] != '-')
			{
				cout<<"\nSquare already filled!! Choose a proper square\n";
				continue;
			}	
			break;		
		}
		
		board[i][j] = (turn ? '0' : 'X');
		
		if(isGameOver(board, board[i][j]))
		{
			cout<<"\nFinal status of board:\n";
			displayBoard(board);
			
			cout<<"\n\n\t\tPlayer "<<turn+1<<" wins!!!!!\n\n";
			break;
		}
		else if(isGameDrawn(board))
		{
			cout<<"\nFinal status of board:\n";
			displayBoard(board);
			
			cout<<"\n\n\t\tThe Game ends in a draw!!!!\n\n";
			break;
		}
		
		turn = 1-turn;
	}
	system("pause");
	return 0;
}
