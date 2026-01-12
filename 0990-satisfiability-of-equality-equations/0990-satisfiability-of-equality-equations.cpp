class Solution
{
    vector<bool> visited;
    vector<int> color;
    vector<vector<int>> adj;
    
public:
    void dfsVisit(int u, int colorNumber);
    bool equationsPossible(vector<string>& equations);
};

/* Performs the dfs and assigns the same colorNumber to each element in the connected component */
void Solution :: dfsVisit(int u, int colorNumber)
{
    // Visit this vertex and assign the same color number as its parent
    visited[u] = true;
    color[u] = colorNumber;
    
    // Traverse the adjaceny list and perform dfs on each element with the same color number
    for(auto v : adj[u])
        if(!visited[v]) dfsVisit(v,colorNumber);
}

/* Returns true if the equation is possible */
bool Solution :: equationsPossible(vector<string>& equations)
{
    // The number of nodes in the graph
    int alphabetSize = 26;
    
    // Resize the adjacency list, visited vector and color vector vector according to number of nodes
    adj.resize(alphabetSize);
    color.resize(alphabetSize);
    visited.resize(alphabetSize);
    
    // Traverse the vector of queries and focus on all the equality relations
    for(auto str: equations)
    {
        // If they are equal, then add an undirected edge between them
        if(str[1]=='=')
        {
            // Extract the letter
            char firstLetter  = str[0];
            char secondLetter = str[3];
            
            // Add undirected edge, since a==b implies b==a.There might be multi edges, but dfs would still work.
            adj[firstLetter-'a'].push_back(secondLetter-'a');
            adj[secondLetter-'a'].push_back(firstLetter-'a');
        }
    }
    
    // Assign same colours to each node in the same connected component
    // Use one color for ecah connected component
    int colorNumber = 0;
    for(int u=0; u<alphabetSize; u++)
    {
        // Visit the vertex if not already visited
        if(!visited[u]) dfsVisit(u,colorNumber);
        
        // Note that after it comes out of the if condition, all vertices in same c-component have been coloured.
        // Preapare a different colur for the next connnected component
        colorNumber ++;
    }
    
    // Traverse the query vector and check the inequality conditons violate equality conditions
    for(auto str : equations)
    {
        // Only check the inequality conditions
        if(str[1]=='!')
        {
            // Extract the letter
            char firstLetter  = str[0];
            char secondLetter = str[3];
            
            // Since, they are unequal, their color must be different
            if(color[firstLetter-'a'] == color[secondLetter-'a']) return false;
        }
    }
    
    // If it reaches here, it means no inequality violation happens.
    // It means we can satisfy the equation by assigning the colorNumber to each node
    return true;
}