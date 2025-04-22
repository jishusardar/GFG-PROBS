<h2><a href="https://www.geeksforgeeks.org/problems/merge-two-bst-s/1?page=1&difficulty%5B%5D=2&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions">Merge two BST 's</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two BSTs, return elements of merged BSTs in <strong>sorted </strong>form.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root1 = [</span>5, 3, 6, 2, 4]<br><span style="font-size: 18px;">       5
&nbsp;    /   \
&nbsp;   3     6
&nbsp;  / \
&nbsp; 2   4 <br></span><span style="font-size: 18px;">root2 = [</span>2, 1, 3, N, N, N, 7, 6, N<span style="font-size: 18px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">]</span><br><span style="font-size: 18px;"><strong>&nbsp;       </strong>2
&nbsp;     /   \
&nbsp;    1     3
&nbsp;           \
&nbsp;            7
&nbsp;           /
&nbsp;          6
<strong>Output: </strong>[1, 2, 2, 3, 3, 4, 5, 6, 6, 7]<strong>
Explanation: </strong>After merging and sorting the two BST we get [1, 2, 2, 3, 3, 4, 5, 6, 6, 7]</span>.</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root1 = [12, 9, N, 6, 11]<strong>
&nbsp;      </strong>12
&nbsp;    /   
&nbsp;   9
&nbsp;  / \ &nbsp;  
&nbsp; 6   11
root2 = [8, 5, 10, 2]<strong>
&nbsp;     </strong>8
&nbsp;   /  \
&nbsp;  5    10
&nbsp; /
&nbsp;2
<strong>Output: </strong>[2, 5, 6, 8, 9, 10, 11, 12]<strong>
Explanation: </strong>After merging and sorting the two BST we get [2, 5, 6, 8, 9, 10, 11, 12]</span>.</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ number of nodes, root-&gt;data ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;