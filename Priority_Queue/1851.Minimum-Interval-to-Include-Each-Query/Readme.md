### 1851.Minimum-Interval-to-Include-Each-Query

对于offline querying的问题，我们首先想到是否可以调整query的顺序来使得问题简化。

对于一个query的时刻q，我们要找到所有区间包括q的events。为了每一个q而筛选一遍所有的events是低效的，使得时间复杂度达到了O(QN). 我们的目标是随着q的遍历，只需对考察的events集合进行增补（引进新的、舍弃旧的），使得events的总遍历是线性时间。

我们想象，对于时刻q，符合题意的events肯定要求startTime必须早于q。有一种想法是：将这些events放入一个以endTime排序的小顶堆里，这样可以弹出那些endTime小于q的时间。剩下PQ里的事件都是在时间上符合要求的。我们为此对于需要同步构造一个multiset，它的元素完全同步于优先队列的元素的进出，但是内部是按照duration排序。这样当PQ里的events都符合时间要求时，multiset里面的第一个元素就是针对这个query的、符合时间要求的最小duration。

但是本题还有一个更巧妙的思想。我们将所有startTime早于q的events放入一个PQ，每个event包含两个属性：{duration, endTime}。我们贪心地看PQ顶端的events，它的duration一定是当前最小的，但是endTime不一定符合要求啊（即endTime<q）. 但是没有关系，不符合条件的就从PQ顶端弹出，直至PQ顶端的events的endTime符合要求，那么自然它的duration也是在符合条件的events里最小的。这其中隐含着一个考虑，那就是endTime不符合要求的events，对于更靠后的query肯定也不会符合要求，所以可以放心舍去。

本题的时间复杂度是o(NlogN)，其中N是事件的个数。因为每个event只会进入pool一次，出pool一次，每次插入/弹出都是logN的时间。这与query的数量没有关系。
