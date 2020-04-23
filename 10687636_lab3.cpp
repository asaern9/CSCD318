#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv){
	MPI_Init(&argc, &argv);
	int process_size, process_id;
	MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
	MPI_Comm_size(MPI_COMM_WORLD, &process_size);
	int message = 0;
	if(process_id != 0){
		MPI_Recv(&message,1,MPI_INT,process_id-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		cout<<"Process "<<process_id<<" received $ "<< message<<" from process "<<process_id-1<<endl;
	}
	else{
		message = 666;
	}
	MPI_Send(&message,1, MPI_INT,(process_id+1)%process_size,0,MPI_COMM_WORLD);
	if(process_id == 0){
		MPI_Recv(&message,1,MPI_INT,process_size-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		cout<<"Process "<<process_id<<" received $ "<< message<<" from process "<<process_size-1<<endl;
	}
	MPI_Finalize();
	return 0;
}
