/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: rwlock_test.cpp,v 1.3 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2005-2006 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "util/rwlock.h"

#include <iostream>
#include <sstream>

#define THREADS			50
#define DATASIZE		1500
#define ITERATIONS	100000


using namespace zorba;
using namespace std;

struct thread_t {
	int					thread_num;
	pthread_t		thread_id;
	int 				updates;
	int					reads;
	int					interval;

	thread_t(int n,int m):thread_num(n),updates(0),reads(0),interval(m) {}
	thread_t():thread_num(0),updates(0),reads(0),interval(0) {}
	~thread_t() {}

};


struct data_t
{
	rwlock			lock;
	int					data;
	int 				updates;

	data_t() : lock(), data(0), updates(0) {}
	~data_t() {}

};


struct thread_t threads[THREADS];
struct data_t data[DATASIZE];


void* thread_routine(void* arg)
{
	thread_t* self = (thread_t*)arg;
	int repeats = 0;
	int iteration;
	int element = 0;
	int status;

	for (iteration = 0; iteration < ITERATIONS; iteration++) {
		// each 'interval' iterations perform an update
		if (iteration % self->interval == 0) {
			status = data[element].lock.writelock();
			if (status!=0){
				ostringstream oss; oss <<"write lock failed: "<<status;
				cout << oss.str() << endl;
				return NULL;
			}
			data[element].data = self->thread_num;
			data[element].updates++;
			self->updates++;
			status = data[element].lock.writeunlock();
			if (status!=0) {
				ostringstream oss; oss <<"write unlock failed: "<<status;
				cout << oss.str() << endl;
				return NULL;
			}
		}
		// look at current data element to see whether the
		// current thread updated it; count the times for report
		else {
			status = data[element].lock.readlock();
			if (status!=0) {
				ostringstream oss; oss <<"read lock failed: "<<status;
				cout << oss.str() << endl;
				return NULL;
			}
			self->reads++;
			if (data[element].data == self->thread_num) repeats++;
			status = data[element].lock.readunlock();
			if (status!=0) {
				ostringstream oss; oss <<"read unlock failed: "<<status;
				cout << oss.str() << endl;
				return NULL;
			}
		}

		element = (element+1) % DATASIZE;
	}

	cout << "Thread " << self->thread_num << " found unchanged elements "
	 		 << repeats << " times\n";
	return NULL;
}


int main(int argc, char* argv[])
{
	int count, data_count;
	int status;
	unsigned seed = 1;
	int thread_updates = 0;
	int data_updates = 0;
	
	// initialize shared data
	for (data_count=0; data_count < DATASIZE; data_count++) {
		data[data_count] = data_t();
	}

	// create threads to access shared data
	for (count=0; count < THREADS; count++) {
		threads[count] = thread_t(count, 1+rand_r(&seed) % 71);
		status = pthread_create(&threads[count].thread_id,
														NULL,
														thread_routine,
														(void*)&threads[count]);
		if (status!=0) {
			ostringstream oss; oss <<"thread create failed: "<<status;
			cout << oss.str() << endl;
			return -1;
		}
	}

	// wait for all threads to complete
	for (count=0; count < THREADS; count++) {
		status = pthread_join(threads[count].thread_id, NULL);
		if (status!=0) {
			ostringstream oss; oss <<"thread join failed: "<<status;
			cout << oss.str() << endl;
			return -1;
		}
		thread_updates+= threads[count].updates;
		cout << count << ": interval " << threads[count].interval
									<< ", updates " << threads[count].updates
									<< ", reads " << threads[count].reads
									<< endl;
	}

	// collect statistics
	for (data_count=0; data_count < DATASIZE; data_count++) {
		data_updates += data[data_count].updates;
		cout	<< "data " << data_count
					<< ":  value " << data[data_count].data
					<< ", updates " << data[data_count].updates
					<< endl;
		data[data_count].lock.destroy();
	}

	cout << thread_updates << " thread updates, "
			 << data_updates << " data updates\n";

	return 0;
}

