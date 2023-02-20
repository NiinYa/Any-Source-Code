import csv

# Write
with open("file1.csv", "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(["SN", "Movie", "Protagonist"])
    writer.writerow([1, "Lord of the Rings", "Frodo Baggins"])
    writer.writerow([2, "Harry Potter", "Harry Potter"])

with open("file2.csv", "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(["SN", "Movie", "Protagonist"])
    writer.writerow([1, "Lord of the Rings", "Frodo Baggins"])
    writer.writerow([2, "Harry Potter", "Harry Potter"])

with open("employee.csv", mode="w", newline="") as file:
    fieldnames = ["emp_name", "dept", "birth_month"]
    writer = csv.DictWriter(file, fieldnames=fieldnames)

    writer.writeheader()
    writer.writerow({'emp_name': 'John Smith',
                     'dept': 'Accounting', 'birth_month': 'November'})
    writer.writerow({'emp_name': 'Erica Meyes',
                    'dept': 'IT', 'birth_month': 'March'})

# Read
with open('file1.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        print(row)

print()

with open('file2.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        print(row)

print()

with open('employee.csv', 'r') as file:
    csv_reader = csv.DictReader(file)
    line_count = 0
    for row in csv_reader:
        if line_count == 0:
            print(f'Column names are {", ".join(row)}')
            line_count += 1
        print(
            f'{row["emp_name"]} works in the {row["dept"]} department, and was born in {row["birth_month"]}')
        line_count += 1
    print(f'Processed {line_count} lines.')