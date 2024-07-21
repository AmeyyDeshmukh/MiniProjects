def main():
    # Load tasks from file
    tasks = load_tasks()

    while True:
        # Display menu options
        print("\n===== Todo List Application =====")
        print("1. View Tasks")
        print("2. Add Task")
        print("3. Mark Task as Completed")
        print("4. Delete Task")
        print("5. Save and Quit")

        choice = input("Enter your choice (1-5): ")

        if choice == '1':
            view_tasks(tasks)
        elif choice == '2':
            add_task(tasks)
        elif choice == '3':
            mark_completed(tasks)
        elif choice == '4':
            delete_task(tasks)
        elif choice == '5':
            save_and_quit(tasks)
            break
        else:
            print("Invalid choice. Please enter a number from 1 to 5.")

def load_tasks():
    try:
        with open("tasks.txt", "r") as f:
            tasks = [line.strip() for line in f.readlines()]
        return tasks
    except FileNotFoundError:
        return []

def view_tasks(tasks):
    if tasks:
        print("\n===== Tasks List =====")
        for idx, task in enumerate(tasks, start=1):
            print(f"{idx}. {task}")
    else:
        print("\nNo tasks found.")

def add_task(tasks):
    task = input("Enter the task: ")
    tasks.append(task)
    print("Task added.")

def mark_completed(tasks):
    view_tasks(tasks)
    try:
        index = int(input("Enter the task number to mark as completed: ")) - 1
        tasks[index] += " (Completed)"
        print("Task marked as completed.")
    except (IndexError, ValueError):
        print("Invalid task number.")

def delete_task(tasks):
    view_tasks(tasks)
    try:
        index = int(input("Enter the task number to delete: ")) - 1
        deleted_task = tasks.pop(index)
        print(f"Task '{deleted_task}' deleted.")
    except (IndexError, ValueError):
        print("Invalid task number.")

def save_and_quit(tasks):
    with open("tasks.txt", "w") as f:
        for task in tasks:
            f.write(task + "\n")
    print("Tasks saved. Exiting.")

if __name__ == "__main__":
    main()