#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H
#include <cstddef>
#include <queue>
#include <vector>

template <typename T, size_t N = 16>
class memoryPool{
    void* raw_ = nullptr;
    std::queue<T*> freeList_;

public:
    memoryPool(){
        raw_ = ::operator new(sizeof(T) * N);
        char* p = static_cast<char*>(raw_);
        for(size_t i = 0; i < N; ++i){
            void* addr = p + i*sizeof(T);
            freeList_.push(static_cast<T*>(addr));
        }
    }
    ~memoryPool(){::operator delete(raw_);}
    T* allocate(){
        if(freeList_.empty()){
            return nullptr;
        }
        T* p = freeList_.front();
        freeList_.pop();
        return p;
    }
    void deallocate(T* p){
        if(p == nullptr)    return;
        freeList_.push(p);
    }
};
#endif
