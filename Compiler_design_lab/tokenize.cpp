#include <bits/stdc++.h>
using namespace std;
unordered_set<string> keywords = {
    "int", "float", "double", "char", "if", "else", "for", "while", "return", "void", "break",
    "continue", "switch", "case"};
unordered_set<char> separators = {'(', ')', '{', '}', '[', ']', ',', ';'};
unordered_set<char> operators = {'+', '-', '*', '/', '=', '<', '>', '!', '%'};
bool isIdentifier(const string &str)
{

    if (str.empty())
        return false;
    if (!isalpha(str[0]) && str[0] != '_')
        return false;
    for (char ch : str)
    {
        if (!isalnum(ch) && ch != '_')
            return false;
    }
    return true;
}
void tokenize(const string &code)
{
    string token;
    int n = code.length();
    for (int i = 0; i < n; ++i)
    {
        char ch = code[i];
        if (isspace(ch))
            continue;
        if (separators.count(ch))
        {
            cout << "Separator: " << ch << endl;
            continue;
        }
        if (operators.count(ch))
        {
            // string op(1, ch);
            // if (i + 1 < n && (code[i + 1] == '='))
            // {
            //     op += '=';
            //     ++i;
            // }
            cout << "Operator: " << ch << endl;
            continue;
        }
        if (isdigit(ch))
        {

            string number;
            while (i < n && (isdigit(code[i]) || code[i] == '.'))
            {
                number += code[i++];
            }
            --i;
            cout << "Number: " << number << endl;
            continue;
        }
        if (isalpha(ch) || ch == '_')
        {
            string word;
            while (i < n && (isalnum(code[i]) || code[i] == '_'))
            {
                word += code[i++];
            }
            if (i < n && code[i] == '(')
            {
                cout << "Function Call: " << word << "()" << endl;
            }
            else if (keywords.count(word))
            {
                cout << "Keyword/Data type: " << word << endl;
                --i;
            }
            else if (isIdentifier(word))
            {
                cout << "Identifier Type: Name: " << word << endl;
                --i;
            }
            continue;
        }
    }
}
int main()
{
    string code;
    getline(cin, code);
    tokenize(code);
    return 0;
}