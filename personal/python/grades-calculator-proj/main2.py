import sqlite3
import re
import os

# Connect to the SQLite database
conn = sqlite3.connect('grades.db')
cursor = conn.cursor()

# Create the grades table if it doesn’t exist
cursor.execute('''
CREATE TABLE IF NOT EXISTS grades (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    subject TEXT,
    exam TEXT,
    weight REAL,
    done INTEGER,
    nominal_grade REAL
)
''')
conn.commit()

def refresh():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')
    # Always print the title at the top
    print("--- University Grade Management System ---\n")

# Helper function to safely evaluate mathematical expressions
def safe_eval(expression):
    if not re.match(r'^[0-9+\-*/(). ]+$', expression):
        raise ValueError("Invalid characters in expression. Use numbers and operators only.")
    try:
        return eval(expression)
    except ZeroDivisionError:
        raise ValueError("Division by zero is not allowed.")
    except Exception as e:
        raise ValueError(f"Invalid expression: {e}")

# Helper function to calculate the final grade for a subject
def get_final_grade(subject):
    cursor.execute("SELECT SUM(nominal_grade * weight) FROM grades WHERE subject = ? AND done = 1", (subject,))
    final_grade = cursor.fetchone()[0]
    return final_grade if final_grade is not None else 0

### Core Functions

def add_subject():
    refresh()
    subject = input("Enter the subject name: ").strip()
    cursor.execute("SELECT COUNT(*) FROM grades WHERE subject = ?", (subject,))
    if cursor.fetchone()[0] > 0:
        print(f"Subject '{subject}' already exists.")
        input("Press Enter to continue...")
        return
    
    try:
        num_exams = int(input("Enter the number of exams: "))
        exams = []
        weights = []
        total_weight = 0
        
        for i in range(num_exams):
            exam = input(f"Enter name of exam {i+1}: ").strip()
            weight_expr = input(f"Enter weight for {exam} (e.g., 0.25 or 1/4): ").strip()
            weight = safe_eval(weight_expr)
            if weight <= 0 or weight > 1:
                print("Weight must be between 0 and 1. Starting over.")
                input("Press Enter to try again...")
                return add_subject()
            exams.append(exam)
            weights.append(weight)
            total_weight += weight
        
        if abs(total_weight - 1.0) > 1e-6:
            print(f"Total weight must equal 1.0, but got {total_weight}. Starting over.")
            input("Press Enter to try again...")
            return add_subject()
        
        for exam, weight in zip(exams, weights):
            cursor.execute(
                "INSERT INTO grades (subject, exam, weight, done, nominal_grade) VALUES (?, ?, ?, 0, 0)",
                (subject, exam, weight)
            )
        conn.commit()
        refresh()
        print(f"Subject '{subject}' added successfully.")
    except ValueError as e:
        print(f"Error: {e}. Please try again.")
        input("Press Enter to continue...")
        return add_subject()
    input("Press Enter to continue...")

def delete_subject(subject):
    confirm = input(f"Are you sure you want to delete '{subject}'? (y/n): ").strip().lower()
    if confirm == 'y':
        cursor.execute("DELETE FROM grades WHERE subject = ?", (subject,))
        conn.commit()
        refresh()
        print(f"Subject '{subject}' deleted.")
    else:
        refresh()
        print("Deletion canceled.")
    input("Press Enter to continue...")

def edit_subject_name(old_subject, new_subject):
    cursor.execute("UPDATE grades SET subject = ? WHERE subject = ?", (new_subject, old_subject))
    conn.commit()
    print(f"Subject name updated from '{old_subject}' to '{new_subject}'.")
    input("Press Enter to continue...")

def bulk_edit_exams(subject):
    cursor.execute("SELECT exam FROM grades WHERE subject = ?", (subject,))
    exams = cursor.fetchall()
    if not exams:
        print(f"Subject '{subject}' not found.")
        input("Press Enter to continue...")
        return
    
    print(f"Enter new grades for each exam in '{subject}':")
    for exam in exams:
        exam_name = exam[0]
        try:
            grade_expr = input(f"Enter grade for {exam_name} (e.g., 85 or 10+76): ").strip()
            grade = safe_eval(grade_expr)
            if grade < 0 or grade > 100:
                print("Grade must be between 0 and 100. Skipping.")
                continue
            cursor.execute(
                "UPDATE grades SET nominal_grade = ?, done = 1 WHERE subject = ? AND exam = ?",
                (grade, subject, exam_name)
            )
        except ValueError as e:
            print(f"Error for {exam_name}: {e}. Skipping.")
    conn.commit()
    print(f"Grades for '{subject}' updated.")
    input("Press Enter to continue...")

def edit_exam(subject, exam):
    print(f"Editing exam '{exam}' in subject '{subject}':")
    print("1. Edit exam name")
    print("2. Edit weight")
    print("3. Edit nominal grade")
    choice = input("Choose an option (1-3): ").strip()
    
    if choice == '1':
        new_exam = input("Enter new exam name: ").strip()
        cursor.execute("UPDATE grades SET exam = ? WHERE subject = ? AND exam = ?", (new_exam, subject, exam))
        conn.commit()
        print(f"Exam name updated to '{new_exam}'.")
    elif choice == '2':
        weight_expr = input("Enter new weight (e.g., 0.25 or 1/4): ").strip()
        try:
            weight = safe_eval(weight_expr)
            if weight <= 0 or weight > 1:
                print("Weight must be between 0 and 1.")
                input("Press Enter to continue...")
                return
            cursor.execute("UPDATE grades SET weight = ? WHERE subject = ? AND exam = ?", (weight, subject, exam))
            conn.commit()
            print(f"Weight updated to {weight}.")
        except ValueError as e:
            print(f"Error: {e}")
    elif choice == '3':
        grade_expr = input("Enter new nominal grade (e.g., 85 or 10+76): ").strip()
        try:
            grade = safe_eval(grade_expr)
            if grade < 0 or grade > 100:
                print("Grade must be between 0 and 100.")
                input("Press Enter to continue...")
                return
            cursor.execute("UPDATE grades SET nominal_grade = ?, done = 1 WHERE subject = ? AND exam = ?", (grade, subject, exam))
            conn.commit()
            print(f"Grade updated to {grade}.")
        except ValueError as e:
            print(f"Error: {e}")
    else:
        print("Invalid choice.")
    input("Press Enter to continue...")

