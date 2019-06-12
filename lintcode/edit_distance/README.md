题目：给出两个单词word1和word2，计算出将word1 转换为word2的最少操作次数。

   你总共三种操作方法：

   插入一个字符
   删除一个字符
   替换一个字符

$思路：用lev_{a,b}(i,j)来表示a和b的Leveinshtein距离(i和j分别代表a和b的长度)，则：$

$当min(i,j)=0时，leva,b(i,j)=max(i,j)，一个字符串的长度为0，编辑距离自然是另一个字符串的长度$

$当ai=bj时，leva,b(i,j)=leva,b(i−1,j−1)，比如xxcz和xyz的距离=xxc和xy的距离$
$否则，lev_{a,b}(i,j)为如下三项的最小值： $

$lev_{a,b}(i−1,j)+1(删除ai)，比如xxc和xyz的距离=xx和xyz的距离+1$
$lev_{a,b}(i,j−1)+1(插入bj)，比如xxc和xyz的距离=xxcz和xyz的距离+1=xxc和xy的距离+1$
$lev_{a,b}(i−1,j−1)+1(替换bj)，比如xxc和xyz的距离=xxz和xyz的距离+1=xx和xy的距离+1$

