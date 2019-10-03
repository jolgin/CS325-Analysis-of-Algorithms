//
//  Created by John Olgin on 7/29/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
using namespace std;

class Graph
{
    int V;
    vector< vector<int> > edgeList;
    vector<unsigned char> visited;
public:
    
    Graph(int V)
    {
        this->V = V;
        edgeList.resize(V);
        visited.resize(V);
    }
    
    void add_edge(int v,int w)
    {
        edgeList[v].push_back(w);
        edgeList[w].push_back(v);
    }
    
    int *BFS(int s)
    {
        /*this array will hold the distances for each vertex*/
        int distanceArray[100][100];
        
        /*This initializes all vertices as unvisited*/
        for(int i; i < V; i++) {
            visited[i] = false;
            distanceArray[i][0] = 0;
        }
        
        
        list<int> q;
        
        /*choose the first vertex and set it to visited and enqueue it*/
        visited[s] = true;
        q.push_back(s);
        
        
        /*until the queue is empty take the front of the queue and determine if its rivals have been visited*/
        while (!q.empty())
        {
            s = q.front();
            q.pop_front();
            int size = edgeList[s].size();
            for(int i = 0; i < size; i++)
            {
                int newInt = i;
                distanceArray[newInt][0]++;
                
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push_back(i);
                }
            }
        }
        
        /*this array holds the distances of each vertex to determine which type of wrestler they are*/
        int holdArray[100];
        for(int i = 0; i < V; i++)
        {
            holdArray[i] = distanceArray[i][0];
        }
        
        return holdArray;
    }
    
};

int main()
{
    // Create a graph given in the above diagram
    ifstream file("wrestler1.txt");
    
    string nameListArray[1000];
    int stringReference[1000];
    int nameListSize;
    
    file >> nameListSize;
    Graph g(nameListSize);
    
    /*read in the names of the wrestlers*/
    for(int i = 0; i < nameListSize; i++)
    {
        file >> nameListArray[i];
        stringReference[i] = i;
    }
    
    /*read in the number of rivalries that exist*/
    int rivalryListSize;
    file >> rivalryListSize;
    
    
    /*read in the names of the wrestlers in pairs of rivalries*/
    for(int i = 0; i < rivalryListSize; i++)
    {
        string rivalryName1;
        string rivalryName2;
        int name1Ref, name2Ref;
        
        file >> rivalryName1;
        file >> rivalryName2;
        
        
        for(int i = 0; i < nameListSize; i++){
            if (nameListArray[i] == rivalryName1){
                name1Ref = i;
            }
            if (nameListArray[i] == rivalryName2){
                name2Ref = i;
            }
        }
        
        /*add an edge as a rivalry*/
        g.add_edge(name1Ref, name2Ref);
    }
    
    
   
    int *newArray = g.BFS(0);
    
    for(int i = 0; i < nameListSize; i++)
    {
        if(newArray[i] % 2 == 0)
        {
            cout << nameListArray[i] << " is a Babyface" << endl;
        }
        else
        {
            cout << nameListArray[i] << " is a Heel" << endl;
        }
    }
    
    return 0;

}
