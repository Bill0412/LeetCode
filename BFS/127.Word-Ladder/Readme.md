### 127.Word-Ladder

典型的BFS求最短路径。为了更高效地遍历，我们需要提前构建好graph，即节点与节点之间的边关系。对于任意两个单词，我们判定是否可以通过transform进行转化，可以的话就说明有这两个单词的联通关系。这个时间复杂度是o(N^2)。

也有其他的方法构建边。对于一个单词，我们对它每个字母尝试变更为其他字母，看看变更后这个新单词是否是集合中已有的其他单词。这个时间复杂度是```O(N*5*26)```.
