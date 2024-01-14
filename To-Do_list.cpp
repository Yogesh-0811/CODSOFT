#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - "
                     << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    void markTaskCompleted(size_t index) {
        if (validateIndex(index)) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        }
    }

    void removeTask(size_t index) {
        if (validateIndex(index)) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        }
    }

private:
    bool validateIndex(size_t index) const {
        if (index >= 1 && index <= tasks.size()) {
            return true;
        } else {
            cout << "Invalid task index." << endl;
            return false;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        cout << "\nTask Manager Menu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Remove Task\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();  // Clear newline from the buffer
                getline(cin, taskDescription);
                taskManager.addTask(taskDescription);
                break;
            }
            case 2:
                taskManager.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                taskManager.markTaskCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                taskManager.removeTask(taskIndex);
                break;
            }
            case 0:
                cout << "Exiting Task Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
