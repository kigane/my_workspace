#ifndef HWK_LIST
#define HWK_LIST

template<typename T>
class hwk_list
{
private:
    hwk_list_node* li;
public:
    hwk_list();
    hwk_list(const hwk_list& lst);
    operator = (const hwk_list& lst);
    ~hwk_list();
};

template<typename T>
class hwk_list_node
{
private:
    hwk_list_node* prev;
    hwk_list_node* next;
    T data;
public:
    hwk_list_node();
    hwk_list_node(const hwk_list_node &lst);
    operator=(const hwk_list_node &lst);
    ~hwk_list_node();
};

#endif // HWK_LIST