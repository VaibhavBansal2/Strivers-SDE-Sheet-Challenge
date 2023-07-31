class Solution
{
public:
    string countAndSay(int &n)
    {
        if (n == 1)
            return "1";
        string ans = "1";
        for (int i = 1; i < n; i++)
        {
            string temp = "";
            int j = 0;
            while (j < ans.size())
            {
                int count = 0;
                char c = ans[j];
                while (ans[j] == c)
                    count++, j++;
                temp += to_string(count);
                temp += c;
            }
            ans = temp;
        }
        return ans;
    }
};