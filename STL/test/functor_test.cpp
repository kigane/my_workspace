#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define SHOW_CONTENT(desc, k)                         \
    cout << desc << "[";                              \
    for (auto ite = k.begin(); ite != k.end(); ++ite) \
        cout << *ite << ", ";                         \
    cout << "]" << endl;

template<typename T>
class TooBig
{
private:
    T cutoff;
public:
    TooBig(const T& t) : cutoff(t) {}
    bool operator()(const T& v)
    {
        return v > cutoff;
    }
};

int main(){
  int vals[10] {50, 100, 90, 132, 56, 77, 210, 213, 555, 666};
  list<int> li1 (vals, vals + 10);  
  list<int> li2 (vals, vals + 10);

  TooBig<int> f100(100);
  li1.remove_if(f100);
  li2.remove_if(TooBig<int>(200));

  SHOW_CONTENT("now list li1 :", li1);
  SHOW_CONTENT("now list li2 :", li2);

}