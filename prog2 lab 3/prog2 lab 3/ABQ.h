
#include <iostream>
//#include "leaker.h"
//#include "leaker.cpp"
//#include "ABS.h"
using namespace std;



template <typename T>
class ABQ {
    //variables
private:
    float _scaleFactor;
    int _currentSize;
    int _capacity;
    T* _queueArrayPointer = nullptr;
public:
    //constructors
    ABQ() {
        _capacity = 1;
        _currentSize = 0;
        _scaleFactor = 2.0f;
        _queueArrayPointer = new T[_capacity];

    }
    ABQ(int capacity) {
        _capacity = capacity;
        _currentSize = 0;
        _scaleFactor = 2.0f;
        _queueArrayPointer = new T[_capacity];
    }
    ABQ(const ABQ& d) {
        _capacity = d.capacity;
        _currentSize = d.currentSize;
        _scaleFactor = d.scaleFactor;
        _queueArrayPointer = d._queueArrayPointer;
        _queueArrayPointer = new T[_capacity];

        for (int i = 0; i < _currentSize; i++) {
            _queueArrayPointer[i] = d.queueArrayPointer[i];
        }
        delete[] _queueArrayPointer;
    }
    ABQ& operator=(const ABQ& d) {
        _capacity = d.capacity;
        _currentSize = d.currentSize;
        _scaleFactor = d.scaleFactor;
        _queueArrayPointer = d._queueArrayPointer;
        _queueArrayPointer = new T[_capacity];

        for (int i = 0; i < _currentSize; i++) {
            _queueArrayPointer[i] = d.queueArrayPointer[i];
        }
        delete[] _queueArrayPointer;
        return *this;
    }
    ~ABQ() {
        delete[] _queueArrayPointer;
    }

    //functions
    void enqueue(T data) {
        //cout << "new pushed current size " << _currentSize << endl;
        if (_currentSize == _capacity) {

            _capacity *= _scaleFactor;
            //cout << "new capacity " << _capacity << endl;

            T* tempArray = new T[_capacity];

            for (int i = 0; i < _currentSize; i++) {
                tempArray[i] = _queueArrayPointer[i];
                //cout << "tempArray " << tempArray[i] << endl;
            }
            
            delete[] _queueArrayPointer;
            _queueArrayPointer = tempArray;

        }
        _queueArrayPointer[_currentSize] = data;
        _currentSize++;
    }

    T dequeue() {
        if (_currentSize == 0) {
            throw runtime_error("An error has occured");
        }
        
        

        T poppedValue = _queueArrayPointer[0];
        

        _currentSize--;
        //cout << "popped current size " << _currentSize << endl;


        
        
        float halfCapacity = _capacity / _scaleFactor;
        //cout << "half capacity " << halfCapacity << endl;

        if (_currentSize < halfCapacity && halfCapacity != 0) {
            _capacity = halfCapacity;

            T* tempArray = new T[_capacity];
            for (int i = 0; i < _currentSize-1; i++) {
                tempArray[i] = _queueArrayPointer[i+1];
            }
            //T removed_value = _stackArrayPointer[_currentSize-1];

            //_currentSize--;
            delete[] _queueArrayPointer;
            _queueArrayPointer = tempArray;

            //delete[] tempArray;

            //return removed_value;
        }
        else {
            T* tempArray = new T[_capacity];
            for (int i = 0; i < _currentSize-1; i++) {
                tempArray[i] = _queueArrayPointer[i+1];
            }
            //T removed_value = _stackArrayPointer[_currentSize-1];

            //_currentSize--;
            delete[] _queueArrayPointer;
            
            _queueArrayPointer = tempArray;
            //delete[] tempArray;
        }

        return poppedValue;


    }

    T peek() {
        if (_currentSize == 0) {
            throw runtime_error("An error has occured");
        }
        T recentValue = _queueArrayPointer[0];
        return recentValue;

    }
    unsigned int getSize() {
        return _currentSize;
    }
    unsigned int getMaxCapacity() {
        return _capacity;
    }
    T* getData() {
        return _queueArrayPointer;
    }

};
