#include <iostream>
#include <mpi.h>
#include <chrono>


using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
	
	
	MPI_Init(&argc,&argv);
	double startTime, endTime;
	startTime = MPI_Wtime();
	int processID, numberProcess;
	MPI_Comm_rank(MPI_COMM_WORLD, &processID);
	MPI_Comm_size(MPI_COMM_WORLD, &numberProcess);
	MPI_Barrier(MPI_COMM_WORLD);
	int firstNumber,lastNumber;
	
	if(processID == 0){
		cout<<"Enter the first number to sum from: ";
		cin>>firstNumber;
		cout<<"Enter the last number: ";
		cin>>lastNumber;
	}
	
	int sum = 0;
	for(int x=firstNumber; x<=lastNumber; x++){
		sum += x;
	}
	if(processID == 0){
		cout<<"The sum from "<<firstNumber<<" to "<<lastNumber<<" is = "<<sum<<endl;
	}
	MPI_Barrier(MPI_COMM_WORLD);
	endTime = MPI_Wtime();
	double executionTime = endTime - startTime;
	if(processID ==0){
		cout<<"On "<<processID<<" node(s) "<<endl;
		cout<<"Execution time is "<< executionTime<<"seconds"<<endl;
	}
	MPI_Finalize();
	
	return 0;
}
