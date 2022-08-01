#10 000 numbers (T files)
| batch_size | BucketSort  | CountingSort | HeapSort    | OptimizedQuickSort | RadixSort   | ShellSort  |
| :----      | :----       | :----        | :----       | :----              | :----       | :----      |
| 32         | 19s 35.16ms | 19s 339.3ms  | 19s 36.24ms | 19s 150.6ms        | 19s 139.9ms | 19s 205ms  |
| 64         | 7s 60.99ms  | 7s 105.1ms   | 6s 958.6ms  | 7s 49.93ms         | 6s 918.8ms  | 6s 993.1ms |
| 128        | 2s 824.3ms  | 2s 867.6ms   | 2s 801.7ms  | 2s 825.5ms         | 2s 748.6ms  | 2s 857.6ms |
| 256        | 1s 271.8ms  | 1s 313.4ms   | 1s 289.6ms  | 1s 268ms           | 1s 242.5ms  | 1s 266ms   |
| 512        | 612.7ms     | 620.1ms      | 633.9ms     | 611.2ms            | 592ms       | 600.3ms    |
| 1024       | 311.9ms     | 310.8ms      | 306.6ms     | 315.6ms            | 301.7ms     | 312.1ms    |

#External Sort (2 Files)
|  Numbers      |  External Sort  |
| :----         |   :----         |
|  1000         |  1s 23.3ms      |
|  10000        | 1m 37s 453.7ms  |