#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

template <typename T>
inline int compare(const T &v1, const T &v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}
//exercise 16.12
template <typename Iter>
Iter mostOccurence(Iter beg, Iter end) {
  struct cmp_org {
    bool operator() (Iter lhs, Iter rhs) {
      return *lhs < *rhs;
    }
  };
  
  typedef std::map<Iter, std::size_t, cmp_org> OccurMap;
  OccurMap occurence;
  while (beg != end) {
    ++occurence[beg++];
  }
  
  std::size_t count(0);
  Iter ret(beg);
  typename OccurMap::iterator it = occurence.begin();
  for (; it != occurence.end(); it++) {
    if (it->second > count) {
      count = it->second;
      ret = it->first;
    }
  }
  return ret;
}
//exercise 16.15
template <typename T, size_t N>
size_t size(const T (&parm)[N]) {
  return N;
}
//complete the queue class
template <typename T> struct  Node
{
  T content;
  Node *next;
  Node() {
    next = NULL;
  }
  Node(const T &t) {
    content = t;
    next = NULL;
  }
  /* data */
};

template <typename T> class Queue {
public:
  Queue(): head(0), tail(0) { };
  Queue(const Queue &q):head(NULL), tail(NULL) { copy_elems(q); };
  Queue& operator= (const Queue &);
  ~Queue() { destory(); };
  T &front() { return head->content; };
  const T &front() const { return head->content; };
  void push(const T &);
  void pop();
  bool empty() const { return head == NULL; };
private:
  Node<T> *head;
  Node<T> *tail;
  //utility functions
  void destory();
  void copy_elems(const Queue &);
};

template <typename T>
void Queue<T>::destory() {
  while (!empty())
    pop();
}

template <typename T>
void Queue<T>::pop() {
  Node<T>* temp = head;
  head = head->next;
  delete temp;
}

template <typename T>
void Queue<T>::push(const T &t) {
  if (head == NULL) {
    head = new Node<T>(t);
    tail = head;
  } else {
    tail->next = new Node<T>(t);
    tail = tail->next;
  }
}

template <typename T>
void Queue<T>::copy_elems(const Queue &orig) {
  for (Node<T> *pt = orig.head; pt; pt = pt->next) {
    push(pt->content);
  }
}

int main() {
  //using a function template
  cout << compare(1, 10) << endl;
  string a1 = "hello";
  string a2 = "hello world";
  cout << compare(a1, a2) << endl;
  Queue<int> qi;
  qi.push(42);
  qi.push(36);
  Queue<int> qi2(qi);
  cout << "the front of qi2 is " << qi2.front() << endl;
  qi2.pop();
  cout << "the front of qi2 after poping is " << qi2.front() << endl;
  qi2.pop();
  if (qi2.empty())
    cout << "qi2 now is empty" << endl;
  else
    cout << "qi2 now is not empty" << endl;
  return 0;
}