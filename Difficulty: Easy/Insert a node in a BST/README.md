<h2><a href="https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1">Insert a node in a BST</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a <strong>BST</strong>(Binary Search Tree)&nbsp;and a key <strong>key</strong>. If the key is not present in the BST, Insert a new node with a value equal to the key into the BST. If the key </span><span style="font-size: 18px;">is already present in the BST, don't modify the BST. R</span><span style="font-size: 18px;">eturn the root of the modified BST after inserting the key.&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Note:&nbsp;</strong>The generated output contains the in-order traversal of the modified tree.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>key = 4
&nbsp; &nbsp; &nbsp;2
&nbsp;  /&nbsp;&nbsp; \ &nbsp; <br>  1&nbsp;  &nbsp; 3
<strong>Output: </strong>1 2 3 4<strong>
Explanation: </strong>After inserting the node 4 Inorder traversal will be 1 2 3 4.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>key = 4
  &nbsp; &nbsp; &nbsp;&nbsp;2
&nbsp; &nbsp; &nbsp;&nbsp;/&nbsp;&nbsp; \
 &nbsp; &nbsp; 1 &nbsp; &nbsp; 3
 &nbsp;  &nbsp; &nbsp; &nbsp;   &nbsp;\
 &nbsp;  &nbsp;&nbsp; &nbsp; &nbsp;   &nbsp;6
<strong>Output: </strong>1 2 3 4 6<strong>
Explanation: </strong>After inserting the node 4 Inorder traversal of the above tree will be 1 2 3 4 6.<br></span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>key = 2
&nbsp; &nbsp; &nbsp;2
&nbsp;  /&nbsp;&nbsp; \ &nbsp; <br>  1&nbsp;  &nbsp; 3
<strong>Output: </strong>1 2 3 <strong>
Explanation:</strong> Node with key=2 already present in BST, Inorder traversal will be 1 2 3.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= number of nodes &lt;= 10<sup>5<br></sup></span><span style="font-size: 18px;">1 &lt;= node-&gt;data &lt;= 10<sup>9</sup></span><br><span style="font-size: 18px;">1 &lt;= key &lt;= 10<sup>9</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Design-Pattern</code>&nbsp;<code>Data Structures</code>&nbsp;