class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string current = "";
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(num);
                strStack.push(current);
                num = 0;
                current = "";
            } else if (c == ']') {
                int repeat = numStack.top(); numStack.pop();
                string temp = current;
                for (int i = 1; i < repeat; i++) current += temp;
                current = strStack.top() + current; strStack.pop();
            } else {
                current += c;
            }
        }
        return current;
    }
};
