题目：线段树是一棵二叉树，他的每个节点包含了两个额外的属性start和end用于表示该节点所代表的区间。start和end都是整数，并按照如下的方式赋值:
   
   根节点的 start 和 end 由 build 方法所给出。
   对于节点 A 的左儿子，有 start=A.left, end=(A.left + A.right) / 2。
   对于节点 A 的右儿子，有 start=(A.left + A.right) / 2 + 1, end=A.right。
   如果 start 等于 end, 那么该节点是叶子节点，不再有左右儿子。
   
思路：就是递归。