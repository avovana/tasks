#include <iostream>

class Arena
{
    unsigned char * const data;
    std::size_t const size;
    std::size_t offset;

public:
    explicit Arena(std::size_t s)
    : data(static_cast<unsigned char *>(::operator new(s)))
    , size(s)
    , offset(0)
    {
        std::cout << "arena[" << this << "] of size " << size << " created.\n";
    }

    Arena(Arena const &) = delete;
    Arena & operator=(Arena const &) = delete;

    ~Arena()
    {
        std::cout << "arena[" << this << "] destroyed; final fill level was: " << offset << "\n";
        ::operator delete(data);
    }

    void * allocate(std::size_t n, std::size_t a)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << " " << "size is:  " << n << std::endl;
        std::cout << " " << "align is: " << a << std::endl;
        offset = (offset + a - 1) / a * a;

        std::cout << "arena[" << this << "] allocating " << n << " bytes at offset " << offset << ".\n";

        if (offset + n > size)
        {
            throw std::bad_alloc();
        }

        void * result = data + offset;
        offset += n;
        return result;
    }

    void deallocate(void *, std::size_t n)
    {
        std::cout << "arena[" << this << "] may deallocate " << n << " bytes.\n";
    }
};