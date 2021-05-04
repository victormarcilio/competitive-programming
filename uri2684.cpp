#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

char html[300];

vector<string> stk;

void parse1(char *c)
{
    int opened = 0;
    while (*c)
    {
        if (*c == '<')
        {
            opened++;
            if (opened > 1)
                throw 1;
        }
        else if (*c == '>')
        {
            opened--;
            if (opened < 0)
                throw 1;
        }
        c++;
    }
    if (opened)
        throw 1;
}
void parse0(char *c)
{
    if (!*c)
    {
        if(!stk.empty())
            throw 1;
        return;
    }
    if (*c == '<')
    {
        string temp;
        bool closing = false;
        if (*(c + 1) == '/')
        {
            closing = true;
            c++;
        }
        c++;
        while (*c != ' ' && *c != '>')
        {
            temp += *c;
            c++;
        }
        if (closing)
            if ((stk.empty() || stk.back() != temp))
                throw 1;
            else
                stk.pop_back();
        else
            stk.push_back(temp);
        if (*c == ' ')
            while (*c != '>')
                c++;
        c++;
        parse0(c);
    }
    else
        parse0(c + 1);
}
int main()
{

#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, op;
    string text;
    scanf("%d", &n);
    while (n--)
    {
        stk.clear();
        scanf("%d %[^\n]", &op, html);
        try
        {
            parse1(html);
            if (op == 1)
            {
                if (strstr(html, "</"))
                    throw 1;                
            }
            else     
                parse0(html);            
            printf("Successful !!\n");            
        }
        catch (int x)
        {
            printf("error\n");
        }
    }
}
