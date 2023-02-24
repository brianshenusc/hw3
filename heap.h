#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  Heap(int m=2, PComparator c = PComparator());

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
  std::vector<T> data; // vector that stores the data
  int m_; // n-ary value1
  PComparator c_; // PComparator obj

};

// Add implementation of member functions here


/**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
template <typename T, typename PComparator>
// default constructor sets the m_ and c_ values based off the constructor
Heap<T,PComparator>::Heap(int m, PComparator c) {
  m_ = m;
  c_ = c;
}


/**
  * @brief Destroy the Heap object
  * 
  */
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

/**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  // adds the item to the end of data
  data.push_back(item);
  std::size_t index = data.size() - 1; 
  // inserts item into the correct index based off whether it is a min or max heap
  while (index != 0) {
      std::size_t parent_index = (index - 1) / m_;
      T& current = data[index];
      T& parent = data[parent_index];
      if (c_(parent, current)) {
          break;
      }
      std::swap(current, parent);
      index = parent_index;
  }

}

/**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
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
    throw std::underflow_error("The heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


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
    throw std::underflow_error("The heap is empty");

  }
  // if the size is 1, delete it from data
  if(data.size() == 1) {
      data.pop_back();
      return;
  }
  // swaps the first and last values and deletes the last value after the swap
  std::swap(data[0], data[data.size()-1]);
  data.pop_back();
  unsigned int currIndex = 0;
  bool isCorrect = false;
 
  while(!isCorrect) {
      // declares and instantiates an array of possible children set to -1 initially
      int childArray[m_];
      for(int i = 0; i < m_; i++) {
        childArray[i] = -1;
      }
      // if a child exists, then its index is set in childArray (stays -1 if doens't exist)
      int count = 1;
      for(int i=0; i < m_; i++) {
        if(data.size()-1 >= currIndex * m_ + count) {
          childArray[i] = currIndex * m_ + count;
          count++;
        }
      }

      // finds the smallest or largest child to swap with depending on if a max or min heap is being used
      unsigned int correctIndex = currIndex;
      bool isDone = true;
      for(int i=0; i < m_; i++) {
        // checks if current child is valid
        if(childArray[i] != -1) {
          isDone = false;
          // finds the correct value to swap with between the children
          if(c_(data[childArray[i]], data[correctIndex])) {
            correctIndex = childArray[i];
          }

        }
      }
      // if nothing needs to be swapped, the function exits
      if(isDone || correctIndex == currIndex) {
        isCorrect = true;
        return;
      }
      // swaps the min or max item with the current index depending on if it is a max or min heap
      std::swap(data[currIndex], data[correctIndex]);
      if(correctIndex * m_ + 1 < data.size() - 1) {
          currIndex = correctIndex;
      }
      else {
        isCorrect = true;
        return;
      }
  }
  



}
/**
  * @brief Returns true if the heap is empty
  * 
  */
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  // if data is empty, return true, false otherwise
  if(data.size() == 0) {
    return true;
  }
  return false;
}

  /**
  * @brief Returns size of the heap
  * 
  */
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  // returns size of the heap
  return data.size();
}



#endif

