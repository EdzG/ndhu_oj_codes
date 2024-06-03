#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

// Structure to represent a staff member
struct Staff {
    int pid;
    vector<int> proc_list; // List of process IDs assigned to the staff member
    bool operator<(const Staff &x) const { // Operator overloading for sorting
        return pid < x.pid; // Sort staff members based on their personal IDs
    }
};

// Structure to represent a job
struct Job {
    int tid, st, proc; // Task ID, start time, processing time
    Job(int t = 0, int s = 0, int e = 0): // Constructor
    tid(t), st(s), proc(e) {} // Initialize job with given parameters
};

// Custom comparator for Job objects
struct cmpJob {
    bool operator() (const Job &a, const Job &b) const {
        return a.st > b.st; // Compare jobs based on their start time (ascending order)
    }
};

// Custom comparator for pairs of integers
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first; // Compare first elements
    return a.second < b.second; // If first elements are equal, compare second elements
}

int main() {
    int N, M, cases = 0; // Number of tasks, number of staff members, scenario counter
    while (scanf("%d", &N) == 1 && N) { // Continue until N is not 0
        map<int, priority_queue<Job, vector<Job>, cmpJob> > scheduler; // Map to store task IDs and their associated jobs
        priority_queue<int, vector<int>, greater<int> > timeline; // Priority queue to maintain the timeline of events
        for (int i = 0; i < N; i++) { // Loop through each task
            int tid, num, t0, t, dt;
            scanf("%d %d %d %d %d", &tid, &num, &t0, &t, &dt); // Read task details
            for (int j = 0; j < num; j++) { // Loop through each job of the task
                scheduler[tid].push(Job(tid, t0, t)); // Push the job into the scheduler map
                timeline.push(t0); // Push the job start time into the timeline
                t0 += dt; // Update the start time for the next job
            }
        }
        scanf("%d", &M); // Read the number of staff members
        Staff staffs[10]; // Array to store staff members
        
        for (int i = 0; i < M; i++) { // Loop through each staff member
            int pid, num, tid;
            scanf("%d %d", &pid, &num); // Read staff member details
            staffs[i].pid = pid; // Assign personal ID
            for (int j = 0; j < num; j++) {
                scanf("%d", &tid); // Read assigned task IDs
                staffs[i].proc_list.push_back(tid); // Store assigned task IDs
            }
        }
        sort(staffs, staffs+M); // Sort staff members based on personal IDs
        int working[10] = {}, preReq[10] = {}, finReq[10] = {}; // Arrays to track working status and prerequisites
        int totTime = -2, now; // Total time, current time
        
        timeline.push(-1); // Push a placeholder into the timeline
        while (!timeline.empty()) // Continue until the timeline is empty
        {
            now = timeline.top(); // Get the current time from the timeline
            timeline.pop(); // Remove the current time from the timeline
            if (now == totTime) // Skip if the current time is the same as the previous time
                continue;
            totTime = now; // Update the total time
           
            for (int i = 0; i < M; i++) { // Loop through each staff member
                if (working[i] && finReq[i] <= now) // Check if the staff member is working and if their task is finished
                    working[i] = 0; // Mark the staff member as not working
            }
            vector< pair<int, int> > D; // Vector to store staff members with available processing capacity
            for (int i = 0; i < M; i++) { // Loop through each staff member
                if (working[i] == 0) { // Check if the staff member is not working
                    D.push_back(make_pair(preReq[i], i)); // Add the staff member to the vector with their prerequisite time
                }
            }
            sort(D.begin(), D.end(), cmp); // Sort the vector based on prerequisites
            for (int i = 0; i < D.size(); i++) // Loop through each staff member with available processing capacity
            {
                Staff &u = staffs[D[i].second]; // Get the staff member
                for (int j = 0; j < u.proc_list.size(); j++) { // Loop through each assigned task
                    int tid = u.proc_list[j]; // Get the task ID
                    if (!scheduler[tid].empty()) { // Check if there are jobs available for the task
                        Job tmp = scheduler[tid].top(); // Get the next job for the task
                        if (tmp.st <= now) { // Check if the job can be started
                            scheduler[tid].pop(); // Remove the job from the scheduler
                            preReq[D[i].second] = now; // Update the prerequisite time for the staff member
                            finReq[D[i].second] = now + tmp.proc; // Update the finishing time for the staff member
                            working[D[i].second] = 1; // Mark the staff member as working
                            timeline.push(finReq[D[i].second]); // Push the finishing time into the timeline
                            break; // Exit the loop
                        }
                    }
                }
            }
        }
        printf("Scenario %d: All requests are serviced within %d minutes.\n", ++cases, totTime); // Print the scenario number and total time
    }
    return 0; // Return 0 to indicate successful completion
}
