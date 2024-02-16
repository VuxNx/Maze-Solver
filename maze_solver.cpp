#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> findDead(vector<vector<int>> grid)
{
    vector<vector<int>> dead;
    if (grid.size() == 0)
        {
            return dead;
        }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i > 0 && i < grid.size() - 1 && j > 0 && j < grid[0].size() - 1 && grid[i][j] == 0)
             {
                if ((grid[i - 1][j] == 1 && grid[i + 1][j] == 1 && grid[i][j - 1] == 1)||(grid[i - 1][j] == 1 && grid[i + 1][j] == 1 &&grid[i][j+1]==1)||(grid[i][j-1]==1&&grid[i][j+1]==1&&grid[i-1][j]==1)||(grid[i][j-1]==1&&grid[i+1][j]==1&&grid[i][j+1]==1))
                    {
                      dead.push_back({i, j});
                    }
            }
        }
    }
    return dead;
}

bool checkSimilar(vector<vector<int>> a, vector<vector<int>> b)
{
    if (a.size() != b.size() || a[0].size() != b[0].size())
    {
        return false;
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int n;
    int num=0;
    vector<vector<int>>complete;
    cin>>n;
    vector<vector<int>>maze;
    maze.resize(n);
    for(int i=0;i<n;i++)
    {
        maze[i].resize(n);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }

    complete.resize(maze.size());
    for(int i=0;i<maze.size();i++)
    {
        complete[i].resize(maze.size());
        for(int j=0;j<maze.size();j++)
        {
            complete[i][j] = maze[i][j];
        }
    }

    vector<vector<int>>dead=findDead(maze);
    for (int i=0;i<dead.size();i++)
    {
        maze[dead[i][0]][dead[i][1]]=1;
    }

    while (!checkSimilar(maze, complete))
    {
        complete = maze;
        dead = findDead(maze);
        for (int i=0;i<dead.size();i++)
        {
            maze[dead[i][0]][dead[i][1]]=1;
        }
    }
    cout<<endl;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

