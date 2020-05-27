#include "general.h"

template<class T>
class QueueWithMax
{
public:
    QueueWithMax(): currentIndedex(0){}

    void push_back(T number)
    {
        while(!maximums.empty() && maximums.back().number <= number)
            maximums.pop_back();

        InternalData internalData = {number, currentIndedex};
        data.push_back(internalData);
        maximums.push_back(internalData);
        ++currentIndedex;
    }

    void pop_back()
    {
        if(maximums.empty()){
            return;
        }

        if(maximums.front().index == data.front().index)
            maximums.pop_front();
        data.pop_front;
    }

    T max() const
    {
        return maximums.front().number;
    }

private:
    struct InternalData
    {
        T number;
        int index;
    };

    deque<InternalData> data;
    deque<InternalData> maximums;
    int currentIndedex;
};