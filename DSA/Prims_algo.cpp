#include <iostream>
#include <string.h>

using namespace std;

class Graph
{
    char Vnames[10][10];
    int cost[10][10], n;

public:
    Graph();
    void creat_graph();
    void display();
    int Position(char[]);
    void prims();
};

Graph::Graph()
{
    n = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cost[i][j] = 999;
        }
    }
}

void Graph::creat_graph()
{
    char ans, Start[10], End[10];
    int wt, i, j;

    cout << "Enter number of nodes";
    cin >> n;

    cout << "\n Enter vertex name:";
    for (i = 0; i < n; i++)
    {
        cin >> Vnames[i];
    }

    do
    {
        cout << "\nEnter Start and end point of edge : ";
        cin >> Start >> End;

        cout << "Enter weight : ";
        cin >> wt;

        i = Position(Start);
        j = Position(End);
        cost[i][j] = cost[j][i] = wt;

        cout << "\nDo you wnat to add more Edges? (y/n) : ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
void Graph::display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        cout << "\n";
        for (j = 0; j < n; j++)
        {
            cout << "\t" << cost[i][j];
        }
    }
}

int Graph::Position(char key[10])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(Vnames[i], key) == 0)
        {
            return i;
        }
    }
    return -1;
}

void Graph::prims()
{
    int cnt = 1, b, i, j, x, y, Total_cost = 0, min, visit[10] = {0};
    char start[10];

    cout << "\n Starting node=";
    cin >> start;

    x = Position(start);
    visit[x] = 1;

    while (cnt < n)
    {
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (visit[i] == 1)
            {
                for (j = 0; j < n; j++) // find minimum from adjacent
                {
                    if (cost[i][j] < min && visit[j] == 0) // not visited
                    {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    } // end of if
                }     // end of inner for
            }         // end of if
        }             // end of outer for
        // outer for find minmum from all adjacent that are visited

        cout << "\n" << Vnames[x] << " - " << Vnames[y] << " : " << min;
        Total_cost = Total_cost + min;
        cost[x][y] = cost[y][x] = 999;
        visit[y] = 1;
        cnt++;
    } // end of while
    cout << "\nTotal cost of tree=>" << Total_cost;
} // end of prims()

int main()
{
    Graph G1;
    G1.creat_graph();
    G1.display();
    G1.prims();
}