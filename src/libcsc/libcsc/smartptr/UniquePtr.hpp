#pragma once

namespace unique {
template <class T> class UniquePtr {

private:
  T *ptr_ = nullptr;

  void destruct() {
      delete ptr_;
  }

public:
  explicit UniquePtr(T *pointer) : ptr_(pointer) {}

  UniquePtr(const UniquePtr &otherPtr) = delete;

  UniquePtr &operator=(const UniquePtr &otherPtr) = delete;

  UniquePtr(UniquePtr &&otherPtr) noexcept : ptr_(otherPtr.ptr) {
    otherPtr.ptr = nullptr;
  }

  UniquePtr &operator=(UniquePtr &&otherPtr) noexcept {
    destruct();
    ptr_ = otherPtr.ptr;
    otherPtr.ptr = nullptr;
  }

  void reset(T *p = nullptr) noexcept {
    destruct();
    ptr_ = p;
  }

  ~UniquePtr() {
    destruct();
    // std::cout << "destructed" << std::endl;
  }

  T *operator->() const { return ptr_; }

  T &operator*() const { return *ptr_; }

  T *get() const { return ptr_; }
};
} // namespace unique
