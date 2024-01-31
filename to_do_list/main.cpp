// Header comment indicating the purpose of the code
// This code represents a simple to-do list application in C++

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Vector to store tasks, statuses, and spaces (for removing tasks)
vector<string> tasks;
vector<string> statuses;
vector<string> spaces;

// Function prototypes
void add_tasks();
void view_tasks();
void Mark_Task_as_Completed();
void remove_task();
int getValidPosition();

int main()
{
    // Variable declarations
    int h;
    string task;
    string decision;
    string status;
    int c=1;

    // Initial user input to populate the to-do list
    cout << "Enter your tasks and their status (Completed or Pending)\nREMARK! type 'done' to finish:\n";
    while (true) {
        cout << "enter the task number " << c << ". Type 'done' to finish" << endl;
        cin >> task;

        if (task == "done") {
            system("cls");
            break;  // Exit the loop if the user types 'done'
        }
        task += " : ";
        cout << "enter the status of the task number " << c <<endl;
        cin >> status;
        c++;
        tasks.push_back(task);

        system("cls");

        // Validate the entered status
        while(status != "Completed" && status != "Pending"){
            cout << "Invalid status!, reenter the task's status (Completed or Pending)" << endl;
            cin >> status;

        }
        statuses.push_back(status);
    }

    // Display a reminder about task positions
    cout << "Reminder: if you want to add, mark task as completed or remove a task, the first task has the position 1, the second task has the position 2, the third task has the position 3 etc" << endl;

    // Initialize spaces vector with empty strings for later use
    for(int u=0; u< tasks.size(); u++){
        spaces.push_back("");
    }

    system("cls");

    // Main menu loop
    while(decision != "exit"){
        cout << "Enter a number to choose an option\n1 : Add task(s) \n2 : Mark Task(s) as Completed\n3 : Remove task(s)\n4 : View tasks\n5 : Exit\n";
        cin >> h;

        switch(h){
    case 4:
        view_tasks();
        break;
    case 1:
        add_tasks();
        break;
    case 2:
        Mark_Task_as_Completed();
        break;
    case 3:
        remove_task();
        break;
    case 5:
        decision  = "exit";
        break;
    default:
        cout << "Invalid option. Enter a number to choose an option\nAdd task(s) : 1\nMark Task(s) as Completed : 2\nRemove task(s) : 3\nView tasks : 4\n" << endl;
        cin >> h;

        }
    }
    return 0;
}

// Function to add tasks to the to-do list
void add_tasks(){

    string addtask,addstatus;
    int n,p;

    system("cls");

    // Input the number of tasks to add
    cout << "Enter the number of tasks: " << endl;
    cin >> n;

    // Validate the entered number of tasks
    while( n<=0){
        cout << "Invalid number. Please enter a positive number: "<< endl;
        cin >> n;
    }

    // Loop to input task details and add them to the list
    for(int j=0;  j<n; j++){
        cout << "enter the task number " << j+1 <<", it statue and the position to add" << endl;
        cin >> addtask;
        addtask +=" : ";
        cin >> addstatus;

        // Validate the entered status
        while(addstatus != "Completed" && addstatus != "Pending"){
            cout << "Invalid status!, reenter the task's status (Completed or Pending)" << endl;
            cin >> addstatus;
    }

        // Get a valid position for the new task
        p = getValidPosition();


        p = max(1, min(p, static_cast<int>(tasks.size()) + 1));

        // Insert the new task and status at the specified position
        tasks.insert(tasks.begin() + (p - 1), addtask);
        statuses.insert(statuses.begin() + (p - 1), addstatus);
    }
}

// Function to view tasks and their statuses
void view_tasks(){

    system("cls");
    // Loop to display tasks and statuses
    for (int i = 0; i < tasks.size(); i++){
        cout << tasks[i] << statuses[i] << endl;
    }
    cout <<endl;
}

// Function to mark tasks as completed
void  Mark_Task_as_Completed(){

        int n1, p1;

        // Input the number of tasks to mark as completed
        system("cls");
        cout << "enter the number of the task/ tasks that you wanna mark it as completed" << endl;
        cin >> n1;

        // Loop to input positions and mark tasks as completed
        for(int k=0; k<n1; k++){
            cout << "enter the position of the task number " << k+1 << " that you want to change its status into completed" << endl;
            p1 = getValidPosition();
            statuses[p1-1]="Completed";
    }
    system("cls");
    }

// Function to remove tasks from the to-do list
void remove_task(){

    int n2, p2;
    system("cls");

    // Input the number of tasks to remove
    cout << "enter the number of the task/ tasks that you wanna remove it from the list" << endl;
    cin >> n2;

    // Loop to input positions and remove tasks
    for(int l=0; l<n2; l++){

        cout << "enter the position of the task number " << l+1 << " that you want to remove it from the list" << endl;
            p2 = getValidPosition();
            system("cls");

            for(int r=p2-1; r<tasks.size()-1; r++){
                tasks[r]=tasks[r+1];
                statuses[r]=statuses[r+1];
            }
            tasks.pop_back();
            statuses.pop_back();

            cout << "As you can see the order of tasks has changed 'cause of removed task(s)\n";
            for (int i = 0; i < tasks.size(); i++){
            cout << tasks[i] << statuses[i] << endl;
    }


    }

        // Remove empty tasks and statuses from the vectors
    for(int d=tasks.size(); d>0; d--){
        if(tasks[d] == ""){
            tasks.erase(tasks.begin() + d);
            statuses.erase(statuses.begin() + d);
        }
    }

}

// Function to get a valid position from the user
int getValidPosition() {
    int position;
    cin >> position;

    // Validate the entered position
    while (cin.fail() || position < 1 || position > tasks.size() /*+ 1*/) {
        cout << "Invalid position. Please enter a valid position: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> position;
    }
    return position;
}
