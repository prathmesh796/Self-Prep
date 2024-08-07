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
    void kru();
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

        cout << "\nDo you want to add more Edges? (y/n) : ";
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

void Graph::kru()
{
    int i, j, x, y, Total_cost = 0, min, gr = 1, flag = 0, temp, v[10] = {0};
    while (flag == 0)
    {
        min = 999;
        for (i = 0; i < n; i++) // find the minimum edge
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    x = i;
                    y = j;
                } // end of if
            }     // end inner for
        }         // end of outer for

        if (v[x] == 0 && v[y] == 0) // both are not visited
        {
            v[x] = v[y] = gr;
            gr++;
        }

        else if (v[x] != 0 && v[y] == 0)
        { 
            v[y] = v[x]; 
        }

        else if (v[x] == 0 && v[y] != 0) 
        {
            v[x] = v[y]; 
        }                
            
        else
        {
            if (v[x] != v[y]) // both belong to diffrent group
            {
                temp = v[x];
                for (i = 0; i < n; i++)
                {
                    if (v[i] == temp)
                    {
                        v[i] = v[y];
                    }
                } 
            }     
        }  
       
        cost[x][y] = cost[y][x] = 999;
        Total_cost = Total_cost + min;
        cout << "\n" << Vnames[x] << " - " << Vnames[y] << " : " << min;
        // print visit array after every step
        temp = v[0];
        flag = 1;
        
        for (i = 0; i < n; i++)
        {
            if (temp != v[i])
            {
                flag = 0;
                break;
            }
        } // end of inner for
    }     // end of while
    cout << "\nTotal cost of tree=" << Total_cost;
}

int main()
{
    Graph ob;
    ob.creat_graph();
    ob.display();
    ob.kru();
}