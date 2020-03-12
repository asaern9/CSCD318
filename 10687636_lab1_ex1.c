#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
	MPI_Init(&argc,&argv);
	int processID, numberProcess;
	MPI_Comm_rank(MPI_COMM_WORLD, &processID);
	MPI_Comm_size(MPI_COMM_WORLD, &numberProcess);
	printf("Hello world from %d of %d\n",processID, numberProcess);
	MPI_Finalize();
	return 0;
}
