#include <QApplication>
#include <time.h>

#include "tp2.h"


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




	// merge
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
