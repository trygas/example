//
// Created by liu on 18-8-19.
//

#ifndef LINTCODE_GENERAL_H
#define LINTCODE_GENERAL_H

#include <iostream>
#include <ostream>
#include <istream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>

typedef unsigned char       ubyte;
typedef unsigned short      ushort;
typedef unsigned int        uint;
typedef unsigned long long  ullong;

#ifndef PI
#define PI 3.141592654f
#endif

#ifndef PIx2
#define PIx2 6.283185308f
#endif

#ifndef MAX_NUM_THREADS
#define MAX_NUM_THREADS 8
#endif

#ifndef MAX_LINE_LENGTH
#define MAX_LINE_LENGTH 512
#endif

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Interval
{
public:
    Interval(int _start, int _end): start(_start), end(_end){}

    friend ostream& operator << (ostream &out, Interval& interval){
        out << interval.start << "   " << interval.end << endl;
        return out;
    }

    friend ostream& operator << (ostream &out, const Interval& interval){
        out << interval.start << "   " << interval.end << endl;
        return out;
    }

public:
    int start, end;
};

int RandomNumber(int start, int end)
{
    srand(time(nullptr));
    return random() % (end - start + 1) + start;
}

template <class T>
void PrintVector(const vector<T> &vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
}

template <class T, class K>
void PrintVectorPair(const vector<pair<T, K> > &vec)
{
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i].first << "   " << vec[i].second;
        cout << endl;
    }
}

template <class T>
void PrintVectorVector(const vector<vector<T> > &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << "[ ";
        PrintVector(vec[i]);
        cout << "]" << endl;
    }
}

template <class T>
bool FindMaxNumber(const vector<T> &data, T &max)
{
    if (data.size() == 0)
        return false;
    T max_number = data[0];

    for (int i = 1; i < data.size(); ++i)
    {
        if (max_number < data[i])
            max_number = data[i];
    }

    max = max_number;
    return true;
}

template <class T>
bool FindMinNumber(const vector<T> &data, T &min)
{
    if (data.size() == 0)
        return false;
    T min_number = data[0];

    for (int i = 1; i < data.size(); ++i)
    {
        if (min_number > data[i])
            min_number = data[i];
    }

    min = min_number;
    return true;
}

template <class T>
T Sum(const vector<T> &data)
{
    T sum_number = T();
    for(int i = 0; i < data.size(); ++i){
        sum_number += data[i];
    }

    return sum_number;
}

template <class T>
class TreeNode
{
public:
    TreeNode() : weight(0), parent(nullptr), left(nullptr), right(nullptr) {}
    TreeNode(T weigh) : weight(weigh), parent(nullptr), left(nullptr), right(nullptr) {}
    TreeNode(vector<T> numbers)
    {
        CreateTree(numbers);
    }

    bool CreateTree(vector<T> numbers)
    {
        if (!numbers[0])
            return 0;

        int size = numbers.size() + 1;
        int last_size = size / 2;
        int level = -1;

        while (size)
        {
            size = size / 2;
            level++;
        }

        this->weight = numbers[0];
        deque<TreeNode *> last_node_level;
        deque<TreeNode *> node_level;
        int string_index_start = 1;
        int string_index_end = 1;
        last_node_level.push_back(this);

        for (int i = 1; i < level; ++i)
        {
            string_index_end += i * 2;

            for (int j = string_index_start; j < string_index_end; j += 2)
            {
                TreeNode *node = last_node_level.front();
                last_node_level.pop_front();

                if (node == nullptr)
                {
                    node_level.push_back(nullptr);
                    node_level.push_back(nullptr);
                }

                if (numbers[j])
                {
                    node->CreateLeft(numbers[j]);
                    node_level.push_back(node->left);
                }
                else
                    node_level.push_back(nullptr);

                if (numbers[j + 1])
                {
                    node->CreateRight(numbers[j + 1]);
                    node_level.push_back(node->right);
                }
                else
                    node_level.push_back(nullptr);
            }

            last_node_level = node_level;
            node_level.clear();
            string_index_start = string_index_end;
        }
    }

