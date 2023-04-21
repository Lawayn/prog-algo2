#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)

    if(origin.size()==1){
        return;
    }

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split

    for(uint i=0; i<origin.size();i++){
        if(i<first.size()){
            first[i] = origin[i];
        } else{
            second[i-first.size()] = origin[i];
        }
    }

	// recursiv splitAndMerge of lowerArray and greaterArray

    splitAndMerge(first);
    splitAndMerge(second);

	// merge

    merge(first, second, origin);
}

void merge(Array& first, Array& second, Array& result)
{
    //init
    uint i = 0;
    uint j = 0;
    uint k = 0;

    //merge

    while(i<first.size() && j< second.size()){
        if(first[i]< second[j]){
            result[k]=first[i];
            i++;
        } else{
            result[k]=second[j];
            j++;
        }
        k++;
    }
    while(i<first.size()){
        result[k] = first[i];
        i++;
        k++;
    }
    while(j<second.size()){
        result[k]=second[j];
        j++;
        k++;
    }
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