def query_information(subject):
    cursor.execute("SELECT exam, weight, done, nominal_grade FROM grades WHERE subject = ?", (subject,))
    rows = cursor.fetchall()

    refresh()
    
    if not rows:
        print(f"Subject '{subject}' not found.")
        input("Press Enter to continue...")
        return
    
    final_grade = get_final_grade(subject)
    approved = final_grade >= 70
    
    print(f"Information for {subject}:\n")
    if approved:
        print(f"{'Exam':<15}{'Weight':<10}{'Nominal Grade':<18}{'Grade':<10}")
        for row in rows:
            exam, weight, done, nominal_grade = row
            grade = nominal_grade * weight if done == 1 else 0
            print(f"{exam:<15}{weight:<10.2f}{nominal_grade:<18.2f}{grade:<10.2f}")
    else:
        print(f"{'Exam':<15}{'Weight':<10}{'Nominal Grade':<18}{'Grade':<10}{'Min to Pass':<15}")
        sum_done = sum(row[3] * row[1] for row in rows if row[2] == 1)
        for row in rows:
            exam, weight, done, nominal_grade = row
            grade = nominal_grade * weight if done == 1 else 0
            if done == 0:
                required = 70 - sum_done
                min_to_pass = max(0, required / weight) if weight > 0 else 0
            else:
                min_to_pass = 0
            print(f"{exam:<15}{weight:<10.2f}{nominal_grade:<18.2f}{grade:<10.2f}{min_to_pass:<15.2f}")
    print(f"\nFinal Grade: {final_grade:.2f}\n")
    input("Press Enter to continue...")

def get_subject_list():
    # Get distinct subjects in sorted order
    cursor.execute("SELECT DISTINCT subject FROM grades")
    subjects = [row[0] for row in cursor.fetchall()]
    return subjects

def list_subjects():
    subjects = get_subject_list()
    refresh()
    if not subjects:
        print("No subjects added yet.\n")
    else:
        print("Available subjects:")
        for idx, subject in enumerate(subjects, start=1):
            # Compute final grade for each subject
            final_grade = get_final_grade(subject)
            status = "Approved" if final_grade >= 70 else "Not Approved"
            print(f"{idx}. {subject} (Final Grade: {final_grade:.2f}, {status})")
        print()
    return subjects

def select_subject(action="select"):
    subjects = list_subjects()
    if not subjects:
        input("Press Enter to continue...")
        return None
    try:
        choice = int(input(f"Enter the subject number to {action}: ").strip())
        if 1 <= choice <= len(subjects):
            return subjects[choice - 1]
        else:
            print("Invalid subject number.")
            input("Press Enter to try again...")
            return select_subject(action)
    except ValueError:
        print("Invalid input. Please enter a number.")
        input("Press Enter to try again...")
        return select_subject(action)

def edit_subject():
    subject = select_subject("edit")
    if not subject:
        return
    
    while True:
        refresh()
        query_information(subject)  # Show subject data before editing
        print(f"Editing subject '{subject}':\n")
        print("1. Edit subject name")
        print("2. Delete subject")
        print("3. Bulk-edit exams")
        print("4. Edit a specific exam")
        print("5. Back to main menu\n")
        choice = input("Choose an option (1-5): ").strip()
        
        if choice == '1':
            new_subject = input("Enter new subject name: ").strip()
            if new_subject and new_subject != subject:
                edit_subject_name(subject, new_subject)
                subject = new_subject  # Update the subject variable
        elif choice == '2':
            delete_subject(subject)
            break  # Exit the edit menu after deletion
        elif choice == '3':
            bulk_edit_exams(subject)
        elif choice == '4':
            exam = input("Enter the exam name to edit: ").strip()
            cursor.execute("SELECT COUNT(*) FROM grades WHERE subject = ? AND exam = ?", (subject, exam))
            if cursor.fetchone()[0] == 0:
                print(f"Exam '{exam}' not found in subject '{subject}'.")
                input("Press Enter to continue...")
            else:
                edit_exam(subject, exam)
        elif choice == '5':
            break
        else:
            print("Invalid choice. Please try again.")
            input("Press Enter to continue...")

def query_subject():
    subject = select_subject("query")
    if subject:
        query_information(subject)

def main_menu():
    while True:
        refresh()
        print("Main Menu:")
        print("1. Add a new subject")
        print("2. Edit subject")
        print("3. Query information for a subject")
        print("4. List all subjects")
        print("5. Exit\n")
        choice = input("Enter your choice (1-5): ").strip()
        
        if choice == '1':
            add_subject()
        elif choice == '2':
            edit_subject()
        elif choice == '3':
            query_subject()
        elif choice == '4':
            list_subjects()
            input("Press Enter to continue...")
        elif choice == '5':
            refresh()
            print("Exiting the program. Goodbye!")
            conn.close()
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 5.")
            input("Press Enter to try again...")

if __name__ == "__main__":
    refresh()
    main_menu()
