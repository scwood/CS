#ifndef QS_H_
#define QS_H_

#include "QSInterface.h"

class QS : public QSInterface {
public:
  QS();
  ~QS();

  // methods
  void swap(int left, int right);
  void sortAll();
  int medianOfThree(int left, int right);
  int partition(int left, int right, int pivotIndex);
  string getArray();
  int getSize();
  void addToArray(int value);
  bool createArray(int size);
  void clear();

  // data members
  int pivot;
  int array_size;
  int add_count;
  
private:
  int* array;
};

#endif // QS_H_