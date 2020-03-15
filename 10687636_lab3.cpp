#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char *argv[]){

    int p_rank, p_size, mg= 10;
    MPI::Status status;
    MPI::Init(argc, argv);
        p_size = MPI::COMM_WORLD.Get_size();
        p_rank = MPI::COMM_WORLD.Get_rank();
        if(p_rank != 0)
        {
            MPI_Recv(&mg, 1, MPI::INT, p_rank-1, 0, MPI::COMM_WORLD, MPI_STATUS_IGNORE);
            cout<<"Process "<<p_rank - 1<<" Received "<<mg <<" from process " << p_rank<< endl;

        }
        else{
            mg = 111;
        }
        MPI_Send(&mg, 1, MPI::INT, (p_rank+1)%p_size, 0, MPI::COMM_WORLD);
        if(p_rank==0)
        { 
            MPI_Recv(&mg, 1, MPI::INT, p_size-1, 0, MPI::COMM_WORLD, MPI_STATUS_IGNORE);
            cout<<"Process "<<p_rank - 1<<" Received "<<mg <<" from process " <<p_size - 1<< endl;

        }

    MPI::Finalize();


    return 0;
}
