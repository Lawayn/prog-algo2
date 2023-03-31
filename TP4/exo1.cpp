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
    int i = 0;
    int i_max = nodeIndex;

    if(this->get(nodeIndex)<this->get(leftChildIndex(nodeIndex)) && leftChildIndex(nodeIndex)<heapSize){
        i_max = leftChildIndex(nodeIndex);
    }
    if(this->get(nodeIndex)<this->get(rightChildIndex(nodeIndex)) && rightChildIndex(nodeIndex)<heapSize){
        i_max = rightChildIndex(nodeIndex);
    }

    if(i_max != i){
        swap(i, i_max);
        heapify(heapSize, i_max);
    }
}

void Heap::buildHeap(Array& numbers)
{
    for(int i = 0; i<numbers.size(); i++){
        heapify(numbers.size(), numbers[i]);
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
