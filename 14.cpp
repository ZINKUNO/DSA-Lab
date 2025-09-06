#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string line;
    cout << "Postfix expression: ";
    getline(cin, line);
    

    stack<int> st;
    string tok;

    for (int i = 0; i <= line.size(); i++)
    {
        if (i == line.size() || line[i] == ' ')
        {
            if (!tok.empty())
            {
                if (isdigit(tok[0]))
                {
                    st.push(stoi(tok));
                }
                else
                {
                    if (st.size() < 2)
                    {
                        cerr << "Not enough operands"<<endl;
                        return 1;
                    }
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    switch (tok[0])
                    {
                    case '+':
                        st.push(a + b);
                        break;
                    case '-':
                        st.push(a - b);
                        break;
                    case '*':
                        st.push(a * b);
                        break;
                    case '/':
                        st.push(a / b);
                        break;
                    default:
                        cerr << "Bad op\n";
                        return 1;
                    }
                }
                tok.clear(); // reset for next token
            }
        }
        else
        {
            tok += line[i]; // like for 10,123,45889 
        }
    }

    if (st.empty())
    {
        cerr << "Empty expression"<<endl;
        return 1;
    }
    cout << "Result = " << st.top() << endl;
    return 0;
}
