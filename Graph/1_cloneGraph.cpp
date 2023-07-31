#include <bits/stdc++.h>
/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
            data = 0;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
            data = val;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
            data = val;
            this->neighbours = neighbours;
        }
    };

******************************************************************************/

graphNode *cloneGraph(graphNode *&node)
{
    if (!node)
        return node;
    graphNode *ans = new graphNode(node->data);
    unordered_map<int, graphNode *> ump;
    ump[node->data] = ans;
    queue<pair<graphNode *, graphNode *>> q;
    q.push({node, ans});
    while (!q.empty())
    {
        graphNode *og = q.front().first, *copy = q.front().second;
        q.pop();
        for (auto &i : og->neighbours)
            if (ump.find(i->data) != ump.end())
                copy->neighbours.push_back(ump[i->data]);
            else
            {
                graphNode *temp = new graphNode(i->data);
                copy->neighbours.push_back(temp);
                q.push({i, temp});
                ump[i->data] = temp;
            }
    }
    return ans;
}