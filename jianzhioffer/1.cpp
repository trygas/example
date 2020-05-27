#include "general.h"

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator=(const CMyString& str)
    {
        // 在这个代码中, 我们在CMyString的构造哈那是中用new分配内存
        // 如果这个时候由于内存不足抛出注入bad_alloc等异常, 但是我们还没有修改原来实例的状态
        // 这就保证了异常安全性.
        if(this != &str){
            CMyString temp(str);

            char* m_temp = temp.m_pData;
            temp.m_pData = m_pData;
            m_pData = m_temp;
        }

        return *this;
    }

/*
 * 这个没有保证异常安全性
    // 返回值的类型为该类型的引用, 这样才能允许连续赋值
    CMyString& operator = (const CMyString& str)
    {
        // 判断传入的参数和当前的实例是否一致
        if(this == &str)
            return *this;

        // 要删除本来的内存
        delete []m_pData;
        m_pData = nullptr;

        // 在这一行里面我们会分配一些内存, 但是如果内存不够则会导致new char抛出异常
        // 这样m_pData在之前已经删除了原来的指针, 所以将是一个空指针
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);

        return *this;
    }
*/

private:
    char* m_pData;
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}