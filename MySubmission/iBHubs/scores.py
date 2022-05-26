def print_student_scores_details(students, scores):
    students_count = len(students)

    student_scores = [
        (students[index], scores[index])
        for index in range(students_count)
    ]

    student_scores = sorted(student_scores, key=lambda x: (-x[1], x[0]))
    print(student_scores)


students = input()
scores = input()

students = students.split(",")
scores = scores.split(",")

scores = [float(data_point) for data_point in scores]
print_student_scores_details(students, scores)
