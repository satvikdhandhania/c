/* Author Satvik Dhandhania Date 5th May
 * Samsung Q1	
 */

/*
# There's cluster N machines in the cloud
# They are connected by a high speed network
#
# There's a dev machine, connected through a much slower link to the cloud
# You want to distribute a large file across all the N machines
#
# Let's assume you have two functions:
#
# copyFromDevToMachine(Machine)
# copyFromMachineToMachine(A, B)
# listOfMachines of the length N
*/

int main(){
	copyFromDevToMachine(1);
	int end=1;
	while(end < N){
	    for(int j=1;j<=end;j++){
	        if(end + j < N) { 
	            copyFromMachineToMachine(j,end+j);
	        }
	    }
	    end = end*2;
	}
	return 0;
}

