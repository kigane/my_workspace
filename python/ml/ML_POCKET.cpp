#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define DIMENTION 5

struct record 
{
    double x[DIMENTION];
    int y;
};

vector<record> training_set;

// 读入训练数据
void get_data(fstream &datafile, vector<record> &dataset)
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
        dataset.push_back(cur_record);
    }
    datafile.close();
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

// 计算错误率
double get_error_rate(double weight[], vector<record> &dataset)
{
    int n = dataset.size();
    double error_rate = 0.0;
    for (int i = 0; i < n; i++)
        if (dataset[i].y != sign(dot_product(weight, dataset[i].x, DIMENTION)))
            error_rate++;
    return error_rate / n;
} 

void pocket_PLA(double weight[], double pocket_weight[], vector<record> &training_set, int iteration)
{
    int n = training_set.size();
    int index = 0;
    int iter = 0; // 记录更新次数
    while (iter < iteration)
    {
        if (training_set[index].y != sign(dot_product(weight, training_set[index].x, DIMENTION)))
        {
            double temp[DIMENTION];
            multiply(temp, training_set[index].x, DIMENTION, training_set[index].y); // y_t * x_t
            add_vector(weight, temp, DIMENTION);                                     // w_t+1 = w_t + y_t * x_t
            if (get_error_rate(pocket_weight, training_set) > get_error_rate(weight, training_set)) // 贪心，保留错误率最小的函数
                for (int i = 0; i < DIMENTION; i++)
                    pocket_weight[i] = weight[i]; 
            iter++;
        }

        if (index == n-1) // 循环遍历训练集
            index = 0;
        else
            index++;
    }
    // for (int i = 0; i < DIMENTION; i++) // 使用最后一次更新后的权向量
    //         pocket_weight[i] = weight[i];
}

int main()
{
    vector<record> training_set;
    vector<record> verifying_set;

    string training_file = "pocket_training_data.txt";
    string verifying_file = "pocket_verifying_data.txt";

    fstream tfs(training_file);
    fstream vfs(verifying_file);
    if (tfs.is_open() && vfs.is_open())
    {
        get_data(tfs, training_set);
        get_data(vfs, verifying_set);
    }
    else
    {
        cerr << "出错，打开文件失败" << endl;
        exit(1);
    }

    double weight[DIMENTION]; // 权向量
    double pocket_weight[DIMENTION]; // 最优权向量
    double average_error = 0.0;
    double training_error = 0.0;
    double verifying_error = 0.0;

    // 重复两千次
    for (int i = 0; i < 2000; i++)
    {
        random_shuffle(training_set.begin(), training_set.end()); // 打乱数据

        // 初始化权向量
        for (int i = 0; i < DIMENTION; i++)
        {
            weight[i] = 0.0;
            pocket_weight[i] = 0.0;
        }
        
        // 运行算法
        pocket_PLA(weight, pocket_weight, training_set, 100);

        // 统计错误率
        training_error = get_error_rate(pocket_weight, training_set);
        verifying_error = get_error_rate(pocket_weight, verifying_set);

        average_error += verifying_error;

        cout << "第" << i << "次实验, 训练误差:" << training_error << ", 验证误差:" << verifying_error << endl; 
    }

    cout << "平均误差:" << average_error/2000 << endl;
}