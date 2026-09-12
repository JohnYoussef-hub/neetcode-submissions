class Solution {
public:
    bool isValid(string s) {

    if (s.empty()) return true;
    if (s.length() == 1 || s.length() % 2 != 0) return false;

    stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            stack.push(c);

        else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) return false;
            char top = stack.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                stack.pop();
            }
            else
                return false;
        }
        else return false;
            
        }

    return stack.empty();
}
};
