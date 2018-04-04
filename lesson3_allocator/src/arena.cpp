#include <iostream>

#define DEBUG 0

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
		#ifdef DEBUG
        std::cout << "arena[" << this << "] of size " << size << " created.\n";
		#endif
    }

    Arena(Arena const &) = delete;
    Arena & operator=(Arena const &) = delete;

    ~Arena()
    {
		#ifdef DEBUG
        std::cout << "arena[" << this << "] destroyed; final fill level was: " << offset << "\n";
		#endif
        ::operator delete(data);
    }

    void * allocate(std::size_t n, std::size_t a)
    {
		#ifdef DEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << " " << "size is:  " << n << std::endl;
        std::cout << " " << "align is: " << a << std::endl;
		#endif
		
        offset = (offset + a - 1) / a * a;

		#ifdef DEBUG
        std::cout << "arena[" << this << "] allocating " << n << " bytes at offset " << offset << ".\n";
		#endif

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
		#ifdef DEBUG
        std::cout << "arena[" << this << "] may deallocate " << n << " bytes.\n";
		#endif
    }
};