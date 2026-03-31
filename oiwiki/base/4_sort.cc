#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>

// 设计一个计数器，计算函数运行的时间
class SortTimer {
    std::string function_name;
    std::chrono::high_resolution_clock::time_point start_time;

    long long duration;

    bool sorted = false;
    bool checker(const std::vector<int> &arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false; // 如果发现一个元素比前一个小，说明数组未排序
            }
        }
        return true; // 数组已排序
    }

public:
    SortTimer(void (*func)(std::vector<int> &), std::string func_name, std::vector<int> arr)
        : function_name(func_name),
          start_time(std::chrono::high_resolution_clock::now()) {
        func(arr);             // 调用函数
        sorted = checker(arr); // 检查排序结果
    }

    ~SortTimer() {
        auto end_time = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cout << "Function " << function_name << " execution time: " << duration << " ms." << " Array sorted: " << (sorted ? "Yes" : "No") << std::endl;
    }

    long long get_duration() const {
        return duration;
    }
};

void random_fill(std::vector<int> &arr, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr.push_back(rand() % n);
    }
}

void selection_sort(std::vector<int> &arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

void bubble_sort(std::vector<int> &arr) {
    size_t n = arr.size();
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (size_t i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
    }
}

void insertion_sort(std::vector<int> &arr) {
    size_t n = arr.size();
    for (size_t i = 1; i < n; ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

void count_sort(std::vector<int> &arr) {
    int max_val = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count(max_val + 1, 0);
    for (int num : arr) {
        ++count[num];
    }
    size_t index = 0;
    for (size_t i = 0; i < count.size(); ++i) {
        while (count[i]-- > 0) {
            arr[index++] = i;
        }
    }
}

void radix_sort(std::vector<int> &arr) {
    int max_val = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        std::vector<int> output(arr.size());
        std::vector<int> count(10, 0);
        for (int num : arr) {
            ++count[(num / exp) % 10];
        }
        for (size_t i = 1; i < count.size(); ++i) {
            count[i] += count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; --i) {
            output[--count[(arr[i] / exp) % 10]] = arr[i];
        }
        arr = output;
    }
}

void quick_sort(std::vector<int> &arr) {
    auto dfs = [&](this auto &&dfs, int left, int right) -> void {
        if (left >= right)
            return;
        int pivot = arr[left + right >> 1];
        int i = left - 1, j = right + 1;
        while (i < j) {
            while (arr[++i] < pivot)
                ;
            while (arr[--j] > pivot)
                ;
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        dfs(left, j);
        dfs(j + 1, right);
    };
    dfs(0, arr.size() - 1);
}

void merge_sort(std::vector<int> &arr) {
    auto dfs = [&](this auto &&dfs, int left, int right) -> void {
        if (left >= right)
            return;
        int mid = left + right >> 1;
        dfs(left, mid);
        dfs(mid + 1, right);
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        for (int i = 0; i < temp.size(); ++i) {
            arr[left + i] = temp[i];
        }
    };
    dfs(0, arr.size() - 1);
}

void heap_sort(std::vector<int> &arr) {
    auto heapify = [&](this auto &&heapify, int n, int i) -> void {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(n, largest);
        }
    };
    auto up = [&](this auto &&up, int n, int i) -> void {
        if (i == 0)
            return;
        int parent = (i - 1) / 2;
        if (arr[parent] < arr[i]) {
            std::swap(arr[parent], arr[i]);
            up(n, parent);
        }
    };
    int n = arr.size();
    // for (int i = n / 2 - 1; i >= 0; --i) {
    //     heapify(n, i);
    // }
    for (int i = 1; i < n; ++i) {
        up(n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

void bucket_sort(std::vector<int> &arr) {
    int bucket_size = 10; // 桶的大小
    int max_val = *std::max_element(arr.begin(), arr.end());
    std::vector<std::vector<int>> buckets(max_val + 1);
    for (int num : arr) {
        buckets[num / bucket_size].push_back(num);
    }
    size_t index = 0;
    for (auto &bucket : buckets) {
        if (!bucket.empty()) {
            std::sort(bucket.begin(), bucket.end());
            for (int num : bucket) {
                arr[index++] = num;
            }
        }
    }
}

void shell_sort(std::vector<int> &arr) {
    size_t n = arr.size();
    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; ++i) {
            int temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {

    std::vector<int> arr;
    random_fill(arr, 100'000); // 填充数组

    if (arr.size() <= 50'000) {
        // n^2 复杂度的排序算法
        {
            SortTimer timer(selection_sort, "Selection Sort", arr);
        }

        {
            SortTimer timer(bubble_sort, "Bubble Sort", arr);
        }

        {
            SortTimer timer(insertion_sort, "Insertion Sort", arr);
        }
    }

    if (arr.size() <= 1'000'000) {
        // nlogn 复杂度的排序算法
        {
            SortTimer timer(quick_sort, "Quick Sort", arr);
        }

        {
            SortTimer timer(merge_sort, "Merge Sort", arr);
        }

        {
            SortTimer timer(heap_sort, "Heap Sort", arr);
        }
    }

    {
        SortTimer timer(bucket_sort, "Bucket Sort", arr);
    }

    {
        SortTimer timer(shell_sort, "Shell Sort", arr);
    }

    // 线性时间复杂度的排序算法
    {
        SortTimer timer(count_sort, "Count Sort", arr);
    }

    {
        SortTimer timer(radix_sort, "Radix Sort", arr);
    }

    return 0;
}