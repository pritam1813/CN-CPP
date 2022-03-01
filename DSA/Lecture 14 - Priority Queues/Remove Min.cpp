#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return INT_MIN;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        int a = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;

        while(parentIndex < pq.size()){
        	int lChildIndex = (2 * parentIndex) + 1;
        	int rChildIndex = (2 * parentIndex) + 2;
        	int minIndex = parentIndex;

        	if(lChildIndex <= pq.size() - 1){
        		if(rChildIndex <= pq.size() - 1){
        			if(pq[lChildIndex] > pq[rChildIndex]){
        				minIndex = rChildIndex;
        			}
        			else{
        				minIndex = lChildIndex;
        			}
        		}
        		else{
        			if(pq[lChildIndex] < pq[parentIndex]){
        				minIndex = lChildIndex;
        			}
        			else{
        				minIndex = parentIndex;
        			}
        		}
        	}

        	if(minIndex == parentIndex){
        		break;
        	}
        	else{
        		int temp = pq[minIndex];
        		pq[minIndex] = pq[parentIndex];
        		pq[parentIndex] = temp;
        	}
        	parentIndex = minIndex;
        }

        return a;
    }
};

int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
