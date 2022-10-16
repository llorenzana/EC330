Imagine that you are managing a supercomputer that runs jobs for your clients. A client can submit a set of jobs, numbered from 1 to n, and the dependencies among them. The dependencies are expressed as pairs. For example, (1, 2) means job 2 depends on job 1, i.e. job 2 can only start after job 1 finishes.

a) Write a program that determines if it is possible to run all the jobs without actually running them (assuming each job takes finite time to run). [20 pt] Below are some example inputs and their expected outputs.

    Input: number of jobs = 2, dependencies = [(1, 2)]
    Output: true
    Explanation: We can run job 1 first followed by job 2.

    Input: number of jobs = 2, dependencies = [(1, 2), (2, 1)]
    Output: false
    Explanation: We need job 1 to finish before we can run job 2, and job 2 to finish before we can run job 1. This is clearly impossible.

Implement your algorithm in the method canFinish in job.cpp

b) Write a program that checks if a given job j can be run in the ith time slot on a
sequential computer. You can assume that i ranges from 1 to n, each job can
finish in one time slot, and you can run no job in a slot. You can also assume the
answer to part a) is true for the input given in this part. [30 pt]
Below are some example inputs and their expected outputs.

    Input: number of jobs = 2, dependencies = [(1, 2)], j = 2, i = 1
    Output: false
    Explanation: We have to run job 1 first before we can run job 2, so job 2 cannot be run as the 1st job
    
    Input: number of jobs = 2, dependencies = [(1, 2)], j = 1, i = 2
    Output: true
    Explanation: we can run no job in the 1st time slot, and then run job 1 in the 2nd time slot.

Implement your algorithm in the method canRun in job.cpp. 
