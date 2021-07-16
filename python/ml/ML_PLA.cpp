#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define DIMENTION 5

double weight[DIMENTION]; // 权向量
int step = 0; // 更新轮数
int n = 0; // 训练样本数
string file = "training_data.txt";

struct record 
{
    double x[DIMENTION];
    int y;
};

vector<record> training_set;

// 读入训练数据
void get_data(fstream &datafile)
{
    while (!datafile.eof())
    {
        record cur_record;
        cur_record.x[0] = 1;
        for (int i = 1; i < DIMENTION; i++)
        {
            datafile >> cur_record.x[i];
        }
        datafile >> cur_record.y;
        training_set.push_back(cur_record);
    }
    datafile.close();
    n = training_set.size();
}

// 感觉可以优化
int sign(double x)
{
    return x <= 0 ? -1 : 1;
}

// 两向量相加，结果放在第一个向量中
void add_vector(double v1[], const double v2[], int d)
{
    for (int i = 0; i < d; i++)
        v1[i] += v2[i];
}

// 两向量点积
double dot_product(const double v1[], const double v2[], int d)
{
    double ret = 0.0;
    for (int i = 0; i < d; i++)
        ret += v1[i] * v2[i];
    return ret;
}

// 实数乘向量
void multiply(double ret[], const double v[], int d, int factor)
{
    for (int i = 0; i < d; i++)
        ret[i] = factor * v[i];
}

void PLA()
{
    int correct_num = 0;
    int index = 0;
    bool isFinished = false;
    while (!isFinished)
    {
        if (training_set[index].y == sign(dot_product(weight, training_set[index].x, DIMENTION)))
            correct_num++;
        else
        {
            double temp[DIMENTION];
            multiply(temp, training_set[index].x, DIMENTION, training_set[index].y);
            add_vector(weight, temp, DIMENTION);
            step++;
            correct_num = 0;
            cout << "step " << step << " : " << "index " << index << " is wrong" << endl;
        }

        if (index == n-1)
            index = 0;
        else
            index++;
        
        if (correct_num == n)
            isFinished = true;        
    }
    cout << "total step is " << step << endl;    
}

int main()
{
    fstream ifs(file);
    if (ifs.is_open())
    {
        get_data(ifs);
    }
    else
    {
        cerr << "出错，打开文件失败" << endl;
        exit(1);
    }

    // 初始化权向量
    for (int i = 0; i < DIMENTION; i++)
        weight[i] = 0.0;

    PLA();

    for (int i = 0; i < DIMENTION; i++)
        cout << weight[i] << endl;
}