//Mykola Savchenko 12.9.2026

#include <iostream>

template <typename T>
class SharedPointer
{
    public:
    
    SharedPointer()
    {
        ref = nullptr;
        ref_count = nullptr;
    }
    
    SharedPointer(T* ptr)
    {
        ref = ptr;
        ref_count = new unsigned(1);
    }
    
    SharedPointer(SharedPointer& sptr)
    {
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count);
    }
    
    ~SharedPointer()
    {
        if(ref != nullptr && ref_count != nullptr)
        {
            remove();
        }
    }
    
    SharedPointer operator = (SharedPointer& sptr)
    {
        if (this != &sptr && *ref_count > 0)
        {
            remove();
        }
        
        if (this != &sptr)
        {
            ref = sptr.ref;
            ref_count = sptr.ref_count;
            ++(*ref_count);
        }
        return *this;
    }
    
    T operator*()
    {
        return *ref;
    }
    
protected:
    
    void remove()
    {
        --(*ref_count);
        
        if (*ref_count == 0)
        {
            std::cout<<"Deleted "<<*ref<<std::endl;
            delete ref;
            delete ref_count;
            
            ref = nullptr;
            ref_count = nullptr;
           
        }
    }
    
    T* ref;
    unsigned* ref_count;
    
};

int main()
{
    return 0;
}
