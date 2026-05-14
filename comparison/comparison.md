# Comparison Between Algorithms

| Comparison Point | Non-Recursive Algorithm | Recursive Algorithm |
|---|---|---|
| Algorithm Type | Iterative | Recursive |
| Design Technique | Merge-like traversal | Divide and Conquer |
| Main Idea | Uses two pointers to move step by step through the two sorted arrays until reaching the k-th element | Removes a group of elements during each recursive call to reduce the search space |
| Data Structure Used | Arrays with two pointers | Arrays with recursive calls and index shifting |
| Extra Storage | No extra array is created | No extra array is created |
| Main Operations | Comparisons, pointer movement, and counting | Recursive calls, comparisons, and index updates |
| Stops When | The counter reaches k | k becomes 1 or one array is exhausted |
| Time Complexity | O(k) | O(log k) |
| Worst Case Time Complexity | O(n + m) | O(log k) |
| Space Complexity | O(1) | O(log k) |
| Reason for Space Complexity | Uses only simple variables such as i, j, count, and current | Uses recursion stack memory |
| Ease of Understanding | Easier to understand and trace | More difficult because of recursion |
| Ease of Implementation | Easier to implement and debug | More complex because of recursive calls and index handling |
| Performance on Small Inputs | Good performance | Good performance |
| Performance on Large Inputs | Slower when k is large | Faster because it reduces the search space |
| Risk of Errors | Lower risk of implementation errors | Higher risk because of recursion and boundary conditions |
| Best Use Case | Educational purposes and small inputs | Large inputs and performance-critical applications |

---

# Conclusion

The non-recursive algorithm is simple and easy to understand because it uses a direct iterative merge-like approach with two pointers.

The recursive algorithm is more efficient because it applies the divide and conquer technique to reduce the search space during each recursive call.

Although the recursive algorithm uses additional memory because of the recursion stack, it achieves significantly better performance for large inputs.

Therefore:

- The non-recursive algorithm is preferred for simplicity and easier implementation.
- The recursive algorithm is preferred for better performance and scalability.
