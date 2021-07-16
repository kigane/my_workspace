#include <iostream>
using namespace std;
class CObject
{
public:
    virtual void Serialize() { cout << "CObject::Serialize() \n\n"; }
};
class CDocument : public CObject
{
public:
    int m_data1;
    CDocument() {};
    CDocument(const CDocument& cdoc)
    {
        this->m_data1 = cdoc.m_data1;
        cout << "copy ctor" << endl;
    }
    void func()
    {
        cout << "CDocument::func()" << endl;
        Serialize();
    }
virtual void Serialize() { cout << "CDocument::Serialize() \n\n"; }
};
class CMyDoc : public CDocument
{
public:
    int m_data2;
    virtual void Serialize() { cout << "CMyDoc::Serialize() \n\n"; }
};

int main()
{
    CMyDoc  mydoc;
    CMyDoc * pmydoc = new CMyDoc;
    cout << "#1 testing" << endl;
    mydoc.func(); // CDocument::func() CMyDoc::Serialize()
    cout << "#2 testing" << endl;
    ((CDocument*)(&mydoc))->func(); // CDocument::func() CMyDoc::Serialize()
    cout << "#3 testing" << endl;
    pmydoc->func(); // CDocument::func() CMyDoc::Serialize()
    cout << "#4 testing" << endl;
		// 这里出现了object slicing
    ((CDocument)mydoc).func(); //!!! CDocument::func() CDocument::Serialize()
}