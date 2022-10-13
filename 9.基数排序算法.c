//伪代码：

// //基数排序算法，array 为待排序序列
// radixSort(array):
//     max = getMax(array)   // 查找 array 序列中的最大值
//     place <- 1            // 默认从个位开始排序
//     while max/place > 0 : // 将最大值的位数作为循环次数
//         countingSort(array, place)  // 调用计数排序算法，根据所选数位对各个元素进行排序
//         place = place * 10

// //计数排序算法，array 为待排序序列，place 指排序所依照的数位
// countingSort(array, place)
//     size <- len(array)       // 获取 array 序列中的元素个数
//     // 根据 place，找到相应数位值最大的元素
//     max <- (array[0] / place) % 10    
//     for i <- 1 to size:
//         if (array[i] / place) % 10 > max：
//             max <- array[i]
//     // 创建 count[max+1]，统计各个元素的出现次数
//     for j <- 0 to size     
//         count[(array[i] / place) % 10] <- count[(array[i] / place) % 10] + 1
//     // 对 count[max+1] 存储的元素做累加操作
//     for i <- 1 to max
//         count[i] <- count[i] + count[i - 1];
//     // 根据 count[max+1] 中的累加值，找到各个元素排序后的具体位置
//     for j <- size down to 0
//         output[count[(array[i] / place) % 10] - 1] <- array[i];
//         // 确定一个元素的位置后，count[max+1] 中相应位置的数值要减 1
//         count[(array[i] / place) % 10] <- count[(array[i] / place) % 10] - 1 
//     return output[size]
// C语言代码
