#include <type_traits>
#include "arena.cpp"

template <typename T, size_t Size = 400>
struct ArenaAllocator
{
    template <typename U, size_t> friend struct ArenaAllocator;

    using value_type = T;
    using pointer = T *;

    explicit ArenaAllocator(Arena * a) : arena(a) {}
    
    template <class U> 
    struct rebind {
        using other =  ArenaAllocator<U, Size>; 
    };

    ArenaAllocator()
    {
        arena = new Arena(Size);
    }

    ~ArenaAllocator()
    {
        delete arena;
    }

    template <typename U>
    ArenaAllocator(ArenaAllocator<U> const & rhs) : arena(rhs.arena) {}

    pointer allocate(std::size_t n)
    {
        return static_cast<pointer>(arena->allocate(n * sizeof(T), alignof(T)));
    }

    void deallocate(pointer p, std::size_t n)
    {
        arena->deallocate(p, n * sizeof(T));
    }

    template <typename ... Args >
    void construct(T* p, Args&& ... args) {
        new(p) T(std::forward <Args>(args) ... );
    };

    template <typename U>
    bool operator==(ArenaAllocator<U> const & rhs) const
    {
        return arena == rhs.arena;
    }

    template <typename U>
    bool operator!=(ArenaAllocator<U> const & rhs) const
    {
        return arena != rhs.arena;
    }

private:
    Arena * arena;
};