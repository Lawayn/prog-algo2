#include <QApplication>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include "tp2.h"

using namespace std;

MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

    // split

    int pivot = toSort[0];

    for (int i=0; i<size;i++){
        if (toSort[i]<pivot){
            lowerArray.insert(lowerSize,toSort[i]);
            lowerSize++;
        } else if(toSort[i]>pivot){
            greaterArray.insert(greaterSize,toSort[i]);
            greaterSize++;
        }
    }
	
	// recursiv sort of lowerArray and greaterArray

    //lowerArray[0]>lowerArray[1]

   if (lowerSize>=2) {
        recursivQuickSort(lowerArray,lowerSize);
    }
   if( greaterSize>=2){
        recursivQuickSort(greaterArray,greaterSize);
   }

	// merge

   int i = 0;
   for(int j = 0; j<lowerSize;j++){
       toSort.insert(i,lowerArray[j]);
       i++;
   }
   toSort.insert(i,pivot);
   i++;
   for(int l = 0; l<greaterSize;l++){
       toSort.insert(i, greaterArray[l]);
       i++;
   }

}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
