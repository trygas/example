#include "general.h"

class accumulate_block
{
public:
    void operator()(double first, double last, double& result)
    {
        for (int i = first; i < last; ++i)
        {
            result += i;
        }
    }
};

double parallel_accumlate(double first, double last, double init)
{
    double const length = last - first;
    double const min_per_thread = 25;
    double const max_threads = (length + min_per_thread - 1) / min_per_thread;
    double const hardware_threads = thread::hardware_concurrency();
    double const num_threads = std::min(hardware_threads!=0?hardware_threads:2,max_threads);
    int const block_size = length / num_threads;

    vector<double > results(num_threads);
    vector<thread> threads(num_threads - 1);
    double block_start = first;

    for (int i = 0; i < num_threads - 1; ++i)
    {
        double block_end = block_start + block_size;
        threads[i] = thread(accumulate_block(), block_start, block_end, ref(results[i]));
        block_start = block_end;
    }

    //这里直接调用类中的函数.
    accumulate_block()(block_start, last, results[num_threads - 1]);
    // 等待每个线程完成,类似gpu的模型
    std::for_each(threads.begin(), threads.end(), mem_fn(&thread::join));

    return accumulate(results.begin(), results.end(), init);
}

int main()
{
    cout << parallel_accumlate(1, 1000, 0);
}