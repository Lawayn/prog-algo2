#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChildIndex(int nodeIndex)
{
    return nodeIndex *2 +1;
}

int Heap::rightChildIndex(int nodeIndex)
{
    return nodeIndex*2+2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
    int i = heapSize;
    this->get(i) = value;
    while(i>0 &&  this->get(i)> this->get((i-1)/2)){
        swap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
    int i_max = nodeIndex;

    int left = leftChildIndex(nodeIndex);
    int right = rightChildIndex(nodeIndex);

    if(left<heapSize && this->get(left)>this->get(nodeIndex)){
        i_max = left;
    }
    if(right<heapSize && this->get(right)<this->get(i_max)){
        i_max = right;
    }

    if(i_max != nodeIndex){
        swap(this->get(nodeIndex), this->get(i_max));
        heapify(heapSize, i_max);
    }
}

void Heap::buildHeap(Array& numbers)
{
    for(unsigned int i = 0; i<numbers.size(); i++){
        insertHeapNode(i, numbers[i]);
    }
}

void Heap::heapSort()
{
     for(int i=this->size()-1;i>0; i--){
         swap(0, i);
         heapify(i,0);
     }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
