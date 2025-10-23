#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <utility>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m_(m), comp_(c) {
    if (m_ < 2) {
      throw std::invalid_argument("Heap arity m must be >= 2");
    }
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int m_;
  PComparator comp_;

  //funcs
  void heapup(size_t loc);
  void heapify(size_t loc);
  size_t pid(const size_t i) const {
    return (i-1) / static_cast<size_t>(m_);
  }

  size_t child(const size_t i) const {
    return i * static_cast<size_t>(m_) + 1;
  }
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {};

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapup(size_t loc) {
    while (loc > 0) {
      size_t par = pid(loc);

      //if child is better than parent, swap 
      if (comp_(data_[loc], data_[par])) {
        std::swap(data_[loc], data_[par]);
        loc = par;
      }
      else {
        break;
      }
    }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t loc) {
  const size_t n = data_.size();
  while (true) {
    size_t best = loc;
    size_t fk = child(loc);

    // of m kids, pick best kid
    for (size_t i = 0; i < static_cast<size_t>(m_); i++) {
      size_t kid = fk + i;
      if (kid < n && comp_(data_[kid], data_[best])) {
        best = kid;
      }
    }

    if (best != loc) {
      std::swap(data_[loc], data_[best]);
      loc = best;
    }
    else {
      break;
    }
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data_.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return data_.empty();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data_.push_back(item);
  heapup(data_.size() - 1);
  return;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("ts is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("ts is empty");
  }

  std::swap(data_.front(), data_.back());
  data_.pop_back();
  if (!empty()) {
    heapify(0);
  }

}



#endif

