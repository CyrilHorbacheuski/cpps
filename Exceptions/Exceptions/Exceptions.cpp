#include <iostream>

// example 1
template<class T>
T* CreateArray(int size)
{
    try
    {
        T* arr = new T[size];
        return arr;
    }
    catch (std::bad_array_new_length)
    {
        std::cout << "array length invalid!";
        return nullptr;
    }
    catch (std::bad_alloc)
    {
        std::cout << "memory is not allocated!";
        return nullptr;
    }
}

// example 2
template<class T>
T* CreateArray2(int size)
{
    try
    {
        if (size >= 1000000 || size < 0)
            throw std::bad_alloc();
    }
    catch (std::bad_alloc)
    {
        std::cout << "memory is not allocated!";
        return nullptr;
    }
    catch (...)
    {
        std::cout << "something wrong happened";
        return nullptr;
    }

    T* arr = new T[size];
    return arr;
}

int main()
{
    size_t size;

    char* str = nullptr;
    while (str == nullptr)
    {
        std::cout << std::endl << "input array size: ";
        std::cin >> size;
        std::cin.get();
        str = CreateArray2<char>(size);
    }

    str[0] = 'a';

    return 0;
}
