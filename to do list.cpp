//task3-to-do_list
//name-Divyansh pandey
#include <iostream>
#include <vector>

// Task class to represent a to-do task
class Task {
public:
    Task(const std::string& description) : description(description) {}
    std::string getDescription() const { return description; }

private:
    std::string description;
};

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "To-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    std::string description;
                    std::cout << "Enter task description: ";
                    std::cin.ignore();
                    std::getline(std::cin, description);
                    tasks.push_back(Task(description));
                    std::cout << "Task added successfully.\n";
                }
                break;

            case 2:
                {
                    if (tasks.empty()) {
                        std::cout << "No tasks in the list.\n";
                    } else {
                        std::cout << "Tasks:\n";
                        for (size_t i = 0; i < tasks.size(); i++) {
                            std::cout << i + 1 << ". " << tasks[i].getDescription() << "\n";
                        }
                    }
                }
                break;

            case 3:
                {
                    if (tasks.empty()) {
                        std::cout << "No tasks to delete.\n";
                    } else {
                        int taskNumber;
                        std::cout << "Enter the number of the task to delete: ";
                        std::cin >> taskNumber;

                        if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
                            tasks.erase(tasks.begin() + taskNumber - 1);
                            std::cout << "Task deleted successfully.\n";
                        } else {
                            std::cout << "Invalid task number.\n";
                        }
                    }
                }
                break;

            case 4:
                std::cout << "Exiting the program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