    bool CreateLeft(T weigh)
    {
        if(left != nullptr)
            return 0;

        left = new TreeNode(weigh);
        left->parent = this;
        return 1;
    }

    bool CreateRight(T weigh)
    {
        if (right != nullptr)
            return 0;

        right = new TreeNode(weigh);
        right->parent = this;
        return 1;
    }

    void PrintFirst()
    {
        cout << this->weight << " ";
        if (this->left) this->left->PrintFirst();
        if (this->right) this->right->PrintFirst();
    }

    inline T get_weight() {return weight;}
    inline T get_weight() const {return weight;}

    inline void set_weight(T weigh) {weight = weigh;}
    inline void set_weight(T weigh) const {weight = weigh;}

    inline TreeNode* get_parent() {return parent;}
    inline TreeNode* get_parent() const {return parent;}

    inline TreeNode* get_left() {return left;}
    inline TreeNode* get_left() const {return left;}

    inline TreeNode* get_right() {return right;}
    inline TreeNode* get_right() const {return right;}

    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    T weight;
};

template <class T>
class ListNode
{
public:
    ListNode(){next_ = nullptr; last_ = nullptr;}
    ListNode(T val){val_ = val; next_ = nullptr; last_ = nullptr;}
    ListNode(T val, ListNode* next, ListNode* last){val_ = val; next_ = next; last_ = last;}

    inline ListNode* get_last(){return last_;}
    inline ListNode* get_last() const {return last_;}

    inline ListNode* get_next(){return next_;}
    inline ListNode* get_next() const {return next_;}

    inline void set_next(ListNode<T> *next){next_ = next;}
    inline void set_next(ListNode<T> *next) const {next_ = next;}

    inline void set_last(ListNode<T> *last){last_ = last;}
    inline void set_last(ListNode<T> *last) const {last_ = last;}

    inline T get_val(){return val_;}
    inline T get_val() const { return val_;}

    inline void set_val(T &val){val_ = val;}
    inline void set_val(T &val) const {val_ = val;}

private:
    T val_;
    ListNode<T> *next_;
    ListNode<T> *last_;
};

template <class T>
void PrintList(ListNode<T> *node)
{
    if (node != nullptr)
    {
        cout << node->get_val() << " ";
        PrintList(node->get_next());
    }
}

template <class T>
void PrintVectorList(vector<ListNode<T>*> &vector_list)
{
    for (int i = 0; i < vector_list.size(); ++i)
    {
        cout << i << ": ";
        PrintList(vector_list[i]);
        cout << endl;
    }
}

class SegmentTreeNode
{
public:
    SegmentTreeNode(): left_(nullptr), right_(nullptr)
    {

    }
    SegmentTreeNode(int start, int end): left_(nullptr), right_(nullptr), start_(start), end_(end), max_(0)
    {

    }

    SegmentTreeNode(int start, int end, int max):left_(nullptr), right_(nullptr), start_(start), end_(end),
                                                 max_(max)
    {

    }

    void PrintFirst()
    {
        cout << "[ " << start_ << ", " << end_ << ", max: " << max_ <<" ]" << endl;
        if (this->left_) this->left_->PrintFirst();
        if (this->right_) this->right_->PrintFirst();
    }

    SegmentTreeNode* get_left() {return left_;}
    SegmentTreeNode* get_left() const { return left_;}

    SegmentTreeNode* get_right() { return right_;}
    SegmentTreeNode* get_right() const {return right_;}

    int get_max() { return max_;}
    int get_max() const {return max_;}

    SegmentTreeNode* Build(int start, int end)
    {
        if (start == end)
            return new SegmentTreeNode(start, end);

        int middle = (start + end) / 2;
        SegmentTreeNode* root = new SegmentTreeNode(start, end);

        root->left_ = Build(start, middle);
        root->right_ = Build(middle + 1, end);

        return root;
    }

