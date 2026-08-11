#include <iostream>
#include <cstring>

class Mystring
{
public:
    Mystring() = default;
    Mystring(const char* string)
    {
        size_t length = std::strlen(string);
        pstr = new char[length + 1];
        for(int i = 0;i < length; i++)
        {
            pstr[i] = string[i];
        }
        pstr[length] = '\0';
    }
    Mystring(const Mystring& other)
    {
        size_t length = std::strlen(other.pstr);
        pstr = new char[length + 1];
        for (size_t i = 0; i < length; i++)
        {
            pstr[i] = other.pstr[i];
        }
        pstr[length] = '\0';
    }
    
    ~Mystring()
    {
        if(pstr!=nullptr)
        {
            delete [] pstr;
            pstr = nullptr;
        }
    }
    
    Mystring& operator = (const Mystring& other)
    {
        if(this == &other)
        {
            return *this;
        }
        if(pstr!=nullptr)
        {
            delete [] pstr;
            pstr = nullptr;
        }
        
        size_t length = std::strlen(other.pstr);
        pstr = new char[length + 1];
        for(int i = 0;i < length; i++)
        {
            pstr[i] = other.pstr[i];
        }
        pstr[length] = '\0';
        
        return *this;
    }
    Mystring operator + (const Mystring& other)
    {
        Mystring NewStr;
        
        size_t thislength = std::strlen(this->pstr);
        size_t otherlength = std::strlen(other.pstr);
        
        NewStr.pstr = new char[thislength + otherlength + 1];
        
        int i = 0;
        for(; i < thislength; i++)
        {
            NewStr.pstr[i] = this->pstr[i];
        }
        for(int j = 0; j < otherlength; j++,i++)
        {
            NewStr.pstr[i] = other.pstr[j];
        }

        NewStr.pstr[thislength + otherlength] = '\0';
        
        return NewStr;
    }
    
    void Print() const
    {
        std::cout<<pstr<<"\n";
    }
    
    
private:
    char * pstr = nullptr;
};

int main()
{
    Mystring A("Hello");
    Mystring B(A);
    B.Print();
    Mystring C("Word");
    Mystring result;
    result = A + C;
    result.Print();

    return 0;
}
