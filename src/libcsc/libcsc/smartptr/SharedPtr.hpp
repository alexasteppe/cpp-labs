#pragma once

namespace shared {
template <class T> class SharedPtr {
private:
  T *ptr_ = nullptr;
  std::size_t *refCounter_;

  void destruct() {
    if (refCounter_ != nullptr) {
      --(*refCounter_);
    } else {
      return;
    }
    if (*refCounter_ == 0) {
      delete ptr_;
      delete refCounter_;
    }
  }

public:
  explicit SharedPtr(T *pointer)
      : ptr_(pointer), refCounter_(new std::size_t(1)) {}

  SharedPtr(const SharedPtr &otherPtr)
      : ptr_(otherPtr.ptr_), refCounter_(otherPtr.refCounter_) {
    if (otherPtr.ptr_ != nullptr) {
      ++(*refCounter_);
    }
  }

  SharedPtr(SharedPtr &&otherPtr) noexcept
      : ptr_(otherPtr.ptr_), refCounter_(otherPtr.refCounter_) {
    otherPtr.refCounter_ = nullptr;
    otherPtr.ptr_ = nullptr;
  }

  SharedPtr &operator=(const SharedPtr &otherPtr) {
    destruct();
    refCounter_ = otherPtr.refCounter;
    ptr_ = otherPtr.ptr;
    if (otherPtr != nullptr) {
      ++(*refCounter_);
    }
  }

  SharedPtr &operator=(SharedPtr &&otherPtr) noexcept {
    destruct();
    refCounter_ = otherPtr.refCounter;
    ptr_ = otherPtr.ptr;
    otherPtr.ptr = nullptr;
    otherPtr.refCounter = nullptr;
  }

  void reset(T *p = nullptr) {
    destruct();
    refCounter_ = nullptr;
    ptr_ = p;
    if (ptr_ != nullptr) {
      refCounter_ = new std::size_t(1);
    }
  }

  ~SharedPtr() {
    destruct();
    // std::cout << "destructed" << std::endl;
  }

  std::size_t use_count() { return *refCounter_; }

  T *operator->() const { return ptr_; } // get()?

  T &operator*() const { return *ptr_; }

  T *get() const { return ptr_; }
};
} // namespace shared