    SegmentTreeNode* Build(vector<int> &vector1, int start, int end)
    {
        if (start == end)
        {
            return new SegmentTreeNode(start, end, vector1[start]);
        }

        int middle = (start + end) / 2;

        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        root->left_ = Build(vector1, start, middle);
        root->right_ = Build(vector1, middle + 1, end);
        root->max_ = max(root->left_->get_max(), root->right_->get_max());

        return root;
    }

    int Query(SegmentTreeNode *node, int start, int end)
    {
        if (node->end_ < start || node->start_ > end)
            return -0x7fffffff;

        if (node->start_ >= start && node->end_ <= end)
            return max_;

        int result_left = Query(node->left_, start, end);
        int result_right = Query(node->right_, start, end);

        return max(result_left, result_right);
    }

    int Modify(SegmentTreeNode* node, int index, int value)
    {
        if (node->start_ == node->end_ && node->start_ == index )
        {
            node->max_ = value;
            return node->max_;
        }
        else if (node->start_ > index || node->end_ < index)
        {
            return node->max_;
        }

        int max_left = Modify(node->left_, index, value);
        int max_right = Modify(node->right_, index, value);

        node->max_ = max(max_left, max_right);
        return node->max_;
    }

private:
    int start_;
    int end_;
    int max_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
};

class Configurator
{
public:
    inline std::string GetArgument(const std::string &directive, const std::string default_param = "") const
    {
        const DirectiveArgumentMap::const_iterator it = m_directive_argument_map.find(directive);

        if (it == m_directive_argument_map.end())
            return default_param;
        else
        {
            std::string tem = it->second;
            int n = tem.find_last_not_of("\r");

            if (n != std::string::npos)
                tem.erase(n + 1, tem.size() - n);

            return tem;
        }
    }

    inline int GetArgument(const std::string &directive, const int default_param) const
    {
        const DirectiveArgumentMap::const_iterator it = m_directive_argument_map.find(directive);

        if (it == m_directive_argument_map.end())
            return default_param;
        else
            return atoi(it->second.c_str());
    }

    inline float GetArgument(const std::string &directive, const float &default_param) const
    {
        const DirectiveArgumentMap::const_iterator it = m_directive_argument_map.find(directive);

        if (it == m_directive_argument_map.end())
            return default_param;
        else
            return float(atof(it->second.c_str()));
    }

    inline bool Load(const std::string file_name)
    {
        m_directive_argument_map.clear();
        ifstream infile;
        infile.open(file_name.data());

        if (!infile.is_open())
            return false;

        std::string buffer;

        while (getline(infile, buffer))
        {
            int len = buffer.size();

            if (buffer[0] == '/' && buffer[1] == '/' || len < 2)
                continue;

            int index = buffer.find('=');
            if (index == string::npos)
                continue;

            const std::string directive = buffer.substr(0, index);
            const std::string argument = buffer.substr(index + 1, buffer.size());

            int i = directive.find_last_not_of(" ");
            const std::string return_directive = directive.substr(0, i + 1);

            int j = argument.find_first_not_of(" ");
            int k = argument.find_last_not_of("\r");
            const std::string return_argument = argument.substr(j, k);

            m_directive_argument_map.insert(DirectiveArgumentMap::value_type(return_directive, return_argument));
        }

        infile.close();
        cout << "Loaded " << file_name << endl;
        return true;
    }

    void Print() const
    {
        printf("[Configurator]\n");
        for (DirectiveArgumentMap::const_iterator it = m_directive_argument_map.begin(); it != m_directive_argument_map.end() ; it++)
        {
            std::cout << it->first << " = " << it->second << endl;
        }
    }

public:
    typedef std::map<std::string, std::string> DirectiveArgumentMap;
    DirectiveArgumentMap m_directive_argument_map;
};

class DirectedGraphNode
{
public:
    DirectedGraphNode(int x): label(x){}

public:
    int label;
    vector<DirectedGraphNode*> neighbors;
};

class UndirectedGraphNode
{
public:
    UndirectedGraphNode(int x): label(x){}
    int label;
    vector<UndirectedGraphNode*> neighbors;
};

typedef TreeNode<int> TreeNodeInt;

#endif //LINTCODE_GENERAL_H
