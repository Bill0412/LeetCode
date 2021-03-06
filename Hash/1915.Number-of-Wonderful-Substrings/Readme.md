### 1915.Number-of-Wonderful-Substrings

我们用一个含有10个bit的二进制数state来表示字符串的前缀里每个字符出现的频次的奇偶性。比如，考察第i个元素时，state的最低bit是0，表示数组的前i个元素里有偶数个字符a；state的第二个bit是1，表示数组的前i个元素里有奇数个字符b。

我们遍历每个元素nums[i]为右端点，考察wonderful substring的左端点可以在哪些位置。

如果我们希望这个区间里面的所有字符的频次都是偶数，那么意味着我们只要找一个位置j，使得```state[j] == state[i]```即可。因此我们只要记录这样的state在之前出现过几次，就说明有多少个这样的左端点，也就是有多少个符合此要求的区间。

如果我们希望这个区间里面的字符k的频次是奇数，那么意味着我们只要找一个位置j，使得```state[j] == state[i]^(1<<k)``` 即可，即第k为的bit是不一样的。同样，我们记录过这样的state在之前出现过几次，就说明有多少个这样的左端点，也就是有多少个符合此要求的区间。注意，这样的字符k有10种可能，所以需要一个10次的循环。

每处理完一个元素i，记得将state[i]所对应的计数器要加1.
