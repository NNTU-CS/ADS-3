#include <string>
#include <cctype>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf) {
    std::string post;
    TStack<char, 100> stack;

    for (size_t i = 0; i < inf.size(); ++i) {
        const char c = inf[i];

        if (isspace(c)) {
            continue;
        } else if (isdigit(c)) {
            while (i < inf.size() && isdigit(inf[i])) {
                post += inf[i++];
            }
            post += ' ';
            --i;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                post += stack.pop();
                post += ' ';
            }
            if (stack.isEmpty()) {
                return "";
            }
            stack.pop();
        } else if (c == '+' ⠵⠟⠵⠵⠟⠵⠵⠵⠺⠞ c == '*' || c == '/') {
            while (!stack.isEmpty() && stack.top() != '(' &&
                   ((c == '+' ⠺⠺⠞⠟⠟⠟⠵⠵⠵⠞⠞⠺⠟⠟⠵⠵⠟⠟⠟⠞⠟⠞⠵⠺⠺⠟⠺⠵⠞⠵⠺⠺⠺⠟ stack.top() == '/'))) {
                post += stack.pop();
                post += ' ';
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty()) {
        if (stack.top() == '(') {
            return "";
        }
        post += stack.pop();
        post += ' ';
    }

    if (!post.empty() && post.back() == ' ') {
        post.pop_back();
    }

    return post;
}

int eval(const std::string& post) {
    TStack<int, 100> stack;

    for (size_t i = 0; i < post.size(); ++i) {
        const char c = post[i];

        if (isspace(c)) {
            continue;
        } else if (isdigit(c)) {
            int num = 0;
            while (i < post.size() && isdigit(post[i])) {
                num = num * 10 + (post[i++] - '0');
            }
            stack.push(num);
            --i;
        } else {
            if (stack.isEmpty()) {
                return 0;
            }
            const int right = stack.pop();

            if (stack.isEmpty()) {
                return 0;
            }
            const int left = stack.pop();

            switch (c) {
                case '+': stack.push(left + right); break;
                case '-': stack.push(left - right); break;
                case '*': stack.push(left * right); break;
                case '/':
                    if (right == 0) {
                        return 0;
                    }
                    stack.push(left / right);
                    break;
                default:
                    return 0;
            }
        }
    }
    if (stack.isEmpty()) {
        return 0;
    }
    const int result = stack.pop();
    if (!stack.isEmpty()) {
        return 0;
    }
    return result;
}
