题目：给出一个二维的字母板和一个单词，寻找字母板网格中是否存在这个单词。
   
   单词可以由按顺序的相邻单元的字母组成，其中相邻单元指的是水平或者垂直方向相邻。每个单元中的字母最多只能使用一次。
   
思路：递归寻找上下左右是否有相似的字符，并且如果寻找过的字符还需要将它视为已经经过。