### 032.Longest-Valid-Parentheses

此题用stack来做非常巧妙.

我们考虑用一个stack来做常规的符号匹配，即
1. 遇到左括号入栈；
2. 遇到右括号，尝试用它对消栈顶的左括号，使其退栈（如果有的话）。否则的话我们就将右括号入栈。

由此，if possible，我们可以为每一个右括号i，寻找与之匹配的左括号j的位置（即离它左边最近的、可以匹配的左括号）。并且我们可以确定，[j:i]这对括号内的字符肯定也是已经正确匹配了的。

但是[j:i]就一定是以i结尾的最长的合法字串了吗？不一定。此时观察，将栈顶元素j退栈“对消”之后，此时新的栈顶元素对应的位置并不一定是与j相邻的。中间这段“空隙”意味着什么呢？对，这段“空隙”是之前已经退栈了的其他合法字符串。所以我们可以在区间[j:i]的左边再加上这段长度。因此，真正的“以j结尾的最长的合法字串”的长度是```i - Stack.top()```。注意stack存放的是所有字符的index。

[Leetcode Link](https://leetcode.com/problems/longest-valid-parentheses)
