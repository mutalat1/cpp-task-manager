#include <iostream>
#include <vector>
using namespace std;

// This struct holds all info for a task
struct Task {
    string title;
    string description;
    bool completed;
};

// This vector stores all the tasks
vector<Task> taskList;

// Adds a new task
void addNewTask() {
    Task myTask;
    cout << "Enter task title: ";
    getline(cin, myTask.title);
    cout << "Enter task description: ";
    getline(cin, myTask.description);
    myTask.completed = false;
    taskList.push_back(myTask);
    cout << "✅ Task added successfully!\n";
}

// Shows all tasks
void showAllTasks() {
    if (taskList.empty()) {
        cout << "📌 No tasks found.\n";
        return;
    }

    cout << "\n📋 Current Tasks:\n";
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". " << taskList[i].title << " - "
             << (taskList[i].completed ? "[Done] ✅" : "[Not done] ⏳") << endl;
    }
}

// Marks a task as completed
void markTaskAsDone() {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskList.size()) {
        cout << "❌ Invalid task number.\n";
        return;
    }

    taskList[taskNumber - 1].completed = true;
    cout << "🎉 Task marked as completed!\n";
}

// Deletes a task
void deleteTask() {
    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskList.size()) {
        cout << "❌ Invalid task number.\n";
        return;
    }

    taskList.erase(taskList.begin() + taskNumber - 1);
    cout << "🗑️ Task deleted successfully.\n";
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore(); // Prevent input bugs after numbers

        switch (choice) {
            case 1:
                addNewTask();
                break;
            case 2:
                showAllTasks();
                break;
            case 3:
                markTaskAsDone();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "👋 Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "⚠️ Invalid option. Please try again.\n";
        }
    }
}
