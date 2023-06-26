bool isValidParenthesis(string &s)
{
    stack<char> st;
    for (auto i : s)
        if (i == '(' || i == '{' || i == '[')
            st.push(i);
        else if (st.empty())
            return false;
        else
            switch (i)
            {
            case ')':
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
                break;
            case '}':
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
                break;
            case ']':
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
    if (st.empty())
        return true;
    return false;
}