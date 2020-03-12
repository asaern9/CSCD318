#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv){
	
	int ieer = MPI_Init(&argc, &argv);
	int numberProcess, processID;
	ieer = MPI_Comm_size(MPI_COMM_WORLD, &numberProcess);
	ieer = MPI_Comm_rank(MPI_COMM_WORLD, &processID);

	//cout<<"I am process "<<processID<<" of "<<numberProcess<<endl;
	if(processID % 2 == 0){
		cout<<"I am even process ("<<processID<<") of "<<numberProcess<<endl;
	}
	else{
		cout<<"I am odd process ("<<processID<<") of "<<numberProcess<<endl;
	}

	ieer = MPI_Finalize();

	return 0;
}