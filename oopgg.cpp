#include <iostream>
#include <cstring>

class String
{
public:
    String();
    String(const char* str);
    String(const char symbol, const int size);
    String(const String& s);
    String& operator=(const String& s);
    ~String();
    void print() const;

protected:
    char* m_str;

private:
    void init(const char* str);
};

String::String() :
    m_str(nullptr)
{}

String::String(const char* str) :
    String()
{
    init(str);
}

String::String(const char symbol, const int size) :
    m_str(new char[size + 1])
{
    for (int i = 0; i < size; i++)
        m_str[i] = symbol;
}

String::String(const String& s) :
    String(s.m_str)
{}

String& String::operator= (const String& s)
{
    if (this != &s) // проверка на присваивание самому себе
    {
        delete[] m_str;
        init(s.m_str);
    }
    return *this;
}

String::~String()
{
    delete[] m_str;
}

void String::print() const
{
    if (m_str)
        std::cout << m_str << std::endl;
}

void String::init(const char* str)
{
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

int main()
{
    String s1, s2("abcd"), s3('c', 3), s4(s2);
    s1.print();
    s2.print();
    s3.print();
    s4.print();

    s1 = s3;
    s1.print();
}